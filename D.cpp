#include "D.h"

int D::count = 0;

D* D::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		return new D();
	}
	else
	{
		//disp();
		throw std::runtime_error("too many objects");
	}
}
int D::get_count()
{
	return count;
}
void D::del()
{
	count--;
	curr_num_of_objects--;
	//disp();
	delete(this);
}
D::~D()
{
	cout<<"D dtor\n";
}

void D::operator delete( void * ) {}
