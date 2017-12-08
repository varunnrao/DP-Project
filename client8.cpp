#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"


//multiple deleted on already deleted object

int main()
{
	
	NTon::set_N(1);
	A* e = E::get();e->set_priority(5);
	
	NTon::disp();
	e->del();
	NTon::disp();
	e->del();
	NTon::disp();
	
	
}
