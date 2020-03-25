#include <stdio.h>
#include <malloc.h>

int ScanInt(void);
int ScanBool(void);

int main()
{
	int x, y, z;
	x = ScanInt();
	y = ScanInt();
	z = ScanInt();

	bool*** arr = (bool***)malloc(z * sizeof(bool**));
	for (int i = 0; i < z; i++)
	{
		arr[i] = (bool**)malloc(y * sizeof(bool*));
		for (int k = 0; k < y; k++)
			arr[i][k] = (bool*)malloc(x * sizeof(bool));
	}

	for (int i = 0; i < z; i++)
		for (int k = 0; k < y; k++)
			for (int j = 0; j < x; j++)
				arr[i][k][j] = ScanBool();

	printf("\n");

	bool** res = (bool**)malloc(y * sizeof(bool*));
	for (int i = 0; i < y; i++)
		res[i] = (bool*)malloc(x * sizeof(bool));

	for (int k = 0; k < y; k++)
		for (int j = 0; j < x; j++)
			res[k][j] = 0;

	for (int i = 0; i < z; i++)
		for (int k = 0; k < y; k++)
			for (int j = 0; j < x; j++)
				if (arr[i][k][j] == 1)
					res[k][j] = 1;

	for (int k = 0; k < y; k++)
	{
		for (int j = 0; j < x; j++)
			printf("%d ", res[k][j]);
		printf("\n");
	}

	for (int i = y - 1; i >= 0; i--)
		free(res[i]);
	free(res);

	printf("\n");

	bool** res1 = (bool**)malloc(z * sizeof(bool*));
	for (int i = 0; i < z; i++)
		res1[i] = (bool*)malloc(y * sizeof(bool));

	for (int k = 0; k < z; k++)
		for (int j = 0; j < y; j++)
			res1[k][j] = 0;

	for (int i = 0; i < x; i++)
		for (int k = 0; k < z; k++)
			for (int j = 0; j < y; j++)
				if (arr[k][j][i] == 1)
					res1[k][j] = 1;

	for (int k = z - 1; k >= 0; k--)
	{
		for (int j = 0; j < y; j++)
			printf("%d ", res1[k][j]);
		printf("\n");
	}

	for (int i = 0; i < z; i++)
		free(res1[i]);
	free(res1);

	printf("\n");

	bool** res2 = (bool**)malloc(z * sizeof(bool*));
	for (int i = 0; i < z; i++)
		res2[i] = (bool*)malloc(x * sizeof(bool));

	for (int k = 0; k < z; k++)
		for (int j = 0; j < x; j++)
			res2[k][j] = 0;

	for (int i = 0; i < y; i++)
		for (int k = 0; k < z; k++)
			for (int j = 0; j < x; j++)
				if (arr[k][i][j] == 1)
					res2[k][j] = 1;

	for (int k = z - 1; k >= 0; k--)
	{
		for (int j = 0; j < x; j++)
			printf("%d ", res2[k][j]);
		printf("\n");
	}

	for (int i = 0; i < z; i++)
		free(res2[i]);
	free(res2);
	
	for (int i = 0; i < z; i++)
		for (int k = 0; k < y; k++)
			free(arr[i][k]);
	for (int i = 0; i < z; i++)
		free(arr[i]);
	free(arr);
}

int ScanInt(void)
{
	int num, check;
	while (true)
	{
		check = scanf_s("%i", &num);
		if (check == 1)
			if (num < 1000)
				break;
			else
				printf("Too big!!! Input < 1000...");
		else
			printf("Invalid Input");
	}
	return num;
}

int ScanBool(void)
{
	int num, check;
	while (true)
	{
		check = scanf_s("%i", &num);
		if (check == 1)
			if (num == 1 || num == 0)
				break;
			else
				printf("Too big!!! 1 or 0...");
		else
			printf("Invalid Input");
	}
	return num;
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
