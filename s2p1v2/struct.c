#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

Datatime *baseconst(){
    Datatime *p = malloc(sizeof(Datatime));
    check_malloc(p);
    printf("Введите день, месяц, год, час и минуты по порядку через пробелы: ");
    if (scanf("%hhu %hhu %hu %hhu %hhu", &p->day, &p->month, &p->year, &p->hour, &p->minute) != 5) {
        printf("Неверный ввод!\n");
        free(p);
        abort();
    }
    if (p->day != 0 && p->day > 31) {
        printf("Ошибка: некорректный день (1-31).\n");
        free(p);
        abort();
    }
    if (p->month != 0 && p->month > 12) {
        printf("Ошибка: некорректный месяц (1-12).\n");
        free(p);
        abort();
    }
    if (p->hour > 23) {
        printf("Ошибка: некорректный час (0-23).\n");
        free(p);
        abort();
    }
    if (p->minute > 59) {
        printf("Ошибка: некорректные минуты (0-59).\n");
        free(p);
        abort();
    }
    return p;
}

Datatime *default_datatime(){
    Datatime *p = malloc(sizeof(Datatime));
    check_malloc(p);
    p->day = 1;
    p->month = 1;
    p->year = 2000;
    p->hour = 0;
    p->minute = 0;
    return p;
}

Datatime *copy(Datatime *p){
    Datatime *copy = malloc(sizeof(Datatime));
    check_malloc(copy);
    copy->day = p->day;
    copy->month = p->month;
    copy->year = p->year;
    copy->hour = p->hour;
    copy->minute = p->minute;
    return copy;
}

void check_malloc(void *ptr) {
    if (!ptr) { 
        printf("Ошибка: не удалось выделить память!\n");
        abort();
    }
}

void print_datatime(Datatime *p){
    printf("Дата и время: %02hhu.%02hhu.%hu %02hhu:%02hhu\n", p->day, p->month, p->year, p->hour, p->minute);
}

Datatime *increment_day(Datatime *p) {
    p->day++;
    if (p->day == 31) { 
        p->day = 1;
        p->month++;
        if (p->month == 12) {
            p->month = 1;
            p->year++;
        }
    }
    return p;
}

Datatime *decrement_day(Datatime *p) {
    p->day--;
    if (p->day == 1) {
        p->day = 31;
        p->month--;
        if (p->month == 1) {
            p->month = 12;
            p->year--;
        }
    }
    return p;
}

void set_day(Datatime *p, unsigned char day) {
    p->day = day;
}

void set_month(Datatime *p, unsigned char month) {
    p->month = month;
}

void set_year(Datatime *p, unsigned short year) {
    p->year = year;
}

void set_hour(Datatime *p, unsigned char hour) {
    p->hour = hour;
}

void set_minute(Datatime *p, unsigned char minute) {
    p->minute = minute;
}

void input_onlyone(Datatime *p, char choice) {
    switch (choice) {
        case 1:
            printf("Введите день: ");
            scanf("%hhu", &p->day);
            break;
        case 2:
            printf("Введите месяц: ");
            scanf("%hhu", &p->month);
            break;
        case 3:
            printf("Введите год: ");
            scanf("%hu", &p->year);
            break;
        case 4:
            printf("Введите час: ");
            scanf("%hhu", &p->hour);
            break;
        case 5:
            printf("Введите минуты: ");
            scanf("%hhu", &p->minute);
            break;
        default:
            printf("Неверный выбор.\n");
            break;
    }
}

void output_onlyone(Datatime *p, char choice) {
    switch (choice) {
        case 1:
            printf("День: %02hhu\n", p->day);
            break;
        case 2:
            printf("Месяц: %02hhu\n", p->month);
            break;
        case 3:
            printf("Год: %hu\n", p->year);
            break;
        case 4:
            printf("Час: %02hhu\n", p->hour);
            break;
        case 5:
            printf("Минуты: %02hhu\n", p->minute);
            break;
        default:
            printf("Неверный выбор.\n");
            break;
    }
}

int compare_datatime(Datatime *dflt, Datatime *bcst) {
    if (dflt->year != bcst->year) return dflt->year - bcst->year;
    if (dflt->month != bcst->month) return dflt->month - bcst->month;
    if (dflt->day != bcst->day) return dflt->day - bcst->day;
    if (dflt->hour != bcst->hour) return dflt->hour - bcst->hour;
    return dflt->minute - bcst->minute;
}

int gequal(Datatime *dflt, Datatime *bcst) {
    return compare_datatime(dflt, bcst) == 0;
}


int greater_than(Datatime *dflt, Datatime *bcst) {
    return compare_datatime(dflt, bcst) > 0;
}

int compare_struct(Datatime *def_con, Datatime *obase){
    char comp_minute = obase->minute - def_con->minute;
    char comp_hour = obase->hour - def_con->hour;
    short comp_year = obase->year - def_con->year;
    char comp_day = obase->day - def_con->day;
    char comp_month = obase->month - def_con->month;
    printf("Разница между датами: %d дней %d месяцев %d лет %d час %d минут\n", comp_day, comp_month, comp_year, comp_hour, comp_minute);
    printf("Это: %d минут\n", comp_day*1440 + comp_month*44640 + comp_year*535680 + comp_hour*60 + comp_minute);
    printf("Или %d часов\n", comp_day * 24 + comp_month * 744 + comp_year * 8760 + comp_hour + comp_minute / 60);
    printf("Или %d дней\n", comp_day + comp_month * 31 + comp_year * 365 + comp_hour / 24 + comp_minute / 1440);
    printf("Или %d месяцев\n", comp_day / 31 + comp_month + comp_year * 12 + comp_hour / (24 * 31) + comp_minute / (1440 * 31));
    printf("Или %d лет\n", comp_day / 365 + comp_month / 12 + comp_year + comp_hour / (24 * 365) + comp_minute / (1440 * 365));
    return 0;
}

int unix_datatime(Datatime *def_con){
    printf("С начала эпохи юникс до введенной Вами даты прошло %d секунд.", def_con->minute * 60 + def_con->hour* 3600 + (def_con->day - 1) * 86400 + (def_con->month - 1) * 2678400 + (def_con->year-1970) * 32140800);
}