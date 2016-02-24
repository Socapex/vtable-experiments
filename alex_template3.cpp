#include <iostream>
#include <vector>


// VTable.
template<typename T, typename R, typename ...P>
void VAssign(T& type, int index, R(*fct)(T&, P...))
{
	long** vtable = (long **)&type;
	vtable[0][index] = (long)fct;
}

template<typename T>
void VResize(T& type, int old_size, int new_size)
{
	long** vtable = (long **)&type;
	long** new_vtable = new long*[1];
	
	new_vtable[0] = new long[new_size];
	
	for(int i = 0; i < old_size; i++) {
		new_vtable[0][i] = vtable[0][i];
	}
	
	for(int i = old_size; i < new_size; i++) {
		new_vtable[0][i] = 0;
	}
	
	vtable[0] = new_vtable[0];
}

template<typename T, typename R, typename ...P>
void VCall(T* type, int index, P... p)
{
	long** vtable = (long **)type;
	typedef R(T::*Fct)(P...);
	Fct func = 0;
	*reinterpret_cast<void**>(&func) = (void*)vtable[0][index];
	(type->*func)(p...);
}


// Example.
//-----------------------------------------------
// Base class.
class Base {
public:
	Base()
	{
	
	}

	virtual void patate(int n)
	{
		std::cout << __FUNCTION__ << " -> " <<  n << std::endl;
	}
	
	virtual void patate2(int n)
	{
		std::cout << "BANGER____ " << n << std::endl;
	}
	double chunkey = 222222;
};

// Global function.
void jesus(Base& base, int n)
{
	std::cout << "JESUS " << base.chunkey << "value : " << n << std::endl;
}

// Global function.
void jesus_christ(Base& base, int n)
{
	std::cout << "JESUS FUCK [2]" << n << std::endl;
}

typedef void(Base::*BaseFct)(int);

int main()
{
	Base* b = new Base();
	
	VResize<Base>(*b, 2, 4);
	VAssign<Base, void, int>(*b, 2, &jesus);
	VAssign<Base, void, int>(*b, 3, &jesus_christ);
//	VCall<Base, void, int>(b, 2, 1000);
//	VCall<Base, void, int>(b, 3, 1000);
//
//	VCall<Base, void, int>(b, 1, 1000);
//	VCall<Base, void, int>(b, 2, 1000);
	std::vector<int> call_list = {0, 1, 2, 3, 2, 2, 1, 1, 0, 0, 0};
	for(auto& n : call_list) {
		VCall<Base, void, int>(b, n, 5);
	}
	
	//	delete b;
	
	
	
	//	Base a;
	//	AssignFuncToVTable<Base, void, int>(a, 0, &jesus);
	//	a.patate(111);
	
	
	
	
	
//	b.patate(111);
	
	
	
	//void (*fct)(Base&, int) = &jesus;
	//fct(123);

	// Example simple.
	// void (Base::*fct2)(int) = &Base::patate;
	
	
	//(a->*fct)(122);
	
//(a->*fct2)(456);




	// ICI.
	//--------------------------------
//	long** vtable = (long **)a;
//	vtable[0][1] = (long)&jesus2;
//	a->patate2(123);
	//--------------------------------
	
	
	
	//vtable[0][0] = vtable[0][1];
	//vtable[0][0] = *(long*)fct;	
	//vtable[0][0] = *(long*)&jesus;	
	
	//vtable[0][0] = (long)&jesus;
	

	//BaseFct my_ptr = 0;	
	//*reinterpret_cast<void**>(&my_ptr) = (void*)vtable[0][0]; 	
	//(a->*my_ptr)(123);	

	//a->patate(99999999);
	
	//std::cout << "Size of Base : " << sizeof(Base) << std::endl;
	//std::cout << "Size of A : " << sizeof(A) << std::endl;

	return 0;
}

