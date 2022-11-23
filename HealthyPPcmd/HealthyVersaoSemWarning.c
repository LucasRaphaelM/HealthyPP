#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pessoa
{
    struct pessoa *anterior;
    int id;
    char nome[60];
    struct informacoes *info;
    struct pessoa *proximo;
};

struct informacoes
{
    struct pessoa *voltar;
    int id;
    char nome[60];
    char genero[10];
    float altura;
    float peso;
    char tipoSangue[4];
    char medicacoes[100];
    struct historicoHospitalar *historico;
};

struct historicoHospitalar
{
    char historico[60];
    struct historicoHospitalar *proximo;
};

typedef struct
{
    struct pessoa *inicio;
    struct pessoa *fim;
} listaDePessoas;

int inserePessoa(listaDePessoas *q, char nome[60], int id);
int insereInfo(listaDePessoas *q, char nome[60], char genero[10], float altura, float peso, char tipoSangue[4],char medicacoes[100]);
void mostra(listaDePessoas *q);
int pesquisaPorNome(listaDePessoas *q, char nome[60]);
int pesquisaPorId(listaDePessoas *q, int id);
int insereHistoricoM(listaDePessoas *q, char nome[60], char historico[60], int id);

int main(void)
{
    listaDePessoas listaDePacientes;
    int teste;
    int id=1;
    char nomePessoa[60];
    char genero[10];
    float altura;
    float peso;
    char tipoSangue[4];
    char medicacoes[100];
    int idPesquisa=0;
    char historico[60];

    listaDePacientes.inicio = NULL;
    listaDePacientes.fim = NULL;

    inserePessoa(&listaDePacientes,"Daniel Siqueira Monteiro",id);
    id++;
    inserePessoa(&listaDePacientes,"Lucas Raphael Moreira Nogueira",id);
    id++;
    inserePessoa(&listaDePacientes,"Diogo Lima",id);
    id++;
    inserePessoa(&listaDePacientes,"Joao Gabriel Moreira Nogueira",id);
    id++;
    inserePessoa(&listaDePacientes,"Larissa Nadur",id);
    id++;
    inserePessoa(&listaDePacientes,"Luis Otavio",id);
    id++;
    inserePessoa(&listaDePacientes,"Wanderlei Junior",id);
    id++;
    inserePessoa(&listaDePacientes,"Bruno De Toledo Nicollielo",id);
    id++;
    inserePessoa(&listaDePacientes,"Tiago Amaral Gaspar",id);
    id++;
    inserePessoa(&listaDePacientes,"Luiz Antonio",id);

    insereInfo(&listaDePacientes,"Daniel Siqueira Monteiro","Masculino",1.84,82,"O-","ADORA FUMAR UMA");
    insereInfo(&listaDePacientes,"Lucas Raphael Moreira Nogueira","Masculino",1.84,73,"O+","NAO");
    insereInfo(&listaDePacientes,"Diogo Lima","Masculino",1.66,68,"A+","VAIPIZIN");
    insereInfo(&listaDePacientes,"Bruno De Toledo Nicollielo","Masculino",1.84,73,"O+","NAO");
    insereInfo(&listaDePacientes,"Joao Gabriel Moreira Nogueira","Masculino",1.76,86,"O+","NAO");
    insereInfo(&listaDePacientes,"Joao Gabriel Moreira Nogueira","Masculino",1.76,86,"O+","NAO");
    insereInfo(&listaDePacientes,"Luiz Antonio","Masculino",1.6,65,"A-","DA PAZ");

    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","pao",0);
    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","pao com arroz",0);
    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","pao com carne",0);

    mostra(&listaDePacientes);


    /*printf("\n\nDigite um nome: ");
    scanf("%59[^\n]s",&nomePessoa);
    getchar();
    printf("Digite o genero: ");
    scanf("%9[^\n]s",&genero);
    getchar();
    printf("Digite a altura: ");
    scanf("%f",&altura);
    getchar();
    printf("Digite a peso: ");
    scanf("%f",&peso);
    getchar();
    printf("Digite o tipo sanguineo: ");
    scanf("%3[^\n]s",&tipoSangue);
    getchar();
    printf("Usa alguma medicacao: ");
    scanf("%99[^\n]s",&medicacoes);
    getchar();
    id++;
    inserePessoa(&listaDePacientes,nomePessoa,id);
    insereInfo(&listaDePacientes,nomePessoa,genero,altura,peso,tipoSangue,medicacoes);*/


    printf("\n\nPesquise um nome: ");
    scanf("%59[^\n]s",&nomePessoa);
    getchar();

    if(pesquisaPorNome(&listaDePacientes, nomePessoa) == 0)
    printf("Nome não encontrado");

    printf("Digite o ID desejado: ");

    scanf("%d",&idPesquisa);
    getchar();

    printf("\n\nDigite o historico: ");
    scanf("%59[^\n]s",&historico);
    getchar();


    insereHistoricoM(&listaDePacientes,nomePessoa,historico,idPesquisa);

    pesquisaPorId(&listaDePacientes, idPesquisa);

    //mostra(&listaDePacientes);
    return 0;

}

int inserePessoa(listaDePessoas *q, char nome[60], int id)
{
    struct pessoa *aux, *umAnterior, *atual;
    aux = (struct pessoa*) malloc(sizeof(struct pessoa));

    if (aux == NULL)
        return 0;

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
    if (strcmp(q->inicio->nome,nome) > 0)
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
    if (strcmp(q->fim->nome,nome) < 0)
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
    while (strcmp(atual->nome,nome) < 0)
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
    char teste[60];

    struct pessoa *aux;

    if (q->inicio == NULL)
        printf("Lista vazia...\n\n");
    else
    {
        aux = q->inicio;
        do
        {
            printf("ID: %d ", aux->id);
            printf("NOME: %s\n", aux->nome);
            aux = aux->proximo;
        } while (aux != q->inicio);
    }
}

int pesquisaPorNome(listaDePessoas *q, char nome[60])
{
    int i=0;
    int j=0;
    int k=0;
    int printa=0;
    int achou=0;


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
                i++;
                j++;
                printa++;
                if(printa >= 3)
                {
                    printf("ID: %d ", aux->id);
                    printf("NOME: %s\n", aux->nome);
                    k++;
                    i = k;
                    j = 0;
                    printa = 0;
                    achou = 1;
                    break;
                }
            }
            else
            {
                k++;
                i = k;
                j = 0;
                printa = 0;
            }
        }while(i < strlen(aux->nome));
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

int insereInfo(listaDePessoas *q, char nome[60], char genero[10], float altura, float peso, char tipoSangue[4],char medicacoes[100])
{
    struct pessoa *auxPessoa;
    struct informacoes *auxInfo;

    auxPessoa = q->inicio;

    do
    {
        if(strcmp(auxPessoa->nome, nome) == 0)
            break;
        auxPessoa = auxPessoa->proximo;
    }while(auxPessoa->nome != q->inicio->nome);
    if(auxPessoa->info == NULL)
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
        /*printf("\n---------------LISTA PESSOAS---------------\n");
        printf("ID: %d\n",auxPessoa->id);
        printf("NOME: %s\n",auxPessoa->nome);
        printf("\n-------------------------------------------\n");
        printf("\n-------------LISTA INFORMACOES-------------\n");
        printf("ID: %d\n",auxInfo->id);
        printf("NOME: %s\n",auxInfo->nome);
        printf("GENERO: %s\n",auxInfo->genero);
        printf("ALTURA: %f\n",auxInfo->altura);
        printf("PESO: %f\n",auxInfo->peso);
        printf("TIPO SANGUINEO: %s\n", auxInfo->tipoSangue);
        printf("MEDICACOES: %s\n",auxInfo->medicacoes);
        printf("\n-------------------------------------------\n");*/
        return 1;
    }
    else
        return 0;

}

int pesquisaPorId(listaDePessoas *q, int id)
{
    int confere = 0;

    struct historicoHospitalar *auxHistorico;
    struct pessoa *auxPessoa;
    struct informacoes *auxInfo;

    auxPessoa = q->inicio;
    do
    {
        if(auxPessoa->id == id)
        {
            confere = 1;
            break;
        }
        auxPessoa = auxPessoa->proximo;
    }while(auxPessoa->nome != q->inicio->nome);

    if(confere)
    {
    auxInfo = auxPessoa->info;
    printf("\n-------------LISTA INFORMACOES-------------\n");
    printf("ID: %d\n",auxInfo->id);
    printf("NOME: %s\n",auxInfo->nome);
    printf("GENERO: %s\n",auxInfo->genero);
    printf("ALTURA: %f\n",auxInfo->altura);
    printf("PESO: %f\n",auxInfo->peso);
    printf("TIPO SANGUINEO: %s\n", auxInfo->tipoSangue);
    printf("MEDICACOES: %s\n",auxInfo->medicacoes);
    printf("HISTORICO HOSPITALAR:");
    auxHistorico = auxInfo->historico;
    do
    {
        printf("\n- %s",auxHistorico->historico);
        auxHistorico = auxHistorico->proximo;
    }while(auxHistorico != NULL);
    printf("\n-------------------------------------------\n");
    }
    else
    {
        printf("\n\nID NAO ENCONTRADO\n\n");
        return 0;
    }
}


int insereHistoricoM(listaDePessoas *q, char nome[60], char historico[60], int id)
{
    struct pessoa *encontra;
    struct informacoes *auxiliar;
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
    }while(q->inicio->nome != encontra->nome);


    if(encontrou)
    {
    encontra = q->inicio;
    do{
        if(encontra->id == id)
        {
            break;
        }
        encontra = encontra->proximo;
    }while(q->inicio->nome != encontra->nome);
    }

    if(encontra->info->historico == NULL)
    {
        encontra->info->historico = danome;
        strcpy(encontra->info->historico->historico,historico);
        danome->proximo = NULL;
        return 1;
    }

    auxDanome = encontra->info->historico;

    while(auxDanome->proximo != NULL)
    {
        if(auxDanome->proximo != NULL)
        {
        auxDanome = auxDanome->proximo;
        }
    }

    auxDanome->proximo = danome;
    strcpy(danome->historico,historico);
    danome->proximo = NULL;
}
