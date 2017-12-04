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
	
	A* a = A::get();
	A* d = D::get();
	A* c = C::get();
	
	NTon::set_N(5);
	
	A* b = B::get();
	A* e = E::get();
	
	b->del();cout<<'\n';
	e->del();cout<<'\n';
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

