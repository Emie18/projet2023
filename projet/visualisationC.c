#include "visualisationC.h"

#define MAX_LINE_LENGTH 100

void visualisationC(float puissance_f)
{
   if (access(".verrouData", F_OK)!=0)
   {
      FILE *fichierverou = fopen(".verrouData", "w");
      FILE *data = fopen("data.txt", "r");
      char ligne[MAX_LINE_LENGTH];
      int num_ligne = 1;
      float  temperature_int = 0;
      float  temperature_ext = 0;
      char tmp[100]="";
      int i = 0;
      if (data != NULL)
      {
        fscanf(data,"%s%f\n%f\n",tmp,&temperature_int,&temperature_ext);

      }
      fclose(data);
      data = fopen("data.txt", "w");
      if (data != NULL)
      {
         if (puissance_f == 0)
         {
            fprintf(data, "false");
         }
         else
         {
            fprintf(data, "true");
         }
         fprintf(data, "\n%.2f \n",temperature_int);
         fprintf(data, "%.2f \n ", temperature_ext);
      }
      else
      {
         printf("echec de l'ouverture du fichier data.txt");
      }
      fclose(data);
      fclose(fichierverou);
      remove(".verrouData");
   }else{
      printf("fichier en cours d'utilisation .verrouData existe!");
   }
}