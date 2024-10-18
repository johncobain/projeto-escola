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


int cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdDisciplina);
void listarDisciplina(Disciplina lista[], int qtdDisciplina);
// void inserirAluno(Disciplina lista[], Pessoa aluno[], int qtdDisciplina);
int excluirDisciplina(Disciplina lista[], int qtdDisciplina);
// int atualizarDisciplina(Disciplina lista[], int qtdDisciplina);


int menuDisciplina(){
	int opcao;
	printf("\n");
	printLine('-',30);
	printf("#### Modulo Disciplina ####\n");
	printLine('-',30);
	printf("0. Voltar\n");
	printf("1. Cadastrar\n");
	printf("2. Listar\n");
	printf("3. Inserir Aluno\n");
	printf("4. Excluir\n");
	printf("5. Atualizar\n");
	printLine('-',30);
	scanf("%d", &opcao);
	return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], Pessoa listaProfessor[], int qtdDisciplina) { 
	while(1){		
		switch(menuDisciplina()){
			case 0: {
				system ("cls");
				return qtdDisciplina;
				break;
			}
			case 1:{
				system ("cls");
				int retorno = cadastrarDisciplina(listaDisciplina, listaProfessor, qtdDisciplina);
				switch(retorno){
					case LISTA_CHEIA: 
						system("cls");
						error("Lista de disciplinas Cheia"); break;
					case ERRO_MATRICULA: 
						system("cls");
						error("Codigo invalido"); break;
					case ERRO_DATA_INVALIDA: 
						system("cls");
						error("Semestre invalido"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Professor nao encontrado"); break;
					case NUM_INVALIDO: 
						system("cls");
						error("Numero de vagas invalido"); break;
					case SUCESSO_CADASTRO: sucess("Disciplina cadastrada com sucesso!"); qtdDisciplina++; break;
				}
				break;
			}
			case 2:{
				system ("cls");
				listarDisciplina(listaDisciplina, qtdDisciplina);
				break;
			}
			case 3:{
				error("Opcao invalida");
				break;
			}
			case 4:{
				system ("cls");
				int retorno = excluirDisciplina(listaDisciplina, qtdDisciplina);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Codigo Invalido"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Codigo Inexistente"); break;
					case SUCESSO_EXCLUSAO: sucess("Disciplina excluida com sucesso!"); qtdDisciplina--; break;
				}
				break; 
			}/*
			case 5: {
			int retorno = atualizarDisciplina(listaDisciplina, qtdDisciplina);

				break;
			}*/
			default:error("Opcao invalida");
		}
	}
}

int cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdDisciplina){
	system ("cls");
	printLine('-',30);
	printf("Cadastrando Disciplina\n");
	printLine('-',30);
    if(qtdDisciplina >= TAM_DISC) return LISTA_CHEIA;

	getchar();
	printf("\nDigite o nome da Disciplina: ");
	fgets(lista[qtdDisciplina].nome,49,stdin);
	fflush(stdin);

	int len = strlen(lista[qtdDisciplina].nome) - 1;
	if (lista[qtdDisciplina].nome[len] == '\n') lista[qtdDisciplina].nome[len] = '\0';

	char codigo[7];
	printf("\nDigite o Codigo da disciplina(AAA000): ");
	fgets(lista[qtdDisciplina].codigo, 7, stdin);
	fflush(stdin);

	len = strlen(lista[qtdDisciplina].codigo) - 1;
	if (lista[qtdDisciplina].codigo[len] == '\n') lista[qtdDisciplina].codigo[len] = '\0';
	if(validarCodigo(lista[qtdDisciplina].codigo)==0) return ERRO_MATRICULA;

	int semestre;
	printf("\nDigite o Semestre: ");
	scanf("%d", &semestre);
	if(semestre<10001||semestre>99999) return ERRO_DATA_INVALIDA;
	if(semestre%10!=1&&semestre%10!=2) return ERRO_DATA_INVALIDA;
	lista[qtdDisciplina].semestre = semestre;
	
	getchar();
	int matricula;
	printf("\nDigite a matricula do Professor: ");
	scanf("%d", &matricula);
	int professor = buscarPessoa(listaProfessor, matricula);
	if(professor == NAO_ENCONTRADO) return NAO_ENCONTRADO;
	lista[qtdDisciplina].professor = listaProfessor[professor];
	
	int vagas;
	printf("\nDigite a quantidade de vagas: ");
	scanf("%d", &vagas);
	if(vagas<0)return NUM_INVALIDO;
	lista[qtdDisciplina].vagas = vagas;

	return SUCESSO_CADASTRO;
}

void listarDisciplina(Disciplina lista[], int qtdDisciplina){
	char esc;
    system ("cls");
	printf("\n");
	if(qtdDisciplina==0){
    	printLine('-',30);
		printf("Lista vazia.\n");
		printLine('-',30);
	}else{
    	printLine('-',50);
		printf("Lista de Disciplina\t|Tamanho: %d\n",qtdDisciplina);
    	printLine('-',50);
		for (int i = 0; i < qtdDisciplina; i++){
			printf("Nome:              \t|%s\n",lista[i].nome);
			printf("Codigo:            \t|%s\n",lista[i].codigo);
			printf("Semestre:          \t|%d\n",lista[i].semestre);
			printf("Professor:         \t|%s\n",lista[i].professor.nome);
			printf("Vagas:             \t|%d\n",lista[i].vagas);
			printLine('-',50);
		}     
	}
	printf("Pressione ENTER para voltar para o menu: ");
	getchar();
	scanf("%c", &esc);
	system("cls");
}

int excluirDisciplina(Disciplina lista[], int qtdDisciplina){
    system ("cls");
	char codigo[7];
	int achou = 0;
	fflush(stdin);
	printf("Digite o codigo da disciplina a ser excluido:");
  	fgets(codigo, 7, stdin);
	fflush(stdin);

	int len = strlen(codigo) - 1;
	if (codigo[len] == '\n') codigo[len] = '\0';
	if(validarCodigo(codigo)==0) return ERRO_MATRICULA;
  
	for (int i = 0; i < qtdDisciplina; i++){
		if (strcmp(codigo, lista[i].codigo)==0){
        	for (int j =i; j<qtdDisciplina - 1; j++){
            	lista[j]=lista[j+1];
  			}   
    		achou = 1;
      		break;
  		}
  	}
  	if (achou) return SUCESSO_EXCLUSAO;
	return NAO_ENCONTRADO;
}
/*
int atualizarDisciplina(Disciplina lista[], int qtdDisciplina) {
  int codigo, achou = 0;
  printf("Digite o codigo da Disciplina a ser atualizada: ");
  scanf("%d", &codigo);
int i = 0;
  for (int i=0; i < qtdDisciplina; i++) {
    if (codigo == lista[i].codigo) {
      achou = 1;
    printf("\n");
    printLine('-',30);
    getchar();
    printf("\nDigite o nome da Disciplina: ");
    fgets(lista[i].nome,19,stdin);
    printf("\nDigite o Semestre: ");
    scanf("%d", &lista[qtdDisciplina].semestre);
      getchar();
    printf("\nDigite o nome do Professor: ");
    fgets(lista[i].nome,19,stdin);   
    printLine('-',30);  
    break;
    }
  }

  if (achou == 1) {
    printf("Disciplina atualizada com sucesso\n");
    return i;
  } else {
    printf("Disciplina não encontrada\n");
    return -1;
  }
}
*/ 