# Car Class

The Car class is designed to represent a basic car entity within a software system. It stores information about the vertices defining the car's shape and the associated colors.

## Overview

The `Car` class encapsulates the following attributes and functionalities:

- **Vertices**: Represents the points in 3D space that define the car's shape.
- **Colors**: Stores the color information associated with the car.

## Usage

### Initializing a Car

To create a `Car` instance, follow these steps:

1. Instantiate a `Car` object by providing vectors of vertices and colors.

    ```cpp
    #include "Car.h"
    #include <vector>
    #include "Point3D.h"

    int main() {
        // Define vertices and colors
        std::vector<Point3D> carVertices = /* Define vertices */;
        std::vector<float> carColors = /* Define colors */;

        // Create a car instance
        Car myCar(carVertices, carColors);
        // ...
        return 0;
    }
    ```

### Accessing Car Data

You can retrieve the stored vertices and colors using the following methods:

- `getVertices()`: Returns the vector of 3D points defining the car's shape.
- `getColors()`: Returns the vector of colors associated with the car.

    ```cpp
    // Example usage of getting vertices and colors
    std::vector<Point3D> vertices = myCar.getVertices();
    std::vector<float> colors = myCar.getColors();
    ```
