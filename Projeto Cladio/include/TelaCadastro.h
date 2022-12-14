#include "BancoDeDadosNomes.h"

typedef struct
{
    char id[4];
    int idI;
    char alturac[5];
    char pesoc[6];
    char nome[40];
    char genero[10];
    float altura;
    float peso;
    char tipoSangue[4];
    char medicacoes[60];
    char historico[60];
} receber;

int TelaCadastro(listaDePessoas *);