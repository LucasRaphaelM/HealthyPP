//LISTA COM INFORMAÇÃO DE NOMES E ID DAS PESSOAS
struct pessoa
{
    struct pessoa *anterior;
    int id;
    char nome[40];
    struct informacoes *info;
    struct pessoa *proximo;
};



//LISTA COM INFORMAÇÕES DAS PESSOAS <- ESSA LISTA VAI SER CONECTADA A LISTA DE CIMA E SÓ VAI TER UM NÓ PARA CADA PESSOA
struct informacoes
{
    struct pessoa *voltar;
    int id;
    char nome[40];
    char genero[10];
    float altura;
    float peso;
    char tipoSangue[4];
    char medicacoes[60];
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


int inserePessoa(listaDePessoas *, char nome[40], int id);//INSERE O NOME E O ID DA PESSOA NA LISTA PRINCIPAL
int insereInfo(listaDePessoas *, char nome[40], char genero[10], float altura, float peso, char tipoSangue[4],char medicacoes[60]);//INSERE AS INFORMAÇÕES DAS PESSOAS <- PARA A SEGUNDA LISTA
void mostra(listaDePessoas *);//FUNÇÃO QUE MOSTRA TODAS AS PESSOAS E SEUS ID'S
int pesquisaPorNome(listaDePessoas *, char nome[40]);//PESQUISA PESSOAS POR NOME <- APENAS DIGITANDO MOREIRA CONSIGUIRA ACHAR EU E MEU IRMÃO POR TER MESMO SOBRENOME ( PODE SER VISTO NOS INSERES ABAIXO)
int pesquisaPorId(listaDePessoas *, int id);//PESQUISA A PESSOA POR ID <- GERALMENTE SERA USADO DEPOIS DE SER PESQUISADO POR NOME PARA CONFIRMAMENTO
int insereHistoricoM(listaDePessoas *, char nome[40], char historico[60], int id);//INSERE HISTÓRICO TANTO POR NOME QUANTO POR ID