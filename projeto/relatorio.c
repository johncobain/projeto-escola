#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "escola.h"
#include "pessoa.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"
#include "relatorio.h"

int menuRelatorio();
int menuRelPessoas(int eh_aluno);

int relPessoas(Pessoa lista[], int qtdPessoa, int eh_aluno);

void listarPSexo(Pessoa lista[], int qtdPessoa, int eh_aluno);
void listarAlfa(Pessoa lista[], int qtdPessoa, int eh_aluno);
void listarNascimento(Pessoa lista[], int qtdPessoa, int eh_aluno);
void listarPDisciplina(Pessoa lista[], int qtdPessoa, int eh_aluno);

void aniversariantes(Pessoa aluno[], Pessoa professor[], int qtdAluno, int qtdProfessor);
void buscarP(Pessoa aluno[], Pessoa Professor[], int qtdAluno, int qtdProfessor);
void discMinVagas(Disciplina disciplina[],int qtdDisciplina);
 

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
			}
			case 3:{
				system ("cls");
				aniversariantes(listaAluno, listaProfessor, qtdAluno, qtdProfessor);
				break;
			}
			case 4:{
				system("cls");
				buscarP(listaAluno, listaProfessor, qtdAluno, qtdProfessor);
				break;
			}
			case 5:{
				system("cls");
				discMinVagas(listaDisciplina,qtdDisciplina);
				break;
			}
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
				eh_aluno?listarAlunos(lista, qtdPessoa):listarProfessor(lista, qtdPessoa);
				break;
			}
			case 2:{
				system ("cls");
				listarPSexo(lista, qtdPessoa, eh_aluno);
				break;
			}
			case 3:{
				system ("cls");
				listarAlfa(lista, qtdPessoa, eh_aluno);
				break;
			}
			case 4:{
				system ("cls");
				listarNascimento(lista, qtdPessoa, eh_aluno);
				break;
			}
			case 5:{
				system("cls");
				eh_aluno?listarPDisciplina(lista, qtdPessoa, 1):listarPDisciplina(lista, qtdPessoa, 0);
				break;
			}
			default:error("Opcao invalida");
		}
	}
}

int menuRelatorio(){
	int opcao;
	printf("\n");
	printLine('-',45);
	printf("#### Modulo Relatorios ####\n");
	printLine('-',45);
	printf("0. Voltar\n");
	printf("1. Relatorios Alunos\n");
	printf("2. Relatorios Professores\n");
	printf("3. Aniversariantes do mes\n");
	printf("4. Buscar Pessoas\n");
	printf("5. Disciplinas por minimo de vagas\n");
	printLine('-',45);
	scanf("%d", &opcao);
	return opcao;
}

int menuRelPessoas(int eh_aluno){
	int opcao;
	printf("\n");
	printLine('-',45);
	eh_aluno?printf("#### Relatorios dos Alunos ####\n"):printf("#### Relatorios dos Professores ####\n");
	printLine('-',45);
	printf("0. Voltar\n");
	printf("1. Listar\n");
	printf("2. Listar por Sexo\n");
	printf("3. Listar ordenado por Nome\n");
	printf("4. Listar por Data de Nascimento\n");
	printf("5. Listar por Maximo de Disciplinas\n");
	printLine('-',45);
	scanf("%d", &opcao);
	return opcao;
}

void listarPSexo(Pessoa lista[], int qtdPessoa, int eh_aluno){
	int esc;
	printf("\n");
	printLine('-',60);
	eh_aluno?printf("#### Alunos do Sexo Masculino ####\n"):printf("#### Professores do Sexo Masculino ####\n");
	printLine('-',60);
	for(int i = 0; i< qtdPessoa; i++){
		if(lista[i].sexo=='M'){
			listarUmaP(lista, i);
			printLine('-', 60);
		}
	}
	printLine('-',60);
	eh_aluno?printf("#### Alunas do Sexo Feminino ####\n"):printf("#### Professoras do Sexo Feminino ####\n");
	printLine('-',60);
	for(int i = 0; i< qtdPessoa; i++){
		if(lista[i].sexo=='F'){
			listarUmaP(lista, i);
			printLine('-', 60);
		}
	}
	printLine('-',60);
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}

int trocar_pessoas(Pessoa *a, Pessoa *b) {
    Pessoa temp = *a;
	*a = *b;
	*b = temp;
}

void listarAlfa(Pessoa lista[], int qtdPessoa, int eh_aluno){
	int esc;
	Pessoa listaOrdenada[TAM_P];
	for (int i = 0; i < qtdPessoa; i++) {
        listaOrdenada[i] = lista[i];
    }

	for(int i = 0; i < qtdPessoa - 1; i++){
		for(int j = 0; j < qtdPessoa - i - 1; j++){
			if(strcmp(listaOrdenada[j].nome, listaOrdenada[j+1].nome)> 0){
				trocar_pessoas(&listaOrdenada[j], &listaOrdenada[j+1]);
			}
		}
	}

	printf("\n");
	printLine('-',60);
	eh_aluno?printf("Alunos ordenados alfabeticamente\n"):printf("Professores ordenados alfabeticamente\n");
	printLine('-',60);

	for (int i = 0; i < qtdPessoa; i++) {
        listarUmaP(listaOrdenada, i);
		printLine('-', 60);
    }
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}

void listarNascimento(Pessoa lista[], int qtdPessoa, int eh_aluno){
	int esc;
	Pessoa listaOrdenada[TAM_P];
	for (int i = 0; i < qtdPessoa; i++) {
        listaOrdenada[i] = lista[i];
    }

	for(int i = 0; i < qtdPessoa - 1; i++){
		for(int j = 0; j < qtdPessoa - i - 1; j++){
			if(getDias(listaOrdenada[j].data_nascimento.dia,listaOrdenada[j].data_nascimento.mes,listaOrdenada[j].data_nascimento.ano)<
			getDias(listaOrdenada[j+1].data_nascimento.dia,listaOrdenada[j+1].data_nascimento.mes,listaOrdenada[j+1].data_nascimento.ano)){
				trocar_pessoas(&listaOrdenada[j], &listaOrdenada[j+1]);
			}
		}
	}

	printf("\n");
	printLine('-',60);
	eh_aluno?printf("Alunos ordenados por Data de Nascimento\n"):printf("Professores ordenados por Data de Nascimento\n");
	printLine('-',60);

	for (int i = 0; i < qtdPessoa; i++) {
        listarUmaP(listaOrdenada, i);
		printLine('-', 60);
    }
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}

void listarPDisciplina(Pessoa lista[], int qtdPessoa, int eh_aluno){
	int disc;
	int esc;
	
	printf("Digite a quantidade maxima de Disciplinas: ");
	scanf("%d", &disc);
	system("cls");
	if(disc>0){
		printf("\n");
		printLine('-',60);
		eh_aluno?printf("Alunos em no maximo %d Disciplinas\n", disc):printf("Professores em no maximo %d Disciplinas\n", disc);
		printLine('-',60);
		for(int i = 0; i<qtdPessoa; i++){
			if(lista[i].disCad<=disc){
				listarUmaP(lista, i);
				printLine('-', 60);
			}
		}
		printf("Pressione ENTER para voltar para o menu: ");
		fflush(stdin);
		scanf("%c", &esc);
		system("cls");
	}else{
		error("Numero Invalido");
	}
}

void aniversariantes(Pessoa aluno[], Pessoa professor[], int qtdAluno, int qtdProfessor){
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);

	int esc;
	int mes;
	printf("Digite o mes: ");
	scanf("%d", &mes);
	fflush(stdin);
	system("cls");
	printf("\n");
	printLine('-',60);
	printf("#### Aniversariantes do Mes %d ####\n", mes);
	printLine('-',60);
	printf("\n");
	printLine('-',60);
	printf("#### Alunos: ####\n");
	printLine('-',60);
	for(int i = 0; i<qtdAluno; i++){
		if(aluno[i].data_nascimento.mes==mes){
			listarUmaP(aluno, i);
			if(mes<tm.tm_mon+1||(mes==tm.tm_mon+1&&aluno[i].data_nascimento.dia<=tm.tm_mday)){
				printf("Idade:\t\t\t|Fez %d Anos\n",getDias(aluno[i].data_nascimento.dia,aluno[i].data_nascimento.mes,aluno[i].data_nascimento.ano)/365);
			}else{
				printf("Idade:\t\t\t|Vai fazer %d Anos\n",(getDias(aluno[i].data_nascimento.dia,aluno[i].data_nascimento.mes,aluno[i].data_nascimento.ano)/365)+1);
			}
			printLine('-', 60);
		}
	}
	printf("\n");
	printLine('-',60);
	printf("#### Professores: ####\n");
	printLine('-',60);
	for(int i = 0; i<qtdProfessor; i++){
		if(professor[i].data_nascimento.mes==mes){
			listarUmaP(professor, i);
			if(mes<tm.tm_mon+1||(mes==tm.tm_mon+1&&professor[i].data_nascimento.dia<=tm.tm_mday)){
				printf("Idade:\t\t\t|Fez %d Anos\n",getDias(professor[i].data_nascimento.dia,professor[i].data_nascimento.mes,professor[i].data_nascimento.ano)/365);
			}else{
				printf("Idade:\t\t\t|Vai fazer %d Anos\n",(getDias(professor[i].data_nascimento.dia,professor[i].data_nascimento.mes,professor[i].data_nascimento.ano)/365)+1);
			}
			printLine('-', 60);
		}
	}
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}

void buscarP(Pessoa aluno[], Pessoa Professor[], int qtdAluno, int qtdProfessor){

}

void discMinVagas(Disciplina disciplina[],int qtdDisciplina){
	int esc;
	int minVagas;
	printf("Digite a quantidade minima de Vagas: ");
	scanf("%d", &minVagas);
	fflush(stdin);
	system("cls");
	printf("\n");
	printLine('-',50);
	printf("#### Disciplinas com no minimo %d vagas ####\n", minVagas);
	printLine('-',50);
	for(int i = 0; i < qtdDisciplina; i++){
		if(disciplina[i].vagas>=minVagas){
			printf("Nome:              \t|%s\n",disciplina[i].nome);
			printf("Codigo:            \t|%s\n",disciplina[i].codigo);
			printf("Semestre:          \t|%d\n",disciplina[i].semestre);
			printf("Professor:         \t|%s\n",disciplina[i].professor.nome);
			printf("Vagas:             \t|%d\n",disciplina[i].vagas);
			printLine('-',50);
		}
	}
	printf("Pressione ENTER para voltar para o menu: ");
	fflush(stdin);
	scanf("%c", &esc);
	system("cls");
}
