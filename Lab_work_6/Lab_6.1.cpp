#include <iostream>
#include <ctime>
using namespace std;

void genarr(float[]);
void show_arr(float[]);
float ne_sum(float[]);
float mimaprod(float[]);
void sort(float[]);

int const N = 10;

int main()
{
	float arr[N];
	genarr(arr);
	show_arr(arr);
	cout << "Sum of negative elements is: s = " << ne_sum(arr) << endl;
	cout << "Product of elements between (max - min): d = " << mimaprod(arr) << endl << endl;
	sort(arr);
	show_arr(arr);

	return 0;
}

void genarr(float array[])
{
	srand((int)time(0));
	
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 100 * 0.1 - 5;
	}
}

void show_arr(float array[])
{
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl << endl;
}

float ne_sum(float array[])
{
	float s = 0;
	for (int i = 0; i < N; i++)
	{
		if (array[i] < 0) s += array[i];
	}

	return s;
}

float mimaprod(float array[])
{
	float prod = 1;

	float minel = array[0];
	int minind = 0;

	float maxel = array[0];
	int maxind = 0;
	int ch = 0;

	for (int i = 1; i < N; i++)
	{
		if (minel > array[i])
		{
			minel = array[i];
			minind = i;
		}

	}

	for (int j = 1; j < N; j++)
	{
		if (maxel < array[j])
		{
			maxel = array[j];
			maxind = j;
		}
	}

	// swap indexes if we want;
	if (minind > maxind)
	{
		ch = maxind;
		maxind = minind;
		minind = ch;
	}
	
	for (minind++; minind < maxind; minind++)
	{
		prod *= array[minind];
	}

	return prod;
}

void sort(float array[])
{
	float t = 0, i = 0;
	int flag;
	do
	{
		flag = 0;
		for (int j = (N - 2); j >= i; j--)
		{
			flag = 0;
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				flag = 1;
			}
		}
		i++;
	} while (flag);
}