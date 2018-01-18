
#include <unistd.h>
#include <sys/types.h>

#include "CThread.h"
//#include "CContainer.h"

#include "CControl_BB.h"
//#include "CComm_BB.h"


//CContainer myCcontainer;

int main()
{
	CControl_BB ZRRegeler;
	CThread CT_ZRRegeler (&ZRRegeler, CThread::PRIORITY_NORM);


	CT_ZRRegeler.start();

	CT_ZRRegeler.join();

	return 0;
}
