#include "NTon.h"

int NTon::N = 0;
int NTon::curr_num_of_objects = 0;
vector<NTon*> NTon::vec_obj;

void NTon::set_N(int n)
{
	N = n;
}
int NTon::get_curr_num_of_objects()
{
	return curr_num_of_objects;
}	

void NTon::disp()
{
	cout<<"\n\n_________________________________________________\n";
	cout<<"N : "<<N<<'\n';
	cout<<"Current Number of Objects : "<<curr_num_of_objects<<'\n';
	cout<<"Remaining Number of Objects : " << N - curr_num_of_objects <<'\n';
	cout<<"_________________________________________________\n\n\n";
}

NTon::NTon() {	} //ensures its not instantiable in any of the derived classes and in the client
