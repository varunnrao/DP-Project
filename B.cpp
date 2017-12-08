#include "B.h"

int B::count = 0;
	
void B::decr_count()
{
	count--;
}	

void B::decr_curr_num_of_objects()
{
	curr_num_of_objects--;
}

void B::set_priority(int p)
{
	priority = p;
	vec_obj.push(this);
}

int B::get_priority()
{
	return priority;
}

B* B::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		B* o = new B();		
		//vec_obj.push(o);		
		return (o);
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

void B::print()
{
	cout<<"B\n";
}

void B::del()
{
	
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(dynamic_cast<B*>(this));
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}

int B::get_count()
{
	return count;
}
/*
void B::del()
{	
	auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<B*>(*it)) == this);
    	delete( dynamic_cast<B*>(*it) );
    	vec_obj.erase(it); 
    	count--;
		curr_num_of_objects--;   	
    }
}
*/

B::~B()
{			
	cout<<"B dtor\n";
}

void B::operator delete( void * ) {}
B::B(){}
