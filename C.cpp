#include "C.h"

int C::count = 0;
		
C* C::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		return new C();
	}
	else
	{
		//disp();
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
	//disp();
	delete(this);
}

C::~C()
{
	cout<<"C dtor\n";
}

void C::operator delete( void * ){}


