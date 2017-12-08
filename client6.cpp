#include "NTon.h"

#include "E.h"


int main()
{
	//Illustration of N-Ton on multiple inheritance
	
	NTon::set_N(4);
	
	{	
		E* e1 = E::get();e1->set_priority(5);
		NTon::disp();
	}

}
