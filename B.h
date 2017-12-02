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
	private:
		void operator delete( void * );
		static int count;
	protected:
		B();
		
};

#endif
