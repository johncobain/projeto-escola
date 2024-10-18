#define TAM_CPF 12

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
  
} Pessoa; 

int buscarPessoa(Pessoa lista[], int matricula);