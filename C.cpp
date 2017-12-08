#include "C.h"

int C::count = 0;
		
void C::decr_count()
{
	count--;
}

void C::decr_curr_num_of_objects()
{
	curr_num_of_objects--;
}

void C::set_priority(int p)
{
	priority = p;
	vec_obj.push(this);
}

int C::get_priority()
{
	return priority;
}

C* C::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;	
		C* o = new C();	
		//vec_obj.push(o);		
		return (o);
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}
void C::print()
{
	cout<<"C\n";
}

void C::del()
{
	
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(dynamic_cast<C*>(this));
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}

int C::get_count()
{
	return count;
}
/*
void C::del()
{		
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<C*>(*it)) == this);
    	delete( dynamic_cast<C*>(*it) );
    	vec_obj.erase(it);
    	count--;
		curr_num_of_objects--;   	
    }
}
*/

C::~C()
{
	cout<<"C dtor\n";
}

void C::operator delete( void * ){}

C::C(){}
