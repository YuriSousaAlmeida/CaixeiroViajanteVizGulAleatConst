#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX_CIDADE 200
#define alfa 100

int num_cidade;
float mat_custo[MAX_CIDADE][MAX_CIDADE];

typedef struct Tsolucao{
    float fo;
    int cidadesVisitadas[MAX_CIDADE];
    int qtdVisitas[MAX_CIDADE];
}Solucao;

void ler_instancia(char *arq);
void imprimirDadosIniciais(int inteiro, float matriz[MAX_CIDADE][MAX_CIDADE]);
void imprimirNaTela(Solucao &sol);
void imprimirNoArquivo(Solucao &sol, char *nomeArq);
void calcularFo(Solucao &sol);
void gerarGulosa(Solucao &sol);
void gerarAleatoria(Solucao &sol);
void gerarGulosaAleatoria(Solucao &sol);
void gerarVizinhanca(Solucao &sol);
#endif
