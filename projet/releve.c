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
            temperature.interieure =
        }else {
            // FT_Read Timeout
        }
    }else {
        // FT_Read Failed
    }
    FT_Close(ftHandle);
}

void lecture_temp( char tab[256], temp_t temperature){
    for (int i = 0;i<256;i++){
        //temperature interieur
        if( tab[i]>>4 == 0x8){
            temperature.interieure = (tab[i] & 0xf);
        }
        if( tab[i]>>4 == 0x8){

        }
    }
}