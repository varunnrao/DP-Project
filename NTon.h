#ifndef NTON_H
#define NTON_H

#include <bits/stdc++.h>

using namespace std;


class NTon
{
	public:
		static void set_N(int n);
		static int get_curr_num_of_objects();
	protected: // ensures access in derived classes but not in client
		static int N;
		static int curr_num_of_objects;	
		static void disp();
		static vector<NTon*> vec_obj;
		static void exit_handler();
		virtual void del() = 0;
		// this makes the class non-instantiable
		//ensures derived classes implement this method.
		NTon(); // ensures its not instantiable
};

#endif
