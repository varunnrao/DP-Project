#include "A.h"

int A::count = 0;

A* A::get()
{	
	
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;		
		vec_obj.push_back(new A());				
		return dynamic_cast<A*>(vec_obj.back());
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

int A::get_count()
{
	return count;
}

void A::del()
{
	count--;
	curr_num_of_objects--;	
	
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<A*>(*it)) == this);
    	delete( dynamic_cast<A*>(*it) );
    	vec_obj.erase(it);     	
    }	
}

A::~A()
{			
	cout<<"A dtor\n";
}

void A::operator delete( void * ) {}

A::A() {}

