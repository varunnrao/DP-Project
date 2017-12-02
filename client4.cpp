#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Illustration of longevity/dependency
	
	NTon::set_N(4);
	
	{
	
		vector<A*> v { A::get(), D::get(), C::get(), B::get()};
	
	
		cout<<"Number of Object : "<<NTon::get_curr_num_of_objects()<<'\n';

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
}