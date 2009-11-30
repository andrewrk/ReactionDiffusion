#include "drawpane.h"

DrawPane::DrawPane(QWidget * parent) :
        QGLWidget(parent)
{

}

void DrawPane::initializeGL()
{
    // Set up the rendering context, define display lists etc.:
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void DrawPane::resizeGL(int w, int h)
{
    // setup viewport, projection etc.:
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
}

void DrawPane::paintGL()
{
    // draw the scene:
    glClearColor(1.0, 1.0, 1.0, 0.0);
}


void DrawPane::setFrameSkip(int n)
{
    m_frameSkip = n;
}

void DrawPane::setStartFrame(int n)
{
    m_startFrame = n;
}

void DrawPane::reset()
{
    m_frame = 0;
    for(int i=0; i<m_startFrame; ++i){
        computeThisFrame();
        ++m_frame;
    }
}

void DrawPane::nextFrame()
{
    for(int i=0; i<m_frameSkip; ++i) {
        computeThisFrame();
        ++m_frame;
    }

}

void DrawPane::computeThisFrame()
{

}

void DrawPane::setParams(double s, double Da, double Db, double betaError)
{
    m_s = s;
    m_Da = Da;
    m_Db = Db;
    m_betaError = betaError;
}
