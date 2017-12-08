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
		int priority;
		virtual ~E();
		virtual void set_priority(int p);
		virtual int get_priority();
		void print();
	private:
		void operator delete( void * );
		static int count;
		virtual void decr_count();
		virtual void decr_curr_num_of_objects();
	protected:
		E();
};


#endif
