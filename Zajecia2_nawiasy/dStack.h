
#ifndef _D_STACK_INCLUDE_ 
#define _D_STACK_INCLUDE_   

typedef struct tagDStackItem 
{
	double fKey; 
	tagDStackItem* pNext; 

}DStackItem;



void dpush(DStackItem** , double c);
double dpop(DStackItem** );  
double dtop(DStackItem* );		
void ddel(DStackItem** );		
int disEmpty(DStackItem* );	

#endif
