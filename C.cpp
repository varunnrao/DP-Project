#include "C.h"

int C::count = 0;
		
C* C::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;		
		vec_obj.push_back(new C());		
		return dynamic_cast<C*>(vec_obj.back());
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

int C::get_count()
{
	return count;
}

void C::del()
{
	count--;
	curr_num_of_objects--;	
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<C*>(*it)) == this);
    	delete( dynamic_cast<C*>(*it) );
    	vec_obj.erase(it);   	
    }
}

C::~C()
{
	cout<<"C dtor\n";
}

void C::operator delete( void * ){}

C::C(){}
