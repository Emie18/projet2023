#include "regulation.h"

float regulation( int regul , float consigne ,	float temperature , int premiere , float* erreur_pre , float* integrale_pre ){
	float cmd;
	float e;
	float integrale=0;
	float derivee=0;

	//kp=1.1 ki=0.2 kd=0.15
	//tout ou rien
	if(regul == 1){
		if(temperature<consigne){
			cmd = 50;
		}else if(temperature>=consigne){
			cmd = 0;
		}
	return cmd;
	//PID
	}else if(regul == 2){
		e = consigne - temperature;
		//si l'erreur est negatif on retourn cmd = 0;
		if(e<0){
			return 0;
		}
		if(premiere != 0){
            if(temperature<consigne){
                integrale = (e + *erreur_pre)*10/2 + *integrale_pre;
                derivee = (e - *erreur_pre)/10;
               
                *erreur_pre = e;
                *integrale_pre = integrale;
				 cmd = 1.1*e + 0.2*integrale + 0.15*derivee;

				 if(cmd>100){
					cmd = 100;
				 }
				 if(cmd<0){
					cmd=0;
				 }
            }
        }else{
			cmd = 1.1*e;
			*erreur_pre = e;
            *integrale_pre = integrale;
		}
		return cmd;
    }
}


float regulationTest(int regul,float consigne,float* tabT, int nT){
    float cmd=100.0;
    int premiere = 0;
    float erreur_pre = 0;
    float integrale_pre = 0;

    for(int i=0;i<nT;i++){
        cmd = regulation(regul ,consigne ,tabT[i] , premiere , &erreur_pre , &integrale_pre);
        premiere++;
    }

    return cmd;

}