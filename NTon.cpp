#include "NTon.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"
#include "E.h"

int NTon::N = 0;
int NTon::curr_num_of_objects = 0;
vector<NTon*> NTon::vec_obj;

void NTon::exit_handler()
{
	if(vec_obj.size() != 0)
	{
		for (vector<NTon*>::reverse_iterator i = vec_obj.rbegin(); i != vec_obj.rend(); ++i ) 
		{ 
			cout<<"\n\n";
			(*i)->del();
		} 
	}
}

void NTon::set_N(int n)
{
	N = n;
	atexit(exit_handler);
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
