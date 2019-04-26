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
#include <stdbool.h>

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

void pushDIN(int x, pilhaDINAMICA *pilha){
    ponteiro aux;
    aux = (ponteiro) malloc(sizeof(nopilha));
    
    aux->chave.id = x;
    aux->deBaixo = pilha->topo;
    pilha->topo = aux;
    pilha->tam ++;
}

void pushEST(int x, pilhaESTATICA *pilha){
    pilha[pilha->topo] = x;
    pilha->topo = pilha[pilha->topo + 1];
}

int binariar(int x){
    
//    for(int k = x; k!=0; k=k/2) 
    //    v = k%2
//        push(v)

    int array[100];
    for (int i = 0; x > 0; i++){
        array[i] = x%2;
        x = x/2;
    }
    return *array;
}



void printPilhaEST(pilhaESTATICA *pilha){
    
}

void printPilhaDIN(pilhaDINAMICA *pilha){
    
}










/*
 * 
 */

FILE *arquivoEntrada;
FILE *arquivoSaida;
    
pilhaDINAMICA pilhaNumerosDin;
pilhaESTATICA pilhaNumerosEst;


int main(int argc, char** argv) {
   
    
    char linha[linhamax];
    char letra;
    bool usarDinamica;
  
    // - CHECAR argc e ARGV
//    if()argc != 3 -- erro
//    argv[1] = string, nome do arquivo de entrada
//    argv[2] = string, nome do arquivo de saida
    
    
    arquivoEntrada = fopen("arq.txt", "r");
    //arquivoEntrada = fopen(argv[1], "r");
    
    
    if (!arquivoEntrada){
        printf("Erro na abertura do arquivo");
        return 2;
    }
    else{
        
        fscanf(arquivoEntrada, "%c", &letra);
        
        if (letra == "d"){
            iniciapilhaDINAMICA(&pilhaNumerosDin);
            usarDinamica = true;
        } else if(letra == "e") {
            iniciapilhaESTATICA(&pilhaNumerosEst);
            usarDinamica = false;
        } else {
            printf("Erro\n");
            exit();
        }
        
        
        for(int i = 1; linha[i] != EOF; i++){
            int N;
            fscanf(arquivoEntrada, "%i", &N);
            obj numero;
            numero.id = N;
            if(usarDinamica) {
                pushDIN(numero, &pilhaNumerosDin);
            } else {
                pushEST(numero, &pilhaNumerosEst);
            }
        }
        
        // imprimir pílha
        if(!usarDinamica) {
            printPilhaEST(&pilhaNumerosEst);
        } else {
            printPilhaDIN(&pilhaNumerosDin);
        }
        
        
        // 2 - Conversao dos numeros
        
        // 3 - escrever no arquivo de saida
        
        // 4 - fechar os arquivos de entrada e saida
        fclose(arquivoEntrada);  
    }
    
    
    
    return (EXIT_SUCCESS);
}


/*

10    
101
110


- pilhaNumeros
- PilhaConversao

leitura
- ler um numero
- push na pilha de Numeros

Pilha (cheia de numeros inteiros) já na ordem inversa

Conversao

- eqnto a pilha não estiver vazia
	- pop
	- Binariar
	- escreve no arquivo de saida
	

Binariar (num)
	- inicializa PilhaNumeros = vazia


*/