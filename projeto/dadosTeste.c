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

void getTeste(Pessoa aluno[], int *qtdAluno, Pessoa professor[], int *qtdProfessor, Disciplina disciplina[], int *qtdDisciplina){
    
    // Alunos

    Pessoa alunosTeste[7] = {
        {gerarMatriculaA(), "John Wick", 'M', {20,8,2005}, "27153214062", {{"INF029"}, {"INF031"}, {"INF028"}, {"INF032"}, {"INF006"}},5},
        {gerarMatriculaA(), "Tony Stark", 'M', {4,4,1995}, "65309371028", {{"INF027"}, {"INF026"}, {"INF031"}},3},
        {gerarMatriculaA(), "Lisa Lisa", 'F', {23,12,2001}, "19285282016", {{"INF029"}, {"INF006"}, {"INF028"}},3},
        {gerarMatriculaA(), "Lisa Simpson", 'F', {9, 5,2005}, "08120608062", {{"INF029"}, {"INF006"}, {"INF028"}, {"INF031"}, {"INF032"}},5},
        {gerarMatriculaA(), "Wendy Testaburger", 'F', {11, 12,2004}, "16581147605", {{"INF027"}, {"INF028"}, {"INF031"}, {"INF032"}},4},
        {gerarMatriculaA(), "Petter Parker", 'M', {20, 8, 2000}, "32442478498", {{"INF027"}, {"INF029"}, {"INF028"}, {"INF031"}, {"INF026"}},5},
        {gerarMatriculaA(), "Harry Potter", 'M', {31, 6,2000}, "93161822048", {{"INF029"}, {"INF031"}, {"INF028"}, {"INF006"}},4}
    };

    *qtdAluno = (sizeof(alunosTeste)/sizeof(alunosTeste[0]));

    for(int i=0; i<= *qtdAluno; i++){
        aluno[i] = alunosTeste[i];
    }

    // Professores

    Pessoa professoresTeste[7] = {
        {gerarMatriculaP(), "Fred Barbosa", 'M', {1,10,1975}, "97906428064", {{"INF027"}},1},
        {gerarMatriculaP(), "Renato Novais", 'M', {20,4,1990}, "16267760324", {{"INF029"}},1},
        {gerarMatriculaP(), "Simone da Silva", 'F', {20,10,1990}, "43303498091", {{"INF031"}},1},
        {gerarMatriculaP(), "Flavia Maristela", 'F', {4, 11,1990}, "58754944090", {{"INF028"}},1},
        {gerarMatriculaP(), "Antonio Carlos", 'M', {20, 10,1985}, "69003573000", {{"INF026"}},1},
        {gerarMatriculaP(), "Allan Freitas", 'M', {10, 8, 1980}, "86162195015", {{"INF032"}},1},
        {gerarMatriculaP(), "Jose Dihego", 'M', {21, 12,1994}, "16625157155", {{"INF006"}},1}
    };

    *qtdProfessor = (sizeof(professoresTeste)/sizeof(professoresTeste[0]));

    for(int i=0; i<= *qtdProfessor; i++){
        professor[i] = professoresTeste[i];
    }

    //Disciplinas

    Disciplina disciplinasTeste[7] = {
        {"Logica de Programacao", "INF027", 20241, 10, professor[0], {aluno[1],aluno[4], aluno[5]}, 3},
        {"Laboratorio de Programacao", "INF029", 20242, 6, professor[1], {aluno[0],aluno[2], aluno[3], aluno[5], aluno[6]}, 5},
        {"Metodologia de Pesquisa", "INF031", 20242, 6, professor[2], {aluno[0],aluno[1], aluno[3], aluno[4],aluno[5],aluno[6]}, 6},
        {"Arquitetura de Software", "INF028", 20242, 8, professor[3], {aluno[0],aluno[2], aluno[3], aluno[4], aluno[5], aluno[6]}, 6},
        {"Introducao a Computacao", "INF026", 20241, 10, professor[4], {aluno[1], aluno[5]}, 2},
        {"Data Communication", "INF032", 20242, 8, professor[5], {aluno[0],aluno[3], aluno[4]}, 3},
        {"Estrutura de dados", "INF006", 20242, 8, professor[6], {aluno[0],aluno[2], aluno[3],  aluno[6]}, 4},
    };


 

    *qtdDisciplina = (sizeof(disciplinasTeste)/sizeof(disciplinasTeste[0]));

    for(int i=0; i<= *qtdDisciplina; i++){
        disciplina[i] = disciplinasTeste[i];
    }

    sucess("Dados Criados com Sucesso!");
}
