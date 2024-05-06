
// Адаптована тільки під локальний конкретний файл, доречно дозволити користоувачу вводити свій файл

#include "expgoods.h"

int main()
{
	FILE* f1{};
	int a = 1;
	do
	{
		printf("\n\tChoose an action with the file:");
		printf("\n\t0 - exit the program");
		printf("\n\t1 - create the file");
		printf("\n\t2 - add to the file");
		printf("\n\t3 - edit the file"); 
		printf("\n\t4 - read from a file");
		printf("\n\t5 - product statement\n");
		scanf_s("%d", &a);
		cin.ignore();
		switch (a)
		{
		case 1: inputfile(f1); break;
		case 2: addtofile(f1); break;
		case 3: editfile(f1); break;
		case 4: outputfile(f1); break;
		case 5: prodstat(f1); break;
		}
	} 
	while (a != 0);

	return 0;
}