// WAP to check whether a expression is having balanced parenthesis or not.

#include <stdio.h>
#define size 100
#include <stdlib.h>

int top = -1;

void check(char exp[])
{
	char st[size], ch;
	int i;
	for (i = 0; exp[i]; i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			push(st, exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (top == -1)
			{
				printf("More Number Of Right Parenthesis!\n");
				return;
			}
			ch = pop(st);
			if ((exp[i] == ')' && ch != '(') ||
				(exp[i] == ']' && ch != '[') ||
				(exp[i] == '}' && ch != '{'))
			{
				printf("Mismatch Parenthesis!\n");
				return;
			}
		}
	}
	if (top != -1)
	{
		printf("Mopre Number Of Left Parenthesis!\n");
	}
	else
	{
		printf("Valid Expression");
	}
}

// Function Definitions..

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
