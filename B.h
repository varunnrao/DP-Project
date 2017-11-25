#ifndef B_H
#define B_H

#include "A.h"

class B: public A
{
	public:		
		static B* get_B();
		static int get_count_B();
		virtual void del();
		virtual ~B();
	private:
		void operator delete( void * );
		static int count_B;
		
};

#endif
