#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <conio.h>

#define pi 3.14159

double ScanE()
{
	while (true)
	{
		printf("%s", "Input e: ");
		int checker;
		double num;
		checker = scanf_s("%lf", &num);
		if (checker == 1)
			if (num <= 1 && num > 0)
				return num;
			else
				printf("%s", "e (0; 1]\n");
		else
			printf("%s", "Invalid Input...\n");
		system("pause");
	}
}

int ScanNum()
{
	int num;
	while (true)
	{
		printf("%s", "Input value: ");
		int checker;
		checker = scanf_s("%i", &num);
		if (checker == 1)
			if (num <= 100000 && num >= -100000)
				break;
			else
				printf("%s", "Too large...\n");
		else
			printf("%s", "Invalid Input...\n");
		system("pause");
	}
	if (num >= 0)
		while (num > 2 * pi)
			num -= 2 * pi;
	else 
		while (num < -2 * pi)
			num += 2 * pi;
	return num;
}

void MyFunc(double x, double e)
{
	double local;
	double rez = 0;
	int k;
	for (k = 1; abs(rez - sin(x)) >= e ; k++)
	{
		double local = 1;
		for (int i = 2 * k - 1; i > 0; i--)
		{
			local *= x;
			local /= (double)i;
		}
		rez += pow(-1, k - 1) * local;
	}
	printf("%.12lf%s%.12lf%s%i", sin(x), "  ", rez, "\n", k);
}

int main()
{
	int value = ScanNum();
	double e = ScanE();
	MyFunc(value, e);
	_getch();
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
