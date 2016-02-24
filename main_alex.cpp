#include <iostream>

class Base {
public:
	Base()
	{
	
	}

	virtual void patate(int n)
	{
		std::cout << "BANG " << n << std::endl;
	}
	
	virtual void patate2(int n)
	{
		std::cout << "BANGER____ " << n << std::endl;
	}
	double chunkey = 2;
};

class A : public Base{
public:
        A()
        {

        }

        //virtual void patate(int n)
        //{
        //        std::cout << "BANG" << std::endl;
        //}

	double chunky = 89;
};

void jesus(Base& base, int n)
{
	std::cout << "JESUS " << base.chunkey << std::endl;
}

void jesus2(void* base, int n)
{
	std::cout << "JESUS " << ((Base*)base)->chunkey << std::endl;
}

typedef void(Base::*BaseFct)(int);

int main()
{
	//void (*fct)(Base&, int) = &jesus;
	//fct(123);

	// Example simple.
	// void (Base::*fct2)(int) = &Base::patate;
	
	Base* a = new Base();
	//(a->*fct)(122);
	
//(a->*fct2)(456);

	// ICI.
	long** vtable = (long **)a;
	//vtable[0][0] = vtable[0][1];
	//vtable[0][0] = *(long*)fct;	
	//vtable[0][0] = *(long*)&jesus;	
	
	//vtable[0][0] = (long)&jesus;
	vtable[0][1] = (long)&jesus2;

	//BaseFct my_ptr = 0;	
	//*reinterpret_cast<void**>(&my_ptr) = (void*)vtable[0][0]; 	
	//(a->*my_ptr)(123);	

	//a->patate(99999999);
	a->patate2(123);
	//std::cout << "Size of Base : " << sizeof(Base) << std::endl;
	//std::cout << "Size of A : " << sizeof(A) << std::endl;

	return 0;
}

