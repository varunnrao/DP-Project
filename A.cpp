#include "A.h"

int A::count = 0;

void A::decr_count()
{
	count--;
}


void A::print()
{
	cout<<"A\n";
}
void A::decr_curr_num_of_objects()
{
	curr_num_of_objects--;
}

void A::set_priority(int p)
{
	priority = p;
	vec_obj.push(this);
}

int A::get_priority()
{
	return priority;
}

A* A::get()
{	
	
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;	
		A* o = new A();	
		//vec_obj.push(o);				
		return (o);
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

void A::del()
{
	
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(dynamic_cast<A*>(this));
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}

int A::get_count()
{
	return count;
}

/*void A::del()
{	
	
	if(this == vec_obj.top())
	{
		count--;
		curr_num_of_objects--;
		vec_obj.pop();
		delete(this);
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
	//auto it = find(vec_obj.begin(), vec_obj.end(), this);
	if(it != vec_obj.end())
    {
    	assert((dynamic_cast<A*>(*it)) == this);
    	delete( dynamic_cast<A*>(*it) );
    	vec_obj.erase(it); 
    	    	
    }	

}
*/
A::~A()
{			
	cout<<"A dtor\n";
}

void A::operator delete( void * ) {}

A::A() {}

