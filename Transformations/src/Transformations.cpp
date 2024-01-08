// Transformations.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Transformations.h"

Transformations::Transformations()
{
    
}
Transformations::~Transformations() {

}
void Transformations::translate_X(std::vector<Point3D>& inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 10);
    }
    
}
std::vector<Point3D> Transformations::translate_X_Left(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 10);
    }
    return inVertices;
}
std::vector<Point3D>  Transformations::translate_X_Right(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() + 10);
    }
    return inVertices;

}
std::vector<Point3D>  Transformations::translate_Y_UP(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() + 10);
    }
    return inVertices;

}
std::vector<Point3D>  Transformations::translate_X_Down(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() - 10);
    }
    return inVertices;

}