#include<stdio.h>

typedef struct{
  int dia;
  int mes;
  int ano;
}data;


typedef struct {
  int matricula;
  char nome[20];
  char sexo;
  data dataNasc;
  char cpf[15];
} Aluno; 

int mainAluno(Aluno listaAluno[], int qtdAluno);

