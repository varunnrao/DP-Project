#ifndef E_H
#define E_H

#include "B.h"
#include "C.h"

class E: public B, public C
{
	public:		
		static E* get();
		static int get_count();
		virtual void del();
		virtual ~E();
	private:
		void operator delete( void * );
		static int count;
	protected:
		E();
};


#endif
