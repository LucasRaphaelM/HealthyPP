/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include "BancoDeDadosNomes.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"



void insereBancoDeDados(listaDePessoas *lista)
{

    int id =1;
    char corpo [10][60] = {"DANIEL SIQUEIRA MONTEIRO",
                           "LUCAS RAPHAEL MOREIRA NOGUEIRA",
                           "DIOGO CESAR SILVA LIMA",
                           "BRUNO DE TOLEDO NICOLIELLO",
                           "JOAO GABRIEL MOREIRA NOGUREIRA",
                           "LUIZ ANTONIO",
                           "RENATA DE SOUSA MOREIRA NOGUEIRA",
                           "ANA ALICE",
                           "SANDY ROSA MELO FRANCO",
                           "VITOR MANOEL CASTRO FERREIRA"};
    char genero[10][10] = {"MASCULINO",
                           "MASCULINO",
                           "MASCULINO",
                           "MASCULINO",
                           "MASCULINO",
                           "MASCULINO",
                           "FEMININO",
                           "FEMININO",
                           "FEMININO",
                           "MASCULINO"};
    float altura[10] = { 1.84,1.84,1.64,1.70,1.76,1.66,1.70,1.60,1.65,1.74};
    float peso[10] = { 72,73,72,65,85,65,95,59,60,76};
    char tipoSangue[10][4] = {"AB+","O+","A-","A+","O+",
                              "AB-","O-","B+","A-","O-"};
    char medicacoes[60] = "DESCONHECIDAS";
    char historico[60] = "PRIMEIRA VEZ";



    for(id=1; id<11; id++)
    {
        inserePessoa(lista, corpo[id-1], id);
        insereInfo(lista,corpo[id-1],genero[id-1],altura[id-1],peso[id-1],tipoSangue[id-1],medicacoes);
        insereHistoricoM(lista,corpo[id-1],historico, id);
    }
}

