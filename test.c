#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <locale.h>
int prices[300] = {0};
wchar_t *names[300] = {'\0'};
int main(){
    setlocale( LC_ALL, "Russian");
    ENTRY e;
    ENTRY *ep;
    wchar_t line[100] = {'\0'};
    wchar_t price[20] = {'\0'};
    int i = 0, i_price = 0, name = 0, j = 0;
    FILE *file = fopen("price_list.txt", "r");
    if (file == NULL) {
        puts("Не удалось открыть файл \"price_list.txt\"\nЦены неизвестны...Нажмите <enter> чтобы выйти из программы...");
        getchar();
        return -1;
    }
    while (fget(line, sizeof(line),file) != NULL){
        while(line[i] != ':'){
            price[i] = line[i];
            i++;
        }
        printf("%c, ", line[i]);
        i++;
        printf("%c, ", line[i]);
        while(line[i] != ':'){
            // printf("%c, ", line[i]);
            // names[name][j] = line[i];
            i++;
            j++;
        }
        prices[i_price] = atoi(price);
        i = 0;
        name++;
        i_price++;
    }
    name = 0;
    for(i = 0; i < 4;i++){
        printf("Товар: %s ;Цена: %d \n", names[i], prices[i] );
    }
}