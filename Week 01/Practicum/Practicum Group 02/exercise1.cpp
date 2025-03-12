#include <iostream>

struct ComplexNumber {
	double real;
	double imag;
};

ComplexNumber init(double re, double im)
{
	ComplexNumber result;
	result.real = re;
	result.imag = im;
	return result;
}

void print(const ComplexNumber& complex)
{
	std::cout << complex.real;
	if (complex.imag == 0)
	{
		return;
	}
	else if (complex.imag < 0)
	{
		std::cout << complex.imag << 'i';
	}
	else
	{
		std::cout << '+'<< complex.imag << 'i';
	}
}

ComplexNumber conjugate(const ComplexNumber& complex)
{
	return ComplexNumber{ complex.real, -complex.imag };
}

ComplexNumber add(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return ComplexNumber{ lhs.real + rhs.real,
						 lhs.imag + rhs.imag };
}

ComplexNumber subratct(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return ComplexNumber{ lhs.real - rhs.real,
						 lhs.imag - rhs.imag };
}

ComplexNumber multiply(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return ComplexNumber{ lhs.real * rhs.real - lhs.imag * rhs.imag,
						  lhs.real * rhs.imag + lhs.imag * rhs.real };
}

ComplexNumber divide(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	double denominator = rhs.real * rhs.real + rhs.imag * rhs.imag;
	if(denominator==0)
	{
		return ComplexNumber{};
	}

	return ComplexNumber{ (lhs.real * rhs.real + lhs.imag * rhs.imag)/denominator,
						  (lhs.real * rhs.imag - lhs.imag * rhs.real)/denominator};
}

int main()
{

	return 0;
}