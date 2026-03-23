typedef struct
{
    int horas;
    int minutos;
    int segundos;
    int tick;
    int flag_tick;
} timer_t;

void task_timerTick(void);
void task_printTime_LCD(void);