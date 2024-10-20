#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"
#include "pessoa.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"
#include "relatorio.h"

int menuRelPessoas(int eh_aluno);

int relPessoas(Pessoa lista[], int qtdPessoa, int eh_aluno);

void listarPSexo(Pessoa lista[], int qtdPessoa, int eh_aluno);
void listarAlfa(Pessoa lista[], int qtdPessoa);
void listarNascimento(Pessoa lista[], int qtdPessoa);
void listarPDisciplina(Pessoa lista[], int qtdPessoa);

int menuRelatorio(){
	int opcao;
	printf("\n");
	printLine('-',40);
	printf("#### Modulo Relatorios ####\n");
	printLine('-',40);
	printf("0. Voltar\n");
	printf("1. Relatorios Alunos\n");
	printf("2. Relatorios Professores\n");
	printf("3. Aniversariantes do mes\n");
	printf("4. Buscar Pessoas\n");
	printf("5. Disciplinas com mais de 40 vagas\n");
	printLine('-',40);
	scanf("%d", &opcao);
	return opcao;
}

int mainRelatorio(Disciplina listaDisciplina[], int qtdDisciplina, Pessoa listaProfessor[], int qtdProfessor, Pessoa listaAluno[], int qtdAluno){
    while(1){		
		switch(menuRelatorio()){
			case 0: {
				system ("cls");
				return 0;
				break;
			}
			case 1:{
				system ("cls");
				relPessoas(listaAluno, qtdAluno, 1);
				break;
			}
			case 2:{
				system ("cls");
				relPessoas(listaProfessor, qtdProfessor, 0);
				break;
			}/*
			case 3:{
				system ("cls");
				int retorno = listarUmaDisciplina(listaDisciplina, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Codigo Inexistentes"); break;
					case SUCESSO_CONSULTA:break;
				}
				break;
			}
			case 4:{
				int retorno = inserirAluno(listaDisciplina, listaAluno, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula ou Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula ou Codigo Inexistentes"); break;
					case LISTA_CHEIA: 
						system("cls");
						error("Lista da Disciplina cheia"); break;
					case SUCESSO_CADASTRO: sucess("Aluno cadastrado na Disciplina com sucesso!");break;
				}
				break;
			}
			case 5:{
				int retorno = excluirAlunoDisciplina(listaDisciplina, listaAluno, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula ou Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula ou Codigo Inexistentes"); break;
					case LISTA_VAZIA: 
						system("cls");
						error("Lista da Disciplina vazia"); break;
					case SUCESSO_EXCLUSAO: sucess("Aluno excluido na Disciplina com sucesso!");break;
				}
				break;
			}*/
			default:error("Opcao invalida");
		}
	}
}

int relPessoas(Pessoa lista[], int qtdPessoa, int eh_aluno){
    while(1){		
		switch(menuRelPessoas(eh_aluno)){
			case 0: {
				system ("cls");
				return 0;
				break;
			}
			case 1:{
				system ("cls");
				eh_aluno?listarAlunos(lista, qtdPessoa):listarProfessor(lista, qtdPessoa);;
				break;
			}
			case 2:{
				system ("cls");
				eh_aluno?listarPSexo(lista, qtdPessoa, 1):listarPSexo(lista, qtdPessoa, 0);
				break;
			}/*
			case 3:{
				system ("cls");
				int retorno = listarUmaDisciplina(listaDisciplina, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Codigo Inexistentes"); break;
					case SUCESSO_CONSULTA:break;
				}
				break;
			}
			case 4:{
				int retorno = inserirAluno(listaDisciplina, listaAluno, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula ou Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula ou Codigo Inexistentes"); break;
					case LISTA_CHEIA: 
						system("cls");
						error("Lista da Disciplina cheia"); break;
					case SUCESSO_CADASTRO: sucess("Aluno cadastrado na Disciplina com sucesso!");break;
				}
				break;
			}
			case 5:{
				int retorno = excluirAlunoDisciplina(listaDisciplina, listaAluno, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula ou Codigo Invalidos"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula ou Codigo Inexistentes"); break;
					case LISTA_VAZIA: 
						system("cls");
						error("Lista da Disciplina vazia"); break;
					case SUCESSO_EXCLUSAO: sucess("Aluno excluido na Disciplina com sucesso!");break;
				}
				break;
			}*/
			default:error("Opcao invalida");
		}
	}
}


int menuRelPessoas(int eh_aluno){
	int opcao;
	printf("\n");
	printLine('-',40);
	eh_aluno?printf("#### Relatorios dos Alunos ####\n"):printf("#### Relatorios dos Professores ####\n");
	printLine('-',40);
	printf("0. Voltar\n");
	printf("1. Listar\n");
	printf("2. Listar por Sexo\n");
	printf("3. Listar por Data de Nascimento\n");
	if(eh_aluno)printf("4. Matriculados em menos de 3 disciplinas\n");
	printLine('-',40);
	scanf("%d", &opcao);
	return opcao;
}

void listarPSexo(Pessoa lista[], int qtdPessoa, int eh_aluno){
	int esc;
	printf("\n");
	printLine('-',40);
	eh_aluno?printf("#### Alunos do Sexo Masculino ####\n"):printf("#### Professores do Sexo Masculino ####\n");
	printLine('-',40);
	for(int i = 0; i< qtdPessoa; i++){
		if(lista[i].sexo=='M'){
			printf("\n");
			eh_aluno?printf("Aluno: "): printf("Professor: ");
			printf("%s - Matricula: %d\n", lista[i].nome, lista[i].matricula);
			printf("\n");
		}
	}
	printLine('-',40);
	eh_aluno?printf("#### Alunas do Sexo Feminino ####\n"):printf("#### Professoras do Sexo Feminino ####\n");
	printLine('-',40);
	for(int i = 0; i< qtdPessoa; i++){
		if(lista[i].sexo=='F'){
			printf("\n");
			eh_aluno?printf("Aluna: "): printf("Professora: ");
			printf("%s - Matricula: %d\n", lista[i].nome, lista[i].matricula);
			printf("\n");
		}
	}
	printLine('-',40);
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}
void listarAlfa(Pessoa lista[], int qtdPessoa);
void listarNascimento(Pessoa lista[], int qtdPessoa);
void listarPDisciplina(Pessoa lista[], int qtdPessoa);