#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QLayout>
#include <QtGui/QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    m_frameSkip(1)
{
    ui->setupUi(this);
    setTextValues();
    setControlEnableStates();

    setUpFrameSkipCombo(15);
}

MainWindow::~MainWindow()
{
    delete ui;
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
}

void MainWindow::on_combo_mode_currentIndexChanged(int)
{
    setControlEnableStates();
}

void MainWindow::setControlEnableStates()
{
    ui->combo_frameSkip->setVisible(ui->combo_mode->currentIndex() == 1);
}


void MainWindow::reset()
{
    m_frame = 0;
    for(int i=0; i<m_startFrame; ++i){
        computeThisFrame();
        ++m_frame;
    }
}

void MainWindow::nextFrame()
{
    for(int i=0; i<m_frameSkip; ++i) {
        computeThisFrame();
        ++m_frame;
    }

    renderImage();
}

void MainWindow::computeThisFrame()
{

}

void MainWindow::renderImage()
{
    // render into the qimage

    // display the qimage
    ui->label_out->setPixmap(QPixmap::fromImage(*m_img));
}
