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
    TrafficJam(QWidget *parent = nullptr);//Constructor
    ~TrafficJam(); //Destructor
    void setupUi(); //sets the ui 

private slots:
    void readOBJ(); //reads obj file of car
    void sceneStatic(); //renders static scene of cars
    void UpperMove(); //moves the car to upper i.e +y direction
    void DownMove(); //moves the car to lower i.e -y direction
    void LeftMove(); //moves the car to left direction i.e, -x
    void RightMove(); //moves the car to right direction i.e, +x
    void selectCar(); //select a specific car from dropdown
    void stop();

private:
   //UI objects of QT 
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
    QPushButton* leftmover_button;
    QPushButton* rightmover_button;
    QPushButton* stop_button;
    QPushButton* car_button;
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
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    std::vector<Point3D> translatedPoints ;
    std::vector<Car> mCarContainer;
    int car_no=0;
    std::vector<float> mObjVertices;
    std::vector<float> mObjColors;
private:
    void addVerticesColor(); //to add Vertices along with color in mVertices and mColors to further render in OpenGLWindow
    void addVertices(); //to add Vertices in mVertices to further render in OpenGLWindow
};
