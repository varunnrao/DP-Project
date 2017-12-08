#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Creation and Deletion using vectors
	
	NTon::set_N(4);
	
	{
	
		vector<A*> v { A::get(), B::get(), C::get(), D::get()};
		v[0]->set_priority(1);
		(dynamic_cast<B*>(v[1]))->set_priority(2);
		(dynamic_cast<C*>(v[2]))->set_priority(3);
		(dynamic_cast<D*>(v[3]))->set_priority(4);
	
	
		NTon::disp();

		for_each(begin(v), end(v), [](A* e)
		{
			e->del();
			cout<<"\n\n";
		});	
	
		B* b1 = B::get();b1->set_priority(5);
		D* d1 = D::get();d1->set_priority(10);
		
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	
		b1->del();
		d1->del();
	
		cout<<NTon::get_curr_num_of_objects()<<'\n';
	}
}
