#include <iostream>

struct Complex
{
	double real;
	double imag;
};

Complex sum(const Complex& first, const Complex& second)
{
	Complex result;
	result.real = first.real + second.real;
	result.imag = first.imag + second.imag;

	return result;
}

Complex diff(const Complex& first, const Complex& second)
{
	Complex result;
	result.real = first.real - second.real;
	result.imag = first.imag - second.imag;

	return result;
}

Complex mult(const Complex& first, const Complex& second)
{
	Complex result;
	result.real = first.real * second.real + first.imag * second.imag;
	result.imag = first.real * second.imag + first.imag * second.real;

	return result;
}

Complex div(const Complex& first, const Complex& second)
{
	double denominator = second.real * second.real + second.imag * second.imag;
	if (denominator == 0)
	{
		return {};
	}
	return Complex{ (first.real * second.real + first.imag * second.imag) / denominator,
					(first.real * second.imag + first.imag * second.real) / denominator };
}

bool isRealNumber(const Complex& complex)
{
	return (complex.imag == 0);
}

int main()
{

	return 0;
}