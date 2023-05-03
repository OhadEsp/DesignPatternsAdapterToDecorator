#pragma once
#include <string>

class MyClass
{	
	class Impl;
	Impl* impl_; 
	
public:
	MyClass(std::string name);
	~MyClass();
	
	void Function1();
	void Function2();
};