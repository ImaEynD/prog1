typedef struct datatime {
    unsigned char day;
    unsigned char month;
    unsigned short year;
    unsigned char hour;
    unsigned char minute;
} Datatime;

Datatime *baseconst();
void check_malloc(void *ptr);
Datatime *copy(Datatime *p);
Datatime *default_datatime();
void print_datatime(Datatime *p);
Datatime *decrement_day(Datatime *p);
Datatime *increment_day(Datatime *p);
void set_day(Datatime *p, unsigned char day);
void set_month(Datatime *p, unsigned char month);
void set_year(Datatime *p, unsigned short year);
void set_hour(Datatime *p, unsigned char hour);
void set_minute(Datatime *p, unsigned char minute);
void output_onlyone(Datatime *p, char choice);
void input_onlyone(Datatime *p, char choice);
int gequal(Datatime *dflt, Datatime *bcst);
int greater_than(Datatime *dflt, Datatime *bcst);
int compare_struct(Datatime *def_con, Datatime *odase);
int unix_datatime(Datatime *def_con);