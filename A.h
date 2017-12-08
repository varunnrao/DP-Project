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
		int priority;
		virtual void set_priority(int p);
		virtual int get_priority();
		void print();
	private:
		void operator delete( void * );
		static int count;	
		virtual void decr_count();
		virtual void decr_curr_num_of_objects();
	protected:
		A();
		
		
		
};

#endif
