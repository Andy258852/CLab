#include <stdio.h>
#include <cstdlib>

float ScanIndex(int);
void ClearWindow();

struct CPolynom
{
private:
	float index[4];
public:
	CPolynom()
	{
		for (int i = 0; i < 4; i++)
			index[i] = 0;
	}
	void SetIndex(float value, int power)
	{
		if (power >= 0 && power < 4)
			index[power] = value;
	}
	float GetIndex(int power)
	{
		if (power >= 0 && power < 4)
			return index[power];
		else return 0;
	}
	void PrintPolynom()
	{	
		if (index[0] == 0 && index[1] == 0 && index[2] == 0 && index[3] == 0)
			printf("%s", "0");
		else 
		{	

			for (int i = 3; i >= 0; i--)
			{
				if (index[i] != 0)
				{	
					if (index[i] > 0)
					{
						printf("%s", " + ");
						printf("%.2f%s%i", index[i], " * x^", i);
					}
					else
					{
						printf("%s", " - ");
						printf("%.2f%s%i", -index[i], " * x^", i);
					}	
				}	
			}
		}	
		printf("%s", "\n");
		system("pause");
	}
	void ScanPolynom()
	{
		for (int i = 3; i >= 0; i--)
			SetIndex(ScanIndex(i), i);
	}
};

CPolynom sum(CPolynom a, CPolynom b)
{
	CPolynom sum;
	for (int i = 0; i < 4; i++)
		sum.SetIndex(a.GetIndex(i) + b.GetIndex(i), i);
	return sum;
}
void Multi(CPolynom a, CPolynom b)
{
	float arr[7];
	arr[6] = a.GetIndex(3) * b.GetIndex(3);
	arr[5] = a.GetIndex(1) * b.GetIndex(2) + a.GetIndex(2) * b.GetIndex(1);
	arr[4] = a.GetIndex(2) * b.GetIndex(2) + a.GetIndex(1) * b.GetIndex(3) + a.GetIndex(3) * b.GetIndex(1);
	arr[3] = a.GetIndex(0) * b.GetIndex(3) + a.GetIndex(3) * b.GetIndex(0) + a.GetIndex(2) * b.GetIndex(1) + a.GetIndex(1) * b.GetIndex(2);
	arr[2] = a.GetIndex(2) * b.GetIndex(0) + a.GetIndex(0) * b.GetIndex(2) + a.GetIndex(1) * b.GetIndex(1);
	arr[1] = a.GetIndex(0) * b.GetIndex(1) + a.GetIndex(1) * b.GetIndex(0);
	arr[0] = a.GetIndex(0) * b.GetIndex(0);
	
	bool checker = 1;
	for (int i = 0; i < 7; i++)
		if (arr[i] != 0)
		{
			checker = 0;
			break;
		}
	if (checker == 0)
	{
		for (int i = 6; i >= 0; i--)
		{
			if (arr[i] != 0)
			{
				if (arr[i] > 0)
				{
					printf("%s", " + ");
					printf("%.2f%s%i", arr[i], " * x^", i);
				}
				else
				{
					printf("%s", " - ");
					printf("%.2f%s%i", -arr[i], " * x^", i);
				}
			}
		}
	}
	else
		printf("%s", "0");
	printf("%s", "\n");
	system("pause");
}

int NumSize(CPolynom a)
{
	int size = 0;
	for (int i = 3; i >= 0 ; i--)
	{
		if (a.GetIndex(i) != 0)
		{
			size = i+1;
			break;
		}
	}
	return size;
}

CPolynom* Div(CPolynom a, CPolynom b)
{
	CPolynom div;
	CPolynom res;
	int x = NumSize(a);
	int y = NumSize(b);
	if (x > y)
	{		
		for (int i = 0; i <= NumSize(a) - NumSize(b); i++)
		{
			float kof = a.GetIndex(0) / b.GetIndex(0);
			int k;
			for (k = 0; k < 3; k++)
				a.SetIndex(a.GetIndex(k + 1) - b.GetIndex(k + 1) * kof, k);
			div.SetIndex(kof, i);
			//a.SetIndex(0, 3 - i);
		}
		res = a;
	}
	else if(x == y)
	{
		float kof = a.GetIndex(3) / b.GetIndex(3);
		for (int k = 2; k >=0; k--)
			res.SetIndex(a.GetIndex(k) - b.GetIndex(k) * kof, k);
		div.SetIndex(kof, 0);
	}
	else
	{
		res = b;
	}
	CPolynom* arr = new CPolynom[2];
	arr[0] = div;
	arr[1] = res;
	return arr;
}

CPolynom sub(CPolynom a, CPolynom b)
{
	CPolynom sub;
	for (int i = 0; i < 4; i++)
		sub.SetIndex(a.GetIndex(i) - b.GetIndex(i), i);
	return sub;
}

void PrintInfo()
{
	printf("%s", "Created by Andrey Mamonov, 2020, all rights reserved\n");
	system("pause");
}

float ScanIndex(int power)
{
	int checker;
	float num;
	while (true)
		{
			ClearWindow();
			void ClearWindow();
			printf("%s%i%s", "Input index of x^", power, ": ");
			checker = scanf_s("%f", &num);
			while (getchar() != '\n');
			if (checker == 1)
				if (num <= 10000)
					break;
				else printf("%s", "Too large\n");
			else printf("%s", "Invalid output\n");
			system("pause");
		}
	
	return num;
}

void ClearWindow()
{
	system("cls");
}

void ShowPar()
{
	printf("%s", "1) Input\n2) Output\n3) Sum\n4) Substraction\n5) Multiplication\n6) Division\n7) Info\n8) Exit\n\nYour choice: ");
}

void menu(CPolynom a, CPolynom b)
{
	
	char input;
	int num;
	int mod;
	bool exit = 0;
	while (!exit)
	{
		ShowPar();
		mod = scanf_s("%i", &num);
		ClearWindow();
		if(mod == 1)
			switch (num + '0')
			{
			case'1':
				a.ScanPolynom();
				b.ScanPolynom();
				break;
			case'2':
				a.PrintPolynom();
				b.PrintPolynom();
				break;
			case'3':
				sum(a, b).PrintPolynom();
				break;
			case'4':
				sub(a, b).PrintPolynom();
				break;
			case '5':
				Multi(a, b);
				break;
			case '6':
				if (NumSize(b) != 0)
				{
					Div(a, b)[0].PrintPolynom();
					printf("%s", "residue: ");
					Div(a, b)[1].PrintPolynom();
				}
				else
				{
					printf("%s", "Error\n");
					system("pause");
				}
				break;
			case'7':
				PrintInfo();
				break;
			case'8':
				exit = 1;
				break;
			default:
				printf("%s", "Choose another number\n");
				system("pause");
			}
		else
		{
			printf("%s", "Invalid input\n");
			system("pause");
		}
		while (getchar() != '\n');
		ClearWindow();
	}	
}

int main()
{	
	CPolynom a,b;
	menu(a, b);
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
