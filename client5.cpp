#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"


int main()
{
	//Illustration of deletion through exit handlers
	
	NTon::set_N(5);
	
	{	
		A* a1 = D::get(); a1->set_priority(10);
		A* a2 = C::get(); a2->set_priority(5);
		A* a3 = E::get(); a3->set_priority(20);
		A* a4 = A::get(); a4->set_priority(15);
		A* a5 = B::get(); a5->set_priority(30);
		NTon::disp();
	}

}
