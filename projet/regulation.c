#include <stdio.h>
#include <stdlib.h>
#include "regulation.h"
	 
float regulationTest(int regul,float consigne,float* tabT, int nT){
	float cmd;
	float e;
	float* erreur;
	float integrale=0;
	float derivee=0;
	//kp=1.1 ki=0.2 kd=0.15
	//tout ou rien
	if(regul == 1){
		for(int i=0; i<nT;i++){
			if(tabT[i]<consigne){
				return 50;
			}else{
				return 0;
			}
			
		}

	//PID
	}else if(regul == 2){
	//intégrale : somme erreur
	//dérivée : erreur actuelle - dernière erreur /100
		for(int i=0; i<nT;i++){
			if(tabT[i]<consigne){
				e = consigne - tabT[i];
				erreur[i]=e;
				cmd = 1.1*e + 0.2*integrale + 0.15*derivee ;
				if(i>0){
					for(int j=0;j<i;j++){
						integrale+=tabT[j];
					}
					derivee = (tabT[i]-tabT[i-1])/100;
				}
			}else{
				cmd = 0;
			}
		}
	}
	return cmd;
}

float reg(float consigne,temp_t temp){

	if(temp.interieure<consigne){
		return 50;
	}else{
		return 0;
			}
	}

