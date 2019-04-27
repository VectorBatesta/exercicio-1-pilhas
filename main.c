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

typedef struct{
    obj chave;
}binariado;


/* pilhas */
typedef struct{
    ponteiro topo; //dinamico = usa no de pilha
    int tam;
}pilhaDINAMICA;

typedef struct {
    obj vetor[255]; //static = usa vetor, nao usa no de pilha
    int topo;
    int capacidade;
}pilhaESTATICA;




void iniciapilhaDINAMICA(pilhaDINAMICA *pilha){
    pilha->tam=0;
    pilha->topo=NULL; //ponteiro aponta pro null pois tem nada
}

void iniciapilhaESTATICA(pilhaESTATICA *pilha){
    pilha->topo=0; //int indica posicao disponivel para insercao
    pilha->capacidade = 255;
}

void pushDIN(obj x, pilhaDINAMICA *pilha){
    ponteiro aux;
    aux = (ponteiro) malloc(sizeof(nopilha));
    
    aux->chave.id = x;
    aux->deBaixo = pilha->topo;
    pilha->topo = aux;
    pilha->tam ++;
}

int estacheiaEST(pilhaESTATICA *pilha){
    if (pilha->topo == pilha->capacidade - 1){
        return 1;
    }
    else
        return 0;
}

void pushEST(obj x, pilhaESTATICA *pilha){
    if (estacheiaEST(pilha)){
        printf("PILHA ESTATICA ESTA CHEIA, AUMENTAR TAMANHO DA PILHA ESTATICA"
                "NO ALGORITMO!!!");
    }
    else {
        obj aux;
        aux = x;
        pilha[pilha->topo] = aux;
        pilha->topo = pilha->topo + 1;
    }
}












void popEST(pilhaESTATICA *pilha, binariado *binariado){
    int x;

    x = pilha[pilha->topo - 1];
    pilha->topo = pilha->topo - 1;
    
    int array;
    array = (ponteiro) malloc(sizeof(binariado));
    
    for (int i = 0; x > 0; i++){
        array[i] = x%2;
        x = x / 2;
    }
    
    binariado->chave.id = array;
}















void printPilhaEST(pilhaESTATICA *pilha){
    printf("Valores na pilha:");
    for (int i = pilha->topo; i >= 0; i--){
        printf("%i, ", pilha->topo);
        pilha->topo --;
    }
}

void printPilhaDIN(pilhaDINAMICA *pilha){
    printf("Valores na pilha:");
    for (int i = pilha->tam; i >= 0; i--){
        ponteiro aux;
        aux = pilha->topo;
        printf("%i, ", pilha->topo->chave.id);
        aux = aux->deBaixo;
    }
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
    arquivoSaida = fopen("arqsaida.txt", "w+");
    
    
    if (!arquivoEntrada){
        printf("Erro na abertura do arquivo");
        exit(EXIT_FAILURE);
    }

    fscanf(arquivoEntrada, "%c", &letra);

    if (letra == 'd'){
        iniciapilhaDINAMICA(&pilhaNumerosDin);
        usarDinamica = true;
    } else if(letra == 'e') {
        iniciapilhaESTATICA(&pilhaNumerosEst);
        usarDinamica = false;
    } else {
        printf("Erro\n");
        exit(EXIT_FAILURE);
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



            // 3 - escrever no arquivo de saida
    if(!usarDinamica) {
        printPilhaEST(&pilhaNumerosEst);
        
        int N;
        N = (ponteiro) malloc(sizeof(binariado));
        
        for(int i = 2; linha[i] != EOF; i++){
            popEST(&pilhaNumerosEst, &N);
            fprintf(arquivoSaida, "%d\n", N);
        }

    } else {
        printPilhaDIN(&pilhaNumerosDin);
        for(int i = 1; linha[i] != EOF; i++){
            int N;
            
            
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    
    
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