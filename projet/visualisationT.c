#include "visualisationT.h"
#include "define.h"
#include <unistd.h>
 #define MAX_LINE_LENGTH 10
void visualisationT(temp_t myTemp)
{
  //on verrifie que le .verrouData n'existe pas
  if (access(".verrouData", F_OK)!=0)
  {
    //creation de fichier verrou
    FILE *fichierverou = fopen(".verrouData", "w");

    //ouverture en mode lecture du fichier data
    FILE *data = fopen("data.txt", "r");
    char line[MAX_LINE_LENGTH];
    if (data != NULL)
    {
      //recuperation de la puissance dans line
    if (fgets(line, MAX_LINE_LENGTH, data) != NULL) {
        printf("La premiere ligne est : %s\n", line);
    }
    }
    //fermeture, puis ouverture en mode lecture cette fois du fichier data
    fclose(data);
    data = fopen("data.txt", "w");

     if (data != NULL)
    {
      //on réécrit dans la fichier data la valeur de la puissance
      fprintf(data, "%s", line);

      //on écrit dans data les nouvelle valeur de température
      fprintf(data, "%.2f\n ", myTemp.interieure);
      fprintf(data, "%.2f\n", myTemp.exterieure);
    }
    else
    {
      //message d'echec à l'ouverture
      printf("echec à l'ouverture");
    }
    //fermeture du fichier data.txt
    fclose(data);
    
    //fermeture et suppression du fichier .verrouData
    fclose(fichierverou);
    remove(".verrouData");
  }
}
