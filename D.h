#ifndef D_H
#define D_H

#include "B.h"

class D: public B
{
	public:		
		static D* get_D();
		static int get_count_D();
		virtual void del();
		virtual ~D();
	private:
		void operator delete( void * );
		static int count_D;
};


#endif
