#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Creation of objects and deletion - Standard functionality
	NTon::set_N(4);
		
	{
		
		A* a = A::get();
		D* d = D::get();
		B* b = B::get();
		C* c = C::get();
		
		a->del();cout<<'\n';
		b->del();cout<<'\n';
		c->del();cout<<'\n';
		d->del();cout<<'\n';

	}

}
