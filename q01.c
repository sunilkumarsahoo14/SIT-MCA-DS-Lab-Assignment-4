// Wap to convert infix expression to postfix expression.

#include <stdlib.h>
#include <stdio.h>
#define size 100
int top = -1;

// Function Declarations...
int prec(char c);
void infix_to_postfix(char in[], char po[]);
void push(char arr[], char ele);
char pop(char arr[]);

// Main Fuinction...
int main()
{
	char infix[200], postfix[200];
	printf("Enter The Infix String: ");
	scanf("%s", infix);
	infix_to_postfix(infix, postfix);
	printf("Postfix: %s", postfix);
	return 0;
}

// infix To postfix Function
void infix_to_postfix(char in[], char po[])
{
	int i, k = 0, temp;
	char st[size];
	for (i = 0; in[i]; i++)
	{
		if (in[i] >= 'a' && in[i] <= 'z' || in[i] >= 'A' && in[i] <= 'Z')
		{
			po[k] = in[i];
			k++;
		}
		else if (in[i] == '(')
		{
			push(st, in[i]);
		}
		else if (in[i] == ')')
		{
			while (top != -1 && st[top] != '(')
			{
				po[k++] = pop(st);
			}
			temp = pop(st);
		}
		else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '^')
		{
			while ((top != -1) && (prec(st[top]) >= prec(in[i])))
			{
				po[k++] = pop(st);
			}
			push(st, in[i]);
		}
	}

	while (top != -1)
	{
		po[k++] = pop(st);
	}
	po[k++] = '\0';
}

// Precedence Function
int prec(char c)
{
	if (c == '+' || c == '-')
	{
		return 2;
	}
	else if (c == '^')
	{
		return 4;
	}
	else if (c == '*' || c == '/')
	{
		return 3;
	}
	else if (c == '(')
	{
		return 1;
	}
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
	return x;
}
 