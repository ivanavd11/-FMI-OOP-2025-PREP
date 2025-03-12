#include <iostream>

enum class Optional {
	A,
	B,
	C,
	D
};

struct Answer
{
	char name[50 + 1];
};

struct Question {
	char title[50 + 1];
	Answer answers[4 + 1];
	Optional op;
	double points;
};

struct Test {
	Question questions[20];
};

int main()
{

	return 0;
}