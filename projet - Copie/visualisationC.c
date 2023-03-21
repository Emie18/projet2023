#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"

#define MAX_LINE_LENGTH 100

void visualisationC(float puissance_f)
{
   if (access(".verrouData", F_OK))
   {
      FILE *fichierverou = fopen(".verrouData", "w");
      FILE *data = fopen("data.txt", "r");
      char ligne[MAX_LINE_LENGTH];
      int num_ligne = 1;
      float  temperature_int;
      float  temperature_ext;
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
         fclose(data);
      }
      else
      {
         printf("echec de l'ouverture du fichier data.txt");
      }
      fclose(data);
      fclose(fichierverou);
      remove(".verrouData");
   }
}
         // Tant qu'on n'a pas atteint la fin du fichier et qu'on a traité moins de trois lignes
         // while (fgets(ligne, MAX_LINE_LENGTH, data) != NULL && num_ligne <= 3)
         // {
         //       i++; 
         //    printf("i: %d ,num: %s\n",i,ligne);// Afficher la ligne
         //    num_ligne++;
         //       // Passer à la ligne suivante
            
         // }