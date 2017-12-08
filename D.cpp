#include "D.h"

int D::count = 0;

void D::decr_count()
{
	count--;
}

void D::decr_curr_num_of_objects()
{
	curr_num_of_objects--;
}

void D::set_priority(int p)
{
	priority = p;
	vec_obj.push(this);
}

int D::get_priority()
{
	return priority;
}

D* D::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		D* o = new D();		
		//vec_obj.push(o);		
		return (o);
	}
	else
	{		
		throw std::runtime_error("too many objects");
	}
}

void D::print()
{
	cout<<"D\n";
}

void D::del()
{
	
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(dynamic_cast<D*>(this));
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}

int D::get_count()
{
	return count;
}

/*
void D::del()
{
	if ( B::get_count() == 0 )
	{		
		auto it = find(vec_obj.begin(), vec_obj.end(), this);
		if(it != vec_obj.end())
		{
			assert((dynamic_cast<D*>(*it)) == this);
			delete( dynamic_cast<D*>(*it) );
			vec_obj.erase(it);
			count--;
			curr_num_of_objects--; 			
		}
	}
	else
	{
		throw std::runtime_error("Cannot delete objects of D while objects of B exist");
	}
}
*/
D::~D()
{
	cout<<"D dtor\n";
}

void D::operator delete( void * ) {}

D::D(){}
