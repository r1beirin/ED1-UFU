/*
  Integrantes:
    Dathan Vitor Santana da Nobrega - 12111BSI292
    Mateus Ribeiro Vaz Pereira - 12111BSI255
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;

struct node{
  int data;
  Node *next;
};

typedef struct{
  Node *head;
} List;

//  Definição da função TAD newNode para criação de um novo nó da lista.
Node *newNode(bool *deuCerto){
  Node *no;

  no = (Node*) malloc(sizeof(Node));

  if(no == NULL) *deuCerto = false;
  else *deuCerto = true;

  return no;
}

//  Função TAD para remoção de um nó da lista.
void deleteNode(Node *no){
    free(no);
}

//  Criação e inicialização da lista
List *create(bool *deuCerto){
  List *L;
  
  L = (List*)malloc(sizeof(List));
  
  //  Cabeça da lista inicia como NULO.
  if(L != NULL){
    L->head = NULL;
    *deuCerto = true;
  }
  else *deuCerto = false;

  return L;
}

//  Função TAD que retorna se a lista está vazia:
//  0 - não vazia, 1 - vazia.
bool isEmpty(List *L){
  return L->head == NULL;
}

//  Função TAD que retorna se a lista está cheia
//  Como a lista não tem um limite, sempre será retornado false.
bool isFull(List *L){
  return false;
}

//  Função TAD para destruir todos os nós da lista.
void destroy(List *L){
    Node *no, *anterior;

    //  Definição do NÓ e do NÓ anterior.
    no = L->head;
    anterior = NULL;

    while(no != NULL){
        anterior = no;
        no = no->next;
        deleteNode(anterior);
    }
    deleteNode(no);
    L->head = NULL;
}

void insere(List *L, int x, bool *deuCerto){
  Node *no, *lAux;
  bool status;

  no = newNode(&status);  
  no->data = x;
  
  //  1ª Caso: lista vazia
  if(isEmpty(L)){
    no->next = NULL;
    L->head = no;
  }
  else{
    //  2ª Inserir no final da lista
    lAux = L->head;
    while(lAux->next != NULL){
      lAux = lAux->next;
    }
    lAux->next = no;
  }
}

void retira(List *L, int elemento, bool *deuCerto){
    Node *no, *anterior;
    bool status;

    no = L->head;
    anterior = NULL;

    //  Avança até achar o elemento a ser encontrado
    while (no != NULL && no->data != elemento){
        anterior = no;
        no = no->next;
    }

    //  Verifica se elemento foi encontrado
    if(no != NULL && no->data == elemento){
        status = true;
    }
    else status = false;
    
    //  Se status == true, remove o elemento:
    if(status == true){
        if(no != L->head){
            anterior->next = no->next;
            deleteNode(no);
        }
        else{
            L->head = no->next;
            deleteNode(no);
        }
        *deuCerto = true;
    }
    else deuCerto = false;
}

int pertence(Node *no, int elemento){
  if((no->next == NULL && no->data == elemento) || no->data == elemento) return 1;
  else if(no->next == NULL) return 0;
  else return pertence(no->next, elemento);
}

int ultimo(Node *no){
  if(no->next == NULL) return no->data;
  else return ultimo(no->next);
}

int soma(Node *no){
  if(no == NULL) return 0;
  else return no->data + soma(no->next);
}

int soma_impar(Node *no){
  if(no == NULL) return 0;
  else{
    if(no->data % 2 != 0) return no->data + soma_impar(no->next);
    return soma_impar(no->next);
  }
}

int n_esimo(Node *no, int nEsimo){
  //  nEsimo == 1 pois a primeira posição é tratada como 1.
  if(nEsimo == 1) return no->data;
  return n_esimo(no->next, nEsimo - 1);
}

int comprimento(Node *no){
  if(no == NULL) return 0;
  return 1 + comprimento(no->next);
}

int main(){
  List *L;
  bool deuCerto;
  int elemento, nEsimo, aux;
  
  L = create(&deuCerto);

  scanf("%d %d", &elemento, &nEsimo);
  while(scanf("%d", &aux) != EOF){
    insere(L, aux, &deuCerto);
  }

  printf("%d\n", pertence(L->head, elemento));
  printf("%d\n", ultimo(L->head));
  printf("%d\n", soma(L->head));
  printf("%d\n", soma_impar(L->head));
  printf("%d\n", n_esimo(L->head, nEsimo));
  printf("%d\n", comprimento(L->head));

  return 0;
}
