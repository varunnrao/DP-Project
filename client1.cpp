#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"


int main()
{
	//Creation of objects and deletion - Standard functionality
	NTon::set_N(4);
		
	{
		
		A* a = A::get();a->set_priority(1);
		D* d = D::get();d->set_priority(2);
		B* b = B::get();b->set_priority(3);
		C* c = C::get();c->set_priority(4);
		
		
		
		NTon::disp();
		
		try
		{
			A* e = E::get();e->set_priority(5);
		}
		catch(const exception& e) 
		{ // caught by reference to base
        	cout << "Exception : "
            	 << e.what() << "\n";
    	}	
    	
    	NTon::disp();
		
		a->del();cout<<'\n';
		d->del();cout<<'\n';
		b->del();cout<<'\n';
		c->del();cout<<'\n';
		
		NTon::disp();

	}

}
