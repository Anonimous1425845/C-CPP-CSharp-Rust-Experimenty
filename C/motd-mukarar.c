#include <stdio.h>

int main(){
    char motd[100];// pole pre 100 znakov
    printf("MOTD:\n");
    // motd = kam to uložiť
    // 100 = maximálna dĺžka
    // stdin = štandardný vstup (klávesnica)
    fgets(motd, 100, stdin);
    
    printf("Today motd is:\n %s",motd);
    
    return 0;
}