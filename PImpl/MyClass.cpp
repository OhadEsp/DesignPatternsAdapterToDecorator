#include "MyClass.h"
#include <iostream>

class MyClass::Impl
{
	std::string name_;
public:
	Impl(std::string name): name_(std::move(name)) {}

	void Function1()
	{
		std::cout << name_ << " Running Function 1" << std::endl;
	}

	void Function2()
	{
		std::cout << "Running Function 2" << std::endl;
	}
};

MyClass::MyClass(std::string name) : impl_(new Impl(name))
{

}

MyClass::~MyClass()
{
	delete impl_;
}

void MyClass::Function1()
{
	impl_->Function1();
}

void MyClass::Function2()
{
	impl_->Function2();
}