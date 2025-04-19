/* 
    Programmer: Felipe Rosa 
    Date: 19/04
*/


#include <stdio.h>


int main() {
    
    /* variables definition */
    int hours_init, minutes_init, hours_end, minutes_end;
    int duracao_horas = 0;
    int duracao_minutos = 0;
    
    /* read stardard input */
    scanf("%d %d %d %d", &hours_init, &minutes_init, &hours_end, &minutes_end);
    
    if(hours_init == hours_end && minutes_init == minutes_end) {
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
        return 0;
    } else if(hours_init < hours_end) {
        duracao_horas += hours_end - hours_init;
        
        if(minutes_init < minutes_end) {
            duracao_minutos = minutes_end - minutes_init;
        } else if (minutes_init > minutes_end) {
            duracao_minutos = 60 - minutes_init;
            duracao_minutos += minutes_end;
            duracao_horas -= 1;
        }
        
    } else if(hours_init > hours_end) {
        duracao_horas += 24 - hours_init;
        duracao_horas += hours_end;
        
        if(minutes_init < minutes_end) {
            duracao_minutos = minutes_end - minutes_init;
        } else if (minutes_init > minutes_end) {
            duracao_minutos = 60 - minutes_init;
            duracao_minutos += minutes_end;
            duracao_horas -= 1;
        }
    } else {
        if(minutes_init < minutes_end) {
            duracao_minutos = minutes_end - minutes_init;
        } else if (minutes_init > minutes_end) {
            duracao_minutos = 60 - minutes_init;
            duracao_minutos += minutes_end;
            duracao_horas += 23;
        }
    }
    
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);
    return 0;
}
