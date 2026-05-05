#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdio.h>

int main(){
    char name[1000];
    printf("Vložte názov:\nInsert name:\nVvedite imya:")
    fgets(name, 1000, stdin);

    ma_engine engine;
    ma_sound sound;

    // INIT ZJ
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        printf("Failed to initialize audio engine.\n");
        printf("Ne udalos' initsializirovat' audiodvizhok.\n");
        return -1;
    }

    // load and play mp3 zaigraj!
    if (ma_sound_init_from_file(&engine, name, 0, NULL, NULL, &sound) != MA_SUCCESS) {
        printf("Failed to load sound.\n");
        printf("Ne udalos' zagruzit' zvuk.\n");
        ma_engine_uninit(&engine);
        getchar();
        return -1;
    }

    ma_sound_start(&sound);
    printf("Playing...\n %s",name);
    printf("Press any key to exit.\n")
    //printf("igraya vipalovacky nazhmite chto-nibud', chtoby zakonchit'\n")
    printf("igraya vipalovacky!\n %s",name);
    printf("Nazhmite lyubuyu klavishu dlya vykhoda.");
    getchar();

    ma_sound_uninit(&sound);
    ma_engine_uninit(&engine);
    return 0;
}