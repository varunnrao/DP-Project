#include "D.h"

int D::count = 0;

D* D::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;		
		vec_obj.push_back(new D());		
		return dynamic_cast<D*>(vec_obj.back());
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}
int D::get_count()
{
	return count;
}
void D::del()
{
	if ( B::get_count() == 0 )
	{
		count--;
		curr_num_of_objects--;
		
		auto it = find(vec_obj.begin(), vec_obj.end(), this);
		if(it != vec_obj.end())
		{
			assert((dynamic_cast<D*>(*it)) == this);
			delete( dynamic_cast<D*>(*it) );
			vec_obj.erase(it); 			
		}
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
