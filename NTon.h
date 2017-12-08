#ifndef NTON_H
#define NTON_H

#include <bits/stdc++.h>

using namespace std;

class NTon;
class cmp
{
	public:
		bool operator()(NTon* lhs, NTon* rhs);	
};


class NTon
{
	public:
		static void set_N(int n);
		static int get_curr_num_of_objects();
		static void disp();
		virtual void del() = 0;
		virtual void set_priority(int p) = 0;
		virtual int get_priority() = 0;
	protected: // ensures access in derived classes but not in client
		static int N;
		static int curr_num_of_objects;	
		
		//static vector<NTon*> vec_obj;
		
		static priority_queue<NTon*, vector<NTon*>, cmp> vec_obj;
		static void exit_handler();
		
		// this makes the class non-instantiable
		// ensures derived classes implement this method.
		NTon(); // ensures its not instantiable
	private:
		virtual void decr_count() = 0;
		virtual void decr_curr_num_of_objects() = 0;
		
};

#endif
