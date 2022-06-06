#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Usar -lm ao fim do comando gcc.
#define PI 3.14

/*
    ===========
    TAD Ponto
    ===========
*/
typedef struct{
    double x;
    double y;
} Ponto;

//  Uso: P1 = criarPonto(x, y); - Declarar P1 como ponteiro para struct Ponto
Ponto *criarPonto(double x, double y){
    Ponto *p;

    p = malloc(sizeof(Ponto));

    if (p != NULL){
        p->x = x;
        p->y = y;
    }
    
    return p;
}

//  destruirPonto(P);
void destruirPonto(Ponto *P){
    free(P);
}

void acessarPonto(Ponto *p, double *x, double *y){
    *x = p->x;
    *y = p->y;
}

//  Uso atribuirPonto(P, &x, &y);
void atribuirPonto(Ponto *p, double *x, double *y){
    p->x = *x;
    p->y = *y;
}

//  Uso: distanciaPonto(P1, P2); - Declarando P1 e P2 como ponteiros para struct Ponto
double distanciaPonto(Ponto *P1, Ponto *P2){
    double x1x2 = pow(P1->x - P2->y, 2);
    double y1y2 = pow(P1->y - P2->y, 2);
    return sqrt(x1x2 + y1y2);
}

/*
    ===========
    TAD Circulo
    ===========
*/
typedef struct{
    Ponto *p;
    double r;
} Circulo;


//  Uso: C = criarCirculo(p, r); - Declarar C como ponteiro para struct Circulo
Circulo *criarCirculo(double x, double y, double raio){
    Circulo *C;

    C = malloc(sizeof(Circulo));

    if(C != NULL){
        C->p = criarPonto(x, y);
        C->r = raio;
    }

    return C;
}

void destruirCirculo(Circulo *C){
    free(C);
}

//  Uso: areaCirculo(C);
double areaCirculo(Circulo *C){
    return PI * (pow(C->r, 2));
}

/*
    Uso: interiorCirculo(P1, C); - Primeiro é instanciado a struct P e depois a struct C
    0 = false
    1 = true
*/
int interiorCirculo(Ponto *P, Circulo *C){
    double val = distanciaPonto(P, C->p);
    if (val <= C->r) return 1;
    else return 0;
}

int main(){
    Ponto *P1, *P2;
    Circulo *C;
    double x, y, p, r;

    printf("Ponto do centro do circulo e o raio (Separados por um espaço. Ex: 5 5 15): ");
    scanf("%lf %lf %lf", &x, &y, &r);
    
    C = criarCirculo(x, y, r);

    printf("Digite X e Y para um ponto qualquer (Separados por um espaço. Ex: 10 20): ");
    scanf("%lf %lf", &x, &y);

    P1 = criarPonto(x, y);

    printf("%d", interiorCirculo(P1, C));

    return 0;
}