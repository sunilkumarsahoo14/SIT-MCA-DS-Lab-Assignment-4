// WAP To Evaluate PostFix Operation.

#include <stdio.h>
#include <stdlib.h>
#define size 100

// Function initializations
int evaluate(char p[]);
void push(char arr[], char ele);
char pop(char arr[]);

int top = -1;

// Main Function

int main()
{
	char postfix[200];
	printf("Enter The Postfix String: ");
	scanf("%s", postfix);
	evaluate(postfix);
	return 0;
}

// Evaluate Function
int evaluate(char p[])
{
	char stack[size], a;
	int i, t1, t2, res;
	for (i = 0; p[i] != '\0'; i++)
	{
		if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))
		{
			printf("Enter The Value Of Operand %c: ",p[i]);
			scanf(" %c", &a);
			push(stack, a);
		}
		else if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/')
		{
			t1 = pop(stack);
			t2 = pop(stack);

			switch (p[i])
			{
			case '+':
				res = t2 + t1;
				break;
			case '-':
				res = t2 - t1;
				break;
			case '*':
				res = t2 * t1;
				break;
			case '/':
				res = t2 / t1;
				break;
			}
			push(stack, res);
		}
	}

	res = pop(stack);
	return res;
}

// Push Function...
void push(char arr[], char ele)
{
	if (top == size - 1)
	{
		printf("Stack Is Full!\n");
		return;
	}
	top = top + 1;
	arr[top] = ele;
	return;
}

// Pop Function...
char pop(char arr[])
{
	int x;
	if (top == -1)
	{
		printf("Underflow Condition!\n");
		exit(0);
	}
	x = arr[top];
	top = top - 1;
}
