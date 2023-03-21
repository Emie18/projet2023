#include "releve.h"

temp_t releve(){

    temp_t temperature;

    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD RxBytes = 8;
    DWORD BytesReceived;
    char RxBuffer[256];
    ftStatus = FT_Open(0,&ftHandle);

    if(ftStatus != FT_OK) {
        // FT_Open failed
        return;
    }
    FT_SetTimeouts(ftHandle,5000,0);
    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    if (ftStatus == FT_OK) {
        if (BytesReceived == RxBytes) {
            // FT_Read OK
        }else {
            // FT_Read Timeout
        }
    }else {
        // FT_Read Failed
    }
    FT_Close(ftHandle);
}

void lecture_temp( char tab[256], temp_t temperature){
// //Déclaration des variables
// unsigned char octet;
// unsigned char last4bits;
// unsigned char first4bits;

// //Lecture de l'octet à partir d'une source de données (ex: port série)
// //Remplacez cette étape par la lecture de votre octet à partir de votre source de données
// octet = 0xA8; //Exemple de valeur, à remplacer par la valeur réelle lue depuis la source de données

// //Vérification si les 4 derniers bits sont égaux à 0x8
// if ((octet & 0x0F) == 0x08) {
//     //Si les 4 derniers bits sont égaux à 0x8, récupération des 4 premiers bits
//     first4bits = octet >> 4;
//     //Affichage de la valeur récupérée si les 4 premiers bits sont égaux à 8
//     if (first4bits == 0x08) {
//         printf("Les 4 premiers bits sont égaux à 0x8 !");
//     } else {
//         printf("Les 4 premiers bits sont différents de 0x8 (valeur : 0x%X)", first4bits);
//     }
// } else {
//     printf("Les 4 derniers bits ne sont pas égaux à 0x8");
// }

    for (int i = 0;i<256;i++){
        //temperature interieur
        if( tab[i]>>4 == 0x8){
            temperature.interieure = (tab[i] & 0xf);
        }
        if( tab[i]>>4 == 0x8){

        }
    }
}