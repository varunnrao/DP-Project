#ifndef D_H
#define D_H

#include "B.h"

class D: public B
{
	public:		
		static D* get();
		static int get_count();
		virtual void del();
		virtual ~D();
	private:
		void operator delete( void * );
		static int count;
	protected:
		D();
};


#endif
