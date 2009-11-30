#ifndef DRAWPANE_H
#define DRAWPANE_H

#include <QGLWidget>

class DrawPane : public QGLWidget
{
    Q_OBJECT

public:
    DrawPane(QWidget * parent);

    void reset();
    void nextFrame();
    void setFrameSkip(int n);
    void setStartFrame(int n);

    void setParams(double s, double Da, double Db, double betaError);

protected:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    // what frame we're on
    int m_frame;
    int m_frameSkip;
    int m_startFrame;

    double m_s, m_Da, m_Db, m_betaError;

    void computeThisFrame();

};

#endif // DRAWPANE_H
