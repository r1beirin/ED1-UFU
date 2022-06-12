#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int topo;
    int elemento[MAX];
} Stack;

Stack *create(){
    Stack *S;
    S = malloc(sizeof(Stack));

    if(S != NULL){
        S->topo = -1;
    }

    return S;
}

void delete(Stack *S){
    free(S);
}

int isEmpty(Stack *S){
    if(S->topo == -1) return 1;
    else return 0;
}

int isFull(Stack *S){
    if(S->topo == MAX) return 1;
    else return 0;
}

//  Exemplo de chamada na main push(S, 30, &status);
void push(Stack *S, int elem, int *status){
    if(isFull(S)) *status = 0;
    else{
        S->topo++;
        S->elemento[S->topo] = elem;
        *status = 1;
    }
}

int main(){
    int status = 0;
    Stack *S;
    S = create();

    push(S, 10, &status);

    //  Tratamento de erro.
    if(status == 0) printf("Erro ao empilhar.");
    else printf("Elemento %d na pos %d\n", S->elemento[S->topo], S->topo);

    return 0;
}