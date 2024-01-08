#include "stdafx.h"
#include "TrafficJam.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <Transformations.h>

TrafficJam::TrafficJam(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(staticScene_button, &QPushButton::clicked, this, &TrafficJam::sceneStatic);
    connect(topmover_button, &QPushButton::clicked, this, &TrafficJam::UpperMove);
    connect(downmover_button, &QPushButton::clicked, this, &TrafficJam::DownMove);
    connect(leftmover_button, &QPushButton::clicked, this, &TrafficJam::LeftMove);
    connect(rightmover_button, &QPushButton::clicked, this, &TrafficJam::RightMove);
    connect(stop_button, &QPushButton::clicked, this, &TrafficJam::stop);
    connect(car_button, &QPushButton::clicked, this, &TrafficJam::selectCar);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

TrafficJam::~TrafficJam()
{
}
void TrafficJam::setupUi()
{

    resize(944, 895);
    mCentralWidget = new QWidget(this);
    mCentralWidget->setObjectName("centralWidget");
    gridLayoutWidget = new QWidget(mCentralWidget);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(-1, -1, 641, 361));
    gridLayout_2 = new QGridLayout(gridLayoutWidget);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setContentsMargins(11, 11, 11, 11);
    gridLayout_2->setObjectName("gridLayout_2");
    gridLayout_2->setContentsMargins(0, 0, 0, 0);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName("verticalLayout_2");
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setObjectName("openGLWidget");
    verticalLayout_2->addWidget(mRenderer, 3);

    gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

    horizontalLayoutWidget = new QWidget(mCentralWidget);
    horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
    horizontalLayoutWidget->setGeometry(QRect(0, 360, 641, 80));
    horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3->setObjectName("horizontalLayout_3");
    horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    horizontalLayout_4->setObjectName("horizontalLayout_4");
    staticScene_button = new QPushButton(horizontalLayoutWidget);
    staticScene_button->setObjectName("staticScene_button");
    staticScene_button->setText("Start");

    horizontalLayout_4->addWidget(staticScene_button);

    topmover_button = new QPushButton(horizontalLayoutWidget);
    topmover_button->setObjectName("topmover_button");
    topmover_button->setText("FORWARD");
    horizontalLayout_4->addWidget(topmover_button);

    downmover_button = new QPushButton(horizontalLayoutWidget);
    downmover_button->setObjectName("downmover_button");
    downmover_button->setText("BACKWARD");
    horizontalLayout_4->addWidget(downmover_button);

    leftmover_button = new QPushButton(horizontalLayoutWidget);
    leftmover_button->setObjectName("pushButton");
    leftmover_button->setText("LEFT");
    horizontalLayout_4->addWidget(leftmover_button);
    rightmover_button = new QPushButton(horizontalLayoutWidget);
    rightmover_button->setObjectName("pushButton");
    rightmover_button->setText("RIGHT");
    horizontalLayout_4->addWidget(rightmover_button);
    car_button = new QPushButton(horizontalLayoutWidget);
    car_button->setObjectName("pushButton");
    car_button->setText("SELECT");
    horizontalLayout_4->addWidget(car_button);
    dropdownMenu = new QMenu(car_button);
    car1_ = dropdownMenu->addAction("Car1");
    car2_ = dropdownMenu->addAction("Car2");
    car3_ = dropdownMenu->addAction("Car3");
    car4_ = dropdownMenu->addAction("Car4");
    car5_ = dropdownMenu->addAction("Car5");
    car6_ = dropdownMenu->addAction("Car6");

    stop_button = new QPushButton(horizontalLayoutWidget);
    stop_button->setObjectName("pushButton");
    stop_button->setText("RESTART");
    horizontalLayout_4->addWidget(stop_button);


    horizontalLayout_3->addLayout(horizontalLayout_4);

    setCentralWidget(mCentralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName("menuBar");
    menuBar->setGeometry(QRect(0, 0, 644, 22));
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName("mainToolBar");
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName("statusBar");
    setStatusBar(statusBar);

    QMetaObject::connectSlotsByName(this);
} 
void TrafficJam::sceneStatic() {
    readOBJ();
    std::vector<Point3D> mCarPoints;
    std::vector<float> mCarColors;
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X() - 30, mPoints[i].Y() + 50, mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i++) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c1(mCarPoints, mCarColors);
    mCarContainer.push_back(c1);
    mCarPoints.clear();
    mCarColors.clear();
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X(), mPoints[i].Y() + 50, mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i++) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c2(mCarPoints, mCarColors);
    mCarContainer.push_back(c2);
    mCarPoints.clear();
    mCarColors.clear();
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X() + 30, mPoints[i].Y() + 50, mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i++) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c3(mCarPoints, mCarColors);
    mCarContainer.push_back(c3);
    mCarPoints.clear();
    mCarColors.clear();
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X() - 30, mPoints[i].Y(), mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i++) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c4(mCarPoints, mCarColors);
    mCarContainer.push_back(c4);
    mCarPoints.clear();
    mCarColors.clear();
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X(), mPoints[i].Y(), mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i++) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c5(mCarPoints, mCarColors);
    mCarContainer.push_back(c5);
    mCarPoints.clear();
    mCarColors.clear();
    for (int i = 0; i < mPoints.size(); i++) {
        Point3D P(mPoints[i].X() + 30, mPoints[i].Y(), mPoints[i].Z());;
        mCarPoints.push_back(P);

    }
    for (int i = 0; i < mObjColors.size(); i += 3) {
        mCarColors.push_back(mObjColors[i]);

    }
    Car c6(mCarPoints, mCarColors);
    mCarContainer.push_back(c6);
    mCarPoints.clear();
    mCarColors.clear();
    addVerticesColor();
    mObjVertices.clear();
    mObjColors.clear();
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);


}
void TrafficJam::readOBJ() {
    
    std::string filePath = "D:\\Shweta_Workplace\\TrafficJam\\11497_Car_v2.obj";
    std::ifstream dataFile;
    dataFile.open(filePath);
    if (!dataFile.is_open()) {
        std::cout << "File not exit" << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(dataFile, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            mObjVertices.push_back(x * 0.1);
            mObjVertices.push_back(y * 0.1);
            mObjVertices.push_back(z * 0.1);
            Point3D p(x*0.1, y*0.1, z*0.1 );
            mPoints.push_back(p);
            mObjColors.push_back(1.0);
            mObjColors.push_back(1.0);
            mObjColors.push_back(0.0);
        
        }  
    }
    
}
void TrafficJam::LeftMove() {
    Transformations tf;
    translatedPoints=tf.translate_X_Left(mCarContainer[car_no].getVertices());
    mCarContainer[car_no].setVertices(translatedPoints);
    mVertices.clear();
    addVertices();
    mRenderer->setVectorOfLines(mVertices);
   
}
void TrafficJam::RightMove() {
    Transformations tf;
    translatedPoints = tf.translate_X_Right(mCarContainer[car_no].getVertices());
    mCarContainer[car_no].setVertices(translatedPoints);
    mVertices.clear();
    addVertices();
    mRenderer->setVectorOfLines(mVertices);

}
void TrafficJam::UpperMove() {
    Transformations tf;
    translatedPoints = tf.translate_Y_UP(mCarContainer[car_no].getVertices());
    mCarContainer[car_no].setVertices(translatedPoints);
    mVertices.clear();
    addVertices();
    mRenderer->setVectorOfLines(mVertices);
}
void TrafficJam::DownMove() {
    Transformations tf;
    translatedPoints = tf.translate_X_Down(mCarContainer[car_no].getVertices());
    mCarContainer[car_no].setVertices(translatedPoints);
    mVertices.clear();
    addVertices();
    mRenderer->setVectorOfLines(mVertices);
}
void TrafficJam::stop() {
    mVertices.clear();
    mColors.clear();
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);
}
void TrafficJam::selectCar() {
    QPoint pos = car_button->mapToGlobal(QPoint(0, car_button->height()));

    connect(car1_, &QAction::triggered, this, [=]() {
        car_no = 0;

        });
    connect(car2_, &QAction::triggered, this, [=]() {
        car_no = 1;
        });

    connect(car3_, &QAction::triggered, this, [=]() {
        car_no = 2;
        });
    connect(car4_, &QAction::triggered, this, [=]() {
        car_no = 3;
        });
    connect(car5_, &QAction::triggered, this, [=]() {
        car_no = 4;
        });
    connect(car6_, &QAction::triggered, this, [=]() {
        car_no = 5;
        });


    dropdownMenu->exec(pos);


}
void TrafficJam::addVertices() {
    for (int i = 0; i < mCarContainer.size(); i++) {
        std::vector<Point3D> carVertices = mCarContainer[i].getVertices();
        std::vector<float> carColors = mCarContainer[i].getColors();
        for (int j = 0; j < carVertices.size(); j++) {
            mVertices << carVertices[j].X() << carVertices[j].Y() << carVertices[j].Z();
        }
    }
}

void TrafficJam::addVerticesColor() {
    for (int i = 0; i < mCarContainer.size(); i++) {
        std::vector<Point3D> carVertices = mCarContainer[i].getVertices();
        std::vector<float> carColors = mCarContainer[i].getColors();
        for (int j = 0; j < carVertices.size(); j++) {
            mVertices << carVertices[j].X() << carVertices[j].Y() << carVertices[j].Z();
        }
        for (float color : carColors) {
            mColors << color;
        }
    }
}
