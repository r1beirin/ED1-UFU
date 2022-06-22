#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    int topo;
    char elemento[MAX];
} Stack;

Stack *create(int *status){
    Stack *S;
    S = malloc(sizeof(Stack));

    if(S != NULL){
        S->topo = -1;
        *status = 1;
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
void push(Stack *S, char elem, int *status){
    if(isFull(S)) *status = 0;
    else{
        S->topo += 1;
        S->elemento[S->topo] = elem;
        *status = 1;
    }
}


//  Exemplo de uso: pop(S1, &retorno, &status);
void pop(Stack *S, char *retorno, int *status){
    if(isEmpty(S)) *status = 0;
    else{
        *retorno = S->elemento[S->topo];
        S->topo -= 1;
        *status = 1;
    }
}

/*
    1. Pilha é uma estrutura de dados utilizada para "empacotar" dados
    de alguma forma organizada. O ultimo a entrar é o primeiro a sair.
    Sempre vemos o "topo" em uma pilha. Pode-se usar, como um exemplo,
    pilha para realizar operações matemáticas na forma pós-fixa.

    2. pop(), pop(), pop(), pop();
    push(B), push(D), push(C), push(A).

    3. [10, 30].

    4. Feito
*/

//  Uso     verifica(S1, str1, str2, &status, &resultado);
void verifica(Stack *S1, char *str1, char *str2, int *status, int *resultado){
    char retorno;
    for(int i = 0; i < strlen(str1) && i < strlen(str2); i++){
        push(S1, str1[i], status);
    }

    for(int i = 0; i < strlen(str1) && i < strlen(str2); i++){
        pop(S1, &retorno, status);
        if(retorno != str2[i]) *resultado = 0;
    }
}

int main(){
    int status = 0, resultado = 1;
    Stack *S1;
    S1 = create(&status);
    char str1[20], str2[20];

    scanf("%s", str1);
    scanf("%s", str2);
    verifica(S1, str1, str2, &status, &resultado);

    //  Tratamento de erro.
    if(status == 0) printf("Erro ao empilhar.");

    return 0;
}