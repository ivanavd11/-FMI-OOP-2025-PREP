#include <iostream>

const int MAX_SIZE_NAME = 20;

enum class Age {
	freshman,
	sophomore,
	junior,
	senior
};

struct Student {
	char* name;
	char* surname;
	int EGN;
	Age age;
};

void printAge(const Age age)
{
	switch (age)
	{
	case Age::freshman: std::cout << "freshman"; break;
	case Age::sophomore: std::cout << "sophomore"; break;
	case Age::junior: std::cout << "junior"; break;
	case Age::senior: std::cout << "senior"; break;
	default:
		std::cout << "none";
		break;
	}
}

void printStudent(const Student& student)
{
	std::cout << "Name:" << student.name <<
		", surname: " << student.surname <<
		", EGN: " << student.EGN <<
		", Age: ";
	printAge(student.age);
}

Age getAgeEnum(int age)
{
	switch (age)
	{
	case 1:
		return Age::freshman;
		break;
	case 2:
		return Age::sophomore;
		break;
	case 3:
		return Age::junior;
		break;
	case 4:
		return Age::senior;
		break;
	default:
		break;
	}

}

Student init()
{
	int nameSize;
	std::cin >> nameSize;
	char* name = new char[nameSize + 1];
	for (int i = 0; i < nameSize; i++)
	{
		std::cin >> name[i];
	}

	int surnameSize;
	std::cin >> surnameSize;
	char* surname = new char[surnameSize + 1];
	for (int i = 0; i < surnameSize; i++)
	{
		std::cin >> surname[i];
	}

	int egn;
	std::cin >> egn;

	int age;
	std::cin >> age;

	Student student;

	student.name = new char[nameSize + 1];
	strncpy(student.name, name, nameSize);
	student.name[nameSize] = '\0';
	delete[] name;

	student.surname = new char[surnameSize + 1];
	strncpy(student.surname, surname, surnameSize);
	student.surname[surnameSize] = '\0';
	delete[] surname;

	student.EGN = egn;
	student.age = getAgeEnum(age);

	return student;
}

struct University {
	char* name;
	Student students[256];
	int studentsSize;

	bool hasStudent(const Student& target)
	{
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].EGN == target.EGN)
			{
				return true;
			}
		}

		return false;
	}

	void addStudent(const Student& other)
	{
		if (hasStudent(other))
		{
			return;
		}

		students[studentsSize++] = other;
	}

	void removeStudent(int targetEgn)
	{
		if (studentsSize == 0)
		{
			return;
		}

		int targetIdx = -1;
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].EGN == targetEgn)
			{
				targetIdx = i;
				break;
			}
		}

		if (targetIdx != -1)
		{
			students[targetIdx].name = nullptr;
			students[targetIdx].surname = nullptr;
		}

		else
		{
			return;
		}

		for (int i = targetIdx; i < studentsSize - 1; i++)
		{

			students[i] = students[i + 1];
		}

		studentsSize -= 1;
	}

	void printStudents(Age age)
	{
		for (int i = 0; i < studentsSize; i++)
		{
			if (students[i].age == age)
			{
				printStudent(students[i]);
			}
		}
	}

};

int main()
{

	return 0;
}