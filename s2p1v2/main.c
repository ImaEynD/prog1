#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

int main(){
    printf("\nКонструктор ввода.\n");
    Datatime *bcons = baseconst();
    //      Конструктор по умолчанию
    Datatime *def_datatime = default_datatime();
    //      Конструктор копирования
    Datatime *copy_datatime = copy(bcons);
    //      Выводы
    printf("\nВывод конструктора ввода.\n");
    print_datatime(bcons);

    printf("Вывод конструктора по умолчанию.\n");
    print_datatime(def_datatime);

    printf("Вывод конструктора копирования.\n");
    print_datatime(copy_datatime);
    //      Операции над объектом структуры
    printf("\nИнкрементация дня.\n");
    Datatime *increment = increment_day(copy_datatime);
    print_datatime(increment);

    printf("Декрементация дня.\n");
    Datatime *decrement = decrement_day(copy_datatime);
    print_datatime(decrement);

    printf("Сеттеры.\n");
    set_day(copy_datatime, 11);
    set_month(copy_datatime, 11);
    set_year(copy_datatime, 1998);
    set_hour(copy_datatime, 23);
    set_minute(copy_datatime, 19);
    print_datatime(copy_datatime);
    //      Ввод/вывод отдельных полей
    printf("\nВвод отдельных полей:\n");
    int choice;
    printf("1. День\n2. Месяц\n3. Год\n4. Час\n5. Минуты\nВыберите поле для ввода: ");
    scanf("%d", &choice);
    input_onlyone(copy_datatime, choice);

    printf("\nВывод отдельных полей.\n");
    printf("1. День\n2. Месяц\n3. Год\n4. Час\n5. Минуты\nВыберите поле для вывода: ");
    scanf("%d", &choice);
    output_onlyone(copy_datatime, choice);
    //      Сравнение двух объектов
    printf("\nФункция сравнения.\n");
    if (gequal(def_datatime, bcons)) {
        printf("Даты равны.");
    } else {
        printf("Даты не равны.\n");
        if (greater_than(def_datatime, bcons)) {
            printf("Дата по умолчанию больше.\n");
        } else {
            printf("Дата по умолчанию меньше.\n");
        }
    }
    //      Сравнение кол-ва дней, месяцев и.т.д
    compare_struct(def_datatime, bcons);
    //      Кол-во секунд с начала эры UNIX
    unix_datatime(bcons);
    //      Деструкторы
    destroy_datatime(bcons);
    destroy_datatime(def_datatime);
    destroy_datatime(copy_datatime);
    return 0;
}