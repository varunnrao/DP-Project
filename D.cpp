#include "D.h"

int D::count = 0;

D* D::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		//return new D();
		vec_obj.push_back(new D());		
		return (D*)vec_obj.back();
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
	if (B::get_count() == 0)
	{
		count--;
		curr_num_of_objects--;
		//disp();
		auto e = remove(vec_obj.begin(), vec_obj.end(), this);
		delete((D*)(*e));
		vec_obj.erase(e,vec_obj.end());
		//delete(this);
	}
	else
	{
		throw std::runtime_error("Cannot delete objects of D while objects of B exist");
	}
}
D::~D()
{
	cout<<"D dtor\n";
}

void D::operator delete( void * ) {}

D::D(){}
