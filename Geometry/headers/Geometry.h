// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GEOMETRY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GEOMETRY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include "pch.h"
// This class is exported from the dll
class GEOMETRY_API Geometry {
public:
	Geometry();
	~Geometry();
};

