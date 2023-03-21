#include <stdio.h>
#include <stdlib.h>
#include "simulateur.h"
#include "regulation.h"
#include "consigne.h"
int main(){

	//testRegulationTOR();
	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialis�e � 0%
	int i=0; // increment de boucle
	float puissance = 70.0; // puissance de chauffage
	float csg = 20;
	int premiere = 0;
    float erreur_pre = 0;
    float integrale_pre = 0;


	for(i=0;i< 300;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
		visualisationT(temperature);
		csg = consigne(csg);
		printf("test consigne: %f",csg);
		puissance = regulation(2,csg,temperature.interieure,premiere , &erreur_pre , &integrale_pre);
		printf("\ntest puissance: %f\n",puissance);
		premiere++;
		//puissance = regulationTest(2,csg,tabT, nT);

		usleep(100000);
 		///teste consigne consigne(3);

 	}
 	simDestruct(monSimulateur_ps); // destruction de simulateur
 	return EXIT_SUCCESS;
 }


//////////////////////////////////////////////////////////////////////////
// while(1){
// float csg = 1;
// csg = consigne(csg);
// puissance = reg(csg,temperature);
// //visualisationC(puissance);
// //visualisationT(temperature);
// printf("\n%f\n",puissance);
// //temperature=simCalc(puissance,monSimulateur_ps);
// }
///////////////////////////////////////////////////////////////////////////
// 	float deltaT = -0.5;
// 	int nT = 3;
// 	float tabT[nT];
// 	tabT[0] = 19.5;
// 	for (i = 1; i < nT; i++)
// 	{
// 		tabT[i] = tabT[i - 1] + deltaT;
// 	}
	