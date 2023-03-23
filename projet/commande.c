#include "commande.h"

void commande(float puis){


    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD BytesWritten;
    char TxBuffer[1]; // Contains data to write to device  
    ftStatus = FT_Open(0, &ftHandle);
    if(ftStatus != FT_OK) {
        printf ("FT_Open failed");
    }
    FT_SetTimeouts(ftHandle,5000,0);
    FT_SetBaudRate(ftHandle,115200);
    TxBuffer[0] = (char)(puis*127)/100;
    printf("buffer: %d",TxBuffer[0]);
    ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);
    if (ftStatus == FT_OK) {
    // FT_Write OK

    }
    else {
    // FT_Write Failed
    }
    FT_Close(ftHandle);

}
