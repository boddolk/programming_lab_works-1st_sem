#pragma warning(disable : 4996) // for strtok(); (Visual Studio 2022)
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void colontok(char*);

int main()
{
	int n, len;
	cout << "Enter lenth os string:" << endl;
	cin >> n;

	char* str = new char[n] {};
	cout << "Enter srting:" << endl;
	cin.ignore();
	cin.getline(str, n);
	cout << endl;
	len = strlen(str) + 1;
	cout << "String in str ->" << setw(len) << str << endl << endl;
	colontok(str);

	return 0;
}


void colontok(char* str1)
{
	int lenth = strlen(str1) + 1;
	char* strcop1 = new char[lenth] {};
	strcpy_s(strcop1, lenth, str1);
	strcop1 = strtok(strcop1, ":");
	strcat(strcop1, ":");
	int l = strlen(strcop1) + 1;

	cout << "Str after ->" << setw(l) << strcop1 << endl;
}