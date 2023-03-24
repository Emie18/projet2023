#include "consigne.h"

float consigne(float thermostatPrec_f)
{
   float thermostat_f = thermostatPrec_f;
   FILE *fichierverrou = NULL;
   //si le fichier .verrouConsigne n'existe pas
   if (access(".verrouConsigne", F_OK)!=0)
   {
      //creation du fichier .verrouConsigne
      fichierverrou = fopen(".verrouConsigne", "w");

      //ouverture du fichier consigne.txt
      FILE *fichier = NULL;
      fichier = fopen("consigne.txt", "r");

      //si le fichier n'existe pas on retourn l'ancienne valeurs
      if(fichier == NULL){
         thermostat_f = thermostatPrec_f;
      }else{

      //on récupère la consigne dans le fichier consigne.txt
      char line[20];
      fgets(line,20,fichier);
      thermostat_f = atof(line);

      //fermeture du fichier consigne.txt
      fclose(fichier);
      }

      //fermeture et suppresion du fichier .verrouConsigne
      fclose(fichierverrou);
      remove(".verrouConsigne");
   }
      //renvoi de la nouvelle consigne
      return thermostat_f;
}
