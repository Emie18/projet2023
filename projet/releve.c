#include "releve.h"

temp_t releve(){

    temp_t temperature;
    temperature.exterieure = 0;
    temperature.interieure = 0;

    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD RxBytes = 8;
    DWORD BytesReceived;
    char RxBuffer[10];
    ftStatus = FT_Open(0,&ftHandle);

    if(ftStatus != FT_OK) {
        printf ("FT_Open failed");
        return temperature;

    }
    FT_SetTimeouts(ftHandle,5000,0);
    FT_SetBaudRate(ftHandle,115200);
    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    if (ftStatus == FT_OK) {
        if (BytesReceived == RxBytes) {
            temperature = lecture_temp(RxBuffer);
            // FT_Read OK
        }else {
            // FT_Read Timeout
        }
    }else {
        printf ("FT_Read failed");
        return temperature;
    }
    FT_Close(ftHandle);
    return temperature;
}

temp_t lecture_temp( char tab[10]){
    // //Déclaration des variables
    temp_t temperature;
    char temp_int = 0;
    char temp_ext = 0;

    for (int i = 0;i<10;i++){
        //temperature interieur
        if( (tab[i] & 0xF0)>>4 == 0x08){
            if( (tab[i+1] & 0xF0)>>4 == 0x09){
                if( (tab[i+2] & 0xF0)>>4 == 0x10){
                    char SOT = ((tab[i] & 0x0F) << 8) + ((tab[i+1] & 0x0F)<<4) + (tab[i+2] & 0x0F);
                    temperature.interieure =  -39,64 + 0,04*SOT;
                }
            }
        }
        if( (tab[i] & 0xF0)>>4 == 0x00){
            if( (tab[i+1] & 0xF0)>>4 == 0x01){
                if( (tab[i+2] & 0xF0)>>4 == 0x02){
            char SOT = ((tab[i] & 0x0F) << 8) + ((tab[i+1] & 0x0F)<<4) + (tab[i+2] & 0x0F);
            temperature.exterieure =  -39,64 + 0,04*SOT;
                }
            }
        }
    }
    return temperature;

}