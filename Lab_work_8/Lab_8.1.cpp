#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct FIRMA 
{
	char NAME[20]; // прізвище працівника;
	char GENDER[6]; // стать працівника;
	int SALARY; // зарплата працівника;
};

void cinagen(FIRMA*, int);
void tolow(char*);
void title();
void coutagen(FIRMA*, int);
void max_salar_sort(FIRMA*, int);
void max_man_salary(FIRMA*, int);

int main()
{
	int n;
	cout << "Enter number of firms: ";
	cin >> n;
	cin.ignore();
	FIRMA* AGENCIA = new FIRMA[n]{};

	cinagen(AGENCIA, n);

	cout << "Before tasks" << endl;
	coutagen(AGENCIA, n);

	cout << "First task" << endl;
	max_salar_sort(AGENCIA, n);

	coutagen(AGENCIA, n);

	cout << "Second task" << endl;
	max_man_salary(AGENCIA, n);

	delete[] AGENCIA;
	return 0;
}


void tolow(char* sentenc) 
{
	int l = (strlen(sentenc) + 1);
	for (int i = 0; i < l; i++)
	{
		sentenc[i] = tolower(sentenc[i]);
	}
}


void cinagen(FIRMA* agencia, int h)
{
	for (int i = 0; i < h; i++)
	{
		cout << "Enter the last name of the worker " << i + 1 << endl;
		cin.getline(agencia[i].NAME, 20);

		cout << "Enter the gender of the worker " << i + 1 << endl;
		cin.getline(agencia[i].GENDER, 6);
		tolow(agencia[i].GENDER);

		cout << "Enter the salary of the worker " << i + 1 << endl;
		cin >> agencia[i].SALARY;
		cin.ignore();

		cout << endl;
	}
}


void title()
{
	int i;

	// Титулка;
	cout << setw(4);
	for (i = 0; i <= 49; i++)
		cout << '=';
	cout << endl;
	cout << setw(15) << "--=" << setw(23) << "Description of workers" << setw(4) << "=--" << endl;
	cout << setw(4);
	for (i = 0; i <= 49; i++)
		cout << '=';
	cout << endl;

	// Перший рядок(з описом інформації в таблиці);
	cout << setw(5) << "||" << setw(4) << "No" << setw(2) << "|" << setw(20) << "Employee" << setw(2) << "|" << setw(7) << "Gender" << setw(2) << "|" << setw(8) << "Salary" << setw(3) << " || " << endl;
	cout << setw(4);
	for (i = 0; i < 50; i++)
		cout << '-';
	cout << endl;
}


void coutagen(FIRMA* agencia, int h)
{
	title();
	for (int i = 0; i < h; i++)
	{
		// Сама таблиця;
		cout << setw(5) << "||" << setw(4) << i + 1 << setw(2) << "|" << setw(20) << agencia[i].NAME << setw(2) << "|" << setw(7) << agencia[i].GENDER << setw(2) << "|" << setw(8) << agencia[i].SALARY << setw(3) << " || " << endl;
		cout << setw(4);
		for (int u = 0; u < 25; u++)
			cout << '-' << setw(2);
		cout << endl;
	}
	cout << endl;
}


void max_salar_sort(FIRMA* agencia, int h)
{
	int i, j;
	for (i = 1; i < h; i++)
	{
		for (j = 0; j < h - i; j++)
		{
			if (agencia[j].SALARY < agencia[j + 1].SALARY)
			{
				swap(agencia[j], agencia[j + 1]);
			}
		}
	}
}


void max_man_salary(FIRMA* agencia, int h)
{
	int gencounter = 0;
	int ind;
	
	for (int i = 0; i < h; i++)
	{
		if (agencia[i].GENDER[0] == 'm')
		{
			gencounter++;
			ind = i;
		}
	}

	if (gencounter == 0)
	{
		cout << "We don`t have any men at the agency." << endl;
	}
 
	if (gencounter > 0)
	{
		title();
		int maxman;
		for (int i = 0; i < h; i++)
		{
			if (agencia[i].GENDER[0] == 'm')
			{
				maxman = i;
				break;
			}
		}

		for (int j = 0; j < h; j++)
		{
			if (agencia[j].GENDER[0] == 'm' && agencia[j].SALARY > agencia[maxman].SALARY)
			{
				maxman = j;
			}
		}
		int r = 0;
		for (int g = 0; g < h; g++)
		{
			if (agencia[g].GENDER[0] == 'm' && agencia[g].SALARY == agencia[maxman].SALARY)
			{
				for (r; r <= gencounter; r++)
				{
					// Сама таблиця;
					cout << setw(5) << "||" << setw(4) << r + 1 << setw(2) << "|" << setw(20) << agencia[g].NAME << setw(2) << "|" << setw(7) << agencia[g].GENDER << setw(2) << "|" << setw(8) << agencia[g].SALARY << setw(3) << " || " << endl;
					cout << setw(4);
					for (int u = 0; u < 25; u++)
						cout << '-' << setw(2);
					cout << endl;
					break;
				}
			}
		}
	}
}