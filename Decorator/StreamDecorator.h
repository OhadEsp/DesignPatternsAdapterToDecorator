#pragma once
#include "OutputStream.h"

class StreamDecorator : public OutputStream
{
	OutputStream* stream_;

public:
	StreamDecorator(OutputStream* stream) : stream_(stream)
	{
	}

	~StreamDecorator() override = default;

	virtual std::string Encode(const std::string& str) = 0;


	void Write(const std::string& str) override
	{
		const auto encoded = Encode(str);
		stream_->Write(encoded);
	}
};

class EncryptedStream : public StreamDecorator
{
	char key_;

public:
	EncryptedStream(OutputStream* stream, const char key) : StreamDecorator(stream), key_(key)
	{
	}

	std::string Encode(const std::string& str) override
	{
		std::string result;

		for (char c : str)
		{
			result.push_back(c + key_);
		}

		return result;
	};
};

class CompressedStream : public StreamDecorator
{
public:
	explicit CompressedStream(OutputStream* stream)
		: StreamDecorator(stream)
	{
	}

	std::string Encode(const std::string& str) override
	{
		std::string result;

		const int length = str.length();
		for (int i = 0; i < length; i++) {

			int count = 1;
			while (i < length - 1 && str[i] == str[i + 1]) {
				count++;
				i++;
			}
			result += std::to_string(count);
			result.push_back(str[i]);
		}

		return result;
	}
};

class LoggingStream : public OutputStream {
	OutputStream* stream_;
	std::string name_;
public:
	LoggingStream(OutputStream* stream, std::string name) : stream_(stream), name_(std::move(name))
	{
	}

	void Write(const std::string& str) {
		std::cout << "LOG(" << name_ << "): " << str << std::endl;
		stream_->Write(str);
	}
};

class RetryStream : public OutputStream
{
	OutputStream* stream_;
	std::string last_str_;
public:
	RetryStream(OutputStream* stream) : stream_(stream)
	{
	}

	void Write(const std::string& str)
	{
		last_str_ = str;

		stream_->Write(str);
	}

	void WriteAgain()
	{
		stream_->Write(last_str_);
	}
};

template <typename T>
class LoggingStream2 : public T
{
	std::string name_;

public:
	template <typename... Args>
	LoggingStream2(std::string name, Args... args) : 
		T(std::forward<Args>(args)...),
		name_(std::move(name))
	{
	}

	void Write(const std::string& str) override
	{
		std::cout << "LOG(" << name_ << "): " << str << std::endl;
		T::Write(str);
	}
};