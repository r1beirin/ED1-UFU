#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;
struct node{
    char elemento;
    Node *next;
};

//  Implementação do algoritmo de stack.
typedef struct{
    Node *topo;
} Stack;

Node *newNode(bool *deuCerto){
    Node *no;

    no = (Node*) malloc(sizeof(Node));

    if(no == NULL) *deuCerto = false;
    else *deuCerto = true;

    return no;
}

void deleteNode(Node *no){
    if(no != NULL) free(no);
}

Stack *create(bool *deuCerto){
    Stack *S;

    S = (Stack*) malloc(sizeof(Stack));

    if(S == NULL) *deuCerto = false;
    else{
        *deuCerto = true;
        //  Primeiro elemento da stack sera NULL.
        S->topo = NULL;
    }

    return S;
}

bool isFull(Stack *S){
    return false;
}

bool isEmpty(Stack *S){
    return S->topo == NULL;
}

void push(Stack *S, char elemento, bool *deuCerto){
    Node *pAux;
    bool status;

    if(isFull(S)) *deuCerto = false;
    else{
        pAux = newNode(&status);
        if(status == false) *deuCerto = false;
        else{
            pAux->elemento = elemento;
            pAux->next = S->topo;
            S->topo = pAux;
            *deuCerto = true;
        }
    }
}

void pop(Stack *S, char *elemento, bool *deuCerto){
    Node *pAux;

    if(isEmpty(S)) *deuCerto = false;
    else{
        pAux = S->topo;
        *elemento = pAux->elemento;
        S->topo = S->topo->next;
        deleteNode(pAux);
        *deuCerto = true;
    }
}

void destroy(Stack *S){
    char elemento;
    bool deuCerto;

    while(!isEmpty(S)) pop(S, &elemento, &deuCerto);
    free(S);
}

int main(){
    Stack *S;
    bool deuCerto;
    char elemento;

    S = create(&deuCerto);
    if(!deuCerto) printf("Erro\n");

    push(S, 'A', &deuCerto);
    if(!deuCerto) printf("Erro\n");
    push(S, 'B', &deuCerto);
    if(!deuCerto) printf("Erro\n");

    while(!isEmpty(S)){
        pop(S, &elemento, &deuCerto);
        printf("%c\n", elemento);
    }

    destroy(S);

    return 0;
}