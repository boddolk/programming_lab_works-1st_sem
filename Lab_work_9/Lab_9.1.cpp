
// Адаптована тільки під локальний конкретний файл, доречно дозволити користоувачу вводити свій файл

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void basic1(FILE*);
void basic2(FILE*);
void passdetect(FILE*, FILE*);
void firsttolast(FILE*);

int main()
{
	FILE* f1{};
	FILE* f2{};
	printf("Before:\n");
	basic1(f1);

	passdetect(f1, f2);

	printf("After 1-st function:\n");
	basic2(f2);

	firsttolast(f2);

	printf("After 2-nd function:\n");
	basic2(f2);

	return 0;
}

//функція для виводу початкового файла;
void basic1(FILE* fcp1)
{
	char str1[285];
	if (fopen_s(&fcp1, "D:\\test.txt", "rt") != NULL)
	{
		printf("File wos not detected");
		exit(0);
	}
	while (fgets(str1, sizeof(str1), fcp1) != 0)
	{
		printf("%s\n\n", str1);
	}
	fclose(fcp1);
}

//функція для виводу зміненого файла;
void basic2(FILE* fcp2)
{
	char str2[285];
	if (fopen_s(&fcp2, "D:\\test2.txt", "rt") != NULL)
	{
		printf("File wos not detected");
		exit(0);
	}
	while (fgets(str2, sizeof(str2), fcp2) != 0)
	{
		printf("%s\n\n", str2);
	}
	fclose(fcp2);
}

//видаляє пропуски та перезаписує в інший файл;
void passdetect(FILE* fcp1, FILE* fcp2)
{
	char cpy1[285];
	if (fopen_s(&fcp1, "D:\\test.txt", "rt") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	int lenth;
	while (fgets(cpy1, sizeof(cpy1), fcp1) != 0)
	{
		lenth = strlen(cpy1) + 1;

		for (int i = 0; i <= lenth; i++)
		{
			if (cpy1[i] == ' ')
			{
				if (cpy1[i + 1] == ' ')
				{
					for (int p = i + 1, j = i + 2; cpy1[p] != '\0'; p++)
					{
						cpy1[p] = cpy1[j];
						if (j <= lenth) j++;
					}
					i--;
				}
			}
		}
	}
	fclose(fcp1);

	if (fopen_s(&fcp2, "D:\\test2.txt", "w") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	fwrite(cpy1, strlen(cpy1), 1, fcp2);
	fclose(fcp2);
}

//доставляє першу букву останьою;
void firsttolast(FILE* fcp2)
{
	char cpy2[285];
	if (fopen_s(&fcp2, "D:\\test2.txt", "r") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	int lenth;
	int count = 0;
	while (fgets(cpy2, sizeof(cpy2), fcp2) != 0)
	{
		char fiel;
		lenth = strlen(cpy2) + 1;
		int i;
		for (i = 0; i <= lenth; i++)
		{
			if (isalpha(cpy2[i]))
			{
				fiel = cpy2[i];
				count++;
				break;
			}
		}
		if (count == 0)
		{
			printf("We don`t have any laters :(");
		}
		if (count > 0)
		{
			for (int j = i; j < lenth; j++)
			{
				if (isalpha(cpy2[j]) || cpy2[j] == '`')
				{
					if (!(isalpha(cpy2[j + 1])) && cpy2[j + 1] != '`')
					{
						cpy2[j] = fiel;
						continue;
					}

					cpy2[j] = cpy2[j + 1];
				}
				if (!(isalpha(cpy2[j])) && cpy2[j] != '`')
					fiel = cpy2[j + 1];
					continue;
			}
		}

	}
	fclose(fcp2);

	if (count > 0)
	{
		if (fopen_s(&fcp2, "D:\\test2.txt", "w") != NULL)
		{
			printf("File was not detected");
			exit(0);
		}
		fwrite(cpy2, strlen(cpy2), 1, fcp2);
		fclose(fcp2);
	}
}