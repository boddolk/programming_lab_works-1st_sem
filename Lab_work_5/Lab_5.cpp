#include <iostream>
#include <cmath>
using namespace std;

void transform(int);
void transform1(int*, int*, int*, int*);
void transform2(int&, int&, int&, int&);

int main()
{
	int square, a, b, c;
	cout << "Enter the required area: ";
	cin >> square;
	cout << endl;
	transform(square);
	cout << endl;
	transform1(&square, &a, &b, &c);
	cout << endl;
	transform2(square, a, b, c);
	cout << endl;

	return 0;
}

void transform(int sqw)
{
	float c = 0;
	for (int i = 1; i < sqw; i++)
	{
		for (int k = 1; k < sqw; k++)
		{
			for (int f = 1; f < sqw; f++)
			{
				c = (i + k + f) / 2;
				if (sqrt(c * (c - i) * (c - k) * (c - f)) == sqw)
				{
					if (i + k > f && k + f > i && f + i > k)
					{
						cout << "a = " << i << "  b = " << k << "  c = " << f << endl;
					}
				}
			}
		}
	}
	cout << endl;
}

void transform1(int* sqw, int* a, int* b, int* g)
{
	float c = 0;
	for (*a; *a < *sqw; (*a)++)
	{
		for (*b; *b < *sqw; (*b)++)
		{
			for (*g; *g < *sqw; (*g)++)
			{
				c = ((*a) + (*b) + (*g)) / 2;
				if (sqrt(c * (c - (*a)) * (c - (*b)) * (c - (*g))) == *sqw)
				{
					if ((*a) + (*b) > *g && (*b) + (*g) > *a && (*g) + (*a) > *b)
					{
						cout << "a = " << *a << "  b = " << *b << "  c = " << *g << endl;
					}
				}
			}
			*g = 1;
		}
		*b = 1;
	}
	cout << endl;
}

void transform2(int& sqw, int& a, int& b, int& g)
{
	a = 1, b = 1, g = 1;
	float c = 0;
	for (a; a < sqw; (a)++)
	{
		for (b; b < sqw; (b)++)
		{
			for (g; g < sqw; (g)++)
			{
				c = (a + b + g) / 2;
				if (sqrt(c * (c - a) * (c - b) * (c - g)) == sqw)
				{
					if (a + b > g && b + g > a && g + a > b)
					{
						cout << "a = " << a << "  b = " << b << "  c = " << g << endl;
					}
				}
			}
			g = 1;
		}
		b = 1;
	}
	cout << endl;
}