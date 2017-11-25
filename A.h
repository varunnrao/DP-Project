#ifndef A_H
#define A_H

#include "NTon.h"

class A : public NTon
{
	public:		
		static A* get_A();
		static int get_count_A();
		virtual void del();
		virtual ~A();
	private:
		void operator delete( void * );
		static int count_A;
		
};

#endif
