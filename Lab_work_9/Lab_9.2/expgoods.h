#pragma once
#include "prototypes.h"

void inputfile(FILE* fcpy1)
{
	if (fopen_s(&fcpy1, "D:\\test92", "wb") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	printf("Enter the number of records\n");
	int a;
	scanf_s("%d", &a);
	cin.ignore();
	EXPGOODS read{};
	for (int i = 1; i <= a; i++)
	{
		printf("Enter the name of the product:\t");
		gets_s(read.prodname, 25);
		printf("Enter the exporter's country:\t");
		gets_s(read.expcountr, 25);
		printf("Enter the quantity of the product:\t");
		scanf_s("%d", &read.quantiti);
		cin.ignore();
		printf("\n");

		fwrite(&read, sizeof(EXPGOODS), 1, fcpy1);
	}
	fclose(fcpy1);
}


void addtofile(FILE* fcpy2)
{
	if (fopen_s(&fcpy2, "D:\\test92", "ab") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	printf("Enter the number of files you want to add:\n");
	int a;
	scanf_s("%d", &a);
	cin.ignore();
	EXPGOODS addition{};
	for (int i = 1; i <= a; i++)
	{
		printf("Enter the name of the product:\t");
		gets_s(addition.prodname);
		printf("Enter the exporter's country:\t");
		gets_s(addition.expcountr);
		printf("Enter the quantity of the product:\t");
		scanf_s("%d", &addition.quantiti);
		cin.ignore();
		printf("\n");

		fwrite(&addition, sizeof(EXPGOODS), 1, fcpy2);
	}
	fclose(fcpy2);
}


void prodnamch(FILE* fcpy3)
{
	char countrname[25]{};
	char oldprod[25]{};
	char newprod[25]{};
	EXPGOODS substitute{};
	printf("Enter the exporter's country:\t");
	gets_s(countrname);
	printf("Enter the name of the product you want to replace:\t");
	gets_s(oldprod);
	printf("Enter new name of product:\t");
	gets_s(newprod);
	int b = (-1) * sizeof(EXPGOODS);
	while (fread(&substitute, sizeof(EXPGOODS), 1, fcpy3))
	{
		if (strcmp(substitute.expcountr, countrname) == 0 && strcmp(substitute.prodname, oldprod) == 0)
		{
			swap(substitute.prodname, newprod);
			fseek(fcpy3, b, 1);
			fwrite(&substitute, sizeof(EXPGOODS), 1, fcpy3);
			break;
		}
	}

}


void countrnamch(FILE* fcpy3)
{
	char prodname1[25]{};
	char oldcountr[25]{};
	char newcountr[25]{};
	EXPGOODS substitute{};
	printf("Enter the name of the country you want to replace:\t");
	gets_s(oldcountr);
	printf("Enter the name of her product:\t");
	gets_s(prodname1);
	printf("Enter new name of country:\t");
	gets_s(newcountr);
	while (fread(&substitute, sizeof(EXPGOODS), 1, fcpy3))
	{
		if (strcmp(substitute.expcountr, oldcountr) == 0 && strcmp(substitute.prodname, prodname1) == 0)
		{
			swap(substitute.expcountr, newcountr);
			fseek(fcpy3, -sizeof(EXPGOODS), 1);
			fwrite(&substitute, sizeof(EXPGOODS), 1, fcpy3);
			break;
		}
	}
}


void quanttch(FILE* fcpy3)
{
	char prodname[25]{};
	char countrname[25]{};
	int newquantt;
	EXPGOODS substitute{};
	printf("Enter the name of the country:\t");
	gets_s(countrname);
	printf("Enter the name of her product:\t");
	gets_s(prodname);
	printf("Enter the new product quantity:\t");
	scanf_s("%d", &newquantt);
	cin.ignore();
	int b = (-1) * sizeof(EXPGOODS);
	while (fread(&substitute, sizeof(EXPGOODS), 1, fcpy3))
	{
		if (strcmp(substitute.expcountr, countrname) == 0 && strcmp(substitute.prodname, prodname) == 0)
		{
			swap(substitute.quantiti, newquantt);
			fseek(fcpy3, b, 1);
			fwrite(&substitute, sizeof(EXPGOODS), 1, fcpy3);
			break;
		}
	}
}


void editfile(FILE* fcpy3)
{
	if (fopen_s(&fcpy3, "D:\\test92", "rb+") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	int a = 0;
	printf("\nSelect what you want to edit:");
	printf("\n\t0 - exit the function");
	printf("\n\t1 - product name");
	printf("\n\t2 - country name");
	printf("\n\t3 - quantity of goods\n");
	scanf_s("%d", &a);
	cin.ignore();
	switch (a)
	{
	case 0: break;
	case 1: prodnamch(fcpy3); break; // редагуванн€ назви продукту;
	case 2: countrnamch(fcpy3); break; // редагуванн€ назви крањни експортера;
	case 3: quanttch(fcpy3); break; // редагуванн€ к≥лькост≥ експортованого товару;
	}
	fclose(fcpy3);
}


void outputfile(FILE* fcpy4)
{
	if (fopen_s(&fcpy4, "D:\\test92", "rb") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	EXPGOODS write;
	int i = 1;
	printf("\n---------------------------------------------------\n||-N-||--Product--||----Country----||--Quantity--||\n---------------------------------------------------\n");
	while (fread(&write, sizeof(EXPGOODS), 1, fcpy4))
	{
		printf("||%3d||%11s||%15s||%12d||\n", i, write.prodname, write.expcountr, write.quantiti);
		i++;
	}
	fclose(fcpy4);
}


void prodstat(FILE* fcpy5)
{
	if (fopen_s(&fcpy5, "D:\\test92", "rb") != NULL)
	{
		printf("File was not detected");
		exit(0);
	}
	EXPGOODS comparison;
	char ourprod[25]{};
	int count = 0;
	printf("Enter the product name to search:\t");
	gets_s(ourprod);

	while (fread(&comparison, sizeof(EXPGOODS), 1, fcpy5))
	{
		if (strcmp(comparison.prodname, ourprod) == 0)
		{
			count++;
		}
	}
	rewind(fcpy5);
	if (count > 0)
	{
		int i = 0;
		int quantsum = 0;
		EXPGOODS* forsort = new EXPGOODS[count]{};
		while (fread(&comparison, sizeof(EXPGOODS), 1, fcpy5))
		{
			if (strcmp(comparison.prodname, ourprod) == 0)
			{
				while (i < count)
				{
					forsort[i] = comparison;
					i++;
					break;
				}
			}
		}
		fclose(fcpy5);
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (int res = strcmp(forsort[i].expcountr, forsort[j].expcountr) < 0)
				{
					swap(forsort[i].expcountr, forsort[j].expcountr);
				}
			}
		}
		printf("\n------------------------------\n||-N-||------|Country|------||\n------------------------------\n");
		for (int i = 0; i < count; i++)
		{
			quantsum += forsort[i].quantiti;
			printf("||%3d||%21s||\n", i + 1, forsort[i].expcountr);
		}
		printf("||General quantity:%9d||\n", quantsum);
		printf("\n");
		delete[] forsort;
	}
	if (count == 0)
	{
		printf("Product was not detected");
		fclose(fcpy5);
	}
}