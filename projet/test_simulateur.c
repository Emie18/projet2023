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
	float deltaT = -0.5;
	int nT = 3;
	float tabT[nT];
	tabT[0] = 19.5;
	for (i = 1; i < nT; i++)
	{
		tabT[i] = tabT[i - 1] + deltaT;
	}
	

	for(i=0;i< 300;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
		visualisationT(temperature);
		csg = consigne(csg);
		printf("test consigne %f",csg);
		puissance = reg(csg,temperature);
		//puissance = regulationTest(2,csg,tabT, nT);
		printf("test consigne %f",puissance);
		usleep(100000);
		///teste consigne consigne(3);

	}
	simDestruct(monSimulateur_ps); // destruction de simulateur
	return EXIT_SUCCESS;
}

//int main(){
/////////////////////////////////////////////
// int i =0 ;
// while(i!=1000){
// while(1){
// usleep(500);
//float csg = consigne(0);
//  float temparature[3]= {10,10,11};
//  float cmd = regulationTest(2,28,temparature,7);
//  printf("cmd : %f",cmd);
// temp_t nouveau;
// nouveau.interieure = csg;
// nouveau.exterieure = 5;

// visualisationT(nouveau);
// }
//////////////////////////////////////////////////////////
//i++;
//}
// float score1=0,score2=0,score3=0,score4=0,score5=0;
// score1 = testVisualisationT();
// score2 = testConsigne();
// score3 = testVisualisationC();
// score4 = testRegulationTOR();
// score5 = testRegulationPID();
// printf("----- Auto tests results: -----\n");
// printf("testVisualisationT\t:score=%g%%\n",score1*100);
// printf("testConsigne \t\t: score=%g %%\n",score2*100);
// printf("testVisualisationC\t:score=%g %%\n",score3*100);
// printf("testRegulationTOR\t:score=%g %%\n",score4*100);
// printf("testRegulationPID\t:score=%g %%\n",score5*100);
// return EXIT_SUCCESS;
//}