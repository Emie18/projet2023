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
      if (data != NULL)
      {
         // Tant qu'on n'a pas atteint la fin du fichier et qu'on a traité moins de trois lignes
         while (fgets(ligne, MAX_LINE_LENGTH, data) != NULL && num_ligne <= 3)
         {
            // Afficher la ligne
            num_ligne++;         // Passer à la ligne suivante
         }
      }
      fclose(data);
      data = fopen("data.txt", "w");
      if (data != NULL)
      {
         if (puissance_f != 0)
         {
            fprintf(data, "true\n");
         }
         else
         {
            fprintf(data, "true\n");
         }
         fprintf(data, "\n%.2f \n", ligne[1]);
         fprintf(data, "%.2f \n ", ligne[2]);
         fclose(data);
      }
      else
      {
         printf("echec de l'ouverture du fichier data.txt");
      }
      remove(".verrouData");
   }
}
