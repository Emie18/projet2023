#include "releve.h"

temp_t releve(){
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