#include "C.h"

int C::count_C = 0;
		
C* C::get_C()
{
	if(curr_num_of_objects < N)
	{
		count_C++;
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

int C::get_count_C()
{
	return count_C;
}

void C::del()
{
	count_C--;
	curr_num_of_objects--;
	//disp();
	delete(this);
}

C::~C()
{
	cout<<"C dtor\n";
}

void C::operator delete( void * ){}


