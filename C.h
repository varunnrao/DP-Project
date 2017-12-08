#ifndef C_H
#define C_H

#include "A.h"

class C: virtual public A
{
	public:		
		static C* get();
		static int get_count();
		virtual void del();
		int priority;
		virtual ~C();
		virtual void set_priority(int p);
		virtual int get_priority();
		void print();
	private:
		void operator delete( void * );
		static int count;
		virtual void decr_count();
		virtual void decr_curr_num_of_objects();
	protected:
		C();
	
		
};

#endif
