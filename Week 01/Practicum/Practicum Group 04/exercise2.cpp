#include <iostream>

struct Point {
	double x;
	double y;
};

Point init()
{
	double x;
	double y;
	std::cin >> x >> y;
	return Point{ x,y };
}

void print(const Point& p)
{
	std::cout << '(' << p.x << ',' << p.y << ')';
}

double distanceToCenter(const Point& p)
{
	Point center{ 0,0 };
	double distance;
	distance = sqrt(p.x * p.x + p.y * p.y);
	return distance;
}

double distance(const Point& a, const Point& b)
{
	double distance;
	distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return distance;
}


struct Triangle {
	Point A;
	Point B;
	Point C;
};

Triangle readTriangle()
{
	Point A = init();
	Point B = init();
	Point C = init();

	return Triangle{ A, B, C };
}

void printTriangle(const Triangle& triangle)
{
	std::cout << "Point A ";
	print(triangle.A);
	std::cout << '\n' << "Point B";
	print(triangle.B);
	std::cout << '\n' << "Point C";
	print(triangle.C);

}

double perimeter(double a, double b, double c)
{
	return a + b + c;
}

double area(const Triangle& triangle)
{
	double a = distance(triangle.B, triangle.C);
	double b = distance(triangle.A, triangle.C);
	double c = distance(triangle.A, triangle.B);

	double halfPerimeter = perimeter(a, b, c) / 2;

	return sqrt(halfPerimeter * (halfPerimeter - a) *
		(halfPerimeter - b) * (halfPerimeter - c));
}

void typeTriangle(const Triangle& triangle)
{
	double a = distance(triangle.B, triangle.C);
	double b = distance(triangle.A, triangle.C);
	double c = distance(triangle.A, triangle.B);

	if (a == b && b == c && a == c)
	{
		std::cout << "Равностранен";
		return;
	}
	if (a == b || b == c || a == c)
	{
		std::cout << "Равнобедрен";
		return;
	}
	else
	{
		std::cout << "Разностранен";
		return;
	}
}

void sortTriangles(Triangle* triangles, int n)
{
	double* areas = new double[n];
	for (int i = 0; i < n; i++)
	{
		areas[i] = area(triangles[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (areas[minIndex] > areas[j])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(triangles[minIndex], triangles[i]);
			std::swap(areas[minIndex], areas[i]);
		}

		delete[] areas;
	}
}

int main()
{

	return 0;
}