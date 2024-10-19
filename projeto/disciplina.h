#include<stdio.h>
// #include "escola.h"
// #include "pessoa.h"
#include "aluno.h"
// #include "professor.h"

#define TAM_DISC 3
#define MAX_VAGAS 50

typedef struct dados_disciplina{
    char nome[50];
    char codigo[7];//INF000
    int semestre;
    int vagas;
    Pessoa professor;
    Pessoa alunos[MAX_VAGAS];
    int alunosCad;
} Disciplina; 


int mainDisciplina(Disciplina listaDisciplina[], Pessoa listaProfessor[], Pessoa listaAluno[], int qtdDisciplina);
