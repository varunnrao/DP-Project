#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


int main()
{
	//Illustration of longevity/dependency
	// you can delete objects of D only after all objects of B are deleted
	
	NTon::set_N(4);
	
	{
	
		vector<A*> v { A::get(), D::get(), C::get(), B::get()};
	
	
		cout<<"Number of Object : "<<NTon::get_curr_num_of_objects()<<'\n';
		try
		{
			for_each(begin(v), end(v), [](A* e)
			{
				e->del();
				cout<<"\n\n";
			});
		}
		catch(const exception& e) 
		{ // caught by reference to base
        	cout << "Exception : "
            	 << e.what() << "\n";
    	}
    	
    	//dtor called by exit handler automatically 
    	//in reverse order of creation after process termination
    	//A dtor has already been called
    	//Order of dtor invocation: B dtor, C dtor, D dtor	
    	//These are the objects that haven't been freed as yet.
		
	}
}
