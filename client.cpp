#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	NTon::set_N(4);
	
	
	
	A* a1 = A::get_A();
	A* a2 = A::get_A();
	
	
	a2->del();
	
	a2 = A::get_A();
	
	a2->del();
	
	A* a3 = B::get_B();
	a3->del();
	
	a1->del();
	
	cout<<NTon::get_curr_num_of_objects()<<'\n';
	
	vector<A*> v { A::get_A(), B::get_B(), C::get_C(), D::get_D()};
	
	
	cout<<NTon::get_curr_num_of_objects()<<'\n';
	
	for_each(begin(v), end(v), [](A* e)
	{
		e->del();
		cout<<"\n\n";
	});	

}
