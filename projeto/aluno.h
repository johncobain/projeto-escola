#include<stdio.h>

typedef struct data_a{
  int dia;
  int mes;
  int ano;
}Data_a;


typedef struct dados_aluno{
  int matricula;
  char nome[50];
  char sexo;
  Data_a data_nascimento;
  char cpf[15];

  struct dados_alunos *prox;
  
} Aluno; 

int mainAluno(Aluno listaAluno[], int qtdAluno);

