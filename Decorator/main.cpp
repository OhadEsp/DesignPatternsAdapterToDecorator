#include "OutputStream.h"
#include "StreamDecorator.h"
#include <functional>
/*
class Logger3 {
	std::string name_;

public:
	Logger3(std::string name)
		: name_(std::move(name))
	{
	}

	void operator()(std::function<void()> func) {
		std::cout << "Entering " << name_ << std::endl;
		func();
		std::cout << "Existing " << name_ << std::endl;
	}
};
*/

template <typename T>
class Logger3;

template <typename R, typename... Args>
class Logger3<R(Args...)>
{
	std::function<R(Args...)> func_;
	std::string name_;
public:
	Logger3(std::function<R(Args ...)> func, std::string name)
		: func_(func), name_(std::move(name))
	{
	}

	R operator()(Args ... args)
	{
		std::cout << "Entering " << name_ << std::endl;
		R result = func_(args...);
		std::cout << "Exiting " << name_ << std::endl;
		return result;
	}
};

template <typename R, typename... Args>
auto make_logger(R(*func)(Args ...), const std::string& name)
{
	return Logger3<R(Args ...)>(std::function < R(Args...) >(func), name);
}

std::string writeToStream(MemoryStream& stream, const std::string& message) {
	stream.Write(message);

	return stream.GetString();
}

int main()
{
	/*
	ConsoleStream stream;

	/*
	CompressedStream compressed(&stream);
	LoggingStream logging(&compressed, "After encrypted");
	EncryptedStream encrypted(&logging, 'd');

	std::cout << std::endl;
	encrypted.Write("AAAABBBCCCCCDDDDDDD");
	std::cout << std::endl;
	*/

	/*
	RetryStream retry(&stream);

	std::cout << std::endl;
	retry.Write("First");
	std::cout << std::endl;
	retry.Write("Second");
	std::cout << std::endl;
	retry.WriteAgain();
	*/

	/*
	LoggingStream2<FileStream> logging("saved to file", R"(C:\temp\output.txt)");

	logging.Write("a new string\n");	
	logging.Write("Another string\n");
	*/

	MemoryStream stream;
	/*
	Logger3 logger("Write");

	std::string result;
	logger([&]() {
		stream.Write("this is a text string");
		result = stream.GetString();
	});
	*/

	auto logged_write = make_logger(writeToStream, "Write");

	std::string result = logged_write(stream, "this is a text string");

	std::cout << std::endl <<"result == " << result << std::endl;
}