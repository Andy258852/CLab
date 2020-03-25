#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

char* ScanString();
char* FirstMove(char*);
char* SecondMove(char*);

int main()
{
	printf("%s", SecondMove(FirstMove(ScanString())));
}

char* SecondMove(char* str)
{
	char list[52];

	for (int i = 0; i < 26; i++)
		list[i] = 97 + i;

	for (int i = 26; i < 52; i++)
		list[i] = 39 + i;

	char checkList[52];
	
	for (int i = 0; i < 52; i++)
		checkList[i] = 0;

	char* res = (char*)malloc(102 * sizeof(char));
	int temp = 0;
	bool flag;

	for (int i = 0; str[i] != '\0'; i++)
	{
		flag = 1;
		for (int k = 0; k < 52; k++)
			if (list[k] == str[i])
			{
				if (checkList[k] == 0)
				{
					checkList[k] = 1;
					res[temp] = str[i];
					temp++;
				}
				flag = 0;
			}
		if (flag == 1)
		{
			res[temp] = str[i];
			temp++;
		}
	}

	for (int i = temp; i < 102; i++)
		res[i] = '\0';

	return res;
}

char* FirstMove(char* str)
{
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
				char temp = str[i - 1];
				str[i - 1] = str[i - count];
				str[i - count] = temp;
			}
			count = 0;
		}
	}
	return str;
}

char* ScanString()
{
	char* str = (char*)malloc(102 * sizeof(char));
	int checker;
	while (true)
	{
		printf("Your Input:\n");
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
