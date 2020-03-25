#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

char* ScanString();

int main()
{
	FILE *voc, *res;

	//char vocName[] = "vocabulary.txt";
	char* vocName = ScanString();
	char resName[] = "result.txt";

	if ((voc = fopen(vocName, "r")) == NULL || (res = fopen(resName, "w")) == NULL)
	{
		printf("I can't open your file! :(");
		return 0;
	}
	
	char str[10001];
	int temp = 0;
	char current;

	while (fscanf(voc, "%c", &current) == 1)
	{
		if (temp == 9999)
		{
			printf("Too much information in vocabulary file! :(");
			return 0;
		}
		str[temp] = current;
		temp++;
	}
	
	for (int i = temp; i < 10000; i++)
		str[i] = '\0';

	char** vocWord = NULL;
	int* numWord = NULL;
	int* numAmount = NULL;
	int size = 0;

	int temp2;
	int count;
	if (isalpha(str[0]))
		count = 1;
	else
		count = 0;

	for (int i = 1; str[i - 1] != '\0'; i++)
	{
		if (isalpha(str[i]))
			count++;
		else
		{
			if (count > 1)
			{
				size++;
				vocWord = (char**)realloc(vocWord, size * sizeof(char*));
				vocWord[size - 1] = (char*)malloc(count * sizeof(char));
				for (int k = 0; k < count; k++)
					vocWord[size - 1][k] = str[i - count + k];
				numWord = (int*)realloc(numWord, size * sizeof(int));
				numWord[size - 1] = count;
				bool flag = 0;
				
				for (int k = 0; k < size - 1; k++)
				{					
					if (numWord[k] == numWord[size - 1])
					{	
						flag = 1;
						for (int j = 0; j < numWord[k]; j++)
							if (vocWord[size - 1][j] != vocWord[k][j])
							{
								flag = 0;
								break;
							}
						temp2 = k;
						if (flag == 1)
							break;
					}
				}
				numAmount = (int*)realloc(numAmount, size * sizeof(int));
				if (flag == 0)
					numAmount[size - 1] = 1;
				else
				{
					numAmount[size - 1] = 0;
					numAmount[temp2]++;
				}
			}
			count = 0;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (numAmount[i] != 0)
		{
			for (int k = 0; k < numWord[i]; k++)
				putchar(vocWord[i][k]);
			printf("%s%i%s", " - ", numAmount[i], " times\n");
			for (int k = 0; k < numWord[i]; k++)
				putc(vocWord[i][k], res);
			fprintf(res, "%s%i%s", " - ", numAmount[i], " times\n");
		}
	}

	fclose(res);
	fclose(voc);
}

char* ScanString()
{
	char* str = (char*)malloc(102 * sizeof(char));
	int checker;
	while (true)
	{
		printf("Input vocabulary file: ");
		checker = scanf_s("%[^\n]", str, 100);
		if (checker == 1)
			break;
		else
		{
			printf("<= 100 symbols\n");
			while (getchar() != '\n');
		}
	}
	return str;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
