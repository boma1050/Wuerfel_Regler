/*
 * CComm.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */
#include "CComm_BB.h"

//extern CContainer myCcontainer; //Objekt myContainer nicht neuanlegen, ist bereits angelegt

void CComm_BB::init()	//Definition von init
{
	pipe.init();
	pipe.waitForClient();
}

void CComm_BB::run() 	//Definition von run
{
			while (true){
				//myCcontainer.getContent(true, data);
				pipe.transmitMessage(data);
				//pipe.receiveMessage(data);
			};
}



