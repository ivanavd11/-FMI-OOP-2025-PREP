#include <iostream>

struct Point {
	int x = 0;
	int y = 0;
};

Point init()
{
	int x;
	int y;
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

int main()
{

	return 0;
}