/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Nov 30 15:20:26 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *combo_mode;
    QLabel *label_5;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QSlider *slider_Da;
    QSlider *slider_Db;
    QLabel *label_2;
    QSlider *slider_s;
    QSlider *slider_betaError;
    QPlainTextEdit *text_s;
    QPlainTextEdit *text_Da;
    QPlainTextEdit *text_Db;
    QPlainTextEdit *text_BetaError;
    QLabel *label_6;
    QComboBox *combo_presets;
    QPushButton *btn_draw;
    QLabel *label_out;
    QComboBox *combo_frameSkip;
    QPushButton *btn_next;
    QLabel *label_frame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(559, 379);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        combo_mode = new QComboBox(centralWidget);
        combo_mode->setObjectName(QString::fromUtf8("combo_mode"));
        combo_mode->setGeometry(QRect(13, 311, 131, 28));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 291, 68, 18));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(3, 7, 261, 285));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(168, 61, 91, 18));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(128, 61, 20, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 61, 16, 18));
        slider_Da = new QSlider(groupBox);
        slider_Da->setObjectName(QString::fromUtf8("slider_Da"));
        slider_Da->setGeometry(QRect(78, 111, 19, 160));
        slider_Da->setMaximum(1000);
        slider_Da->setValue(250);
        slider_Da->setOrientation(Qt::Vertical);
        slider_Db = new QSlider(groupBox);
        slider_Db->setObjectName(QString::fromUtf8("slider_Db"));
        slider_Db->setGeometry(QRect(148, 111, 19, 160));
        slider_Db->setMaximum(10000);
        slider_Db->setValue(6250);
        slider_Db->setOrientation(Qt::Vertical);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(68, 61, 21, 18));
        slider_s = new QSlider(groupBox);
        slider_s->setObjectName(QString::fromUtf8("slider_s"));
        slider_s->setGeometry(QRect(18, 111, 19, 160));
        slider_s->setMaximum(10000);
        slider_s->setSingleStep(0);
        slider_s->setValue(3125);
        slider_s->setOrientation(Qt::Vertical);
        slider_betaError = new QSlider(groupBox);
        slider_betaError->setObjectName(QString::fromUtf8("slider_betaError"));
        slider_betaError->setGeometry(QRect(198, 111, 19, 160));
        slider_betaError->setMaximum(100000);
        slider_betaError->setValue(500);
        slider_betaError->setOrientation(Qt::Vertical);
        text_s = new QPlainTextEdit(groupBox);
        text_s->setObjectName(QString::fromUtf8("text_s"));
        text_s->setGeometry(QRect(8, 81, 51, 26));
        text_s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_s->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_Da = new QPlainTextEdit(groupBox);
        text_Da->setObjectName(QString::fromUtf8("text_Da"));
        text_Da->setGeometry(QRect(68, 81, 51, 26));
        text_Da->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_Db = new QPlainTextEdit(groupBox);
        text_Db->setObjectName(QString::fromUtf8("text_Db"));
        text_Db->setGeometry(QRect(128, 81, 51, 27));
        text_Db->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_BetaError = new QPlainTextEdit(groupBox);
        text_BetaError->setObjectName(QString::fromUtf8("text_BetaError"));
        text_BetaError->setGeometry(QRect(188, 81, 51, 27));
        text_BetaError->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(15, 29, 68, 18));
        combo_presets = new QComboBox(groupBox);
        combo_presets->setObjectName(QString::fromUtf8("combo_presets"));
        combo_presets->setGeometry(QRect(74, 24, 169, 28));
        btn_draw = new QPushButton(centralWidget);
        btn_draw->setObjectName(QString::fromUtf8("btn_draw"));
        btn_draw->setGeometry(QRect(153, 311, 98, 28));
        label_out = new QLabel(centralWidget);
        label_out->setObjectName(QString::fromUtf8("label_out"));
        label_out->setGeometry(QRect(261, 58, 280, 280));
        combo_frameSkip = new QComboBox(centralWidget);
        combo_frameSkip->setObjectName(QString::fromUtf8("combo_frameSkip"));
        combo_frameSkip->setGeometry(QRect(13, 344, 132, 28));
        btn_next = new QPushButton(centralWidget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(152, 344, 98, 28));
        label_frame = new QLabel(centralWidget);
        label_frame->setObjectName(QString::fromUtf8("label_frame"));
        label_frame->setGeometry(QRect(301, 34, 211, 20));
        label_frame->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        combo_mode->clear();
        combo_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Results Only", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Frame Skip", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Frame-by-Frame", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Beta Error", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Db", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Da", 0, QApplication::UnicodeUTF8));
        text_s->setPlainText(QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Preset:", 0, QApplication::UnicodeUTF8));
        combo_presets->clear();
        combo_presets->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 2A - Large Spots", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 2B - Small Spots", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 2C - Cheetah", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 2D - Leopard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 3A - Irregular Spots", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 3B - Reticulation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 3C - Random Stripes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Figure 3D - Mixed Large and Small Stripes", 0, QApplication::UnicodeUTF8)
        );
        btn_draw->setText(QApplication::translate("MainWindow", "&Draw", 0, QApplication::UnicodeUTF8));
        label_out->setText(QString());
        btn_next->setText(QApplication::translate("MainWindow", "&Next", 0, QApplication::UnicodeUTF8));
        label_frame->setText(QApplication::translate("MainWindow", "Frame: 0", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
