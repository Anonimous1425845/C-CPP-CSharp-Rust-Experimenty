#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdio.h>

int main(){
    ma_engine engine;

    // INIT ZJ
    if (ma_engine_init(NULL, &engine) != MA_SUCCES) {
        return -1;
    }

    // play mp3
    ma_engine_play_sound(&engine, "NCS.mp3", NULL);
    printf("igraya vipalovacky nazhmite chto-nibud', chtoby zakonchit'");
    getchar();

    ma_engine_uninit(&engine);
    return 0
}