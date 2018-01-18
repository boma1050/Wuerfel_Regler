/*
 * CControl_BB.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CCONTROL_BB_H_
#define CCONTROL_BB_H_

#include "IRunnable.h"
//#include "CContainer.h"
#include "SMPU6050Data.h"
#include "SMPU6050Data_BB.h" //Eigenes Struct, da anstatt Int --> double benötigt werden
#include "CBBBHardware.h"

//const double alpha = 2.295081967; // alpha = rs1/rs2 bereits berechnet

class CControl_BB :public IRunnable
{
public:
	CControl_BB();   //Konstruktor deklarieren

	void run();		// run innerhalb von CControl_BB deklarieren
	void init(); 	// init innerhalb von CControl_BB deklarieren
	double getPhi() 	; //SensorToWinkel deklarieren
	void readValue();
	double getPsi__d();
	void FBC();
	void getInfo();
	double getPhi__d();
	double grad_in_rad(double winkel_grad);

private:

	SMPU6050Data	Sensordaten1;
	SMPU6050Data	Sensordaten2;
	CBBBHardware	meine_Hardware;
	//SContent		content;

	double			phi_xy_roh, phi_xy, phi__d_g_1, phi__d_g_2, phi__d,
					k1, k2, k3, phi, psi__d,
					m_dre, b_dre;
	const double	alpha, m_xy, b_xy, alpha_phi_c, LSB_Gyro, T;
	UInt16			adcValue;
	float 			tm;
};



#endif /* CCONTROL_BB_H_ */
