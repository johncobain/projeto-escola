#include <stdio.h>
#define TAM 3

#include "escola.h"
#include "aluno.h"
#include "professor.h"
#include "utils.h"
#include "disciplina.h"


int menuGeral(){
  int opcao;
  printLine('-',20);
  printf("#### SISTEMA ESCOLA ####\n");
  printf("Digite a opção\n");
  printf("0 - Sair\n");
  printf("1 - Gerenciar Aluno\n");
  printf("2 - Gerenciar Professor\n");
  printf("3 - Gerenciar Disciplina\n");
  printLine('-',20);
  scanf("%d", &opcao);
  return opcao;
}

// primeiramente eu tenho que entender o que foi que eu escrevi aqui
int main() {
	Aluno aluno;/*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	Aluno *inicioListaAluno = NULL; // inicio da lista de alunos
	
	/*
	Professor professor;
	int qtdProfessor = 0;
	Disciplina disciplina;
	int qtdDisciplina=0;
	*/
	
	
	while(1){
		switch(menuGeral()){
			case 0: {
				system ("clear");
				printf("Finalizando Escola\n");
	        	finalizarEscola(inicioListaAluno);
				return 0;
				break;
			}		
			case 1:{
				system ("clear");
				printf("\n");
				printLine('-',20);
				printf(" Modulo Aluno\n");
				printLine('-',20);
				qtdAluno = mainAluno(listaAluno, qtdAluno);
				printf("\n");
				break;

			}
			case 2:{
				system ("clear");
				printf("\n");
				printLine('-',20);
				printf("Modulo Professor\n");
				printLine('-',20);
				qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
				printf("\n");
				break;
			}
			case 3:{
				system ("clear");
				printf("\n");
				printLine('-',20);
				printf("Modulo Disciplina\n");
				printLine('-',20);
				qtdDisciplina = mainDisciplina(listaDisciplina, qtdDisciplina);
				printf("\n");
				break;
			}
			default:{
				system ("clear");
				printf("\n");
				printf("Opção Invalida!!\n");
				printLine('-',20);
			}    
		}

	}	
	return 0;
}



