#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Header.h"

using namespace std;

int main()
{
    srand(time(NULL));
    char arquivo[50];
    strcpy(arquivo, "toy.txt");
    Solucao sol;
    sol.fo=0;

    ler_instancia(arquivo);


    /*
    printf("Digite as cidades da rota do caixeiro:\n");
    for(int i=0;i<num_cidade;i++){
        scanf("%d", &sol.cidadesVisitadas[i]);
    }
    */

    gerarAleatoria(sol);
    //imprimirDadosIniciais(num_cidade,mat_custo);
    calcularFo(sol);
    imprimirNaTela(sol);
    imprimirNoArquivo(sol, "SaidaTela.txt");


    return 0;
}

void ler_instancia(char *arq){
    FILE *f;
    f=fopen(arq,"r");

    fscanf(f, "%d", &num_cidade);
    for(int i=0;i<num_cidade;i++){
        for(int j=0;j<num_cidade;j++){
            fscanf(f, "%f", &mat_custo[i][j]);
        }
    }

    fclose(f);
}

//Para teste dos dados de entrada
void imprimirDadosIniciais(int inteiro, float matriz[MAX_CIDADE][MAX_CIDADE]) {
    printf("%d\n", num_cidade);
    for(int i=0;i<num_cidade;i++){
        for(int j=0;j<num_cidade;j++){
            printf("%.2f ", mat_custo[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void imprimirNaTela(Solucao &sol){
    printf("FO: %.2f\n", sol.fo);
    printf("Cidades percorridas: Iniciando na cidade ");
    for(int i=0; i<num_cidade;i++){
        printf("[->]:%d   ", sol.cidadesVisitadas[i]);
    }printf("[->]:%d\n", sol.cidadesVisitadas[0]);
    printf("Quantidade p/ cidade: ");
    for(int i=0; i<num_cidade;i++){
        printf("[%d]:%d   ",i , sol.qtdVisitas[i]);
    }printf("\n");
}

void imprimirNoArquivo(Solucao &sol, char *nomeArq){
    FILE *f;
    f=fopen(nomeArq, "w");
    fprintf(f,"FO: %.2f\n", sol.fo);
    fprintf(f,"Cidades percorridas: Iniciando na cidade ");
    for(int i=0; i<num_cidade;i++){
        fprintf(f,"[->]:%d   ", sol.cidadesVisitadas[i]);
    }fprintf(f,"[->]:%d\n", sol.cidadesVisitadas[0]);
    fprintf(f,"Quantidade p/ cidade: ");
    for(int i=0; i<num_cidade;i++){
        fprintf(f,"[%d]:%d   ",i , sol.qtdVisitas[i]);
    }fprintf(f,"\n");
    fclose(f);
}

void calcularFo(Solucao &sol){
    gerarVizinhanca(sol); //Gerando vizinhança direto na fo
    for(int i=0;i<num_cidade;i++){
        sol.qtdVisitas[i]=0;
    }
    for(int i=0;i<num_cidade;i++){
        sol.qtdVisitas[sol.cidadesVisitadas[i]]++;
    }
    for(int i=0;i<num_cidade-1;i++){
            sol.fo+=mat_custo[sol.cidadesVisitadas[i]][sol.cidadesVisitadas[i+1]];
    }sol.fo+=mat_custo[sol.cidadesVisitadas[num_cidade-1]][sol.cidadesVisitadas[0]];
    for(int j=0;j<num_cidade;j++){
        if(sol.qtdVisitas[j]==0) sol.fo+=alfa;
        else if(sol.qtdVisitas[j]>1) sol.fo+=(alfa*(sol.qtdVisitas[j]-1));
    }
}

void gerarGulosa(Solucao &sol){

}

void gerarAleatoria(Solucao &sol){
    int aleatorio;
    for(int i=0; i<num_cidade; i++){
        sol.cidadesVisitadas[i]=0;
    }
    for(int i=0; i<num_cidade; i++){
        if(i==0){
          sol.cidadesVisitadas[i]= rand() % num_cidade;
          continue;
        }
        do{
           aleatorio = rand() % num_cidade;
        }while(sol.cidadesVisitadas[i-1]==aleatorio);
        sol.cidadesVisitadas[i]=aleatorio;
    }
}

void gerarGulosaAleatoria(Solucao &sol){

}

void gerarVizinhanca(Solucao &sol){
    int cidadeAux;
    int aleat = rand() % num_cidade;
    int aleat2;
    do{
        aleat2 = rand() % num_cidade;
    }while(aleat==aleat2);

    cidadeAux = sol.cidadesVisitadas[aleat];
    sol.cidadesVisitadas[aleat]=sol.cidadesVisitadas[aleat2];
    sol.cidadesVisitadas[aleat2]=cidadeAux;

}
