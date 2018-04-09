#include <iostream>
#include <stdlib.h> //dla malloca biblioteka
#include "dStack.h" //musi byc interfejs
//bedziemy uzywac standtarowego wejscia i wyjscia


using namespace std;

//DStackItem* pDHead = NULL; //!!!!!! wskaźnik musi byc zainicjowany, WAZNE, inicjuje NULLem albo od razu wskauzje na coś, zNUllem wskazujemy na to, że stos jest pusty


void dpush(DStackItem** pDStack, double x)
{
	DStackItem* p = (DStackItem*)malloc(sizeof(DStackItem)); //informujemy ile bajtów przydzielić, mozemy skorzystac z funkcji sizeof, musimy zrzutowac funkcje alloc do rodzaju zmiennej stackitem, teraz musimy wyzerowac przydzielona pamiec
	if (p) //p jest adresem, jezeli nie wskazuje nigdzie, to wyjdzie null
	{
		memset(p, 0, sizeof(DStackItem)); //'pudelko' zostalo wyzerowane
		p->fKey = x; //informacja(?)
		p->pNext = *pDStack; //dowiazanie nowego elementu listy
		*pDStack= p;
	}
	else
		perror("ERROR\n\n");
}


double dpop(DStackItem** pDHead) //zmieniamy rodzaj gdy bierzemy liczbe np int albo double
{
	double d = 0; 
	if (!disEmpty(*pDHead))
	{
		d = dtop(*pDHead);
		ddel(pDHead);
	}
	else
		perror("ERROR: Stack underflow \n\n");
	return d;

}
double dtop(DStackItem* pDHead)
{
	if (!disEmpty(pDHead))
		return pDHead->fKey;
	else
		perror("ERROR: Stack underflow\n");
	
	return 0;
}
void ddel(DStackItem** pDHead) //usuniecie elementu z listy
{
	if (!disEmpty(*pDHead))
	{
		DStackItem* p = *pDHead;
		*pDHead = p->pNext;
		free(p); //usuwamy
	}
	else
		perror("ERROR: Stack underflow\n");
}
int disEmpty(DStackItem* pDHead)
{
	return !pDHead;
}