#include "Utils.h"

#define SUCESSO_CADASTRO -1
#define ERRO_MATRICULA -2
#define ERRO_CADASTRO_SEXO -3
#define ERRO_DATA_INVALIDA -4
#define ERRO_CPF_INVALIDO -5
#define LISTA_VAZIA -6
#define LISTA_CHEIA -7
#define SUCESSO_EXCLUSAO -8
#define NAO_ENCONTRADO -9

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