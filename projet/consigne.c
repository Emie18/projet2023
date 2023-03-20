#include "consigne.h"

   float consigne(float thermostatPrec_f)
   {
      FILE* fichierverrou = fopen(".verrouconsigne", "w");
 

      FILE* fichier = NULL;
      float consigne = 0; 
      fichier = fopen("consigne.txt", "r");

      if (fichier != NULL)
      {
         fscanf(fichier, "%f", &consigne);
         printf("consigne: %f",consigne);

         fclose(fichier);
      }else{
          printf("non:");
      }
    //if(access(".verroudata",0)!=0){
      float thermostat_f=0;
      //return thermostat_f;
      remove(".verrouconsigne");
      return consigne;
    //}

   }
