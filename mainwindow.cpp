#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTextValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTextValues()
{
    ui->text_s->setPlainText(QString::number(ui->slider_s->value()/100000.0f));
    ui->text_Da->setPlainText(QString::number(ui->slider_Da->value()/1000.0f));
    ui->text_Db->setPlainText(QString::number(ui->slider_Db->value()/100000.0f));
    ui->text_BetaError->setPlainText(QString::number(ui->slider_betaError->value()/10000.0f));
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
            m_frameSkip = ui->text_frameSkip->toPlainText().toInt();
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

void MainWindow::on_combo_mode_currentIndexChanged(int index)
{
    ui->text_frameSkip->setVisible(index == 1);
    ui->lbl_frameSkip->setVisible(index == 1);

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

}

void MainWindow::computeThisFrame()
{

}
