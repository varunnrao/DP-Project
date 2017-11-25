#include "B.h"

int B::count_B = 0;
		
B* B::get_B()
{
	if(curr_num_of_objects < N)
	{
		count_B++;
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

int B::get_count_B()
{
	return count_B;
}

void B::del()
{
	count_B--;
	curr_num_of_objects--;
	//disp();
	delete(this);
}
B::~B()
{			
	cout<<"B dtor\n";
}

void B::operator delete( void * ) {}
