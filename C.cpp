#include "C.h"

int C::count = 0;
		
C* C::get()
{
	if(curr_num_of_objects < N)
	{
		count++;
		curr_num_of_objects++;
		//disp();
		//return new C();
		vec_obj.push_back(new C());		
		return (C*)vec_obj.back();
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
	
	auto e = remove(vec_obj.begin(), vec_obj.end(), this);
	delete((C*)(*e));
	vec_obj.erase(e,vec_obj.end());
	//delete(this);
}

C::~C()
{
	cout<<"C dtor\n";
}

void C::operator delete( void * ){}

C::C(){}
