#include "define.h"
#include "releve.h"
#include "commande.h"
#include "regulation.h"
#include "consigne.h"
#include "visualisationT.h"
#include "visualisationC.h"
int main(){
    printf("OK\n");
    /*
    temp_t temperature = releve();
    float puissance = 0.0;
    //initialisation de la première consigne à 20° si lecture impossible
	float csg = 20;
	csg = consigne(csg);
	//initialisation des outils pour le calcul de PID
	int premiere = 0;
    float erreur_pre = 0;
    float integrale_pre = 0;
    	//boucle infinit
	while(1){
		temperature=releve(); // simulation de l'environnement
		//Ecriture des nouvelles température dans le fichier data.txt
		visualisationT(temperature);
		//récupération de la consigne qui se trouve dans consigne.txt
		csg = consigne(csg);
		if(csg<=5){
			//on eteind le chauffage puissance = 0
			visualisationC(0);
			return 0;
		}
		//affichage de la consigne dans le terminale
		printf("Consigne: %f",csg);
		//calcule de la puissance le premier argument est le choix:
		//1 pour TOR et 2 pour PID
		puissance = regulation(2,csg,temperature.interieure,premiere , &erreur_pre , &integrale_pre);
		//Ecriture de true ou false dans le fichier data.txt
		visualisationC(puissance);
		//affiche la nouvelle puissance
		printf("\nPuissance: %f\n",puissance);
		//incrementation de la decision pour le calcul de l'intégrale
		premiere++;

        commande(temperature);
		//attendre
		usleep(100000);
 	}
*/
}