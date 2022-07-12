#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 30

//  Definição de struct Pair contendo i e j para manipulação na pilha.
typedef struct{
    int i;
    int j;
}Pair;

//  Definição da Pilha contendo o topo e um vetor contendo i,j como elementos unicos.
typedef struct{
    int top;
    Pair *vet;
}Stack;

//  Função booleana que verifica se a pilha está vazia
bool empty(Stack *S){
    return S->top == -1;
}

//  Função booleana que verifica se a pilha está cheia
bool full(Stack *S){
    return S->top == MAX-1;
}

/*
    A função pop modifica os valores passados por referência de i e j.
    Decrementa o topo da pilha em 1 unidade.
*/
bool pop(Stack *S, int *i, int *j){
    if(empty(S)) return false;
    else{
        *i = S->vet[S->top].i;
        *j = S->vet[S->top].j;
        S->top = S->top - 1;
        return true;
    }
}

/*
    A função push atualiza os valores do vetor do tipo pair na pilha.
    Aumenta o topo em 1 unidade.
*/
bool push(Stack *S, int i, int j){
    if(full(S)) return false;
    S->top = S->top + 1;
    S->vet[S->top].i = i;
    S->vet[S->top].j = j;
    return true;
}

/*
    Criação e alocação dinâmica da pilha e do vetor do tipo pair.
    Inicialização do topo em -1.
*/
Stack* criar(){
    Stack *P;

    P = (Stack*)malloc(sizeof(Stack));
    P->vet = (Pair*)malloc(MAX*sizeof(Pair));
    if(P!=NULL) P->top = -1;
    return P;
}

bool destruir(Stack *S){
    free(S);
    return true;
}

//  Função armazenamento que passa por referência num de vertices, num de arestas e matriz.
void armazenamento(int vertice, int arestas, int matriz[vertice][vertice]){

    //  Inicia todas as posições da matriz como peso 0.
    for (int i = 0; i < vertice; i++){
        for (int j = 0; j < vertice; j++){
            matriz[i][j] = 0;
        }
    }

    //(a =1,b = 2, c = 3, etc.)
    for (int k = 0; k < arestas; k++){
        int i, j, x;
        scanf("%d %d %d", &i, &j, &x);
        matriz[i-1][j-1]=x;
    }
}

/*
    Função procura que realiza a procura e a soma
    de um caminho em um grafo inserido na matriz.
*/
int procura(int vertice, int matriz[vertice][vertice], Stack *S,int ini, int fim){
    bool deuCerto;

    for (int i = ini-1, j=1; j <= vertice; j++){
        /*
            Caso 1 de parada: se o valor encontrado for igual a 0 e a coluna for a ultima
            Desempilha o topo da pilha, i e j recebem novos valores (do vertice anterior)
        */
         if(matriz[i][j] == 0 && j >= vertice-1){
            deuCerto = pop(S, &i, &j);
            if(!deuCerto) return -1;
            else continue;
        }
        
        /*
            Caso 2 de parada: se o valor for diferente de 0 e coluna for a escolhida
            Usa um while para desempilhar tudo e realizar a soma.
        */
        if(matriz[i][j] != 0 && j == fim-1){
            int soma = matriz[i][j];
            while (pop(S,&i,&j)){
                soma += matriz[i][j];
            }
            return soma;
        }

        /*
            Caso base: se o valor for 0, j++ do for.
            Se não for 0, então empilha i e j,
            após isso, a linha é modificada (recebe j) e coluna retorna ao inicio.
        */
        if(matriz[i][j] == 0) continue;
        else{
            push(S, i, j);
            i = j;
            j = -1; //  J volta sendo -1 pois quando voltar o loop ele começa no zero. (j++)
        }
    }
}

int main(){
    int valor, vertice, arestas, ini, fim;
    Stack *S;
    S = criar();

    scanf("%d %d", &vertice, &arestas);
    int matriz[vertice][vertice];

    armazenamento(vertice, arestas, matriz);
    
    scanf("%d %d", &ini, &fim);
    valor = procura(vertice, matriz, S, ini, fim);

    printf("%d\n", valor);
}