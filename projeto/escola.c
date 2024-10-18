#include <stdio.h>
#include <stdlib.h>

#include "escola.h"
#include "pessoa.h"
#include "utils.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"


int menuGeral(){
	int opcao;
	printf("\n");
	printLine('-',30);
	printf("#### Sistema Escola ####\n");
	printLine('-',30);
	printf("Digite a opcao\n");
	printf("0. Sair\n");
	printf("1. Gerenciar Aluno\n");
	printf("2. Gerenciar Professor\n");
	printf("3. Gerenciar Disciplina\n");
	printLine('-',30);
	scanf("%d", &opcao);
	return opcao;
}

// primeiramente eu tenho que entender o que foi que eu escrevi aqui
int main() {
	system ("cls");
	Pessoa listaAluno[TAM_ALUNO];/*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	int qtdAluno = 0;// inicio da lista de alunos
	
	Pessoa listaProfessor[TAM_PROFESSOR];
	int qtdProfessor = 0;

	Disciplina listaDisciplina[TAM_DISC];
	int qtdDisciplina=0;
	
	
	while(1){
		switch(menuGeral()){
			case 0: {
				int esc;
				system ("cls");
				printf("\n");
				printLine('-',30);
				printf("Finalizando Escola\n");
				printLine('-',30);
				printf("Pressione ENTER para encerrar: ");
				getchar();
				scanf("%c", &esc);
				system("cls");
	        	//qtdAluno = finalizarEscola(listaAluno, qtdAluno);
	        	//qtdProfessor = finalizarEscola(listaProfessor, qtdProfessor);
				return 0;
				break;
			}		
			case 1:{
				system ("cls");
				qtdAluno = mainAluno(listaAluno, qtdAluno);
				break;
			}
			case 2:{
				system ("cls");
				qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
				break;
			}
			case 3:{
				system ("cls");
				qtdDisciplina = mainDisciplina(listaDisciplina, listaProfessor, qtdDisciplina);
				break;
			}
			default:{error("Opcao invalida");}    
		}
	}	
	return 0;
}
