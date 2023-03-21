#include "visualisationT.h"
#include "define.h"
#include <unistd.h>
 #define MAX_LINE_LENGTH 10
void visualisationT(temp_t myTemp)
{
  if (access(".verrouData", F_OK)!=0)
  {
    FILE *fichierverou = fopen(".verrouData", "w");
    FILE *data = fopen("data.txt", "r");
    char line[MAX_LINE_LENGTH];
    if (data != NULL)
    {
    if (fgets(line, MAX_LINE_LENGTH, data) != NULL) {
        printf("La premiere ligne est : %s\n", line);
    }
    }
    fclose(data);
    data = fopen("data.txt", "w");
     if (data != NULL)
    {
      fprintf(data, "%s", line);
      fprintf(data, "%.2f\n ", myTemp.interieure);
      fprintf(data, "%.2f\n", myTemp.exterieure);
      
    }
    else
    {
      printf("echec à l'ouverture");
    }
    fclose(data);
    fclose(fichierverou);
    remove(".verrouData");
  }
}
