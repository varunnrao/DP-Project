#include "E.h"

int E::count = 0;

void E::decr_count()
{
	count--;
}

void E::decr_curr_num_of_objects()
{
	curr_num_of_objects--;
}

void E::set_priority(int p)
{
	priority = p;
	vec_obj.push(this);
}

int E::get_priority()
{
	return priority;
}

E* E::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;	
		E* o = new E();
		//vec_obj.push(o);		
		return (o);
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}
void E::print()
{
	cout<<"E\n";
}

void E::del()
{
	
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(dynamic_cast<E*>(this));
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}

int E::get_count()
{
	return count;
}
/*
void E::del()
{	
	

	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
	{		
		assert((dynamic_cast<E*>(*it)) == this);
		delete( dynamic_cast<E*>(*it) );			
		vec_obj.erase(it); 		
		count--;
		curr_num_of_objects--;			
	}	
}
*/

E::~E()
{
	cout<<"E dtor\n";
}

void E::operator delete( void * ) {}

E::E(){}
