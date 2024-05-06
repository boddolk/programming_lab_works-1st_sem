#pragma warning(disable : 4996) // for strtok(); (Visual Studio 2022)
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctype.h>

using namespace std;

int oddlength(char*);
void symbcouter(char*);
void brackdetect(char*);

int main()
{
	const int N = 60;
	char str[N] {};
	int len;

	cout << "Enter string: ";
	cin.getline(str, N);
	cout << endl;
	
	len = strlen(str) + 1;
	cout << "String in str:" << setw(len) << str << endl;
	cout << endl;

	cout << "Number of words with an odd number of characters:" << setw(5) << oddlength(str) << endl << endl;
	symbcouter(str);
	cout << endl;
	
	brackdetect(str);
	len = strlen(str) + 1;
	cout << "String in str:" << setw(len) << str << endl << endl;

	return 0;
}

int oddlength(char* str1)
{
	int lenth = strlen(str1) + 1;
	char* strcop1 = new char[lenth] {};
	strcpy(strcop1, str1);
	int count = 0;
	int lattercount = 0;
	int l;

	char* str1Ptr;
	str1Ptr = strtok(strcop1, " ");
	while (str1Ptr != NULL)
	{
		l = strlen(str1Ptr);
		for (int i = 0; i < l; i++)
		{
			if (isalpha(str1Ptr[i]))
			{
				lattercount++;
			}
		}

		if (lattercount % 2 != 0) count++;
		lattercount = 0;
		
		str1Ptr = strtok(NULL, " ");
	}
	delete[] str1Ptr;
	return count;
}


void symbcouter(char* str2)
{
	int lenth = (strlen(str2) + 1);
	char* strcop2 = new char[lenth] {};
	strcpy(strcop2, str2);
	int count = 1;
	int i, j;

	for (int l = 0; l < lenth; l++)
	{
		strcop2[l] = tolower(strcop2[l]);
	}
	for (i = 0; i < lenth; i++)
	{
		if (!isalpha(strcop2[i]))
		{
			continue;
		}
		for (j = i + 1; j < lenth; j++)
		{
			if (strcop2[i] == strcop2[j])
			{
				count++;
				strcop2[j] = 0;
			}
		}
		cout << "Latter:" << setw(2) << strcop2[i] << " would repeat:" << setw(4) << count << endl;
		count = 1;
	}
	delete[] strcop2;
}


void brackdetect(char* str3)
{
	int lenth = strlen(str3) + 1;
	char* strcop3 = new char[lenth] {};
	strcpy_s(strcop3, lenth, str3);

	for (int i = 0; i < lenth; i++)
	{
		if (str3[i] == '(')
		{
			for (int j = i + 1; j < lenth; j++)
			{
				if (str3[j] == ')')
				{
					++j;
					for (i; str3[i] != '\0'; i++)
					{
						strcop3[i] = strcop3[j];
						if (j <= lenth)
						{
							j++;
						}
					}
				}
			}

		}
	}
	strcpy(str3, strcop3);
	delete[] strcop3;
}