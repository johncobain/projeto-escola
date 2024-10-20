#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "escola.h"
#include "pessoa.h"
#include "utils.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "relatorio.h"
#include "dadosTeste.h"

void getTeste(Pessoa aluno[], Pessoa professor[], Disciplina disciplina[]){
    
    // 4 Alunos

    strcpy(aluno[0].nome, "John");
    strcpy(aluno[0].cpf, "27153214062");
    aluno[0].sexo = 'M';
    aluno[0].data_nascimento.ano = 2005;
    aluno[0].data_nascimento.mes = 8;
    aluno[0].data_nascimento.dia = 20;
    aluno[0].matricula = gerarMatriculaA();
    aluno[0].disCad = 5;
    strcpy(aluno[0].disciplinas[0], "INF029");
    strcpy(aluno[0].disciplinas[1], "INF031");
    strcpy(aluno[0].disciplinas[2], "INF028");
    strcpy(aluno[0].disciplinas[3], "INF032");
    strcpy(aluno[0].disciplinas[4], "INF006");
    
    strcpy(aluno[1].nome, "Mark");
    strcpy(aluno[1].cpf, "65309371028");
    aluno[1].sexo = 'M';
    aluno[1].data_nascimento.ano = 2006;
    aluno[1].data_nascimento.mes = 10;
    aluno[1].data_nascimento.dia = 10;
    aluno[1].matricula = gerarMatriculaA();
    aluno[1].disCad = 3;
    strcpy(aluno[1].disciplinas[0], "INF027");
    strcpy(aluno[1].disciplinas[1], "INF026");
    strcpy(aluno[1].disciplinas[2], "INF031");

    strcpy(aluno[2].nome, "Mary");
    strcpy(aluno[2].cpf, "19285282016");
    aluno[2].sexo = 'F';
    aluno[2].data_nascimento.ano = 2007;
    aluno[2].data_nascimento.mes = 11;
    aluno[2].data_nascimento.dia = 23;
    aluno[2].matricula = gerarMatriculaA();
    aluno[2].disCad = 3;
    strcpy(aluno[2].disciplinas[0], "INF029");
    strcpy(aluno[2].disciplinas[1], "INF006");
    strcpy(aluno[2].disciplinas[2], "INF028");

    strcpy(aluno[3].nome, "Lisa");
    strcpy(aluno[3].cpf, "08120608062");
    aluno[3].sexo = 'F';
    aluno[3].data_nascimento.ano = 2003;
    aluno[3].data_nascimento.mes = 8;
    aluno[3].data_nascimento.dia = 4;
    aluno[3].matricula = gerarMatriculaA();
    aluno[3].disCad = 5;
    strcpy(aluno[3].disciplinas[0], "INF029");
    strcpy(aluno[3].disciplinas[1], "INF006");
    strcpy(aluno[3].disciplinas[2], "INF028");
    strcpy(aluno[3].disciplinas[3], "INF031");
    strcpy(aluno[3].disciplinas[4], "INF032");

    // 4 Professores

    strcpy(professor[0].nome, "Fred");
    strcpy(professor[0].cpf, "97906428064");
    professor[0].sexo = 'M';
    professor[0].data_nascimento.ano = 1975;
    professor[0].data_nascimento.mes = 10;
    professor[0].data_nascimento.dia = 1;
    professor[0].disCad = 2;
    strcpy(professor[0].disciplinas[0], "INF027");
    strcpy(professor[0].disciplinas[1], "INF029");
    professor[0].matricula = gerarMatriculaP();

    strcpy(professor[1].nome, "Allan");
    strcpy(professor[1].cpf, "86162195015");
    professor[1].sexo = 'M';
    professor[1].data_nascimento.ano = 1980;
    professor[1].data_nascimento.mes = 8;
    professor[1].data_nascimento.dia = 10;
    professor[1].disCad = 2;
    strcpy(professor[1].disciplinas[0], "INF032");
    strcpy(professor[1].disciplinas[1], "INF006");
    professor[1].matricula = gerarMatriculaP();

    strcpy(professor[2].nome, "AC");
    strcpy(professor[2].cpf, "69003573000");
    professor[2].sexo = 'M';
    professor[2].data_nascimento.ano = 1985;
    professor[2].data_nascimento.mes = 10;
    professor[2].data_nascimento.dia = 20;
    professor[2].disCad = 1;
    strcpy(professor[2].disciplinas[0], "INF026");
    professor[2].matricula = gerarMatriculaP();

    strcpy(professor[3].nome, "Simone");
    strcpy(professor[3].cpf, "43303498091");
    professor[3].sexo = 'F';
    professor[3].data_nascimento.ano = 1988;
    professor[3].data_nascimento.mes = 10;
    professor[3].data_nascimento.dia = 21;
    professor[3].disCad = 1;
    strcpy(professor[3].disciplinas[0], "INF031");
    professor[3].matricula = gerarMatriculaP();

    strcpy(professor[4].nome, "Flavia");
    strcpy(professor[4].cpf, "58754944090");
    professor[4].sexo = 'F';
    professor[4].data_nascimento.ano = 1990;
    professor[4].data_nascimento.mes = 11;
    professor[4].data_nascimento.dia = 4;
    professor[4].disCad = 1;
    strcpy(professor[4].disciplinas[0], "INF028");
    professor[4].matricula = gerarMatriculaP();

    //7 Disciplinas

    strcpy(disciplina[0].nome, "Logica de Programacao");
    strcpy(disciplina[0].codigo, "INF027");
    disciplina[0].semestre = 20241;
    disciplina[0].professor = professor[0];
    disciplina[0].vagas = 12;
    disciplina[0].alunosCad = 1;
    disciplina[0].alunos[0] = aluno[1];

    strcpy(disciplina[1].nome, "Laboratorio de Programacao");
    strcpy(disciplina[1].codigo, "INF029");
    disciplina[1].semestre = 20242;
    disciplina[1].professor = professor[0];
    disciplina[1].vagas = 6;
    disciplina[1].alunosCad = 3;
    disciplina[1].alunos[0] = aluno[0];
    disciplina[1].alunos[1] = aluno[2];
    disciplina[1].alunos[2] = aluno[3];

    strcpy(disciplina[2].nome, "Metodologia de Pesquisa");
    strcpy(disciplina[2].codigo, "INF031");
    disciplina[2].semestre = 20242;
    disciplina[2].professor = professor[3];
    disciplina[2].vagas = 6;
    disciplina[2].alunosCad = 3;
    disciplina[2].alunos[0] = aluno[0];
    disciplina[2].alunos[1] = aluno[1];
    disciplina[2].alunos[2] = aluno[3];

    strcpy(disciplina[3].nome, "Arquitetura de Software");
    strcpy(disciplina[3].codigo, "INF028");
    disciplina[3].semestre = 20242;
    disciplina[3].professor = professor[4];
    disciplina[3].vagas = 10;
    disciplina[3].alunosCad = 3;
    disciplina[3].alunos[0] = aluno[0];
    disciplina[3].alunos[1] = aluno[2];
    disciplina[3].alunos[2] = aluno[3];

    strcpy(disciplina[4].nome, "Introducao a computacao");
    strcpy(disciplina[4].codigo, "INF026");
    disciplina[4].semestre = 20241;
    disciplina[4].professor = professor[2];
    disciplina[4].vagas = 10;
    disciplina[4].alunosCad = 1;
    disciplina[4].alunos[0] = aluno[1];

    strcpy(disciplina[5].nome, "Data Communication");
    strcpy(disciplina[5].codigo, "INF032");
    disciplina[5].semestre = 20242;
    disciplina[5].professor = professor[1];
    disciplina[5].vagas = 8;
    disciplina[5].alunosCad = 2;
    disciplina[5].alunos[0] = aluno[0];
    disciplina[5].alunos[1] = aluno[3];

    strcpy(disciplina[6].nome, "Estrutura de dados");
    strcpy(disciplina[6].codigo, "INF006");
    disciplina[6].semestre = 20242;
    disciplina[6].professor = professor[1];
    disciplina[6].vagas = 8;
    disciplina[6].alunosCad = 3;
    disciplina[6].alunos[0] = aluno[0];
    disciplina[6].alunos[1] = aluno[2];
    disciplina[6].alunos[2] = aluno[3];

    sucess("Dados Criados com Sucesso!");
}
