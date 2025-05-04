#include <stdio.h>


void read_date(int* day_init, 
               int* hours_init, 
               int* minutes_init, 
               int* seconds_init, 
               int* day_finish, 
               int* hours_finish, 
               int* minutes_finish, 
               int* seconds_finish) {
    
    char garbage[100];
    char garbage_char;
    scanf("%s", garbage); /* limpa a palavra Dia do buffer*/
    scanf("%d", day_init);
    scanf("%d", hours_init);
    scanf(" %c", &garbage_char); /* limpa o caracter : do buffer*/
    scanf(" %d", minutes_init);
    scanf(" %c", &garbage_char); /* limpa o caracter : do buffer*/
    scanf(" %d", seconds_init);
    scanf(" %s", garbage); /* limpa a palavra Dia do buffer*/
    scanf("%d", day_finish);
    scanf("%d", hours_finish);
    scanf(" %c", &garbage_char); /* limpa o caracter : do buffer*/
    scanf(" %d", minutes_finish);
    scanf(" %c", &garbage_char); /* limpa o caracter : do buffer*/
    scanf(" %d", seconds_finish);

}


void process_duration(int day_init, int hours_init, int minutes_init, int seconds_init,
    int day_finish, int hours_finish, int minutes_finish, int seconds_finish, 
    int* duration_days, int* duration_hours, int* duration_minutes, int* duration_seconds) {

        int total_seconds_day_init = seconds_init + minutes_init * 60 +  hours_init * 3600 + day_init * 3600 * 24;
        int total_seconds_day_finish = seconds_finish + minutes_finish * 60 +  hours_finish * 3600 + day_finish * 3600 * 24;

        int delta = total_seconds_day_finish - total_seconds_day_init;

        *duration_days = delta / (3600 * 24);
        delta = delta % (3600 * 24);

        *duration_hours = delta / (3600);
        delta = delta % (3600);

        *duration_minutes = delta / (60);
        delta = delta % (60);

        *duration_seconds = delta;

}


int main() {

    int day_init, hours_init, minutes_init, seconds_init,
        day_finish, hours_finish, minutes_finish, seconds_finish;

    /* read date input */
    read_date(&day_init, &hours_init, &minutes_init, &seconds_init,
        &day_finish, &hours_finish, &minutes_finish, &seconds_finish);

    
    int duration_days, duration_hours, duration_minutes, duration_seconds;

    process_duration(day_init, hours_init, minutes_init, seconds_init,
                    day_finish, hours_finish, minutes_finish, seconds_finish, 
                    &duration_days, &duration_hours, &duration_minutes, &duration_seconds);
    
    printf("%d dia(s)\n", duration_days);
    printf("%d hora(s)\n", duration_hours);
    printf("%d minuto(s)\n", duration_minutes);
    printf("%d segundo(s)\n", duration_seconds);
    
    return 0;
}