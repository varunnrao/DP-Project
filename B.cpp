#include "B.h"

int B::count = 0;
		
B* B::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;		
		vec_obj.push_back(new B());		
		return dynamic_cast<B*>(vec_obj.back());
	}
	else
	{		
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
	
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<B*>(*it)) == this);
    	delete( dynamic_cast<B*>(*it) );
    	vec_obj.erase(it);    	
    }
}

B::~B()
{			
	cout<<"B dtor\n";
}

void B::operator delete( void * ) {}
B::B(){}
