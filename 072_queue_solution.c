/*

Programmer: Felipe Rosa
Date: 11/05

*/

#include <stdio.h>  
#include <stdlib.h>
#include <stdlib.h>   /* exit, EXIT_FAILURE */
#include <string.h>


/* Estruturas */
/* Estrutura que representa um nó da linked list,
conectado ao próximo nó, o último nó apontar para NULL */
typedef struct Node {
    int value;
    struct Node* next; /* dentro da estrutura, temos que usar struct Node,
                        pois a estrutura ainda nao esta definida */
} Node;

/* Estrutura que organiza os nós como um todo, 
também utilizado para guardar alguns metadados globais da estrutura*/
typedef struct List {
    int size;
    Node *head, *tail, *curr;
} Queue_linked_list;




/* ------------------------------------------ */
/* Prototipos das funcoes                     */

/* Funcoes construtoras*/
Node *create_List_node(int value);
Queue_linked_list *create_List_linked_list();

/* get */
int frontValue(Queue_linked_list* l);
int length(Queue_linked_list* l);

/* insert items */
void enqueue(Queue_linked_list *l, int value);

/* remove clear destroy */
static void reset_list(Queue_linked_list *l);
void clear(Queue_linked_list *l);
void destroy(Queue_linked_list **pl);
static int list_is_empty(const Queue_linked_list *l);
int remove_list(Queue_linked_list *l);

/* show entire list and cursors */
void printList(const Queue_linked_list *l);

/* ------------------------------------------ */
/* Implementações --------------------------- */

/* Implementações Funcoes construtoras ------ */

Node *create_List_node(int value){

    Node *n = (Node *)malloc(sizeof(Node)); /* aloca memória para um nó */

    if(!n) { /* verifica se a alocação de memória foi bem sucedida */
        return NULL;
    }

    n->value = value;
    n->next = NULL;
    return n;

}


Queue_linked_list *create_queue_linked_list(){

    Queue_linked_list *l = (Queue_linked_list *)malloc(sizeof(Queue_linked_list)); /* aloca memória para a list*/

    if(!l) { /* verifica se a alocação de memória foi bem sucedida */
        return NULL;
    }

    Node *node_head = create_List_node(0);

    l->size = 0;
    l->head = l->tail = l->curr = node_head;
    return l;

}


/* Implementações get ----------------------- */

/* retorna a o valor a direita do cursor */
int frontValue(Queue_linked_list* l){

    if(l->curr->next) {
        return l->tail->value;
    } else {
        printf("***EXIT ERROR***: O cursor nao encontrou nada a direita para retornar\n");
        exit(EXIT_FAILURE);          /* encerra o programa */
    }
}

/* retorna o tamanho da lista, sem contar o cabeçalho */
int length(Queue_linked_list* l){
    return l->size;
}


/* Implementações insert -------------------- */


void enqueue(Queue_linked_list *l, int value) {

    Node *new_node = create_List_node(value);
    l->tail->next = new_node;
    l->tail = new_node;
    l->size++;

}



/* Implementações move cursor ---------------- */

/* move o cursor para o primeiro nó, o nó head*/
void move_to_start(Queue_linked_list* l){
    l->curr = l->head;
}

/* move o cursor para o último nó, nó cauda */
void move_to_end(Queue_linked_list* l){
    l->curr = l->tail;
}

/* move o cursor para o nó anterior */
void prev(Queue_linked_list* l){

    Node* temp = l->head;

    if(l->curr != l->head) {
        while(temp->next != l->curr) {
            temp = temp->next;
        }
    
        l->curr = temp;
    } else {
        printf("Nao tem posicoes possiveis anteriores na linkedlist\n");
    }
    
}

/* move o cursor da lista para o próximo nó */
void next(Queue_linked_list* l){

    if(l->curr->next) {
        l->curr = l->curr->next;
    } else {
        printf("Nao tem posicoes possiveis a frente na linkedlist\n");
    }
}

/* move o cursor para uma posição especificada */
void move_to_pos(Queue_linked_list* l, int pos){

    int i = 0;
    if(pos < l->size && pos > 0) {
        for(int i = 0; i < pos; i++) {
            next(l);
        }
    } else if (pos == 0){
        move_to_start(l);
    } else {
        printf("Posicao acima das possiveis\n");
    }
    
}


/* Implementações remove clear destroy  -------- */

/* devolve a lista ao estado "vazia" usando o sentinela já existente */
static void reset_list(Queue_linked_list *l) {
    l->head->next = NULL;
    l->tail = l->curr = l->head;
    l->size = 0;
}

/* remove todos os elementos da lista e reinicializa a TAD */
void clear(Queue_linked_list *l) {
    if (l == NULL) return;

    Node *node = l->head->next;     /* primeiro nó de dado */
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    reset_list(l);                  /* zera metadados */
}

void destroy(Queue_linked_list **pl) {
    if (pl == NULL || *pl == NULL) return;

    Queue_linked_list *l = *pl;

    clear(l);           /* remove nós de dados (não libera sentinela) */

    free(l->head);      /* libera o sentinela */
    free(l);            /* libera a própria lista */

    *pl = NULL;         /* evita ponteiro pendurado */
}

/* retorna 1, se for uma lista vazia, e 0 se for uma lista com elementos*/
static int list_is_empty(const Queue_linked_list *l) {
    
    if( !l->head->next ) {
        return 1;
    } else {
        return 0;
    }

}


/* remove um elemento a direita do cursor e o retorna*/
/* remove um elemento a direita do cursor e o retorna*/
int dequeue(Queue_linked_list *l) {
    if (l == NULL || l->curr == NULL || l->curr->next == NULL) {
        return 0;
    }

    Node *removido = l->curr->next;      /* nó que será removido */
    int   value  = removido->value;      /* salva valor antes de liberar */

    /* religa a lista: cursor → nó seguinte ao removido */
    l->curr->next = removido->next;

    /* se o removido era o último, ajusta tail */
    if (removido == l->tail) {
        l->tail = l->curr;
    }
        
    free(removido);
    l->size--;

    return value;
}


/* exibe a lista, e seus cursores 
   { -> ponteiro head
   | -> ponteiro curr
   } -> ponteiro tail */
void printList(const Queue_linked_list *l) {

    if(list_is_empty(l) && l->curr == l->tail && l->tail == l->curr) {
        printf("<{|}>\n");
        return;  
    }

    Node* temp;
    if( l->head->next) {
        temp = l->head;
        printf("<{");

        if(temp == l->curr) {
            printf("|");
        }

        temp = temp->next;
    } 

    while(temp) {
        
        
        printf("%d", temp->value);

        if(temp == l->curr) {
            printf("|");
        } else if (temp->next) {
            printf(", ");
        }

        if(temp == l->tail) {
            printf("}>\n");
            return;
        }


        temp = temp->next;
    }
}


int main() {
     
    int c, value, sum;
    char end[4];
    char command[50];

    scanf("%d", &c);


    for(int i = 1; i < c + 1; i++) { // testcases

        Queue_linked_list *L = create_queue_linked_list();
        printf("Caso %d:\n", i);

        while(scanf("%s", command) == 1 && strcmp(command, "end") != 0) { // each testcase

            if(!strcmp(command, "enqueue") || !strcmp(command, "dequeue")) {
                scanf("%d", &value);
            } 

            if(!strcmp(command, "enqueue")) {
                enqueue(L, value);
            } else if(!strcmp(command, "dequeue")) {
                sum = 0;
                for(int a = 0; a < value; a++) {
                    sum += dequeue(L);
                }
                printf("%d\n", sum);
            }
            
        }
        

        destroy(&L);
    }

}