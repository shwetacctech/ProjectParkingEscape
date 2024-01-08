// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CAR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CAR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <vector>
#include "pch.h"
#include <Point3D.h>
// This class is exported from the dll
class CAR_API Car {
public:
	Car(std::vector<Point3D> inVertices, std::vector<float> inColor);
	~Car();
public:
	std::vector<Point3D> getVertices();
	std::vector<float> getColors();
	void setVertices(std::vector<Point3D> newVertices );
	void setColor(std::vector<float> newColor);
private:
	std::vector<Point3D> mVertices;
	std::vector<float> mColor;
};
