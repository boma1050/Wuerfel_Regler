/*
 * CComm.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CCOMM_BB_H_
#define CCOMM_BB_H_

#include "IRunnable.h"
#include "CContainer.h"
#include "SContent.h"
#include "CServer.h"
#include <unistd.h>


class CComm_BB : public IRunnable
{
public:
	 void init();
	 void run();		 //Starten der Funktion

//	CComm_BB();   //Konstruktor deklarieren


private:

	SContent data;
	CServer pipe;

};





#endif /* CCOMM_BB_H_ */
