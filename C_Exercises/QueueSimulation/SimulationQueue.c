#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "Q_Array.h"
#include "TStoixeiouOuras.h"
#include "TTamias.h"

#define K 5

int main(void)
{	TOuras      	oura;				 /*clients'queue*/
	float			pithanotita_afiksis; /*possibility of one client to arrive*/
	unsigned int	xronos_eksipiretisis;/*time of service*/ 
	unsigned int	xronos_prosomoiosis; /*total time of the simulation running*/
	
	unsigned int	xronos;				 /*simulation clock*/
	
	
	unsigned int	xronos_anamonis;	 /*total time of waiting in the queue*/
	TSOuras		Pelatis;		 	/* the client */
	float			mesos_xronos;		 /*average time of waiting in the queue*/
	float			randomAfixi;
	int             tamiasInactive=0;
	time_t			t;
	
	/*max,min*/
	unsigned int   maxXronosEx; /*max time of service*/
	unsigned int   minXronosEx; /*min time of service*/
	
	unsigned int   xronosClose; /* super market closure*/
             int   diafora[K];  
	
        printf("Give the following (5 input elements):\na)units of time for the simulation running (>=0),\nb)possibility that one client arrives in units of time (0<=possibility<=1),\nc)max time of service (>=1)\nd)min time of service (in units of time ),\ntime of closure(less than half of the simulation running time you gave)");
	//printf("Give units of time for the simulation running (0 <=)\n, possibility that one client arrives in units of time (0,1)\n ,max time of service (>=1)\n and min time of service in units of time )\n");
	scanf("%u %f %u %u %u",&xronos_prosomoiosis,&pithanotita_afiksis,&maxXronosEx,&minXronosEx,&xronosClose );
	getchar();
	printf("Simulation will run for %4u units of time.\n",xronos_prosomoiosis);
	printf("Possibility that one client arrives is: %4.2f.\n",pithanotita_afiksis);
	
	/*prints*/
	printf("Max time of service is %d units of time .\n",maxXronosEx);
	printf("Min time of service is %d units of time .\n\n\n",minXronosEx);
	printf("The super market closes at %d units of time!\n\n\n\n\n",xronosClose);
	assert(xronosClose<(xronos_prosomoiosis)/2);   /*check if simulation runs after super market closure*/
	
	/*Epektasi se K Oures kai antistoixa Tamia*/
   int i;
   for (i=1;i<=K;i++) 
   {
    xronos_eksipiretisis= minXronosEx+(rand()%(maxXronosEx-minXronosEx+1)); /*random service time between min and max*/  
	printf("Queue K=%d \n The service time is : %d units of time.(random number between min and max)\n",i,xronos_eksipiretisis);
	xronos = 0;
	xronos_anamonis =0;
	srand(time(&t));

	OuraDimiourgia(&oura);
	TTamias Tamias; /* Cashier */
    TamiasDimiourgia(&Tamias); 
    
	while( xronos < xronos_prosomoiosis )
	{	/* Client  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
			if (!OuraProsthesi(&oura, Pelatis)){
                  printf("The Queue is too small!Simulation stops running\n");
                  getchar();
                  return 0;
        	};
    	};
    	
    	/* Cashier */
    	
		if ( TamiasFree(Tamias))	/*free cashier*/
			if (!OuraKeni(oura))			/*there is a client*/
			{	OuraApomakrynsh(&oura,&Pelatis);		/*client leaves queue / is at the checkout*/
			    
				xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*time of waiting*/
				/* printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
				TamiasNewCustomer(&Tamias);
				TamiasSetXrono(&Tamias,xronos_eksipiretisis); /* kalyptei to trexon unit time */
			}else TamiasNoWork(&Tamias);
		else TamiasSetBusy(&Tamias);		/*busy cashier (there is a client at the checkout */
		
		xronos++; /*running time increases by 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/

	if ( TamiasGetArithmosPelaton(Tamias)== 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((int)TamiasGetArithmosPelaton(Tamias));

	printf("%d clients left the queues\n",TamiasGetArithmosPelaton(Tamias));
	printf("The average waiting time was %4.2f units of time.\n",mesos_xronos);
	printf("The cashier was inactive for %d units of time\n",TamiasGetInactiveXronos(Tamias) );
    getchar();

    /* print*/
    int theRest;     /*clients left waiting*/
    if (xronos_prosomoiosis = xronos)
       theRest=oura.CountIn-TamiasGetArithmosPelaton(Tamias);
	 
    printf("The number of clients left waiting is  %d\n", theRest);
    
    printf("Cashier was busy for %d units of time in total\n",TamiasGetBusyXronos(Tamias));
    
    /*prints CountIn ,CountOut*/
    printf(" %d  clients entered the queue and %d clients left the queue\n\n\n\n\n",oura.CountIn,oura.CountOut);
	assert(oura.CountIn-oura.CountOut==oura.metritis);       /*check */
	
	if(theRest!=0)  /*if there are clients remaining after closure*/
	{
	printf("AFTER super market closes:\nThere are %d clients remaining in the k=%d queue:\n",theRest,i);
    xronos++;  /*time++ so that the simulation continues running after the super market is closed*/ 
    while( theRest!=0 && xronos <xronos_prosomoiosis )  /*apo to xrono pou typika kleinei to souper market mexri to telos tou simulation*/
    { 
     
     if ( TamiasFree(Tamias))	/*free cachier*/
			if (!OuraKeni(oura))			/*there is a client*/
			{	OuraApomakrynsh(&oura,&Pelatis);		/*client is served*/
			    
				xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*time waiting in the queue*/
				TamiasNewCustomer(&Tamias);
				TamiasSetXrono(&Tamias,xronos_eksipiretisis); 
				theRest--; 
			}else TamiasNoWork(&Tamias);
		else TamiasSetBusy(&Tamias);		/*cashier is busy */
	 
	 diafora[i]=xronos-xronosClose;	 /*time the simpulation runs after the super market closure*/
	 xronos++; /*time++*/
	}
	
	 printf("Total working time for the cashier is %d units of time.\n",xronosClose+diafora[i]);
	 printf("Cashier: %d continued working for %d units of time AFTER the typical closure of the super market in order to serve all the remaining clients\n\n\n\n\n\n\n",i,diafora[i]);
     }   
    	
	
    
}
	return 0;
}
    

	




