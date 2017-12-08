#ifndef D_H
#define D_H

#include "B.h"

class D: public B
{
	public:		
		static D* get();
		static int get_count();
		virtual void del();
		int priority;
		virtual ~D();
		virtual void set_priority(int p);
		virtual int get_priority();
		void print();
	private:
		void operator delete( void * );
		static int count;
		virtual void decr_count();
		virtual void decr_curr_num_of_objects();
	protected:
		D();
};


#endif
