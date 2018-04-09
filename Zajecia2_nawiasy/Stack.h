
#ifndef _STACK_INCLUDE_ 
#define _STACK_INCLUDE_   

typedef struct tagStackItem //modul stosu
{
	char cKey; //info
	tagStackItem* pNext; //wsk na nastpeny na stosie

}StackItem;

//typedef StackItem* StackType;

void push(StackItem** pStack, char c); //wloz na stos
char pop(StackItem** pStack);   //zdejmij i zwroc
char top(StackItem* pStack);		//zwroc wart szczytu
void del(StackItem** pStack);		//usun ze szczuti stosu
int isEmpty(StackItem* pStack);		//1 (prawda) gdy stos pusty 0 w przeciwnym wypadku
//tam gdzie modyfikujemy parametry wejscia i wyjscia musimy dac podowjny wskaznik




#endif


