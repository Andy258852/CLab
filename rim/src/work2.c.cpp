#include <stdio.h>
#include <conio.h>

void printer(int x)
{	
	if (x >= 10000) {
		while (x >= 10)
		{
			printf("%s", "x");
			x -= 10000;
		}
	}
	else if (x >= 9000) {
		printf("%s", "Mx");
		x -= 9000;
	}
	else if (x >= 5000) {
		printf("%s", "v");
		x -= 5000;
	}
	else if (x >= 4000) {
		printf("%s", "Mv");
		x -= 4000;
	}
	else if (x >= 1000) {
		while (x >= 1000)
		{
			printf("%s", "M");
			x -= 1000;
		}
	}
	else if (x >= 900) {
		printf("%s", "CM");
		x -= 900;
	}
	else if (x >= 500) {
		printf("%s", "D");
		x -= 500;
	}
	else if (x >= 400) {
		printf("%s", "CD");
		x -= 400;
	}
	else if (x >= 100) {
		while (x >= 100)
		{
			printf("%s", "C");
			x -= 100;
		}
	}
	else if (x >= 90) {
		printf("%s", "XC");
		x -= 90;
	}
	else if (x >= 50) {
		printf("%s", "L");
		x -= 50;
	}
	else if (x >= 40) {
		printf("%s", "XL");
		x -= 40;
	}
	else if (x >= 10) {
		while (x >= 10)
		{
			printf("%s", "X");
			x -= 10;
		}
	}
	else if (x >= 9) {
		printf("%s", "IX");
		x -= 9;
	}
	else if (x >= 5) {
		printf("%s", "V");
		x -= 5;
	}
	else if (x >= 4) {
		printf("%s", "IV");
		x -= 4;
	}
	else if (x >= 1) {
		while (x >= 1)
		{
			printf("%s", "I");
			x -= 1;
		}
	}
	if (x != 0)
		printer(x);
}

int main()
{
	int number, checker;
	while (true)
	{
		printf("%s", "Input number <= 10000: ");
		checker = scanf("%i", &number);
		while (getchar() != '\n');
		if (checker == 1)
			if (number <= 10000)
				break;
		printf("%s", "Invalid input, try again\n");
	}
	printf("%s", "Result:");
	printer(number);
	_getch();
}