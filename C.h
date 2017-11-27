#ifndef C_H
#define C_H

#include "A.h"

class C: public A
{
	public:		
		static C* get();
		static int get_count();
		virtual void del();
		virtual ~C();
	private:
		void operator delete( void * );
		static int count;
	protected:
		C();
	
		
};

#endif
