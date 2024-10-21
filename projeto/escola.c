#include <stdio.h>
#include <stdlib.h>

#include "escola.h"
#include "pessoa.h"
#include "utils.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "relatorio.h"
#include "dadosTeste.h"


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
	printf("4. Relatorios\n");
	printf("5. Dados de Teste\n");
	printLine('-',30);
	scanf("%d", &opcao);
	return opcao;
}

// primeiramente eu tenho que entender o que foi que eu escrevi aqui
int main() {
	system ("cls||clear");
	Pessoa listaAluno[TAM_P];/*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	int qtdAluno = 0;// inicio da lista de alunos
	
	Pessoa listaProfessor[TAM_P];
	int qtdProfessor = 0;

	Disciplina listaDisciplina[TAM_DISC];
	int qtdDisciplina=0;
	
	
	while(1){
		switch(menuGeral()){
			case 0: {
				int esc;
				system ("cls||clear");
				printf("\n");
				printLine('-',30);
				printf("Finalizando Escola\n");
				printLine('-',30);
				printf("Pressione ENTER para encerrar: ");
				getchar();
				scanf("%c", &esc);
				system("cls||clear");
	        	//qtdAluno = finalizarEscola(listaAluno, qtdAluno);
	        	//qtdProfessor = finalizarEscola(listaProfessor, qtdProfessor);
				return 0;
				break;
			}		
			case 1:{
				system ("cls||clear");
				qtdAluno = mainAluno(listaAluno, qtdAluno);
				break;
			}
			case 2:{
				system ("cls||clear");
				qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
				break;
			}
			case 3:{
				system ("cls||clear");
				qtdDisciplina = mainDisciplina(listaDisciplina, listaProfessor, listaAluno, qtdDisciplina);
				break;
			}
			case 4:{
				system ("cls||clear");
				mainRelatorio(listaDisciplina, qtdDisciplina, listaProfessor, qtdProfessor, listaAluno, qtdAluno);
				break;
			}
			case 5:{
				system ("cls||clear");
				getTeste(listaAluno, &qtdAluno, listaProfessor, &qtdProfessor, listaDisciplina, &qtdDisciplina);
				break;
			}
			default:{error("Opcao invalida");}    
		}
	}	
	return 0;
}
