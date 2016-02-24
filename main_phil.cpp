#include <iostream>

class Base
{
public:
	virtual void patate() {
		std::cout << "patate BASE " << std::endl;
	}

	virtual void d() {
		std::cout << "d" << std::endl;
	}

	virtual void b() {
		std::cout << "a" << std::endl;
	}

};

class A : public Base
{
public:
	void patate() {
		std::cout << "Patate A " << std::endl;
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
		std::cout << "tomate " << std::endl;
	}

	virtual void blee() {
		std::cout << "blee " << std::endl;
	}

	// int test = 42;
};

void jesus()
{
	std::cout << "jesus baby!" << std::endl;
}

int main(int argc, char* argv[])
{
	A* a = new A();
	long* asLong = (long *)a;
	long** vtable = (long **)a;

	printf("Vtable pointer: %ld\n", asLong[0]);
	printf("First entry of a VTABLE: %ld\n\n", vtable[0][0]);

	// ((void (*)()) vtable[0][0])(); // Call first a method.
	// vtable[0][0] = vtable[0][1];
	// ((void (*)()) vtable[0][0])(); // Call second a method.

	Tomate t;
	long** tomateVtabl = (long **)&t;
	// ((void (*)()) tomateVtabl[0][0])();
	// vtable[0][0] = tomateVtabl[0][0];
	// ((void (*)()) vtable[0][0])();

	long jesusPointer = (long)&jesus;
	// vtable[0][0] = jesusPointer;
	// ((void (*)()) vtable[0][0])();

	long** newVTable = new long*[1];
	newVTable[0] = new long[6];

	for (int i = 0; i < 3; ++i) {
		newVTable[0][i] = vtable[0][i];
	}

	for (int i = 3; i < 5; ++i) {
		newVTable[0][i] = tomateVtabl[0][i - 3];
	}

	newVTable[0][5] = jesusPointer;

	// // TEST //
	// for (int i = 0; i < 6; ++i) {
	// 	((void (*)()) newVTable[0][i])();
	// }










	a = (A*)newVTable[0];
	delete[] vtable;

	struct Test {
		void (*je)();
		void (*suis)();
		void (*un)();
		void (*objet)();
		void (*re)();
		void (*cree)();
	};

	Test* test;
	test = (Test*)a;
	test->je();
	test->suis();
	test->un();
	test->objet();
	test->re();
	test->cree();

	delete test;
	return 0;
}
