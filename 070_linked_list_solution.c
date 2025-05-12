/*

Programmer: Felipe Rosa
Date: 12/05

*/

#include <stdio.h>  
#include <stdlib.h>
#include <stdlib.h>   /* exit, EXIT_FAILURE */

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
} List_linked_list;




/* ------------------------------------------ */
/* Prototipos das funcoes                     */

/* Funcoes construtoras*/
Node *create_List_node(int value);
List_linked_list *create_List_linked_list();

/* get */
int get_value(List_linked_list* l);
int curr_pos(List_linked_list* l);
int length(List_linked_list* l);

/* insert items */
void insert(List_linked_list *l, int value);
void append(List_linked_list *l, int value);

/* move cursor */
void move_to_start(List_linked_list* l);
void move_to_end(List_linked_list* l);
void prev(List_linked_list* l);
void next(List_linked_list* l);
void move_to_pos(List_linked_list* l, int pos);

/* remove clear destroy */
static void reset_list(List_linked_list *l);
void clear(List_linked_list *l);
void destroy(List_linked_list **pl);
static int list_is_empty(const List_linked_list *l);
int remove_list(List_linked_list *l);

/* show entire list and cursors */
void printList(const List_linked_list *l);

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


List_linked_list *create_List_linked_list(){

    List_linked_list *l = (List_linked_list *)malloc(sizeof(List_linked_list)); /* aloca memória para a list*/

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
int get_value(List_linked_list* l){

    if(l->curr->next) {
        return l->curr->next->value;
    } else {
        printf("***EXIT ERROR***: O cursor nao encontrou nada a direita para retornar\n");
        exit(EXIT_FAILURE);          /* encerra o programa */
    }
}

/* retorna o tamanho da lista, sem contar o cabeçalho */
int length(List_linked_list* l){
    return l->size;
}

/* retorna a posição atual do cursor*/
int curr_pos(List_linked_list* l){

    int i = 0;
    
    Node* temp = l->head;
    while( temp != l->curr ) {
        i++;
        temp = temp->next;
    }

    return i;
}


/* Implementações insert -------------------- */

/* insert: insere à direita do cursor */
void insert(List_linked_list *l, int value) {

    Node *new_node = create_List_node(value); /* cria um novo nó*/

    if ( l->curr != l->tail ) { /* se o cursor nao estiver no final */
        new_node->next = l->curr->next;
        l->curr->next = new_node;
        l->size++;
    } else {
        new_node->next = NULL;
        l->tail = new_node;
        l->curr->next = l->tail;
        l->size++;
    }

}

/* append: insere no final */
void append(List_linked_list *l, int value) {

    Node *new_node = create_List_node(value);
    l->tail->next = new_node;
    l->tail = new_node;
    l->size++;

}


/* Implementações move cursor ---------------- */

/* move o cursor para o primeiro nó, o nó head*/
void move_to_start(List_linked_list* l){
    l->curr = l->head;
}

/* move o cursor para o último nó, nó cauda */
void move_to_end(List_linked_list* l){
    l->curr = l->tail;
}

/* move o cursor para o nó anterior */
void prev(List_linked_list* l){

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
void next(List_linked_list* l){

    if(l->curr->next) {
        l->curr = l->curr->next;
    } 
}


/* move o cursor para uma posição especificada */
void move_to_pos(List_linked_list* l, int pos){

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
static void reset_list(List_linked_list *l) {
    l->head->next = NULL;
    l->tail = l->curr = l->head;
    l->size = 0;
}

/* remove todos os elementos da lista e reinicializa a TAD */
void clear(List_linked_list *l) {
    if (l == NULL) return;

    Node *node = l->head->next;     /* primeiro nó de dado */
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    reset_list(l);                  /* zera metadados */
}

void destroy(List_linked_list **pl) {
    if (pl == NULL || *pl == NULL) return;

    List_linked_list *l = *pl;

    clear(l);           /* remove nós de dados (não libera sentinela) */

    free(l->head);      /* libera o sentinela */
    free(l);            /* libera a própria lista */

    *pl = NULL;         /* evita ponteiro pendurado */
}

/* retorna 1, se for uma lista vazia, e 0 se for uma lista com elementos*/
static int list_is_empty(const List_linked_list *l) {
    
    if( !l->head->next ) {
        return 1;
    } else {
        return 0;
    }

}


/* remove um elemento a direita do cursor e o retorna*/
int remove_list(List_linked_list *l) {
    
    if (l == NULL || l->curr == NULL || l->curr->next == NULL) {
        return -1;
    } else {
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


}


/* exibe a lista, e seus cursores 
   { -> ponteiro head
   | -> ponteiro curr
   } -> ponteiro tail */
void printList(const List_linked_list *l) {

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

int count_list(const List_linked_list *l, int value) {

    Node *temp = l->head;
    int i = 0;
    while(temp) {
        if(temp->value == value) {
            i++;
        }
        temp = temp->next;
    }
    return i;
}

int main() {
     
    int c, n, value;
    char command[50];

    scanf("%d", &c);


    for(int i = 1; i < c + 1; i++) { // testcases
        scanf("%d", &n);

        List_linked_list *L = create_List_linked_list();
        printf("Caso %d:\n", i);
        for(int j = 0; j < n; j++) { // each testcase
            scanf("%s", command);

            if(!strcmp(command, "insert") || !strcmp(command, "count")) {
                scanf("%d", &value);
            } else {
                value = NULL;
            }



            if(!strcmp(command, "insert")) {
                insert(L, value);
            } else if(!strcmp(command, "next")) {
                next(L);
            } else if(!strcmp(command, "prev")) {
                prev(L);
            } else if(!strcmp(command, "remove")) {
                remove_list(L);
            } else if(!strcmp(command, "count")) {
                printf("%d\n", count_list(L, value));
            }
            
        }

        destroy(&L);
    }

}