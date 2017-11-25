#ifndef C_H
#define C_H

#include "A.h"
class C: public A
{
	public:		
		static C* get_C();
		static int get_count_C();
		virtual void del();
		virtual ~C();
	private:
		void operator delete( void * );
		static int count_C;
		
};


#endif
