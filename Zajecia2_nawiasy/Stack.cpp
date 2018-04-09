
#include <iostream>
#include <stdlib.h> //dla malloca biblioteka
#include "Stack.h" //musi byc interfejs
 //bedziemy uzywac standtarowego wejscia i wyjscia


using namespace std;



//StackItem* pHead = NULL; //!!!!!! wskaźnik musi byc zainicjowany, WAZNE, inicjuje NULLem albo od razu wskauzje na coś, zNUllem wskazujemy na to, że stos jest pusty

void push(StackItem** pHead, char c) //do kazdej funkcji przekazuje wskaznik stosu
{
	StackItem* p = (StackItem*)malloc(sizeof(StackItem)); //informujemy ile bajtów przydzielić, mozemy skorzystac z funkcji sizeof, musimy zrzutowac funkcje alloc do rodzaju zmiennej stackitem, teraz musimy wyzerowac przydzielona pamiec
	if (p) //p jest adresem, jezeli nie wskazuje nigdzie, to wyjdzie null
	{
		memset(p, 0, sizeof(StackItem)); //'pudelko' zostalo wyzerowane, po mallocu musimy uzyc memseta
		p->cKey = c; //informacja(?)
		p->pNext = *pHead; //dowiazanie nowego elementu listy
		*pHead = p;
	}
	else
		perror("ERROR\n\n");
}

char pop(StackItem** pHead) //zmieniamy rodzaj gdy bierzemy liczbe np int albo double
{
	char c = 0;
	if (!isEmpty(*pHead))
	{
		c = top(*pHead);
		del(pHead);
	}
	else
		perror("ERROR: Stack underflow \n\n");
	return c;

}

char top(StackItem* pHead)
{
	if (!isEmpty(pHead))
		return pHead->cKey; //zwraca szczytowy element
	return 0;
}
void del(StackItem** pHead) //usuniecie elementu
{
	if (!isEmpty(*pHead))
	{
		StackItem* p = *pHead;
		*pHead = p->pNext;
		free(p); //usuwamy
	}
	else
		perror("ERROR: Stack underflow\n");
}
int isEmpty(StackItem* pHead)
{
	return !pHead;
}

