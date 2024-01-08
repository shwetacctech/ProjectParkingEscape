#pragma once
#include "pch.h"
#include <vector>
#include <Point3D.h>
// This class is exported from the dll
class TRANSFORMATIONS_API Transformations {
public:
	Transformations();
	~Transformations();
	void translate_X(std::vector<Point3D>& inVertices);
	std::vector<Point3D> translate_X_Left(std::vector<Point3D> inVertices);
	std::vector<Point3D>  translate_X_Right(std::vector<Point3D> inVertices);
	std::vector<Point3D>  translate_Y_UP(std::vector<Point3D> inVertices);
	std::vector<Point3D>  translate_X_Down(std::vector<Point3D> inVertices);

};

