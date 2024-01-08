#pragma once
#include "pch.h"
class GEOMETRY_API Point3D
{
    
public:
        // Constructors
        Point3D();
        Point3D(double inx_coord, double iny_coord, double inz_coord);

        // Getter methods
        double X() ;
        double Y() ;
        double Z() ;

        // Setter methods
        void setX(double x_coord);
        void setY(double y_coord);
        void setZ(double z_coord);
private:
    double mX;
    double mY;
    double mZ;

};


