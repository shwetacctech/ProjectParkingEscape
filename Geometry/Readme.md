# Point3D Class - Geometry Entity

The `Point3D` class represents a 3D point entity within a geometric system. It encapsulates the coordinates (X, Y, Z) of a point in space.

## Overview

The `Point3D` class provides functionalities to manage and retrieve the coordinates of a 3D point.

- **Constructors**: Initializes a Point3D object with default or specified coordinates.
- **Getter methods**: Accesses individual X, Y, and Z coordinates.
- **Setter methods**: Sets individual X, Y, and Z coordinates.

This class is useful for storing and manipulating points in 3D space for various geometric calculations or applications.

## Usage

### Initializing a Point3D

To create a `Point3D` instance:

1. Instantiate a `Point3D` object using either the default constructor or by specifying X, Y, and Z coordinates.

    ```cpp
    #include "Point3D.h"

    int main() {
        // Default constructor creates a point at the origin (0, 0, 0)
        Point3D defaultPoint;

        // Create a point with specific coordinates
        Point3D customPoint(1.0, 2.5, -3.7);
        // ...
        return 0;
    }
    ```

### Accessing Point Coordinates

You can retrieve and modify individual X, Y, and Z coordinates using the following methods:

- `X()`, `Y()`, `Z()`: Retrieve the respective coordinate values.
- `setX()`, `setY()`, `setZ()`: Modify the respective coordinate values.

    ```cpp
    // Example usage of getting and setting coordinates
    Point3D myPoint(2.0, 3.0, 4.0);

    double xCoord = myPoint.X();
    double yCoord = myPoint.Y();
    double zCoord = myPoint.Z();

    myPoint.setX(5.0);
    myPoint.setY(6.0);
    myPoint.setZ(7.0);
    ```
