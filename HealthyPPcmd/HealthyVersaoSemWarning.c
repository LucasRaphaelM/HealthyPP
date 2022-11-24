#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//LISTA COM INFORMAÇÃO DE NOMES E ID DAS PESSOAS
struct pessoa
{
    struct pessoa *anterior;
    int id;
    char nome[60];
    struct informacoes *info;
    struct pessoa *proximo;
};

//LISTA COM INFORMAÇÕES DAS PESSOAS <- ESSA LISTA VAI SER CONECTADA A LISTA DE CIMA E SÓ VAI TER UM NÓ PARA CADA PESSOA
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

//LISTA COM HISTORICO HOSPITALAR DAS PESSOAS
struct historicoHospitalar
{
    char historico[60];
    struct historicoHospitalar *proximo;
};

//ONDE APONTA PARA O INICIO DA LISTA
typedef struct
{
    struct pessoa *inicio;
    struct pessoa *fim;
} listaDePessoas;

int inserePessoa(listaDePessoas *q, char nome[60], int id);//INSERE O NOME E O ID DA PESSOA NA LISTA PRINCIPAL
int insereInfo(listaDePessoas *q, char nome[60], char genero[10], float altura, float peso, char tipoSangue[4],char medicacoes[100]);//INSERE AS INFORMAÇÕES DAS PESSOAS <- PARA A SEGUNDA LISTA
void mostra(listaDePessoas *q);//FUNÇÃO QUE MOSTRA TODAS AS PESSOAS E SEUS ID'S
int pesquisaPorNome(listaDePessoas *q, char nome[60]);//PESQUISA PESSOAS POR NOME <- APENAS DIGITANDO MOREIRA CONSIGUIRA ACHAR EU E MEU IRMÃO POR TER MESMO SOBRENOME ( PODE SER VISTO NOS INSERES ABAIXO)
int pesquisaPorId(listaDePessoas *q, int id);//PESQUISA A PESSOA POR ID <- GERALMENTE SERA USADO DEPOIS DE SER PESQUISADO POR NOME PARA CONFIRMAMENTO
int insereHistoricoM(listaDePessoas *q, char nome[60], char historico[60], int id);//INSERE HISTÓRICO TANTO POR NOME QUANTO POR ID

int main(void)
{
    listaDePessoas listaDePacientes;
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

    //PUXANDO TODAS AS FUNÇÕES PARA INSERIR OS NOMES E O ID NA ALOCAÇÃO DINAMICA DA LISTA PRINCIPAL E FAZ id++ PARA O PROXIMO DA LISTA JA RECEBER O PROXIMO ID
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

    //INSERE INFORMAÇÕES PESSOAIS NA SEGUNDA LISTA( NOME COMPLETO / ALTURA / PESO / TIPO SANGUÍNEO / SE USA ALGUM TIPO DE MEDICAÇÃO )
    insereInfo(&listaDePacientes,"Daniel Siqueira Monteiro","Masculino",1.84,82,"O-","NAO");
    insereInfo(&listaDePacientes,"Lucas Raphael Moreira Nogueira","Masculino",1.84,73,"O+","NAO");
    insereInfo(&listaDePacientes,"Diogo Lima","Masculino",1.66,68,"A+","NAO");
    insereInfo(&listaDePacientes,"Bruno De Toledo Nicollielo","Masculino",1.84,73,"O+","NAO");
    insereInfo(&listaDePacientes,"Joao Gabriel Moreira Nogueira","Masculino",1.76,86,"O+","NAO");
    insereInfo(&listaDePacientes,"Joao Gabriel Moreira Nogueira","Masculino",1.76,86,"O+","NAO");
    insereInfo(&listaDePacientes,"Luiz Antonio","Masculino",1.6,65,"A-","NAO");

    //FUNÇÃO QUE INSERE UM HISÓRICO HOSPITALAR/DOENÇAS DA PESSOA ( PASSAMOS O NOME PARA A FUNÇÃO CHECAR EM QUE PESSOA DEVEMOS INSERIR O HISTÓRICO, OU PUDEMOS USAR O ID TAMBEM
    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","OSSO FRATURADO",0);
    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","ASMA",0);
    insereHistoricoM(&listaDePacientes,"Daniel Siqueira Monteiro","ROMPIMENTO DO LIGAMENTO",0);

    //FUNÇÃO QUE MOSTRA TODAS AS PESSOAS E SEUS ID'S
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

    /*printf("\n\nDigite o historico: ");
    scanf("%59[^\n]s",&historico);
    getchar();*/

    //FUNÇÃO QUE VAI INSERIR UM NOVO HISTÓRICO MEDICO PARA A PESSOA
    //insereHistoricoM(&listaDePacientes,nomePessoa,historico,idPesquisa);

    //FUNÇÃO QUE PESQUISA A PESSOA POR ID E MOSTRA TODAS AS INFORMAÇÕES DELA
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
        } while (aux != q->inicio);//PERCORRE POR TODA A LISTA PRINTANDO NA TELA O NOME E O ID DE TODOS ATÉ VOLTAR PRO INICIO DA LISTA
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
                i++;//i++ E j++ ANDAM JUNTOS
                j++;
                printa++;//PRINTA++ QUANDO CHEGAR A 3, SIGNIFICA QUE PELO MENOS 3 LETRAS ESTÃO IGUAIS, ENTÃO ENTRA NO IF E PRINTA O ID E O NOME DA PESSOA QUE SE IGUALOU PELO MENOS 3 LETRAS
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
    }while(auxPessoa->nome != q->inicio->nome);//PASSA PELA LISTA TODA PARA ENCONTRAR A PESSOA POR ID

    if(confere)//SE ACHAR A PESSOA ENTRA NESSE IF E PRINTA TODAS AS INFORMAÇÕES
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
    }while(auxHistorico != NULL);//LOOP QUE VAI PRINTAR TODO HISTORICO DA PESSOA
    printf("\n-------------------------------------------\n");
    }
    else//CASO NAO ENCONTRE A PESSOA
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
}
