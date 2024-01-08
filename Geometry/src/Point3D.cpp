#include "pch.h"
#include "Point3D.h"
#include "pch.h"
#include "Point3D.h"
#include <iostream>

// Constructors
Point3D::Point3D() : mX(0.0), mY(0.0), mZ(0.0) {}

Point3D::Point3D(double inx_coord, double iny_coord, double inz_coord) : mX(inx_coord), mY(iny_coord), mZ(inz_coord) {}

// Getter methods
double Point3D::X() {
    return mX;
}

double Point3D::Y() {
    return mY;
}

double Point3D::Z() {
    return mZ;
}

// Setter methods
void Point3D::setX(double x_coord) {
    mX = x_coord;
}

void Point3D::setY(double y_coord) {
    mY = y_coord;
}

void Point3D::setZ(double z_coord) {
    mZ = z_coord;
}
