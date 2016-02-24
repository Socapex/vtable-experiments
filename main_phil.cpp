#include <iostream>

class Base
{
public:
	virtual void patate(int a) {
		std::cout << "patate BASE " << a << std::endl;
	}

	virtual void d() {
		std::cout << "d" << std::endl;
	}

	void b() {
		std::cout << "a" << std::endl;
	}

};

class A : public Base
{
public:
	void patate(int a) {
		std::cout << "Patate A " << a << std::endl;
	}

	void d() {
		std::cout << "d" << std::endl;
	}

	void b() {
		std::cout << "a" << std::endl;
	}

	void g() {
		std::cout << "asdf" << std::endl;
	}

private:
	int tomate = 42;
};

class Tomate
{
	// This is private, still works!
	virtual void tomate() {
		std::cout << "tomate " << test << std::endl;
	}

	int test = 42;
};

void jesus()
{
	std::cout << "jesus baby!" << std::endl;
}

int main(int argc, char* argv[])
{
	A a;
	long* asLong = (long *)&a;
	long** vtable = (long **)&a;

	printf("Vtable pointer: %ld\n", asLong[0]);
	printf("First entry of a VTABLE: %ld\n\n", vtable[0][0]);

	((void (*)()) vtable[0][0])(); // Call first a method.
	vtable[0][0] = vtable[0][1];
	((void (*)()) vtable[0][0])(); // Call second a method.

	Tomate t;
	long** tomateVtabl = (long **)&t;

	vtable[0][0] = tomateVtabl[0][0];
	((void (*)()) vtable[0][0])();


	long jesusPointer = (long)&jesus;
	vtable[0][0] = jesusPointer;
	((void (*)()) vtable[0][0])();

	return 0;
}
