#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <ctype.h>

char* ScanDigit(void);

struct Node
{
	struct Node* pPrevious;
	struct Node* pNext;
	int value;
};

struct list
{
	struct Node* tail;
	struct Node* head;
	int size;
};

struct list pushFront(struct list a, int value)
{
	if (a.size == 0)
	{
		a.head = a.tail = (struct Node*)malloc(sizeof(struct Node));
		if (a.head == NULL)
		{
			printf("Error");
			exit(0);
		}
		a.head->value = a.tail->value = value;
		a.head->pNext = a.head->pPrevious = a.tail->pNext = a.tail->pPrevious = NULL;
	}
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		if (temp == NULL)
		{
			printf("Error");
			exit(0);
		}
		temp->pNext = a.head;
		temp->pPrevious = NULL;
		temp->value = value;
		a.head->pPrevious = temp;
		a.head = temp;
	}
	a.size++;
	return a;
}

struct list push(struct list a, int value)
{
	if (a.size == 0)
	{
		a.head = a.tail = (struct Node*)malloc(sizeof(struct Node));
		if (a.head == NULL)
		{
			printf("Error");
			exit(0);
		}
		a.head->value = a.tail->value = value;
		a.head->pNext = a.head->pPrevious = a.tail->pNext = a.tail->pPrevious = NULL;
	}
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		if (temp == NULL)
		{
			printf("Error");
			exit(0);
		}
		temp->pPrevious = a.tail;
		temp->pNext = NULL;
		temp->value = value;
		a.tail->pNext = temp;
		a.tail = temp;
	}
	a.size++;
	return a;
}

struct list deleteFirst(struct list a)
{
	if (a.size > 0)
	{
		if (a.size == 1)
		{
			free(a.head);
			a.head = a.tail = NULL;
		}
		if (a.size == 2)
		{
			struct Node* temp = a.head;
			a.tail->pPrevious = NULL;
			a.head = a.tail;
			free(temp);
		}
		else
		{
			struct Node* temp = a.head;
			a.head = a.head->pNext;
			a.head->pPrevious = NULL;
			free(temp);
		}
		a.size--;
	}
	return a;
}

struct list deleteLast(struct list a)
{
	if (a.size > 0)
	{
		if (a.size == 1)
		{
			free(a.head);
			a.head = a.tail = NULL;
		}
		if (a.size == 2)
		{
			struct Node* temp = a.tail;
			a.head->pNext = NULL;
			a.tail = a.head;
			free(temp);
		}
		else
		{
			struct Node* temp = a.tail;
			a.tail = a.tail->pPrevious;
			a.tail->pNext = NULL;
			free(temp);
		}
		a.size--;
	}
	return a;
}

int at(struct list a, int num)
{
	struct Node* current;
	if (num < a.size / 2)
	{
		current = a.head;
		for (int i = 0; i < num; i++)
		{
			current = current->pNext;
		}
	}
	else
	{
		current = a.tail;
		for (int i = a.size - 1; i > num; i--)
		{
			current = current->pPrevious;
		}
	}
	return current->value;
}

struct list clear(struct list a)
{
	if (a.size > 0)
	{
		int temp = a.size;
		for (int i = 0; i < temp - 1; i++)
			a = deleteFirst(a);
		free(a.head);
		a.head = a.tail = NULL;
		a.size = 0;
	}
	return a;
}

struct digit
{
	int sign;
	struct list root;
};

struct list sum(struct list a, struct list b)
{
	int current;
	int old = 0;
	struct list temp = { NULL,NULL,0 };
	for (int i = 0;; i++)
	{
		if (i >= a.size && i >= b.size)
		{
			if (old == 1)
				temp = pushFront(temp, 1);
			break;
		}
		current = 0;
		if (a.size - 1 - i >= 0)
			current += at(a, a.size - 1 - i);
		if (b.size - 1 - i >= 0)
			current += at(b, b.size - 1 - i);
		current += old;
		old = 0;

		if (current > 9)
		{
			current %= 10;
			old++;
		}
		temp = pushFront(temp, current);
	}
	return temp;
}

struct list cutZero(struct list a)
{
	while (1)
	{
		if (at(a, 0) == 0 && at(a, 0) != a.size - 1)
			a = deleteFirst(a);
		else
			break;

	}
	return a;
}

struct list sub(struct list a, struct list b)
{
	int current;
	int old = 0;
	struct list temp = { NULL,NULL,0 };
	for (int i = 0; i < a.size || i < b.size; i++)
	{
		current = 0;
		if (a.size - 1 - i >= 0)
			current += at(a, a.size - 1 - i);
		if (b.size - 1 - i >= 0)
			current -= at(b, b.size - 1 - i);
		current -= old;
		old = 0;

		if (current < 0)
		{
			current += 10;
			old++;
		}
		temp = pushFront(temp, current);
	}
	return temp;
}
struct list multnum(struct list a, int num)
{
	struct list res = { NULL,NULL,0 };
	res = push(res, 0);
	for (int i = 0; i < num; i++)
		res = sum(res, a);
	return res;
}

struct list mult(struct list a, struct list b)
{
	struct list res = { NULL,NULL,0 };
	res = push(res, 0);
	struct list temp;
	for (int i = 0; i < a.size; i++)
	{
		temp = multnum(b, at(a, a.size - 1 - i));
		for (int k = 0; k < i; k++)
			temp = push(temp, 0);
		res = sum(res, temp);
	}
	return res;
}

int isbigger(struct list a, struct list b)
{
	int flag = 1;
	if (a.size > b.size)
		flag = 1;
	else if (a.size < b.size)
		flag = 0;
	else
	{
		for (int i = 0; i < a.size; i++)
		{
			if (at(a, i) > at(b, i))
			{
				flag = 1;
				break;
			}
			if (at(a, i) < at(b, i))
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

struct list* div(struct list a, struct list b)
{
	struct list res = { NULL, NULL, 0 };
	res = push(res, 0);
	struct list local = { NULL, NULL, 0 };
	struct list temp = { NULL, NULL, 0 };
	int counter;

	struct list arr[2];

	while (isbigger(a, b) == 1)
	{
		counter = 0;
		local = clear(local);
		local = push(local, 1);
		temp = clear(temp);
		for (int i = 0; i < b.size; i++)
			temp = push(temp, at(b, i));
		while (isbigger(push(temp, 0), a) == 0)
		{
			temp = push(temp, 0);
			counter++;
		}

		a = cutZero(sub(a, temp));
		for (int i = 0; i < counter; i++)
			local = push(local, 0);
		for (int i = 0; i < counter; i++)
			temp = push(temp, 0);
		res = sum(res, local);
	}
	arr[0] = res;
	arr[1] = a;
	clear(local);
	clear(temp);
	return arr;
}

struct digit* LongDivLong(struct digit a, struct digit b)
{
	struct digit res[2];

	if ((a.sign == 1 && b.sign == 1) || (a.sign == 0 && b.sign == 0))
	{
		res[0] = { 1, div(a.root, b.root)[0] };
	}
	else
	{
		if (isbigger(a.root, b.root))
			res[0] = { 0, div(a.root, b.root)[0] };
		else
			res[0] = { 1, div(a.root, b.root)[0] };
	}
	res[1] = { 1, div(a.root, b.root)[1] };
	return res;
}

struct digit LongMulLong(struct digit a, struct digit b)
{
	struct digit res;
	if ((a.sign == 1 && b.sign == 1) || (a.sign == 0 && b.sign == 0))
	{
		res = { 1, mult(a.root, b.root) };
	}
	else
	{
		res = { 0, mult(a.root, b.root) };
	}
	res.root = cutZero(res.root);
	if (res.root.size == 1 && at(res.root, 0) == 0)
		res.sign = 1;
	return res;
}

struct digit LongSumLong(struct digit a, struct digit b)
{
	struct digit res;
	if (a.sign == 1 && b.sign == 1)
	{
		res = { 1, sum(a.root, b.root) };
	}
	else if (a.sign == 0 && b.sign == 0)
	{
		res = { 0, sum(a.root, b.root) };
	}
	else if (a.sign == 1 && b.sign == 0)
	{
		if (isbigger(a.root, b.root))
			res = { 1, cutZero(sub(a.root, b.root)) };
		else
			res = { 0, cutZero(sub(b.root, a.root)) };
	}
	else if (a.sign == 0 && b.sign == 1)
	{
		if (isbigger(a.root, b.root))
			res = { 0, cutZero(sub(a.root, b.root)) };
		else
			res = { 1, cutZero(sub(b.root, a.root)) };
	}
	if (res.root.size == 1 && at(res.root, 0) == 0)
		res.sign = 1;
	return res;
}

struct digit LongSubLong(struct digit a, struct digit b)
{
	struct digit res;
	if (a.sign == 1 && b.sign == 0)
	{
		res = { 1, sum(a.root, b.root) };
	}
	else if (a.sign == 0 && b.sign == 1)
	{
		res = { 0, sum(a.root, b.root) };
	}
	else if (a.sign == 1 && b.sign == 1)
	{
		if (isbigger(a.root, b.root))
			res = { 1, cutZero(sub(a.root, b.root)) };
		else
			res = { 0, cutZero(sub(b.root, a.root)) };
	}
	else if (a.sign == 0 && b.sign == 0)
	{
		if (isbigger(a.root, b.root))
			res = { 0, cutZero(sub(a.root, b.root)) };
		else
			res = { 1, cutZero(sub(b.root, a.root)) };
	}
	if (res.root.size == 1 && at(res.root, 0) == 0)
		res.sign = 1;
	return res;
}

struct digit GetDigit();

int main()
{
	struct digit a = GetDigit();
	struct digit b = GetDigit();

	struct list temp = LongSumLong(a, b).root;

	printf("a + b = ");
	if (LongSumLong(a, b).sign == 0)
		printf("-");
	for (int i = 0; i < temp.size; i++)
		printf("%i", at(temp, i));
	clear(temp);

	temp = LongSubLong(a, b).root;

	printf("\na - b = ");
	if (LongSubLong(a, b).sign == 0)
		printf("-");
	for (int i = 0; i < temp.size; i++)
		printf("%i", at(temp, i));
	clear(temp);

	temp = LongMulLong(a, b).root;

	printf("\na * b = ");
	if (LongMulLong(a, b).sign == 0)
		printf("-");
	for (int i = 0; i < temp.size; i++)
		printf("%i", at(temp, i));
	clear(temp);

	if (b.root.size == 1 && at(b.root, 0) == 0)
		printf("\nDivision by zero is impossible");
	else
	{
		temp = LongDivLong(a, b)[0].root;

		printf("\na / b = ");
		if (LongDivLong(a, b)[0].sign == 0)
			printf("-");
		for (int i = 0; i < temp.size; i++)
			printf("%i", at(temp, i));
		clear(temp);

		temp = LongDivLong(a, b)[1].root;

		printf("\na %c b = ", '%');
		if (LongDivLong(a, b)[1].sign == 0)
			printf("-");
		for (int i = 0; i < temp.size; i++)
			printf("%i", at(temp, i));
		clear(temp);
	}
}

struct digit GetDigit()
{
	char* first = ScanDigit();
	int i;
	if (isdigit(first[0]))
		i = 0;
	else
		i = 1;

	struct list temp = { NULL,NULL,0 };

	for (; first[i] != '\0'; i++)
		temp = push(temp, first[i] - '0');

	int sign = 1;
	if (first[0] == '-')
		sign = 0;
	struct digit a = { sign,temp };

	return a;
}

char* ScanDigit(void)
{
	int checker;
	int flag;
	char* str = (char*)malloc(sizeof(char) * 101);
	if (str == NULL)
	{
		printf("Error");
		exit(0);
	}
	while (1)
	{
		printf("Input digit: ");
		checker = scanf_s("%s", str, 100);
		if (checker == 1)
		{
			flag = 1;
			for (int i = 1; str[i] != '\0'; i++)
			{
				if (!isdigit(str[i]))
				{
					flag = 0;
					break;
				}
			}

			if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
				flag = 0;

			if (flag == 1)
			{
				while (getchar() != '\n');
				return str;
			}
		}
		while (getchar() != '\n');
		printf("Invalid input\n");
	}
}
