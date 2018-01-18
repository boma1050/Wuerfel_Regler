/**
 * @author	Michael Meindl
 * @date	5.12.2016
 * @brief	Structure to hold the relevant MPU-Values
 */
#ifndef SMPU6050DATA_BB_H
#define SMPU6050DATA_BB_H
#include "Global.h"

struct SMPU6050Data_BB
{
public:
	double mX__dd;		//! Sensor  X-Acceleration []
	double mY__dd;		//! Sensor  Y-Acceleration []
	double mPhi__d;		//! Sensor  Z-Angular Velocity []
	double mPadding;
};

#endif
