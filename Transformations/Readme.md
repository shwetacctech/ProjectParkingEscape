# Transformations Class

The Transformations class is part of a library that provides functionality for translating 3D vertices along different axes. This library is exported from a DLL and includes methods for translating vertices in various directions.

## Methods

### `translate_X_Left`
```cpp
std::vector<Point3D> translate_X_Left(std::vector<Point3D> inVertices);
```
### `translate_X_Right`
std::vector<Point3D> translate_X_Right(std::vector<Point3D> inVertices);
```
### `translate_Y_UP`
cpp
```
std::vector<Point3D> translate_Y_UP(std::vector<Point3D> inVertices);
Translates the input vertices upward along the Y-axis.
```
### `translate_X_Down`
cpp
```
std::vector<Point3D> translate_X_Down(std::vector<Point3D> inVertices);
Translates the input vertices downward along the Y-axis.
```
Usage
To use this library for transforming 3D vertices, follow these steps:

Include the necessary header files.
Create an instance of the Transformations class.
Call the desired translation methods, passing in the vertices to be transformed.
Example usage:

cpp
```
#include "Transformations.h"

// Create an instance of Transformations
Transformations transformer;

// Define a vector of 3D points (inVertices) to be transformed

// Translate vertices to the left along the X-axis
std::vector<Point3D> translatedVertices = transformer.translate_X_Left(inVertices);
```
