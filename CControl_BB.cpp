/*
 * CControl_BB.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#include <unistd.h>
#include "CControl_BB.h"
#include <math.h>       // für atan
#include <iostream>

using namespace std;

//extern CContainer myCcontainer; //Objekt myContainer nicht neuanlegen, ist bereits angelegt

//CMPU6050::CMPU6050(UInt8 deviceNr) : mAccelXFd(-1),mbccelXFd(-1)
CControl_BB::CControl_BB() : 	alpha				(2.295081967),
								m_xy				(57.628656436980230),
								b_xy				(-0.183538290532259),
								alpha_phi_c			(0.98),
								LSB_Gyro			(1/16.0),
								T					(0.02),

							//	k1					(2.2583),
							//	k2					(0.1462),
							//	k3					(0.0007),
							//Orginal werte:
								k1					(-1.46473588630499),
								k2					(-0.108561236227978),
								k3					(-0.000409062842021413),
							//Orginalwerte / 2:
								//k1					(-0.903068815306001),
							//	k2 					(-0.0779794229293012),
							//	k3					(-0.000218811757064748),

								// extern PC
								//k1					(-1.5563),
								//k2					(-0.2696),
								//k3					(-0.00053255),
							//	k3					(-1.684922229099208e-04),
								m_dre				(950),
								b_dre				(2026)
{
	adcValue	= -1;
	phi		= -1;
	phi_xy = 0;
	//phi_c		= 0.785398; //45 grad
	//phi_c		= 0;
	tm 			= 0;
	phi_xy_roh	= 0;
	psi__d		= 0;
	phi__d		= 0;
	phi__d_g_1	= 0;
	phi__d_g_2	= 0;


}

void CControl_BB::init() 		//Definition von init
{
	meine_Hardware.enableMotor();
	meine_Hardware.openBrake();
}

void CControl_BB::run() 		//Definition von run
{
	while(true)
	{
		this->readValue();
		this->FBC();
		this->getInfo();
		usleep(20000);
	}
}

void CControl_BB::readValue(){
	meine_Hardware.fetchValues(adcValue, Sensordaten1, Sensordaten2);

	phi			= this->getPhi();
	phi__d		= this->getPhi__d();
	psi__d		= this->getPsi__d();
}

void CControl_BB::FBC() 		//Feedback Controller
{
	tm = (k1 * (phi-0.07) + k2 * phi__d + k3 * psi__d * 1.0);
	tm = phi >= -0.3 && phi <= 0.3 ? tm : 0;

 	meine_Hardware.setTorque(tm);
}

double CControl_BB::getPhi()   // Phi in RAD
{
	phi_xy_roh		= atan2( Sensordaten1.mX__dd - (double)(alpha * (double)Sensordaten2.mX__dd), -1.0*(Sensordaten1.mY__dd - (double)(alpha * (double)Sensordaten2.mY__dd)) );
	phi_xy	= phi_xy_roh;//this->grad_in_rad(m_xy * phi_xy_roh + b_xy);

	return (alpha_phi_c * (phi + T * phi__d) + (1 - alpha_phi_c) * phi_xy); //in RAD
}

double CControl_BB::getPhi__d()   // Winkelgeschwindigkeit in RAD/sek
{
	phi__d_g_1 =  LSB_Gyro * (Sensordaten1.mPhi__d );
 	phi__d_g_2 =  LSB_Gyro * (Sensordaten2.mPhi__d );

	return -(this->grad_in_rad((phi__d_g_1 + phi__d_g_2) / 2));
}


double CControl_BB::getPsi__d(){  // Drehzahl in Rad/sek
	return ((adcValue-b_dre)*5.0)*2*3.14/60.0;
}

double CControl_BB::grad_in_rad(double winkel_grad)//Winkel von Grad in Rad berechnen
{
	return (winkel_grad * 3.14159265359 / 180);
}


void CControl_BB::getInfo()
{
	cout << "phi(g):" << phi*180/3.14159265359;// << endl;
	//cout << "Phi(RAD): "<< this->getPhi() << endl;
	//cout << "Phi__d(G): "<< this->getPhi__d()*180/3.14159265359 << endl;
	cout << "  Drehzahl: "<< psi__d;// << endl;
	cout << "  r_out,tm: "<< tm;// << endl;
	//cout << "phi_xy(g): "<< this->phi_xy*180/3.14159265359  << endl;
	//cout << "phi_xy_roh: "<< this->phi_xy_roh  << endl;
	//cout << "Sensordaten1.mPhi__d "<< this->Sensordaten1.mPhi__d << endl;
	//cout << "Sensordaten2.mPhi__d "<< this->Sensordaten2.mPhi__d << endl;
	cout << "  phi__d "<< phi__d << endl;

	//usleep(200000);
}
