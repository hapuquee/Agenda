#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listase.h"

typedef struct evento{
    unsigned dia, mes, ano, hora, min;
    char descricao[140];
    char prioridade[10];
    char tempo[15];
}evento;

evento* criar_evento(int dia, int mes, int ano, int hora, int min, char* tempo, char* descricao, char* prioridade){
    evento* e = malloc(sizeof(evento));
    e->dia = dia;
    e->mes = mes;
    e->ano = ano;
    e->hora = hora;
    e->min = min;
    strcpy(e->descricao, descricao);
    strcpy(e->prioridade, prioridade);
    strcpy(e->tempo, tempo);
    return e;
}

evento* ler_evento(){
    unsigned dia, mes, ano, hora, min;
    char descricao[140], prioridade[10];
    char tempo[40];

    scanf("%d/%d/%d", &dia, &mes, &ano);
    scanf("%d:%d", &hora, &min);
    scanf("%s", descricao);
    scanf("%s", prioridade);
    sprintf(tempo,"%d/%d/%d %d:%d", ano, mes, dia, hora, min);
    return criar_evento(dia, mes, ano, hora, min, tempo, descricao, prioridade);
}

void imprimir_evento(void* e){
    evento* ee = e;
    printf("%02d/%02d/%02d %02d:%02d %s %s", ee->dia, ee->mes, ee->ano, ee->hora, ee->min, ee->descricao, ee->prioridade);
}

int comparar_evento(void* info1, void* info2){
    evento* e1 = info1;
    evento* e2 = info2;
    int c;

    c = strcmp(e1->tempo, e2->tempo);

    return c;
} 

//aula
typedef struct t_agenda{
    lse* eventos;
}t_agenda;

t_agenda* criar_agenda(){
    t_agenda* agenda = malloc(sizeof(t_agenda));
    agenda->eventos = criar_lse(imprimir_evento, comparar_evento);
    return agenda;
}

void agendar_evento(t_agenda* agenda, void* evento){
    inserir_ordenado_lse(agenda->eventos, evento);
}

int quantificar_eventos(t_agenda* agenda){
    return tamanho(agenda->eventos);
}

void proximo_evento(t_agenda* agenda){
    imprimir_evento(primeiro(agenda->eventos));
}

void alterar_evento(char* tempo, evento* e2, t_agenda* agenda){
    evento* e1 = malloc(sizeof(evento));

    strcpy(e1->tempo, tempo);

    alterar_elem(e1, e2, agenda->eventos);

    free(e1);
}

void cancelar_evento(char* tempo, t_agenda* agenda){
    evento *e = malloc(sizeof(evento));

    strcpy(e->tempo, tempo);

    imprimir_evento(remover_elem(e, agenda->eventos));
}

void concluir_evento(t_agenda* agenda){
    remover_prim(agenda->eventos);
}

void main(){
    int d;
    t_agenda* agenda;
    agenda = criar_agenda();

    do{
        scanf("%d%*c", &d);
        if(d == 1){
            evento* e;
            e = ler_evento();
            agendar_evento(agenda, e);
        }
        else if(d == 2){
            printf("%d", quantificar_eventos(agenda));
        }
        else if(d == 3){
            proximo_evento(agenda);
        }
        else if(d == 4){
            int dia, mes, ano, hora, min;
            char tempo[17];
            evento* e;

            scanf("%d/%d/%d", &dia, &mes, &ano);
            scanf("%d:%d", &hora, &min);
            sprintf(tempo,"%d/%d/%d %d:%d", ano, mes, dia, hora, min);
            e = ler_evento();

            alterar_evento(tempo, e, agenda);
        }
        else if(d == 5){
            int dia, mes, ano, hora, min;
            char tempo[17];

            scanf("%d/%d/%d", &dia, &mes, &ano);
            scanf("%d:%d", &hora, &min);
            sprintf(tempo,"%d/%d/%d %d:%d", ano, mes, dia, hora, min);
            printf("\n");
            cancelar_evento(tempo, agenda);
        }
        else if(d == 6){
            concluir_evento(agenda);
        }

    }while(d!=-1);
}
