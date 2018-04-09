#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Stack.h"
#include "dStack.h"

using namespace std;

#define DOT '.' 

double ONP();
int IsOper(char c);
int IsDigit(char c);
int prior(char c);
double GetNum();
char GetOper();
void SkipSpaces();
double Calcul(char cOper, double arg1, double arg2);


int main(int argc, char* argv[])
{
	cout << "Podaj wyrazenie: \n";

	cout << "Wartosc wyrazenia wynosi = " << ONP() << "\n\n";

	system("PAUSE");
	return 0;
}

double ONP()
{
	char c;
	StackItem* pStack = NULL;
	DStackItem* pDStack = NULL;

	while ((IsOper(c = GetOper())) || IsDigit(c))
	{
		if (IsOper(c))
		{
			if (c == '(') push(&pStack, c);
			else if (c == ')')
			{
				while ((c = pop(&pStack)) != '(')
				{
					double x = dpop(&pDStack);
					dpush(&pDStack, Calcul(c, dpop(&pDStack), x));
				}
			}
			else
			{
				while (prior(c) <= prior(top(pStack)))
				{
					double x = dpop(&pDStack);
					dpush(&pDStack, Calcul(pop(&pStack), dpop(&pDStack), x));
				}
				push(&pStack, c);//wlozyc na stos wczytany operator
			}
		}
		else if (IsDigit(c))
		{
			ungetc(c, stdin);
			dpush(&pDStack, GetNum());
		}
	}
	while (!isEmpty(pStack))
	{
		double x = dpop(&pDStack);
		dpush(&pDStack, Calcul(pop(&pStack), dpop(&pDStack), x));
	}
	return dpop(&pDStack);
}
int IsOper(char c)
{
	switch (c)
	{
	case'(':
	case')':
	case'+':
	case'-':
	case'*':
	case'/':
	case'^':return 1;
	}
	return 0;
}

int IsDigit(char c) 
{
	return (c >= '0') && (c <= '9');
}

int prior(char c)
{
	switch (c)
	{
	case'+':
	case'-':return 1;
	case'*':
	case'/':return 2;
	case'^':return 3;
	}
	return 0;
}

double GetNum()
{
	char c;
	double res = 0;

	SkipSpaces();
	while (IsDigit(c = getchar()))
		res = res * 10 + (c - '0');
	if (c == DOT)
	{
		double coef = 0.1;
		while (IsDigit(c = getchar()))
		{
			res += (c - '0') * coef;
			coef *= 0.1;
		}
	}
	ungetc(c, stdin);
	return res;
}

char GetOper()
{
	SkipSpaces();
	return getchar();
}

void SkipSpaces()
{
	char c;
	while ((c = getchar()) == ' ');
	ungetc(c, stdin);
}

double Calcul(char cOper, double arg1, double arg2)
{
	switch (cOper)
	{
	case'+': return arg1 + arg2;
	case'-': return arg1 - arg2;
	case'*': return arg1 * arg2;
	case'/': 
		if (fabs(arg2) < 1E-15)
			{
				printf("BLAD, nie dzielimy przez 0!\n\n");
				return INFINITY;
			}
		else
			{
				return arg1 / arg2;
			}
	case'^': return pow(arg1, arg2);

	}
	return 0;
	
}





