#ifndef A_H
#define A_H

#include "NTon.h"

class A : public NTon
{
	public:		
		static A* get();
		static int get_count();
		virtual void del();
		virtual ~A();
	private:
		void operator delete( void * );
		static int count;
	protected:
		A();
		
};

#endif
