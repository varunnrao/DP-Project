#include "B.h"

int B::count = 0;
		
B* B::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		return new B();
	}
	else
	{
		//disp();
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
	//disp();
	delete(this);
}
B::~B()
{			
	cout<<"B dtor\n";
}

void B::operator delete( void * ) {}
