#include "consigne.h"

float consigne(float thermostatPrec_f)
{
   float thermostat_f = 0;
   FILE *fichierverrou = NULL;
   //si le fichier .verrouConsigne n'existe pas
   if (access(".verrouConsigne", F_OK))
   {
      //creation du fichier .verrouConsigne
      fichierverrou = fopen(".verrouConsigne", "w");

      //ouverture du fichier consigne.txt
      FILE *fichier = NULL;
      fichier = fopen("consigne.txt", "r");

      //si le fichier n'existe pas on retourn l'ancienne valeurs
      if(fichier == NULL){
         return thermostatPrec_f;
      }

      //on récupère la consigne dans le fichier consigne.txt
      char line[20];
      fgets(line,20,fichier);
      thermostat_f = atof(line);

      //affiche la valeur de la consigne
      printf("consigne :%.2f \n", thermostat_f);

      //fermeture du fichier consigne.txt
      fclose(fichier);
      //fermeture et suppresion du fichier .verrouConsigne
      fclose(fichierverrou);
      remove(".verrouConsigne");
      //renvoi de la nouvelle consigne
      return thermostat_f;
   }
      //renvoi de la nouvelle consigne
      return thermostatPrec_f;
}
