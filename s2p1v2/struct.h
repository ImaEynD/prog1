typedef struct datatime {
    unsigned char day;
    unsigned char month;
    unsigned short year;
    unsigned char hour;
    unsigned char minute;
} Datatime;

//    Функции добавление объектов структуры
Datatime *baseconst();
Datatime *copy(Datatime *p);
Datatime *default_datatime();

//    Функция вывода
void print_datatime(Datatime *p);

//    Функции изменения объекта структуры(Инкремент, декремент и сеттеры)
Datatime *decrement_day(Datatime *p);
Datatime *increment_day(Datatime *p);
void set_day(Datatime *p, unsigned char day);
void set_month(Datatime *p, unsigned char month);
void set_year(Datatime *p, unsigned short year);
void set_hour(Datatime *p, unsigned char hour);
void set_minute(Datatime *p, unsigned char minute);
void output_onlyone(Datatime *p, char choice);
void input_onlyone(Datatime *p, char choice);

//    Функции сравнения двух объектов
int gequal(Datatime *dflt, Datatime *bcst);
int greater_than(Datatime *dflt, Datatime *bcst);

//    Функции вычисления временного промежутка между датами
void compare_struct(Datatime *def_con, Datatime *odase);
void unix_datatime(Datatime *def_con);

//    Функции работы с памятью
void destroy_datatime(Datatime *p);
void malloc_info(void *ptr);