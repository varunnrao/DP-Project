#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"

//multiple set_N calls

int main()
{
	NTon::set_N(3);
	
	A* a = A::get();a->set_priority(1);
	A* d = D::get();d->set_priority(2);
	A* c = C::get();c->set_priority(3);
	
	NTon::set_N(5);
	
	A* b = B::get();b->set_priority(4);
	A* e = E::get();e->set_priority(5);
	
	a->del();cout<<'\n';
	d->del();cout<<'\n';
	NTon::set_N(3);//succeeds!
	
	try
	{
		NTon::set_N(2);//fails!
	}
	catch(const exception& e)
	{
		cout<<"Exception: "<<e.what()<<'\n';
	}	
}

