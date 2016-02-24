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

	double chunkey = 222222;
};

template<typename T, typename R, typename ...P>
void AssignFuncToVTable(T& type, int index, R(*fct)(T&, P...))
{
	long** vtable = (long **)&type;
	vtable[0][index] = (long)fct;
}

void jesus(Base& base, int n)
{
	std::cout << "JESUS " << base.chunkey << std::endl;
}

int main()
{
	Base a;
	AssignFuncToVTable<Base, void, int>(a, 0, &jesus);
	a.patate(111);

	return 0;
}

