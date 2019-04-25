/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 25 de Abril de 2019, 16:00
 */

#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE
#define linhamax 100

/* inicializacao das estruturas das pilhas */
typedef struct{
    int id;
}obj;

typedef struct nopilha *ponteiro;

typedef struct{
    obj chave;
    ponteiro deBaixo;
}nopilha;



/* pilhas */
typedef struct{
    ponteiro topo; //dinamico = usa no de pilha
    int tam;
}pilhaDINAMICA;

typedef struct {
    obj vetor[255]; //static = usa vetor, nao usa no de pilha
    int topo;
}pilhaESTATICA;




void iniciapilhaDINAMICA(pilhaDINAMICA *pilha){
    pilha->tam=0;
    pilha->topo=NULL; //ponteiro aponta pro null pois tem nada
}

void iniciapilhaESTATICA(pilhaESTATICA *pilha){
    pilha->topo=0; //int indica posicao disponivel para insercao
}

void push(int x, pilhaDINAMICA *pilha){
    nopilha aux;
    aux = (ponteiro) malloc(sizeof(pilhaDINAMICA));
    
    aux->chave.id = x;
    aux->deBaixo = pilha->topo;
    pilha->topo = aux;
    pilha->tam ++;
}

int binariar(int x){
    int array[100];
    for (int i = 0; x > 0; i++){
        array[i] = x%2;
        x = x/2;
    }
    return *array;
}




/*
 * 
 */
int main(int argc, char** argv) {
    FILE *arquivo;
    
    char linha[linhamax];
    
    arquivo = fopen("arq.txt", "r");
    
    
    if (!arquivo){
        printf("Erro na abertura do arquivo");
        return 2;
    }
    else{
        fgets(linha, sizeof(linha), arquivo);
        if (linha == "d"){
            pilhaDINAMICA pilha;
            iniciapilhaDINAMICA(&pilha);

            for(int i = 1; linha[i] != EOF; i++){
                int N;
                fscanf(arquivo, "%i", N);
                
                int convertidoemBinary;
                convertidoemBinary = binariar(N);
                
                push(convertidoemBinary, &pilha);
            }
        }     
    }
    return (EXIT_SUCCESS);
}

