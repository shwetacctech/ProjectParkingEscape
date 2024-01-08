// Car.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Car.h"

Car::Car(std::vector<Point3D> inVertices,std::vector<float> inColor):
mVertices(inVertices),
mColor(inColor)
{

}
Car::~Car() {

}
std::vector<Point3D> Car::getVertices() {
	return mVertices;
}
std::vector<float> Car::getColors() {
	return mColor;
}
void Car::setVertices(std::vector<Point3D> newVertices) {
	mVertices = newVertices;
}

void Car::setColor(std::vector<float> newColor) {
	mColor = newColor;
}