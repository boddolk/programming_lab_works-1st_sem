#include <iostream>
#include <ctime>
using namespace std;

const int N = 4;
const int M = 5;

void genarr(float[][M]);
void show_arr(float[][M]);
float non_zero_str(float[][M]);
void doubmax(float[][M], float, float);
float maxel(float[][M]);
float minel(float[][M]);
float maelwpar(float[][M], float, float);


int main()
{
	float arr[N][M] {};

	genarr(arr);

	show_arr(arr);
	
	cout << non_zero_str(arr) << " non-zero rows." << endl << endl;
	
	float maxpar = maxel(arr);
	float minpar = minel(arr);

	doubmax(arr, maxpar, minpar);

	return 0;
}


void genarr(float array[N][M])
{
	srand((int)time(0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array[i][j] = rand() % 100 * 0.1 - 5;
		}
	}
}

void show_arr(float array[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl << endl;
	}
}


float non_zero_str(float array[N][M])
{
	int num = 0;
	
	for (int i = 0; i < N; i++)
	{
		int ind = 0;
		for (int j = 0; j < M; j++)
		{
			if (array[i][j] == 0)
			{
				ind += 1;
			}
		}
		if (ind == 0)
		{
			num += 1;
		}
	}

	return num;
}


void doubmax(float array[N][M], float b, float k)
{
	int repetit = 0;	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (b == array[i][j])
			{
				repetit += 1;
			}
		}
	}

	if (repetit > 1)
	{
		cout << b << " the maximum number in the matrix that occurred more than once." << endl;
	}

	if (repetit == 1 && b == k)
	{
		cout << "We do not have such an element." << endl;
	}

	if (repetit == 1 && b > k)
	{
		float g = maelwpar(array, b, k);

		doubmax(array, g, k);
	}
}


float maxel(float array[N][M])
{
	float maxel = array[0][0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maxel < array[i][j])
			{
				maxel = array[i][j];
			}
		}
	}

	return maxel;
}


float minel(float array[N][M])
{
	float minel = array[0][0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (minel > array[i][j])
			{
				minel = array[i][j];
			}
		}
	}

	return minel;
}


float maelwpar(float array[N][M], float elem, float elem2)
{
	float c = elem2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (c < array[i][j] && array[i][j] < elem)
			{
				c = array[i][j];
			}
		}
	}

	return c;
}