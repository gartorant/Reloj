#include "interval_timer_ISR.c"

typedef struct
{
    int horas;
    int minutos;
    int segundos;
    int tick;
    int flag_tick;
} timer_t;

void task_timerTick(timer_t *timer);
void task_printTime_LCD(timer_t *timer)