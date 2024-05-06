#include <iostream>
using namespace std;

int detoftime(int, int, int);

int main()
{
	int a, b, c, a1, b1, c1;
	cout << "Enter first curent time (hours, minutes, seconds)" << endl;
	cin >> a >> b >> c;
	cout << "Enter second curent time (hours, minutes, seconds)" << endl;
	cin >> a1 >> b1 >> c1;

	cout << "From 12:00 to the first interval: " << detoftime(a, b, c) << " seconds" << endl;

	cout << "From 12:00 to the second interval: " << detoftime(a1, b1, c1) << " seconds" << endl;

	cout << "Passed " << abs(detoftime(a, b, c) - detoftime(a1, b1, c1)) << " seconds" << endl;

	return 0;
}

int detoftime(int x, int y, int z)
{
	const int p = 12;
	const int n = 60;
	while (z >= n)
	{
		y += z / n;
		z = z % n;
	}
	while (y >= n)
	{
		x += y / n;
		y = y % n;
	}
	while (x > p)
	{
		x -= p;
	}
	int f = x * 3600 + y * 60 + z;

	return f;
}