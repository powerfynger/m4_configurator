#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// 
// 
// Раскопать информацию про enum
// 
// 

typedef struct node {
    char name[30];
    int price;
    struct node* next;
} node;



struct scope {
    char base[16];
    char approach; // Увеличение
    char colour[8];
};

struct magazine {
    float callibre;
    char size[20];
};


struct m4 {
    char tactical_bracing; // Тактическое крепление
    struct scope scope;
    char barrel[16];
    char barrel_mods[16];
    char underbarrel_mods[20];
    char trigger[20];
    char magazine_holder;
    char handle[64];
    char stock[20];
    char tube[64];
    char rifle_case[20];
    struct magazine magazine;
    enum { in_progress, done } status;
};

int prices[10] = { 0 };

struct m4 current_config;


void create_config();
void save_config();
void check_prices();
void change_config();
void exit_app();
char safe_input();
void draw_menu();
void clean_stdin();
void change_tactical_bracing();
void change_scope();
void change_barrel();
void change_trigger();
void change_underbarrel_mods();
void change_handle();
void change_stock();
void change_case();
void change_magazine();
int read_prices();

int main() {
    setlocale(LC_ALL, "Russian");
    char choice = '\0';
    puts("\t\t\tУтилита запущена!\n\n");
    if (read_prices() == -1) { return 0; }
    while (1) {
        draw_menu();
        choice = safe_input();
        switch (choice) {
        case '1':
            create_config();
            system("cls");
            break;

        case '2':
            printf("%c", choice);
            break;

        case '3':
            printf("%c", choice);
            break;

        case '4':
            change_config();
            system("cls");
            break;

        case '5':
            check_prices();
            system("cls");
            break;

        case '6':
            exit_app();
            return 1;
            break;

        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }


    return 0;
}

void create_config() {
    system("cls");
    change_tactical_bracing();
    change_scope();
    change_barrel();
    change_trigger();
    change_underbarrel_mods();
    change_handle();
    change_stock();
    change_case();
    change_magazine();
    current_config.magazine.callibre = 5.56;
    current_config.status = 1;
    puts("Создание конфигурации штурмовой винтовки М4 успешно завершено!\nНажмите <enter>, чтобы продолжить...");
    system("pause");
}

void change_config() {
    char change = 0;
    if (!current_config.status) {
        system("cls");
        puts("Текущая конфигурация не выбрана.\nВыберете пункт создания или импорта конфигураций в меню.\nНажмите\
<enter>, чтобы продолжить...");
        system("pause");
        return;
    }
    while (!change) {
        system("cls");
        char choice = '\0';
        puts("\t\tМеню изменения конфигурации!");
        puts("Выберете пункт, который нужно изменить:\n\
Введите\t: 1<Enter>\tналичие тактического крепления.\n\
Введите\t: 2<Enter>\tприцел.\n\
Введите\t: 3<Enter>\tствол и его модификатор.\n\
Введите\t: 4<Enter>\tподствольный модификатор.\n\
Введите\t: 5<Enter>\tспусковая скоба.\n\
Введите\t: 6<Enter>\tпоказать следующие 4 пункта.\n\
Введите\t: 7<Enter>\tвыход.\
");
        choice = safe_input();
        switch (choice) {
        case '1':
            system("cls");
            change_tactical_bracing();
            change++;
            break;
        case '2':
            system("cls");
            change_scope();
            change++;
            break;
        case '3':
            system("cls");
            change_barrel();
            change++;
            break;
        case '4':
            system("cls");
            change_underbarrel_mods();
            change++;
            break;
        case '5':
            system("cls");
            change_trigger();
            change++;
            break;
        case '6':
            system("cls");
            puts("\t\tМеню изменения конфигурации!");
            puts("Выберете пункт, который нужно изменить:\n\
Введите\t: 1<Enter>\tопора.\n\
Введите\t: 2<Enter>\tприклад.\n\
Введите\t: 3<Enter>\tчехол.\n\
Введите\t: 4<Enter>\tмагазин.\n\
Введите\t: 5<Enter>\tназад.\
    ");
            choice = safe_input();
            switch (choice) {
            case '1':
                system("cls");
                change_handle();
                change++;
                break;
            case '2':
                system("cls");
                change_stock();
                change++;
                break;
            case '3':
                system("cls");
                change_case();
                change++;
                break;
            case '4':
                system("cls");
                change_magazine();
                change++;
                break;
            case '5':

                break;
            default:
                puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                system("pause");
                break;
            }

            break;
        case '7':
            return;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
    }
}

void save_config() {
    return;
}

void check_prices() {
    system("cls");
    puts("\t\tПросмотр цен на текущую конфигурацию!\nБазовая стоимость штурмовой винтовки M4 : 20.000 крышек .");
    if (current_config.tactical_bracing) {
        printf("Доплата за тактическое крепление : %d", prices[0]);
    }

}

void exit_app() {
    char choice_safe;
    while (1) {
        system("cls");
        puts("\t\tСохранить текущую конфигурацию?\nВведите : 1<Enter>\tда.\nВведите : 2<Enter>\tнет.\n");
        // clean_stdin();
        choice_safe = safe_input();
        switch (choice_safe) {
        case '1':
            if (current_config.status == 0) {
                puts("\t\tНикакая конфигурация не выбрана, сохранять нечего.\nНажмите <enter>, чтобы выйти...");
                system("pause");
                return;
            }
            save_config();
            puts("\t\tКонфигурация успешно сохранена в файл!\nНажмите <enter>, чтобы выйти...");
            system("pause");
            return;
            break;
        case '2':
            return;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            // clean_stdin();
            system("pause");
            break;
        }
    }
}

void draw_menu() {
    puts("\
\t\tКонструктор штурмовой винтовки М4 v0.0.1\n\n\
Введите\t: 1<Enter>\tсоздать конфигурацию вручную.\n\
Введите\t: 2<Enter>\tсохранить созданную конфигурацию товара в файл.\n\
Введите\t: 3<Enter>\tимпортировать существующую конфигурацию товара из файла.\n\
Введите\t: 4<Enter>\tпосмотреть/изменить текущую конфигурацию товара.\n\
Введите\t: 5<Enter>\tрассчитать цену на товар заданной конфигурации.\n\
Введите\t: 6<Enter>\tвыход.\
");
}

int read_prices() {
    node* list;
    list = (node*)malloc(sizeof(node));
    if (list) {
        list->next = NULL;
    }
    else {
        puts("Not enough mem");
        return 0;
    }
    FILE* file;
    if (!fopen_s(&file, "price_list.txt", "r")) {
        char line[100] = { '\0' };
        while (fgets(line, sizeof(line), file) != NULL) {
            int i = 0, j = 0;
            char price[10] = { '\0' };
            char name[30] = { '\0' };
            while (line[i] != ':') {
                price[i] = line[i];
                i++;
            }
            i++;
            while (line[i] != ':') {
                name[j] = line[i];
                j++; i++;
            }
            push(list, name, atoi(price));
        }
    }
    else {
        puts("Не удалось открыть файл \"price_list.txt\"\nЦены неизвестны...Нажмите <enter> чтобы выйти из программы...");
        system("pause");
        return -1;
    }
    return 1;
}

char safe_input() {
    printf(">> ");
    char buff[200] = { '\0' };
    fgets(buff, sizeof(buff), stdin);
    if (buff[1] != 10) {
        return 0;
    }

    return buff[0];
}

void clean_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void change_tactical_bracing() {
    char change = 0;//, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Установить тактическое крепление?(влияет на выбор прицелa).");
        puts("Введите : 1<enter>\t\tДа.\nВведите : 2<enter>\t\tНет.");
        choice = safe_input();
        switch (choice) {
        case '1':
            current_config.tactical_bracing = 1;
            change++;
            break;
        case '2':
            current_config.tactical_bracing = 0;
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_scope() {
    char change = 0, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете прицел.");
        puts("Введите : 1<enter>\t\tНичего.\nВведите : 2<enter>\t\tКоллиматор\nВведите : 3<enter>\t\tОптика.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.scope.base, "Нет");
            change++;
            break;
        case '2':
            system("cls");
            strcpy(current_config.scope.base, "Коллиматор");
            while (!change_tmp) {
                puts("\t\t\tМеню создания конфигурации!\n");
                puts("Выберете цвет прицела");
                puts("Введите : 1<enter>\t\tКрасный.\nВведите : 2<enter>\t\tЗеленый");
                char choice_temp = safe_input();
                switch (choice_temp) {
                case '1':
                    strcpy(current_config.scope.colour, "Красный");
                    change_tmp++;
                    break;
                case '2':
                    strcpy(current_config.scope.colour, "Зеленый");
                    change_tmp++;
                    break;
                default:
                    puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                    system("pause");
                    break;
                }
                system("cls");
            }
            change_tmp = 0;
            change++;
            break;
        case '3':
            system("cls");
            strcpy(current_config.scope.base, "Оптика");
            if (current_config.tactical_bracing == 1) {
                while (!change_tmp) {
                    puts("\t\t\tМеню создания конфигурации!\n");
                    puts("Выберете кратность увеличения прицела");
                    puts("Введите : 1<enter>\t\tУвеличение 2х.\nВведите : 2<enter>\t\tУвеличение 4х");
                    char choice_temp = safe_input();
                    switch (choice_temp) {
                    case '1':
                        current_config.scope.approach = 2;
                        change_tmp++;
                        break;
                    case '2':
                        current_config.scope.approach = 4;
                        change_tmp++;
                        break;
                    default:
                        puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                        system("pause");
                        break;
                    }
                    system("cls");
                }
                change_tmp = 0;
                change++;
                break;
            }
            puts("Так как отсутсвует тактическое крепление кратность увеличения только 2х\nНажмите <enter>, чтобы продолжить.");
            system("pause");
            current_config.scope.approach = 2;
            change_tmp = 0;
            change++;
            break;

        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_barrel() {
    char change = 0, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете тип ствола для установки(влияет на выбор доступных модификаций).");
        puts("Введите : 1<enter>\t\tУкороченный.\nВведите : 2<enter>\t\tСтандартный.\nВведите : 3<enter>\t\tУдлинённый.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.barrel, "Укороченный");
            change++;
            break;
        case '2':
            strcpy(current_config.barrel, "Обычный");
            change++;
            break;
        case '3':
            strcpy(current_config.barrel, "Удлиненный");
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
    change = 0;
    while (!change) {
        if (!strcmp(current_config.barrel, "short") || !strcmp(current_config.barrel, "long")) {
            while (!change_tmp) {
                puts("\t\t\tМеню создания конфигурации!\n");
                puts("Выберете модификации ствола.");
                puts("Введите : 1<enter>\t\tНичего.\nВведите : 2<enter>\t\tКомпенсатор.");
                choice = safe_input();
                switch (choice) {
                case '1':
                    strcpy(current_config.barrel_mods, "Нет");
                    change_tmp++;
                    break;
                case '2':
                    strcpy(current_config.barrel_mods, "Компенсатор");
                    change_tmp++;
                    break;
                default:
                    puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                    system("pause");
                    break;
                }
                system("cls");
            }
            change++;
            change_tmp = 0;
            break;
        }
        while (!change_tmp) {
            puts("\t\t\tМеню создания конфигурации!\n");
            puts("Выберете модификации ствола.");
            puts("Введите : 1<enter>\t\tНичего.\nВведите : 2<enter>\t\tКомпенсатор.\nВведите : 3<enter>\t\tПламягаситель.\n\
Введите : 4<enter>\t\tГлушитель.");
            choice = safe_input();
            switch (choice) {
            case '1':
                strcpy(current_config.barrel_mods, "Нет");
                change_tmp++;
                break;
            case '2':
                strcpy(current_config.barrel_mods, "Компенсатор");
                change_tmp++;
                break;
            case '3':
                strcpy(current_config.barrel_mods, "Пламягаситель");
                change_tmp++;
                break;
            case '4':
                strcpy(current_config.barrel_mods, "Глушитель");
                change_tmp++;
                break;
            default:
                puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                system("pause");
                break;
            }
            system("cls");
        }
        change++;
        change_tmp = 0;
        break;
    }
}

void change_trigger() {
    char change = 0, change_tmp = 0;
    char choice = '\0';

    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете тип спусковой скобы.");
        puts("Введите : 1<enter>\t\tПолимерная.\nВведите : 2<enter>\t\tАлюминиевая.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.trigger, "Полимерная");
            change++;
            break;
        case '2':
            strcpy(current_config.trigger, "Алюминиевая");
            while (!change_tmp) {
                system("cls");
                puts("\t\t\tМеню создания конфигурации!\n");
                puts("Хотите установить держатель для магазина?");
                puts("Введите : 1<enter>\t\tДа.\nВведите : 2<enter>\t\tНет.");
                char choice_temp = safe_input();
                switch (choice_temp) {
                case '1':
                    current_config.magazine_holder = 1;
                    change_tmp++;
                    break;
                case '2':
                    current_config.magazine_holder = 0;
                    change_tmp++;
                    break;
                default:
                    puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                    system("pause");
                    break;
                }
                system("cls");
            }
            change_tmp = 0;
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_underbarrel_mods() {
    char change = 0;//, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете подствольный модификатор.");
        puts("Введите : 1<enter>\t\tНичего.\nВведите : 2<enter>\t\tТактический фонарь.\nВведите : 3<enter>\t\tЛазерная указка\n\
Введите : 4<enter>\t\tГранатомёт М203.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.underbarrel_mods, "Нет");
            change++;
            break;
        case '2':
            strcpy(current_config.underbarrel_mods, "Тактический фонарь");
            change++;
            break;
        case '3':
            strcpy(current_config.underbarrel_mods, "Лазерная указка");
            change++;
            break;
        case '4':
            strcpy(current_config.underbarrel_mods, "Гранатомёт М203");
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");


    }
}

void change_handle() {
    char change = 0;//, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        if (!strcmp(current_config.underbarrel_mods, "Гранатомёт М203")) {
            puts("Невозможно установить опору, из-за выбранной модификации(Гранатомёт М203)\nНажмите <enter>, чтобы продолжить");
            system("pause");
            strcpy(current_config.handle, "Нет");
            change++;
            break;
            system("cls");
        }
        puts("Выберете опору.");
        puts("Введите : 1<enter>\t\tНичего.\nВведите : 2<enter>\t\tПистолетная рукоять.\nВведите : 3<enter>\t\t2-секционная ножка.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.handle, "Нет");
            change++;
            break;
        case '2':
            strcpy(current_config.handle, "Пистолетная рукоять");
            change++;
            break;
        case '3':
            strcpy(current_config.underbarrel_mods, "2-секционная ножка");
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_stock() {
    char change = 0, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете тип приклада.");
        puts("Введите : 1<enter>\t\tСтандартный.\nВведите : 2<enter>\t\tТелескопический.\nВведите : 3<enter>\t\tПолимерный.");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.stock, "Стандартный");
            change++;
            break;
        case '2':
            strcpy(current_config.stock, "Телескопический");
            while (!change_tmp) {
                system("cls");
                puts("\t\t\tМеню создания конфигурации!\n");
                puts("Выберете трубу для телескопического приклада.");
                puts("Введите : 1<enter>\t\tСтандартная.\nВведите : 2<enter>\t\tС буферизацией отдачи.");
                char choice_temp = safe_input();
                switch (choice_temp) {
                case '1':
                    strcpy(current_config.tube, "Стандартная");
                    change_tmp++;
                    break;
                case '2':
                    strcpy(current_config.tube, "С буферизацией отдачи");
                    change_tmp++;
                    break;
                default:
                    puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                    system("pause");
                    break;
                }
                system("cls");
            }
            change_tmp = 0;
            change++;
            break;
        case '3':
            strcpy(current_config.trigger, "Полимерный");
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_case() {
    char change = 0, change_tmp = 0;
    char choice = '\0';
    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Добавить чехол?");
        puts("Введите : 1<enter>\t\tДа.\nВведите : 2<enter>\t\tНет.");
        choice = safe_input();
        switch (choice) {
        case '2':
            strcpy(current_config.rifle_case, "Нет");
            change++;
            break;
        case '1':
            while (!change_tmp) {
                system("cls");
                puts("\t\t\tМеню создания конфигурации!\n");
                puts("Выберете цвет чехла.");
                puts("Введите : 1<enter>\t\tЧёрный.\nВведите : 2<enter>\t\tКамуфляж.\nВведите : 3<enter>\t\tРоссия.");
                char choice_temp = safe_input();
                switch (choice_temp) {
                case '1':
                    strcpy(current_config.rifle_case, "Чёрный");
                    change_tmp++;
                    break;
                case '2':
                    strcpy(current_config.rifle_case, "Камуфляж");
                    change_tmp++;
                    break;
                case '3':
                    strcpy(current_config.rifle_case, "Камуфляж");
                    change_tmp++;
                    break;
                default:
                    puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
                    system("pause");
                    break;
                }
                system("cls");
            }
            change_tmp = 0;
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void change_magazine() {
    char change = 0;//, change_tmp = 0;
    char choice = '\0';

    while (!change) {
        puts("\t\t\tМеню создания конфигурации!\n");
        puts("Выберете размер магазина");
        puts("Введите : 1<enter>\t\tСтандартный(30 пуль каллибра 5,56x45).\nВведите : 2<enter>\t\tУвеличенный(40 пуль каллибра 5,56x45).\n\
Введите : 3<enter>\t\tБольшой(60 пуль каллибра 5,56x45)");
        choice = safe_input();
        switch (choice) {
        case '1':
            strcpy(current_config.magazine.size, "Стандартный");
            change++;
            break;
        case '2':
            strcpy(current_config.magazine.size, "Увеличенный");
            change++;
            break;
        case '3':
            strcpy(current_config.magazine.size, "Большой");
            change++;
            break;
        default:
            puts("Выбор не распознан :(\nНажмите <enter> и повторите попытку...");
            system("pause");
            break;
        }
        system("cls");
    }
}

void push(node* pr, char* name, int price) {
    node* tmp;
    node* p;
    tmp = (node*)malloc(sizeof(node));
    if (tmp) {
        p = pr->next;
        pr->next = tmp;
        tmp->price = price;
        strcpy_s(tmp->name, 30, name);
        tmp->next = p;
    }
}

void print_list(node* p) {
    while (p != NULL) {
        printf("Название - %s, Цена - %d\n", p->name, p->price);
        p = p->next;
    }
}