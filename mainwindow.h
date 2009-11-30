#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QImage>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent * event);

private:
    Ui::MainWindow *ui;

    // what frame we're on
    int m_frame;
    int m_frameSkip;
    int m_startFrame;

    QImage * m_img;
    double * m_a;
    double * m_b;
    double * m_betas;

    int m_width, m_height;


    double m_s, m_Da, m_Db, m_betaError;

    void computeThisFrame();
    void reset();
    void nextFrame();
    void setFrameSkip(int n);
    void setStartFrame(int n);
    void renderImage();
    void cleanupBuffers();
    void goFrames(int n);

    void setTextValues();
    void setControlEnableStates();
    void setUpFrameSkipCombo(int n);

    inline int indexOf(int x, int y){ return y * m_width + x; }

private slots:
    void on_combo_frameSkip_currentIndexChanged(int index);
    void on_btn_next_clicked();
    void on_combo_mode_currentIndexChanged(int index);
    void on_btn_draw_clicked();
    void on_slider_betaError_valueChanged(int value);
    void on_slider_Db_valueChanged(int value);
    void on_slider_Da_valueChanged(int value);
    void on_slider_s_valueChanged(int value);
};

#endif // MAINWINDOW_H
