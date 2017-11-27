#include "B.h"

int B::count = 0;
		
B* B::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		//return new B();
		vec_obj.push_back(new B());		
		return (B*)vec_obj.back();
	}
	else
	{
		//disp();
		throw std::runtime_error("too many objects");
	}
}

int B::get_count()
{
	return count;
}

void B::del()
{
	count--;
	curr_num_of_objects--;
	//disp();
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert(((B*)(*it)) == this);
    	delete( (B*)(*it) );
    	vec_obj.erase(it);
    	
    	    	 
    	
    }
/*	
	auto e = remove(vec_obj.begin(), vec_obj.end(), this);
	//delete((B*)(*e));
	assert(((B*)(*e)) == this); 
	delete(this);
	vec_obj.erase(e,vec_obj.end());
	//delete(this);
*/
}
B::~B()
{			
	cout<<"B dtor\n";
}

void B::operator delete( void * ) {}
B::B(){}
