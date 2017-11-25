#include "D.h"

int D::count_D = 0;

D* D::get_D()
{
	if(curr_num_of_objects < N)
	{
		count_D++;
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
int D::get_count_D()
{
	return count_D;
}
void D::del()
{
	count_D--;
	curr_num_of_objects--;
	//disp();
	delete(this);
}
D::~D()
{
	cout<<"D dtor\n";
}

void D::operator delete( void * ) {}
