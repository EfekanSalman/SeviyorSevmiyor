#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main(int argc, char *argv[]) {
	
	char *durumlar[2] = {"Seviyor yes beee!!!", "Allahin belasi Sevmiyor "};
    int yaprakSayisi, i;
    
    printf("Cicegin yaprak sayisini giriniz: ");
    scanf("%d", &yaprakSayisi);
    
    if(yaprakSayisi < 1) {
        printf("Gecersiz yaprak sayisi.\n");
        return 1;
    }
    
    
    srand(time(NULL)); 
    int baslangic = rand() % 2; 
    
    for(i = 0; i < yaprakSayisi; i++) {
        clearScreen(); 
        printf("%d. yaprak: %s\n", i + 1, durumlar[(baslangic + i) % 2]);
        fflush(stdout); 
        sleep(1);
    }
    
    clearScreen();
    printf("Sonuc: %s!\n", durumlar[(baslangic + yaprakSayisi - 1) % 2]); 
    
	
	return 0;
}
