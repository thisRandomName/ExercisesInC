#ifndef __TTamias__ 
#define __TTamias__

typedef struct {
	int enapomenonXronos; /*time left UNTIL one client is served/checks out*/
	int TimeBusy; /*TOTAL time of cashier being busy*/
	int TimeInactive; /*TOTAL time of cashier being inactive*/
	int ArithmosPelaton; /*total number of clients of one cashier*/ 
}TTamias;                /*cashier*/


void TamiasDimiourgia(TTamias *Tamias);
void TamiasNewCustomer(TTamias *Tamias);
void TamiasSetXrono(TTamias *Tamias,int XronosEksipiretisis);
void TamiasSetBusy(TTamias *Tamias);
void TamiasNoWork(TTamias *Tamias);

int TamiasFree(TTamias Tamias);
int TamiasGetArithmosPelaton(TTamias Tamias);
int TamiasGetInactiveXronos(TTamias Tamias);
int TamiasGetBusyXronos(TTamias Tamias);



#endif
