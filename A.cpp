#include "A.h"

int A::count_A = 0;

A* A::get_A()
{	
	
	if(curr_num_of_objects < N)
	{
		count_A++;
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

int A::get_count_A()
{
	return count_A;
}

void A::del()
{
	count_A--;
	curr_num_of_objects--;
	//disp();
	delete(this);
}

A::~A()
{			
	cout<<"A dtor\n";
}

void A::operator delete( void * ) {}

