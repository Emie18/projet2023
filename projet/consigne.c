#include "consigne.h"

float consigne(float thermostatPrec_f)
{
   float thermostat_f = 0;
   FILE *fichierverrou = NULL;
   if (access(".verrouConsigne", F_OK))
   {
      fichierverrou = fopen(".verrouConsigne", "w");
      FILE *fichier = NULL;
      fichier = fopen("consigne.txt", "r");
      if(fichier == NULL){
         return thermostatPrec_f;
      }
      char line[20];
      fgets(line,20,fichier);
      thermostat_f = atof(line);
      //fscanf(fichier, "%f", &thermostat_f);
      printf("consigne :%.2f \n", thermostat_f);
      fclose(fichier);
      fclose(fichierverrou);
      remove(".verrouConsigne");
      return thermostat_f;
   }
      return thermostatPrec_f;
}
