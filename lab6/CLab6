#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
	char symbol;
	struct Node* pRight;
	struct Node* pLeft;
};

struct Node* addFrom(int c, struct Node *current)
{
	if (current == NULL)
	{
		struct Node* temp = (struct Node*)malloc(sizeof(temp));
		temp->symbol = c;
		temp->pLeft = temp->pRight = NULL;
		current = temp;
	}
	else if (c >= current->symbol)
	{
		current->pRight = addFrom(c, current->pRight);
	}
	else
	{
		current->pLeft = addFrom(c, current->pLeft);
	}
	return current;
}

void printFrom(struct Node* current)
{
	if (current != NULL) {
		printf("%i ", current->symbol);
		printFrom(current->pRight);
		printFrom(current->pLeft);
	}
}

struct Node* add(struct Node* tree, char c)
{
	return addFrom(c, tree);
}

int showAmountFrom(struct Node* current)
{
	int i = 0;
	if (current != NULL)
	{
		i += showAmountFrom(current->pRight);
		i += showAmountFrom(current->pLeft);
		i++;
	}
	return i;
}

int showAmount(struct Node* tree)
{
	return showAmountFrom(tree);
}

struct Node* insertString(char* s, struct Node* tree)
{
	for (int i = 0; s[i] != '\0'; i++) {
		tree = add(tree, s[i]);
	}
	return tree;
}

struct Node* getNode(char c, struct Node* current, int number)
{
	struct Node* res = NULL;
	if (current != NULL) {
		if(c > current->symbol)
			res = getNode(c, current->pRight, number);
		else if (c < current->symbol)
			res = getNode(c, current->pLeft, number);
		else
		{
			if (number > 0)
				res = getNode(c, current->pRight, number - 1);
			else
				res = current;
		}
	}
	return res;
}

void printNodeNum(char c, struct Node* tree, int number)
{
	if(getNode(c,tree,number) != NULL)
	{
		printf("Number of nodes in the left subtree: ");
		printf("%i",showAmount(getNode(c,tree,number)->pLeft));

		printf("\nNumber of nodes in the right subtree: ");
		printf("%i",showAmount(getNode(c,tree,number)->pRight));
	}
	else
		printf("The %i symbol '%c' isn't found", number + 1, c);
}

char* ScanString();
char* ScanChar();
int ScanInteger();

int main()
{
	char* s = ScanString();
	struct Node* tree = NULL;
	tree = insertString(s, tree);

	char* c = ScanChar();
	printNodeNum(c[0],tree,ScanInteger() - 1);
	free(s);
	free(c);
	getch();
}

int ScanInteger()
{
	int num, checker;
	while(1)
	{
		printf("Input number of this symbol in string: ");
		checker = scanf_s("%i", &num);
		if (checker == 1)
		{
			if (num < 101 && num > 0) {
				while(getchar() != '\n');
				break;
			}
		}
		printf("Invalid input\n");
		while(getchar() != '\n');
	}
	return num;
}

char* ScanChar()
{
	char* s = (char*)malloc(sizeof(char) * 2);
	int checker;
	while (1)
	{
		printf("Input symbol: ");
		checker = scanf_s("%[^\n]", s, 1);
		if (checker == 1)
		{
			while(getchar() != '\n');
			break;
		}
		printf("Invalid input\n");
		while(getchar() != '\n');
	}
	return s;
}

char* ScanString()
{
	char* s = (char*)malloc(sizeof(char) * 101);
	int checker;
	while (1)
	{
		printf("Input string: ");
		checker = scanf_s("%[^\n]", s, 100);
		if (checker == 1)
		{
			while(getchar() != '\n');
			break;
		}
		printf("Invalid input\n");
		while(getchar() != '\n');
	}
	return s;
}
