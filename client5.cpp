#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Illustration of deletion through exit handlers
	
	NTon::set_N(4);
	
	{	
		A* a1 = D::get(); A* a2 = C::get();	
		NTon::disp();
	}

}
