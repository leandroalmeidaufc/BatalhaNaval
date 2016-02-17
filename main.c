/**********************************************************************************
***********************************************************************************
                                BATALHA NAVAL
TRABALHO PRATICO DA DISCIPLINA DE PROGRAMAÇÃO (CK0110) 2015.2
 
 GABRIEL SOUSA FIRMINO - 362963 (TURMA DE TERÇA-FEIRA)
    DENSEVOLVIMENTO DA PARTE "GRÁFICA" E DA FUNÇÃO PRINCIPAL DAS JOGADAS DO COMPETIDOR MAQUINA,ONDE ERA SORTEADA 
    A POSIÇÃO QUE ELA ATACARIA E VERIFICAVA TODAS AS POSSIÇÕES POSSIVEIS QUANDO HOUVESSE ACERTO DA
    EM UMA EMBARCAÇÃO(INTELIGENCIA DA JOGADA), TAMBEM  REALIZOU OPERAÇÕES PARA TRABALHO COM A STRUCT E 
    AUXILO NAS DEMAIS FUNÇÕES DO PROGRAMA TRABALHADAS EM GRUPO;
 LEANDRO ALMEIDA DE CARVALHO - 362973 (TURMA DE QUINTA-FEIRA)
    ALOCOU NA MEMORIA DA STRUCT CRIADA,TODAS AS EMBARCAÇÕES MEDIANTE AS FUNÇÕES RANDOMICAS VALIDANDO O 
    PREENCHIMENTO DA "Celula" PARA QUE NÃO HOUVESSE CONFLITO E PREENCHMENTO REPETIDO DOS BARCOS, ALEM DE 
    TRABALHAR NA RANDOMIZAÇÃO E PADRONIZAÇÃO DA ALEATORIEDADE TAMBÉM AUXILOU NAS DEMAIS FUNÇÕES DO PROGRAMA
    TRABALHADAS EM GRUPO;
 VICTOR LUCAS DEODATO - 362988 (TURMA DE TERÇA-FEIRA)
    DENSOLVIMENTO DA FUNÇÃO DE ENTRADA E VALIDAÇÃO DAS JOGADAS DO COMPETIDOR HUMANO, EXCLUINDO QUALQUER OUTRAS
    POSSIBILIDADES DE ENTRADA QUE NÃO FOSSEM VALIDAS, ALEM DE TRABALHO DE AUXILO AS FUNÇÕES DE ALEATORIEDADE E 
    AUXILO NAS DEMAIS FUNÇÕES DO PROGRAMA TRABALHADAS EM GRUPO;

 
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./biblioteca.h"
#define VERTICAL 1
#define HORIZONTAL 0
#define ESQUERDA 1
#define DIREITA 0
#define VERDADE 1
#define FALSO 0

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO MAIN PRINCIPAL ONDE SÃO INICIALIZADOS O TABULEIRO DOS COMPETIDORES E A LISTA DE POSSIBILIDADES(USADA PARA 
    IDENTIFICAR AS POSSIVEIS JOGADAS DO COMPETIDOR MAQUINA)

 **********************************************************************************************************************/

int main(int argc, char const *argv[]) 
{
    Tabuleiro *tabuleiroJogador;
    Tabuleiro *tabuleiroMaquina;
    ListaPossibilidades *lista;
 
    Posicao jogadaHumano;
    Posicao jogadaComputador;

    srand(time(NULL));
 
    tabuleiroJogador = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    inicializarTabuleiro(tabuleiroJogador);
 
    tabuleiroMaquina = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    inicializarTabuleiro(tabuleiroMaquina);
 
    alocarEmbarcacoes(tabuleiroMaquina);
    alocarEmbarcacoes(tabuleiroJogador);

    lista = (ListaPossibilidades*) malloc(sizeof(ListaPossibilidades));
    lista->vazio = VERDADE;
    
    imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
    getchar();

    while (VERDADE) 
    {
        jogadaHumano =  humanoJoga(tabuleiroJogador,tabuleiroMaquina);  
        imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
        getchar();

        jogadaComputador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
        imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
        getchar();

        printf("Ultima jogada do Computador: [%d][%d]\n",jogadaComputador.linha+1,jogadaComputador.coluna+1);
        printf("Ultima jogada do Humano: [%d][%d]\n",jogadaHumano.linha+1,jogadaHumano.coluna+1);
    }

    return 0;
}