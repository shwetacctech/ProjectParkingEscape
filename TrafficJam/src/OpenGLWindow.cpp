#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include <iostream>

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(550, 450);
    QStringList file_lists = { "vertexShader.glsl" ,"fragmentShader.glsl" };
    mShaderWatcher = new QFileSystemWatcher(file_lists, this);
    connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
    mTimer->start(16);
    mTimeValue = 0.0f;
}

OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();
    QObject::disconnect(mContextWatchConnection);
}


void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vertices)
{
    mVertice = vertices;
    update();
}

void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colors)
{
    mColor = colors;
    update();
}


void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();
    QMatrix4x4 matrix;
    matrix.ortho(-2.0f * 20, 2.0f * 20, -2.0f * 20, 2.0f * 20, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    matrix.rotate(rotationAngle);
    matrix.scale(scaleFactor);

    mProgram->setUniformValue(m_matrixUniform, matrix);
    mProgram->setUniformValue("time", mTimeValue);
    GLfloat* verticesData = mVertice.data();
    GLfloat* colorsData = mColor.data();

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);

    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);

    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, mVertice.size() /3);

    
}

void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors)
{
    mVertice = vertices;
    mColor = colors;
    update();  // Schedule a repaint
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    
    if (event->buttons() & Qt::LeftButton) {
        QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
        QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);

       
        rotationAngle = rotX * rotY* rotationAngle;
        update();
    }
    lastPos = event->pos();
}
void OpenGLWindow::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0) {
        zoomIn();
    }
    else {
        zoomOut();
    }
}
// Assuming you have a zoom factor, for instance, zoomFactor = 1.1 for 10% zoom in
void OpenGLWindow::zoomIn()
{
    scaleFactor *= 1.1f;
    update(); // Trigger repaint
}

void OpenGLWindow::zoomOut()
{
    scaleFactor /= 1.1f;
    update(); // Trigger repaint
}
QString OpenGLWindow::readShader(QString filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Invalid file";

    QTextStream stream(&file);
    QString line = stream.readLine();

    while (!stream.atEnd()) {
        line.append(stream.readLine());
    }
    file.close();
    return line;
}
void OpenGLWindow::initializeGL()
{
    QString qvertexShaderSource = readShader("vertexShader.glsl");
    QString qfragmentShaderSource = readShader("fragmentShader.glsl");

    rotationAngle = QQuaternion::fromAxisAndAngle(0.0f, 0.0f, 1.0f, 0.0f); // Initialize rotation angle


    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, qvertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, qfragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    m_colAttr = mProgram->attributeLocation("colAttr");
    m_matrixUniform = mProgram->uniformLocation("matrix");
    if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1) {
        qDebug() << "Shader attribute or uniform location error.";
        // Handle the error appropriately, e.g., return or throw an exception
    }
}
void OpenGLWindow::shaderWatcher()
{

    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    mProgram->release();
    mProgram->removeAllShaders();
    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();


}

void OpenGLWindow::updateAnimation() {
    mTimeValue += 0.05f;
    update();
}

