#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QLayout>
#include <QtGui/QPixmap>

#include <cstdlib>
#include <cstring>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    m_frameSkip(1),
    m_img(NULL),
    m_a(NULL),
    m_b(NULL),
    m_betas(NULL)
{
    ui->setupUi(this);
    setTextValues();
    setControlEnableStates();

    setUpFrameSkipCombo(15);
}

MainWindow::~MainWindow()
{
    delete ui;
    cleanupBuffers();

    if( m_img ) {
        delete m_img;
        m_img = NULL;
    }
}

void MainWindow::setUpFrameSkipCombo(int n)
{
    ui->combo_frameSkip->clear();
    for(int i=0; i<n; ++i){
        ui->combo_frameSkip->addItem(QString::number(i+1) + QString(" frames"));
    }
}

void MainWindow::setTextValues()
{
    ui->text_s->setPlainText(QString::number(ui->slider_s->value()/100000.0f));
    ui->text_Da->setPlainText(QString::number(ui->slider_Da->value()/1000.0f));
    ui->text_Db->setPlainText(QString::number(ui->slider_Db->value()/100000.0f));
    ui->text_BetaError->setPlainText(QString::number(ui->slider_betaError->value()/10000.0f));

    ui->combo_frameSkip->setCurrentIndex(m_frameSkip-1);
}

void MainWindow::on_slider_s_valueChanged(int value)
{
    ui->text_s->setPlainText(QString::number(value/100000.0f));
}

void MainWindow::on_slider_Da_valueChanged(int value)
{
    ui->text_Da->setPlainText(QString::number(value/1000.0f));
}

void MainWindow::on_slider_Db_valueChanged(int value)
{
    ui->text_Db->setPlainText(QString::number(value/100000.0f));
}

void MainWindow::on_slider_betaError_valueChanged(int value)
{
    ui->text_BetaError->setPlainText(QString::number(value/10000.0f));
}

void MainWindow::on_btn_draw_clicked()
{
    m_s = ui->text_s->toPlainText().toDouble();
    m_Da = ui->text_Da->toPlainText().toDouble();
    m_Db = ui->text_Db->toPlainText().toDouble();
    m_betaError = ui->text_BetaError->toPlainText().toDouble();


    switch(ui->combo_mode->currentIndex())
    {
        case 0: // skip t to the end
            m_frameSkip = 1;
            m_startFrame = 2000;
            break;
        case 1: // frame skip by n
            m_frameSkip = ui->combo_frameSkip->currentIndex() + 1;
            m_startFrame = 0;
            break;
        case 2: // start at beginning
            m_frameSkip = 1;
            m_startFrame = 0;
            break;
        default:
            throw "invalid combo box index";
    }

    reset();

    // go to first frame
    nextFrame();
}

void MainWindow::on_combo_mode_currentIndexChanged(int)
{
    setControlEnableStates();
}

void MainWindow::setControlEnableStates()
{
    ui->combo_frameSkip->setVisible(ui->combo_mode->currentIndex() == 1);
}

void MainWindow::cleanupBuffers()
{
    if( m_a ) {
        delete[] m_a;
        m_a = NULL;
    }
    if( m_b ) {
        delete[] m_b;
        m_a = NULL;
    }
    if( m_betas ) {
        delete[] m_betas;
        m_betas = NULL;
    }
}


void MainWindow::reset()
{
    m_width = ui->label_out->width();
    m_height = ui->label_out->height();

    m_frame = 0;

    // initialize a, b, and beta
    cleanupBuffers();
    m_betas = new double[m_width * m_height];
    m_a = new double[m_width * m_height];
    m_b = new double[m_width * m_height];


    for(int y=0; y<m_height; ++y) {
        for(int x=0; x<m_width; ++x) {
            int this_index = indexOf(x,y);
            m_betas[this_index] = 12.0 + rand() / (double) RAND_MAX;
            m_a[this_index] = 4.0;
            m_b[this_index] = 4.0;
        }
    }


    goFrames(m_startFrame);
}

void MainWindow::goFrames(int n)
{
    for(int i=0; i<n; ++i){
        computeThisFrame();
        ++m_frame;
    }
}

void MainWindow::nextFrame()
{
    goFrames(m_frameSkip);

    renderImage();
}

void MainWindow::computeThisFrame()
{
    double deltaT = 0.5;

    double * old_a = new double[m_width * m_height];
    double * old_b = new double[m_width * m_height];

    memcpy(old_a, m_a, sizeof(double) * m_width * m_height);
    memcpy(old_b, m_b, sizeof(double) * m_width * m_height);

    for(int y=0; y<m_height; ++y){
        for(int x=0; x<m_width; ++x){
            int this_index = indexOf(x,y);
            double a = old_a[this_index];
            double b = old_b[this_index];
            double beta = m_betas[this_index];
            m_a[this_index] += m_s * (16.0 - a * b) + m_Da * (
                    old_a[indexOf((x+m_width+1)%m_width, y)] +
                    old_a[indexOf((x+m_width-1)%m_width, y)] +
                    old_a[indexOf(x, (y+m_height+1)%m_height)] +
                    old_a[indexOf(x, (y+m_height-1)%m_height)] -
                    4.0 * a);
            m_b[this_index] += m_s * (a * b - b - beta) + m_Db * (
                    old_b[indexOf((x+m_width+1)%m_width, y)] +
                    old_b[indexOf((x+m_width-1)%m_width, y)] +
                    old_b[indexOf(x, (y+m_height+1)%m_height)] +
                    old_b[indexOf(x, (y+m_height-1)%m_height)] -
                    4.0 * b);
        }
    }

    delete[] old_a;
    delete[] old_b;

}

void MainWindow::renderImage()
{
    // render into the qimage
    if( ! m_img )
        m_img = new QImage(m_width, m_height, QImage::Format_RGB32);

    for(int y=0; y<m_height; ++y) {
        for( int x=0; x<m_width; ++x) {
            int this_index = indexOf(x,y);
            double a = m_a[this_index];
            double b = m_b[this_index];
            m_img->setPixel(x,y,qRgb(a/(a+b) * 255.0, 0, b/(a+b) * 255.0));
        }
    }

    // display the qimage
    ui->label_out->setPixmap(QPixmap::fromImage(*m_img));
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Space) {
        nextFrame();
        event->accept();
    }
}

void MainWindow::on_btn_next_clicked()
{
    nextFrame();
}
