#include <iostream>

enum class Error {
	Invalid,
	Valid,
	Nullptr,
	EmptyText,
	Overflow
};

struct TextToNumber {
	int number;
	Error status;
};

TextToNumber convert(const char* text)
{
	int number = 0;
	if (!text)
	{
		return TextToNumber{ number, Error::Nullptr };
	}

	int sizeText = strlen(text);
	if (sizeText == 0)
	{
		return TextToNumber{ number, Error::EmptyText };
	}

	for (int i = 0; text[i] != '\0'; i++)
	{
		char symbol = text[i];
		if (symbol >= '0' && symbol <= '9')
		{
			number *= 10;
			number += (symbol - '0');
		}
		else
		{
			return TextToNumber{ 0, Error::Invalid };
		}
	}

	return TextToNumber{ number, Error::Valid };

}

void printError(Error e)
{
	switch (e)
	{
	case Error::Invalid:
		std::cout << "Invalid";
		break;
	case Error::Valid:
		std::cout << "Valid";
		break;
	case Error::Nullptr:
		std::cout << "Nullptr";
		break;
	case Error::EmptyText:
		std::cout << "EmptyText";
		break;
	case Error::Overflow:
		std::cout << "Overflow";
		break;
	default:
		std::cout << "Unknown";
		break;
	}
}

void printNumber(const char* text)
{
	TextToNumber num = convert(text);
	std::cout << num.number << " error: ";
	printError(num.status);
}

int main()
{
	char text[32] = "564";
	printNumber(text);
}