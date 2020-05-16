#include <stdio.h>
#include <stdlib.h>
#include "TTamias.h"

void TamiasDimiourgia(TTamias *Tamias) /*initializes  struct Tamias*/
{
	Tamias->enapomenonXronos=0;
	Tamias->TimeBusy=0;
	Tamias->TimeInactive=0;
	Tamias->ArithmosPelaton=0;
}

void TamiasNewCustomer(TTamias *Tamias) /*increases by 1 clients that have checked out*/
{
	Tamias->ArithmosPelaton++;
}

void TamiasSetXrono(TTamias *Tamias,int XronosEksipiretisis) 
{
	Tamias->enapomenonXronos=XronosEksipiretisis;
}

void TamiasSetBusy(TTamias *Tamias) /*auxanei to xrono apasxolisis tamia kata 1 kai meiwnei ton enapomeinanta kata 1*/
{
	Tamias->TimeBusy++;
	Tamias->enapomenonXronos--;
	
}

void TamiasNoWork(TTamias *Tamias) /*increases time inactive by 1*/
{
	Tamias->TimeInactive++;
	
}

int TamiasFree(TTamias Tamias) /*check if cashier is free */
{
	return (Tamias.enapomenonXronos==0 );
}

int TamiasGetArithmosPelaton(TTamias Tamias) /*returns number of clients */
{
	return Tamias.ArithmosPelaton;
}

int TamiasGetInactiveXronos(TTamias Tamias) /*returns time inactive*/
{
	return Tamias.TimeInactive;
}

int TamiasGetBusyXronos(TTamias Tamias) /*returns total time of service of cashier's clients/cashier being busy*/
{
	return Tamias.TimeBusy;
}




