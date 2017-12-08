#ifndef B_H
#define B_H

#include "A.h"

class B: virtual public A
{
	public:		
		static B* get();
		static int get_count();
		virtual void del();
		virtual ~B();
		int priority;
		virtual void set_priority(int p);
		virtual int get_priority();
		void print();
	private:
		void operator delete( void * );
		static int count;
		virtual void decr_count();
		virtual void decr_curr_num_of_objects();
	protected:
		B();
		
};

#endif
