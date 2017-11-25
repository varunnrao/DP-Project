#include "A.h"

int A::count = 0;

A* A::get()
{	
	
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		return new A();
	}
	else
	{
		//disp();
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
	//disp();
	delete(this);
}

A::~A()
{			
	cout<<"A dtor\n";
}

void A::operator delete( void * ) {}
A::A() {}

