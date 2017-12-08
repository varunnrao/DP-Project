#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"




int NTon::N = 0;
int NTon::curr_num_of_objects = 0;
priority_queue<NTon*, vector<NTon*>, cmp> NTon::vec_obj;
/*
void NTon::del()
{
	cout<<this<<'\n';
	cout<<vec_obj.top()<<'\n';
	//delete(vec_obj.top());
	cout<<vec_obj.size()<<'\n';
	if(this == vec_obj.top())
	{
		this->decr_count();//
		//this->count--;
		this->decr_curr_num_of_objects();//
		//this->curr_num_of_objects--;
		vec_obj.pop();
		delete(this);
	}
	else
	{
		throw runtime_error("Invalid priority");
	}
}
*/

void NTon::exit_handler()
{
	while(vec_obj.size() != 0)
	{
		/*for (vector<NTon*>::reverse_iterator i = vec_obj.rbegin(); i != vec_obj.rend(); ++i ) 
		{ 
			cout<<"\n\n";
			(*i)->del();
		} 
		*/
		vec_obj.top()->del();
		cout<<'\n';
		//vec_obj.pop();
	}
}

void NTon::set_N(int n)
{
	if(N == 0 || n>N || ( get_curr_num_of_objects() < N && n < N) )
	{
		//when set_N is called once or more than once, it succeeds only if
		// 1. set_N has never been called before OR
		// 2. the new value provided to N greater than the earlier value
		// 3. the new value provided to N is lesser than old value, but client hasn't created N objects as yet, i.e new value of N must < curr_num_of_objects and n< N
		N = n;
		atexit(exit_handler);
	}
	else
	{
		//set_N is called more than once and the new value of N is less than the objects that currently exist.
		//hence client must first free them and then provide a new value of N
		int num_of_objects = get_curr_num_of_objects();
		int num_of_objects_to_delete = num_of_objects - n;
		throw std::runtime_error(to_string(num_of_objects) + " objects exist! Delete atleast " + to_string(num_of_objects_to_delete));
	}
}
int NTon::get_curr_num_of_objects()
{
	return curr_num_of_objects;
}	

void NTon::disp()
{
	cout<<"\n\n__________________________________________\n";
	cout<<"N \t\t\t\t: \t"<<N<<'\n';
	cout<<"Current Number of Objects \t: \t"<<get_curr_num_of_objects()<<'\n';
	cout<<"Number of A object(s)     \t: \t"<<A::get_count()<<'\n';
	cout<<"Number of B object(s)     \t: \t"<<B::get_count()<<'\n';
	cout<<"Number of C object(s)     \t: \t"<<C::get_count()<<'\n';
	cout<<"Number of D object(s)     \t: \t"<<D::get_count()<<'\n';
	cout<<"Number of E object(s)     \t: \t"<<E::get_count()<<'\n';
	cout<<"Remaining Number of Objects \t: \t" << N - curr_num_of_objects <<'\n';
	cout<<"__________________________________________\n\n\n";
}

NTon::NTon() {	} //ensures its not instantiable in any of the derived classes and in the client

bool cmp::operator()(NTon* lhs, NTon* rhs)
{
	return lhs->get_priority() > rhs->get_priority();
}

