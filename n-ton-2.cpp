#include <bits/stdc++.h>

using namespace std;



class NTon
{		
	public:
		static void set_N(int n)
		{
			N = n;
		}
		static int get_curr_num_of_objects()
		{
			return curr_num_of_objects;
		}		
	protected: // ensures access in derived classes but not in client
		static int N;
		static int curr_num_of_objects;
		static void disp()
		{
			cout<<"\n\n_________________________________________________\n";
			cout<<"N : "<<N<<'\n';
			cout<<"Current Number of Objects : "<<curr_num_of_objects<<'\n';
			cout<<"Remaining Number of Objects : " << N - curr_num_of_objects <<'\n';
			cout<<"_________________________________________________\n\n\n";
		}
		NTon() {	} //ensures its not instantiable in any of the derived classes and in the client
};


class A : public NTon
{
	public:		
		static A* get_A()
		{	
			
			if(curr_num_of_objects < N)
			{
				count_A++;
				curr_num_of_objects++;
				disp();
				return new A();
			}
			else
			{
				disp();
				throw std::runtime_error("too many objects");
			}
		}
		
		static int get_count_A()
		{
			return count_A;
		}
		
		virtual void del()
		{
			count_A--;
			curr_num_of_objects--;
			disp();
			delete(this);
		}
		
		virtual ~A()
		{			
			cout<<"A dtor\n";
		}
		
	private:
		void operator delete( void * ) {}
		static int count_A;
	
};

class B: public A
{
	public:
		
		static B* get_B()
		{
			if(curr_num_of_objects < N)
			{
				count_B++;
				curr_num_of_objects++;
				disp();
				return new B();
			}
			else
			{
				disp();
				throw std::runtime_error("too many objects");
			}
		}
		
		static int get_count_B()
		{
			return count_B;
		}
		
		virtual void del()
		{
			count_B--;
			curr_num_of_objects--;
			disp();
			delete(this);
		}
		virtual ~B()
		{			
			cout<<"B dtor\n";
		}
	private:
		void operator delete( void * ) {}
		static int count_B;
};

class C: public A
{
	
	public:
		
		static C* get_C()
		{
			if(curr_num_of_objects < N)
			{
				count_C++;
				curr_num_of_objects++;
				disp();
				return new C();
			}
			else
			{
				disp();
				throw std::runtime_error("too many objects");
			}
		}
		
		static int get_count_C()
		{
			return count_C;
		}
		
		virtual void del()
		{
			count_C--;
			curr_num_of_objects--;
			disp();
			delete(this);
		}
		
		virtual ~C()
		{
			cout<<"C dtor\n";
		}
	private:
		void operator delete( void * ) {}
		static int count_C;
};

class D: public B
{
	public:
		
		static D* get_D()
		{
			if(curr_num_of_objects < N)
			{
				count_D++;
				curr_num_of_objects++;
				disp();
				return new D();
			}
			else
			{
				disp();
				throw std::runtime_error("too many objects");
			}
		}
		static int get_count_D()
		{
			return count_D;
		}
		virtual void del()
		{
			count_D--;
			curr_num_of_objects--;
			disp();
			delete(this);
		}
		~D()
		{
			cout<<"D dtor\n";
		}
	private:
		void operator delete( void * ) {}
		static int count_D;
};

int NTon::N = 0;
int NTon::curr_num_of_objects = 0;
int A::count_A = 0;
int B::count_B = 0;
int C::count_C = 0;
int D::count_D = 0;


int main()
{
	NTon::set_N(4);
	
	
	
	A* a1 = A::get_A();
	A* a2 = A::get_A();
	
	
	a2->del();
	
	a2 = A::get_A();
	
	a2->del();
	
	A* a3 = B::get_B();
	a3->del();
	
	a1->del();
	
	cout<<NTon::get_curr_num_of_objects()<<'\n';
	
	vector<A*> v { A::get_A(), B::get_B(), C::get_C(), D::get_D()};
	
	
	cout<<NTon::get_curr_num_of_objects()<<'\n';
	
	for_each(begin(v), end(v), [](A* e)
	{
		e->del();
		cout<<"\n\n";
	});	
}
