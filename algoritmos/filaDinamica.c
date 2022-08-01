#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef struct{
    int primeiro;
    int final;
    int numElementos;
    char *elemento;
} Queue;

Queue *create(bool *deuCerto){
    Queue *Q;

    Q = malloc(sizeof(Queue));
    Q->elemento = malloc(MAX * sizeof(char));

    if(Q == NULL) *deuCerto = false;
    else{
        Q->primeiro = 0;
        Q->final = 0;
        Q->numElementos = 0;
        *deuCerto = true;
    }

    return Q;
}

void delete(Queue *Q, bool *deuCerto){
    if(Q != NULL){
        free(Q);
        *deuCerto = true;
    }
    else *deuCerto = false;
}

bool isEmpty(Queue *Q){
    return Q->numElementos == 0;
}

bool isFull(Queue *Q){
    return Q->numElementos == MAX;
}

void enqueue(Queue *Q, char elemento, bool *deuCerto){
    if(isFull(Q)) *deuCerto = false;
    else{
        Q->elemento[Q->final] = elemento;
        
        if(Q->final == MAX - 1) Q->final = 0;
        else Q->final += 1;

        Q->numElementos += 1;
        *deuCerto = true;
    }
}

void dequeue(Queue *Q, char *elemento, bool *deuCerto){
    if(isEmpty(Q)) *deuCerto = false;
    else{
        *elemento = Q->elemento[Q->primeiro];

        if(Q->primeiro == MAX - 1) Q->primeiro = 0;
        else Q->primeiro += 1;

        Q->numElementos -= 1;
        *deuCerto = true;
    }
}

int main(){
    Queue *Q;
    bool deuCerto;
    char elemento;

    Q = create(&deuCerto);

    if(!deuCerto) printf("Erro na fila.\n");

    enqueue(Q, 'A', &deuCerto);
    enqueue(Q, 'B', &deuCerto);
    enqueue(Q, 'C', &deuCerto);

    if(!deuCerto) printf("Erro na fila.\n");    

    while (!isEmpty(Q)){
        dequeue(Q, &elemento, &deuCerto);
        printf("%c ", elemento);
    }

    delete(Q, &deuCerto);
    if(!deuCerto) printf("Erro na fila.\n");  


    return 0;
}