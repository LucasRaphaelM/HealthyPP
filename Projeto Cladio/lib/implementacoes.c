/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include <string.h>
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

int inserePessoa(listaDePessoas *q, char nome[40], int id)
{
    struct pessoa *aux, *umAnterior, *atual;
    aux = (struct pessoa*) malloc(sizeof(struct pessoa));

    if (aux == NULL)
        return 0;

    //aux = q->inicio;
    // Lista vazia, portanto insere no primeiro lugar da lista
    if (q->inicio == NULL)
    {
        strcpy(aux->nome, nome);
        aux->id = id;
        aux->info = NULL;
        q->inicio = aux;
        q->fim = aux;
        aux->proximo = q->inicio;
        aux->anterior = q->fim;
        return 1;
    }

    // Lista não vazia, portanto insere um novo inicio
    if (strcmp(q->inicio->nome,nome) > 0)//USANDO STRCMP PARA COMPARAR OS NOMES E ENCAIXALOS NA LISTA EM FORMA ALFABETICA
    {
        strcpy(aux->nome, nome);
        aux->id = id;
        aux->info = NULL;
        aux->proximo = q->inicio;
        q->inicio->anterior = aux;
        q->inicio = aux;
        q->fim->proximo = aux;
        aux->anterior = q->fim;
        return 1;
    }

    // Lista não vazia, portanto insere um novo final
    if (strcmp(q->fim->nome,nome) < 0)//USANDO STRCMP PARA COMPARAR OS NOMES E ENCAIXALOS NA LISTA EM FORMA ALFABETICA
    {
        strcpy(aux->nome, nome);
        aux->id = id;
        aux->info = NULL;
        q->fim->proximo = aux;
        aux->anterior = q->fim;
        aux->proximo = q->inicio;
        q->fim = aux;
        q->inicio->anterior = q->fim;
        return 1;
    }

    // Lista não vazia, portanto insere no meio
    umAnterior = q->inicio;
    atual = q->inicio->proximo;
    while (strcmp(atual->nome,nome) < 0)//USANDO STRCMP PARA COMPARAR OS NOMES E ENCAIXALOS NA LISTA EM FORMA ALFABETICA
    {
        umAnterior = atual;
        atual = atual->proximo;
    }
    strcpy(aux->nome, nome);
    aux->id = id;
    aux->info = NULL;
    aux->proximo = atual;
    aux->anterior = umAnterior;
    umAnterior->proximo = aux;
    atual->anterior = aux;
    return 1;
}


void mostra(listaDePessoas *q)
{
    struct pessoa *aux;
    int y = 0;

    if (q->inicio == NULL)
    {
        printf("Lista vazia...\n\n");
    }
    else
    {
        aux = q->inicio;
        do
        {
            BeginDrawing();
            DrawText(aux->nome,0,y,40,BLACK);
            EndDrawing();
            y+=50;
            aux = aux->proximo;
        } while (aux != q->inicio);//PERCORRE POR TODA A LISTA PRINTANDO NA TELA O NOME E O ID DE TODOS ATÉ VOLTAR PRO INICIO DA LISTA
    }
}


int pesquisaPorNome(listaDePessoas *q, char nome[40])
{
    int i=0;
    int j=0;
    int k=0;
    int printa=0;
    int achou=0;
    int y = 90;


    struct pessoa *aux;

    aux = q->inicio;

    //esse do-while é o responsavel por andar pela lista princial que contem ID e NOME
    do
    {
        //esse do-while é o responsavel por comparar cada letra do nome digitado com os nomes ja cadastrados
        do
        {
            //if responsavel por comparar pelo menos 3 letras iguais ja printa o NOME e ID e ja passa para o proximo da lista
            if(aux->nome[i] == nome[j])
            {
                i++;//i++ E j++ ANDAM JUNTOS
                j++;
                printa++;//PRINTA++ QUANDO CHEGAR A 3, SIGNIFICA QUE PELO MENOS 3 LETRAS ESTÃO IGUAIS, ENTÃO ENTRA NO IF E PRINTA O ID E O NOME DA PESSOA QUE SE IGUALOU PELO MENOS 3 LETRAS
                if(printa >= 3)
                {
                    //BeginDrawing();
                    DrawText(aux->nome,10,y,40,BLACK);
                    DrawText(TextFormat("ID: %d", aux->id),1120,y,40,BLACK);
                    //EndDrawing();
                    y += 60;
                    k++;
                    i = k;
                    j = 0;
                    printa = 0;
                    achou = 1;
                    break;
                }
            }
            else//CASO CONTRARIO RESETA AS VARIAVEIS PARA PODER PASSAR POR TODAS AS POSSIBILIDADES POSSIVEIS
            {
                k++;
                i = k;
                j = 0;
                printa = 0;
            }
        }while(i < strlen(aux->nome));//FICA NO LOOP ATÉ PASSAR POR TODO O NOME QUE ESTA NA LISTA
        k=0;
        i=0;
        j=0;
        printa=0;
        aux = aux->proximo;
    }while(aux->nome != q->inicio->nome);
    if(achou)
        return 1;
    return 0;
}


int insereInfo(listaDePessoas *q, char nome[40], char genero[10], float altura, float peso, char tipoSangue[4],char medicacoes[60])
{
    struct pessoa *auxPessoa;
    struct informacoes *auxInfo;

    auxPessoa = q->inicio;

    do
    {
        if(strcmp(auxPessoa->nome, nome) == 0)
            break;
        auxPessoa = auxPessoa->proximo;
    }while(auxPessoa->nome != q->inicio->nome);//LOOP QUE PROCURA EM QUAL NO A PESSOA ESTA PARA ADICIONAR AS INFORMAÇÕES A ELA
    if(auxPessoa->info == NULL)//CASO A PESSOA AINDA NÃO TENHA CADASTRO(INFORMAÇÕES) VAI SER ADICIONADA
    {
        auxInfo = (struct informacoes*) malloc(sizeof(struct informacoes));
        auxPessoa->info = auxInfo;
        auxInfo->id = auxPessoa->id;
        strcpy(auxInfo->nome,auxPessoa->nome);
        strcpy(auxInfo->genero,genero);
        auxInfo->voltar = auxPessoa;
        auxInfo->historico = NULL;
        auxInfo->peso = peso;
        auxInfo->altura = altura;
        strcpy(auxInfo->tipoSangue,tipoSangue);
        strcpy(auxInfo->medicacoes,medicacoes);
        return 1;
    }
    else
        return 0;

}






int pesquisaPorId(listaDePessoas *q, int id) //FUNÇÃO QUE PESQUISA A PESSOA POR ID E MOSTRA TODAS AS INFORMAÇÕES DELA
{
    bool confere = false;
    int y = 490;

    struct historicoHospitalar *auxHistorico;
    struct pessoa *auxPessoa;
    struct informacoes *auxInfo;

    auxPessoa = q->inicio;
    do
    {
        if(auxPessoa->id == id)
        {
            confere = true;
        }
        else
            auxPessoa = auxPessoa->proximo;
    }while(auxPessoa->nome != q->inicio->nome && !confere);//PASSA PELA LISTA TODA PARA ENCONTRAR A PESSOA POR ID

    if(confere)//SE ACHAR A PESSOA ENTRA NESSE IF E PRINTA TODAS AS INFORMAÇÕES
    {
    auxInfo = auxPessoa->info;
    BeginDrawing();
    DrawText(auxInfo->nome,10,70,40,BLACK);
    DrawText(TextFormat("ID: %d",auxPessoa->id),1120, 70,40,BLACK);
    DrawText(auxInfo->genero,10,210,40,BLACK);
    DrawText(TextFormat("%1.2f", auxInfo->altura),480,210,40,BLACK);
    DrawText(TextFormat("%3.2f", auxInfo->peso),660,210,40,BLACK);
    DrawText(auxInfo->tipoSangue,840, 210,40,BLACK);
    DrawText(auxInfo->medicacoes,10, 350,30,BLACK);
    DrawText("HISTORICO MEDICO:",10, 450,30,BLACK);
    EndDrawing();

    auxHistorico = auxInfo->historico;
    if(auxHistorico->proximo == NULL)
    {
        BeginDrawing();
        DrawText(TextFormat("-%s",auxHistorico->historico),40, y,30,DARKGRAY);
        EndDrawing();
    }
    else
    {
    do
    {
        BeginDrawing();
        DrawText(TextFormat("-%s",auxHistorico->historico),40, y,30,DARKGRAY);
        EndDrawing();
        y += 35;
            auxHistorico = auxHistorico->proximo;
    }while(auxHistorico!= NULL);//LOOP QUE VAI PRINTAR TODO HISTORICO DA PESSOA
    }
    }
    else//CASO NAO ENCONTRE A PESSOA
    {
        BeginDrawing();
        DrawText("NAO HA CADASTROS\nCOM ESSE USUARIO",100, 200,100,MAROON);
        EndDrawing();
        return 4;
    }
    return 0;
}



int insereHistoricoM(listaDePessoas *q, char nome[40], char historico[60], int id)
{
    struct pessoa *encontra;
    struct historicoHospitalar *danome, *auxDanome; // para nao ficar repetindo os nomes, no caso, historico
    int encontrou = 1;

    danome = (struct historicoHospitalar*) malloc(sizeof(struct historicoHospitalar));

    encontra = q->inicio;

    do{
        if(strcmp(encontra->nome, nome)==0)
        {
            encontrou = 0;
            break;
        }
        encontra = encontra->proximo;
    }while(q->inicio->nome != encontra->nome);//LOOP QUE PROCURA O NO DA PESSOA POR NOME E CASO NÃO ENCONTRE POR NOME NO DO-WHILE DE BAIXO PROCURA POR ID


    if(encontrou)//SÓ ENTRA NESSE IF PRA PESQUISAR POR ID CASO NÃO ENCONTRE A PESSOA POR NOME
    {
    encontra = q->inicio;
    do{
        if(encontra->id == id)
        {
            break;
        }
        encontra = encontra->proximo;
    }while(q->inicio->nome != encontra->nome);//LOOP PRA PORCURAR NO DA PESSOA POR ID
    }

    if(encontra->info->historico == NULL)//SE FOR A PRIMEIRA VEZ DA PESSOA DO HISPITAL
    {
        encontra->info->historico = danome;
        strcpy(encontra->info->historico->historico,historico);
        danome->proximo = NULL;
        return 1;
    }

    auxDanome = encontra->info->historico;//CASO FOR A SEGUNDA O MAIS VEZ DA PESSOA NO HOSPITAL

    while(auxDanome->proximo != NULL)
    {
        if(auxDanome->proximo != NULL)
        {
        auxDanome = auxDanome->proximo;
        }
    }//WHILE QUE PROCURA QUAL HISTÓRICO TEM O PONTEIRO DE PROXIMO APONTADO PRA NULO PARA ADICIONAR O NOVO HISTÓRICO

    auxDanome->proximo = danome;
    strcpy(danome->historico,historico);
    danome->proximo = NULL;
    return 0;
}
