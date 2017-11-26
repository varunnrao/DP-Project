#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	NTon::set_N(4);
	
	{	
	
		A* a1 = A::get();
	
		a1->del();
		A* a2 = A::get();
	
	
		a2->del();
	
		a2 = A::get();
	
		a2->del();
	
		A* a3 = B::get();
		a3->del();
	
	
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	
		vector<A*> v { A::get(), B::get(), C::get(), D::get()};
	
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	
		for_each(begin(v), end(v), [](A* e)
		{
			e->del();
			cout<<"\n\n";
		});	
	
		B* b1 = B::get();
		D* d1 = D::get();
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	
		b1->del();
		d1->del();
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	}
	
	{
		cout<<"Testing out Exit Handlers - Longevity\n";	
	
		A* a1 = D::get(); A* a2 = C::get();	
	}
}
