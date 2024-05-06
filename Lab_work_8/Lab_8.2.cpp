#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Employee
{
	char F[20]; // прізвище;
	int Z; // Зарплата;
	int P; // Кількість зарплати, яку було утримано;
	int S; // Зарплата, яка була фактично видана;
};

void cinenterpr(Employee*, int);
int sumZ(Employee*, int);
int sumP(Employee*, int);
int sumS(Employee*, int);
void title1();
void title2();
void coutenterpr(Employee*, int);
void mima_sallar_sort(Employee*, int); // Відсортувати за зростанням зарпатні;
void maxactsal(Employee*, int, int);

int main()
{
	int n;
	int m;
	cout << "Enter the number of workers in the enterprise: " << endl;
	cin >> n;
	cout << "Enter the maximum actual salary:" << endl;
	cin >> m;
	cin.ignore();
	Employee* enterprise = new Employee[n]{};

	cinenterpr(enterprise, n);

	cout << "Before tasks" << endl;
	coutenterpr(enterprise, n);

	mima_sallar_sort(enterprise, n);

	cout << "After sort" << endl;
	coutenterpr(enterprise, n);

	maxactsal(enterprise, n, m);

	return 0;
}

void cinenterpr(Employee* enterpr, int h)
{
	for (int i = 0; i < h; i++)
	{
		cout << "Enter the last name of the worker " << i + 1 << endl;
		cin.getline(enterpr[i].F, 20);

		cout << "Enter the worker's salary " << i + 1 << endl;
		cin >> enterpr[i].Z;
		cin.ignore();

		cout << "Enter how much salary was withheld " << i + 1 << endl;
		cin >> enterpr[i].P;
		cin.ignore();

		enterpr[i].S = enterpr[i].Z - enterpr[i].P;

		cout << endl;
	}
}

int sumZ(Employee* enterpr, int h)
{
	int sZ = 0;
	for (int i = 0; i < h; i++)
	{
		sZ += enterpr[i].Z;
	}

	return sZ;
}

int sumP(Employee* enterpr, int h)
{
	int sP = 0;
	for (int i = 0; i < h; i++)
	{
		sP += enterpr[i].P;
	}

	return sP;
}


int sumS(Employee* enterpr, int h)
{
	int lS = 0;
	for (int i = 0; i < h; i++)
	{
		lS += enterpr[i].S;
	}

	return lS;
}

void title1()
{
	// Титулка;
	int i;
	cout << setw(4);
	for (i = 0; i <= 63; i++)
		cout << '=';
	cout << endl;

	cout << setw(23) << "--=" << setw(23) << "Enterprise  statistics" << setw(4) << "=--" << endl;

	cout << setw(4);
	for (i = 0; i <= 63; i++)
		cout << '=';
	cout << endl;

	// Перший рядок(з описом інформації в таблиці);
	cout << setw(5) << "||" << setw(4) << "No" << setw(2) << "|" << setw(20) << "Employee" << setw(2) << "|" << setw(8) << "Salary" << setw(2) << "|" << setw(10) << "Withheld" << setw(2) << "|" << setw(9) << "Acrued" << setw(3) << " || " << endl;
	cout << setw(4);
	for (i = 0; i < 64; i++)
		cout << '-';
	cout << endl;
}

void title2()
{
	// Титулка;
	int i;
	cout << setw(4);
	for (i = 0; i <= 63; i++)
		cout << '=';
	cout << endl;

	cout << setw(32) << "--=" << setw(8) << "Extract" << setw(4) << "=--" << endl;

	cout << setw(4);
	for (i = 0; i <= 63; i++)
		cout << '=';
	cout << endl;

	// Перший рядок(з описом інформації в таблиці);
	cout << setw(5) << "||" << setw(4) << "No" << setw(2) << "|" << setw(20) << "Employee" << setw(2) << "|" << setw(8) << "Salary" << setw(2) << "|" << setw(10) << "Withheld" << setw(2) << "|" << setw(9) << "Acrued" << setw(3) << " || " << endl;
	cout << setw(4);
	for (i = 0; i < 64; i++)
		cout << '-';
	cout << endl;
}

void coutenterpr(Employee* enterpr, int h)
{
	int i, j;
	
	title1();
	// Сама таблиця;
	for (j = 0; j < h; j++)
	{
		cout << setw(5) << "||" << setw(4) << j + 1 << setw(2) << "|" << setw(20) << enterpr[j].F << setw(2) << "|" << setw(8) << enterpr[j].Z << setw(2) << "|" << setw(10) << enterpr[j].P << setw(2) << "|" << setw(9) << enterpr[j].S << setw(3) << "||" << endl;
		cout << setw(4);
		for (i = 0; i < 32; i++)
			cout << '-' << setw(2);
		cout << endl;
	}

	// Підсумок таблиці(суми);
	cout << setw(4);
	for (i = 0; i <= 63; i++)
		cout << '=';
	cout << endl;

	cout << setw(5) << "||" << setw(26) << "In total" << setw(2) << "|" << setw(8) << sumZ(enterpr, h) << setw(2) << "|" << setw(10) << sumP(enterpr, h) << setw(2) << "|" << setw(9) << sumS(enterpr, h) << setw(3) << "||" << endl;
	cout << setw(4);
	for (i = 0; i < 32; i++)
		cout << '-' << setw(2);
	cout << endl;
}

void mima_sallar_sort(Employee* enterpr, int h)
{
	int i, j;
	for (i = 1; i < h; i++)
	{
		for (j = 0; j < h - i; j++)
		{
			if (enterpr[j].S > enterpr[j + 1].S)
			{
				swap(enterpr[j], enterpr[j + 1]);
			}
		}
	}
}

void maxactsal(Employee* enterpr, int h, int v)
{
	int i, j;
	int count = 0;
	for (int x = 0; x < h; x++)
	{
		if (enterpr[x].S <= v)
			count++;
	}

	if (count == 0)
		cout << "We don`t have such workers!" << endl;

	if (count > 0)
	{
		title2();
		for (int u = 0; u < h;u++)
		{
			if (enterpr[u].S <= v)
			{
				for (int p = 0; p < h; p++)
				{
					// Сама таблиця;
					cout << setw(5) << "||" << setw(4) << p + 1 << setw(2) << "|" << setw(20) << enterpr[u].F << setw(2) << "|" << setw(8) << enterpr[u].Z << setw(2) << "|" << setw(10) << enterpr[u].P << setw(2) << "|" << setw(9) << enterpr[u].S << setw(3) << "||" << endl;
					cout << setw(4);
					for (i = 0; i < 32; i++)
						cout << '-' << setw(2);
					cout << endl;

					break;
				}
			}
		}
	}
}