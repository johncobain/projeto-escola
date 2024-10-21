#define TAM_CPF 12
#define MAX_DISC 10
#define TAM_P 5

typedef struct dma{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct dados_pessoa{
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[TAM_CPF];
  char disciplinas[MAX_DISC][7];
  int disCad;
} Pessoa; 

int buscarPessoa(Pessoa lista[], int matricula);
int listarUmaP(Pessoa lista[], int i);