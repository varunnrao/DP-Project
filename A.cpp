#include "A.h"

int A::count = 0;

A* A::get()
{	
	
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		//A* a = new A();
		vec_obj.push_back(new A());	
			
		return (A*)vec_obj.back();
	}
	else
	{
		//disp();
		throw std::runtime_error("too many objects");
	}
}



int A::get_count()
{
	return count;
}

void A::del()
{
	count--;
	curr_num_of_objects--;	
	auto e = remove(vec_obj.begin(), vec_obj.end(), this);
	delete((A*)(*e));
	vec_obj.erase(e,vec_obj.end());	
	//disp();
	//delete(this);
}

A::~A()
{			
	cout<<"A dtor\n";
}

void A::operator delete( void * ) {}
A::A() {}

