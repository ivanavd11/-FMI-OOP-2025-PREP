#include <iostream>

namespace CONSTANT {
	const int MAX_NAME = 32;
	const int MAX_FN = 6;
	const int MAX_STUDENTS = 50;
}

enum class Specialty {
	 Õ,
	—»,
	»—,
	Ã,
	»,
	œÃ,
	Ã»,
	¿ƒ
};

struct Student {
	char name[CONSTANT::MAX_NAME];
	char fn[CONSTANT::MAX_FN];
	unsigned grade = 0 ;
	Specialty s;
};

struct Course {
	Student students[CONSTANT::MAX_STUDENTS];
	int countStudents;
};

Student init(const char* name, const char* fn, Specialty specialty)
{
	if (!name || !fn )
	{
		return Student{};
	}

	Student st;
	strcpy(st.name, name);
	strcpy(st.fn, fn);
	switch (specialty)
	{
	case Specialty:: Õ: st.s = Specialty:: Õ;
		break;
	case Specialty::—»:st.s = Specialty::—»;
		break;
	case Specialty::»—:st.s = Specialty::»—;
		break;
	case Specialty::Ã:st.s = Specialty::Ã;
		break;
	case Specialty::»:st.s = Specialty::»;
		break;
	case Specialty::œÃ:st.s = Specialty::œÃ;
		break;
	case Specialty::Ã»:st.s = Specialty::Ã»;
		break;
	case Specialty::¿ƒ:st.s = Specialty::¿ƒ;
		break;
	default: return;
		break;
	}

	return st;
}

void printSpecial(const Specialty specialty)
{
	switch (specialty)
	{
	case Specialty:: Õ: std::cout<<" Õ";
		break;
	case Specialty::—»:std::cout << "—»";
		break;
	case Specialty::»—:std::cout << "»—";
		break;
	case Specialty::Ã:std::cout << "Ã";
		break;
	case Specialty::»:std::cout << "»";
		break;
	case Specialty::œÃ:std::cout << "œÃ";
		break;
	case Specialty::Ã»:std::cout << "Ã»";
		break;
	case Specialty::¿ƒ:std::cout << "¿ƒ";
		break;
	default: std::cout << "ÕÂ ÁÌ‡ÂÏ";
		break;
	}
}

void printStudent(const Student& student)
{
	std::cout << "Name: " << student.name
		<< ", FN: " << student.fn <<
		", grade: " << student.grade <<
		", specialty: ";
	printSpecial(student.s);
}

void printCourse(const Course& course)
{
	std::cout << "	Course: " << '\n';
	for (int i = 0; i < course.countStudents; i++)
	{
		std::cout << "Student π" << i + 1 << '\n';
		printStudent(course.students[i]);
		std::cout << '\n';
	}
}

void addStudent(const Student& student, Course& course)
{
	if (course.countStudents == CONSTANT::MAX_STUDENTS)
	{
		return;
	}
	course.students[course.countStudents++] = student;
}

void removeStudent(const char* fn, Course& course)
{
	if (!fn)
		return;
	for (int i = 0; i < course.countStudents; i++)
	{
		if (course.students[i].fn == fn)
		{
			course.students[i] = course.students[course.countStudents--];
			return;
		}
	}
}


void sortCourse(Course& course)
{
	for (int i = 0; i < course.countStudents - 1; i++)
	{
		int minGrade = i;
		for (int j = i + 1; j < course.countStudents; j++)
		{
			if (course.students[i].grade <= course.students[minGrade].grade)
			{
				minGrade = j;
			}
		}

		if (minGrade != i)
		{
			if (course.students[minGrade].grade < course.students[i].grade
				|| strcmp(course.students[minGrade].name, course.students[i].name) < 0)
			{
				std::swap(course.students[minGrade], course.students[i]);
			}
		}
	}
}

int main()
{

	return 0;
}