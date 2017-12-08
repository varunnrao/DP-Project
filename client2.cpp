#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Display of Liskov's Principle
	
	NTon::set_N(4);
		
	{	
	
		A* a1 = A::get();a1->set_priority(1);
	
		a1->del();
		A* a2 = A::get();a2->set_priority(1);
	
	
		a2->del();
	
		a2 = A::get();a2->set_priority(1);
		
		NTon::disp();
	
		a2->del();
	
		A* a3 = B::get();a3->set_priority(1);
		a3->del();
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';

	}
	
}
