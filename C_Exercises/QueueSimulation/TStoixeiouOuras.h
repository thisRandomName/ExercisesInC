#ifndef __TStoixeiouOuras__ 
#define __TStoixeiouOuras__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis; /* time of service*/
} TSOuras; /* name TSOuras is used in ATD Oura - not to be changed */

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras testdata);
/* name TSOurasSetValue is used in ATD Oura - not to be changed */

/* All names below indicate that Typos Stoixeiou is Pelatis (Client) */

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos);
int  PelatisGetXronoEisodou(TSOuras stoixeio);
void PelatisSetXronoEksipiretisis(TSOuras *stoixeioPtr,int duration);
int PelatisGetXronoEksipiretis(TSOuras stoixeio);

#endif

