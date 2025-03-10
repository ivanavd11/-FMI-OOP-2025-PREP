#include <iostream>

struct Point
{
	double x;
	double y;
};

struct Triangle
{
	char identifier[20];
	Point a;
	Point b;
	Point c;
};

double area(const Point& p1, const Point& p2, const Point& p3)
{
	int a = p1.x * (p2.y - p3.y);
	int b = p2.x * (p3.y - p1.y);
	int c = p3.x * (p1.y - p2.y);
	return (a + b + c < 0 ? -(a + b + c) : (a + b + c)) / 2.0;
}

void sortTriangles(int N, Triangle* triangles)
{
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j) 
		{
			if (area(triangles[j].a, triangles[j].b, triangles[j].c) > 
				area(triangles[j+1].a, triangles[j+1].b, triangles[j+1].c))
			{
				Triangle temp = triangles[j];
				triangles[j] = triangles[j + 1];
				triangles[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	Triangle* triangles = new Triangle[N];

	for (int i = 0; i < N; i++)
	{
		std::cin >> triangles[i].identifier;
		std::cin >> triangles[i].a.x >> triangles[i].a.y;
		std::cin >> triangles[i].b.x >> triangles[i].b.y;
		std::cin >> triangles[i].c.x >> triangles[i].c.y;
	}

	sortTriangles(N, triangles);
	for (int i = 0; i < N; i++)
	{
		std::cout << triangles[i].identifier << '/n';
	}
	delete[] triangles;


}