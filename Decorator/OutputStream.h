#pragma once

#include <string>
#include <iostream>
#include <fstream>

class OutputStream
{
public:
	virtual ~OutputStream() = default;
	virtual void Write(const std::string& str) = 0;
};

class ConsoleStream : public OutputStream
{
public:
	void Write(const std::string& str) override
	{
		std::cout << str;
	}
};

class MemoryStream : public OutputStream
{
	std::string memory_;
public:
	void Write(const std::string& str) override
	{
		memory_ += str;
	}

	std::string GetString() const
	{
		return memory_;
	}

	void Clear()
	{
		memory_.clear();
	}
};

class FileStream : public OutputStream
{
	std::string file_name_;

public:
	FileStream(){}
	FileStream(std::string file_name) : file_name_(std::move(file_name))
	{
	}

	void SetFileName(std::string file_name) {
		file_name_ = file_name;
	}

	void Write(const std::string& str) override
	{
		std::ofstream output(file_name_, std::ios_base::app);

		output << str;
	}
};