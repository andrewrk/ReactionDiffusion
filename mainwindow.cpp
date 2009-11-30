#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTextValues();

    // add the opengl widget
    ui->widget_out->setVisible(false);

    m_drawPane = new DrawPane(this);
    this->layout()->addWidget(m_drawPane);
    m_drawPane->setGeometry(ui->widget_out->geometry());
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
    m_drawPane->setParams(ui->text_s->toPlainText().toDouble(),
                          ui->text_Da->toPlainText().toDouble(),
                          ui->text_Db->toPlainText().toDouble(),
                          ui->text_BetaError->toPlainText().toDouble());

    switch(ui->combo_mode->currentIndex())
    {
        case 0: // skip t to the end
            m_drawPane->setFrameSkip(1);
            m_drawPane->setStartFrame(2000);
            break;
        case 1: // frame skip by n
            m_drawPane->setFrameSkip(ui->text_frameSkip->toPlainText().toInt());
            m_drawPane->setStartFrame(0);
            break;
        case 2: // start at beginning
            m_drawPane->setFrameSkip(1);
            m_drawPane->setStartFrame(0);
            break;
        default:
            throw NULL;
    }

    m_drawPane->reset();
    m_drawPane->updateGL();
}

void MainWindow::on_combo_mode_currentIndexChanged(int index)
{
    ui->text_frameSkip->setVisible(index == 1);
    ui->lbl_frameSkip->setVisible(index == 1);

}
