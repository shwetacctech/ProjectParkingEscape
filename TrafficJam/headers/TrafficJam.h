#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrafficJam.h"
#include "OpenGLWindow.h"
#include <Point3D.h>
#include <Car.h>

class TrafficJam : public QMainWindow
{
    Q_OBJECT

public:
    TrafficJam(QWidget *parent = nullptr);
    ~TrafficJam();
    void setupUi();

private slots:
    void readOBJ();
    void sceneStatic();
    void UpperMove();
    void DownMove();
    void LeftMove();
    void RightMove();
    void selectCar();
    void stop();

private:
    Ui::TrafficJamClass ui;
   
    OpenGLWindow* mRenderer;
    QWidget* mCentralWidget;
    QWidget* gridLayoutWidget;
    QGridLayout* gridLayout_2;
    QVBoxLayout* verticalLayout_2;
    QOpenGLWidget* openGLWidget;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* horizontalLayout_3;
    QHBoxLayout* horizontalLayout_4;
    QPushButton* staticScene_button;
    QPushButton* topmover_button;
    QPushButton* downmover_button;
    QPushButton* pushButton;
    QPushButton* rightmover_button,* car_button;
    QPushButton* stop_button;
    QMenu* dropdownMenu;
    QAction* car1_;
    QAction* car2_;
    QAction* car3_;
    QAction* car4_;
    QAction* car5_;
    QAction* car6_;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    std::vector<Point3D> mPoints;
    std::vector<Point3D> mnPoints;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    std::vector<Point3D> translatedPoints ;
    std::vector<Car> mCarContainer;
    int car_no=0;
private:
    void addVerticesColor();
    void addVertices();
};
