#ifndef __Q_Array__ 
#define __Q_Array__
#include "TStoixeiouOuras.h"


#define QSIZE 1000

typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	
	/* gia to erwtima 2 - epipleon metrites */
	int CountIn; /* counter-elements entering queue */
	int CountOut; /*counter-elements leaving queue*/
	
	
	TSOuras pinakas[QSIZE];	/* array of queue elements */
} TOuras;	   /* New Name of Type Queue */

void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);


int OuraGetSize(TOuras oura);


int OuraGetCountIn(TOuras oura);
int OuraGetCountOut(TOuras oura);


#endif

