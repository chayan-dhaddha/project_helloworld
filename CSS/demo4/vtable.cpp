#include <iostream>
#include <stdio.h>

class animal
{
public:
	virtual void make_noise() = 0;
};

class crow : public animal
{
public:
	virtual void make_noise();
};

class dog : public animal
{
public:
	virtual void make_noise();
};

void crow::make_noise()
{
	std::cout << "kaw kaw" << std::endl;
}

void dog::make_noise()
{
	std::cout << "bow bow" << std::endl;
}


int main()
{
	char* string = new char[32];
	animal* a = new dog();
	printf("address of string: %p; animal: %p\n", string, a);
	std::cin >> string;
	a->make_noise();
	return 0;
}

