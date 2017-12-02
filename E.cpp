#include "E.h"

int E::count = 0;

E* E::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;		
		vec_obj.push_back(new E());		
		return dynamic_cast<E*>(vec_obj.back());
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

int E::get_count()
{
	return count;
}

void E::del()
{
	count--;
	curr_num_of_objects--;
	
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
	{
		assert((dynamic_cast<E*>(*it)) == this);
		delete( dynamic_cast<E*>(*it) );
		vec_obj.erase(it); 			
	}
}

E::~E()
{
	cout<<"E dtor\n";
}

void E::operator delete( void * ) {}

E::E(){}
