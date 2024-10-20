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


int cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdDisciplina, int atualizacao);
void listarDisciplina(Disciplina lista[], int qtdDisciplina);
int listarUmaDisciplina(Disciplina lista[], int qtdDisciplina);
int inserirAluno(Disciplina lista[], Pessoa aluno[], int qtdDisciplina);
int excluirAlunoDisciplina(Disciplina lista[], Pessoa aluno[], int qtdDisciplina);
int excluirDisciplina(Disciplina lista[], int qtdDisciplina);
int atualizarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdDisciplina);


int menuDisciplina(){
	int opcao;
	printf("\n");
	printLine('-',30);
	printf("#### Modulo Disciplina ####\n");
	printLine('-',30);
	printf("0. Voltar\n");
	printf("1. Cadastrar\n");
	printf("2. Listar\n");
	printf("3. Listar uma Disciplina\n");
	printf("4. Inserir Aluno\n");
	printf("5. Excluir Aluno\n");
	printf("6. Excluir\n");
	printf("7. Atualizar\n");
	printLine('-',30);
	scanf("%d", &opcao);
	return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], Pessoa listaProfessor[], Pessoa listaAluno[], int qtdDisciplina) { 
	while(1){		
		switch(menuDisciplina()){
			case 0: {
				system ("cls");
				return qtdDisciplina;
				break;
			}
			case 1:{
				system ("cls");
				int retorno = cadastrarDisciplina(listaDisciplina, listaProfessor, qtdDisciplina, 0);
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
					case MAX_DISC_CAD: 
						system("cls");
						error("Professor atingiu o Maximo de Disciplinas"); break;
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
					case MAX_DISC_CAD: 
						system("cls");
						error("Aluno atingiu o Maximo de Disciplinas"); break;
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
			}
			case 6:{
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
			}
			case 7: {
			int retorno = atualizarDisciplina(listaDisciplina, listaProfessor, qtdDisciplina);
			switch(retorno){
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
					case SUCESSO_CADASTRO: sucess("Disciplina atualizado com sucesso!"); break;
				}
				break;
			}
			default:error("Opcao invalida");
		}
	}
}

int cadastrarDisciplina(Disciplina lista[], Pessoa listaProfessor[], int qtdDisciplina, int atualizacao){
	system ("cls");
	printLine('-',30);
	printf("Cadastrando Disciplina\n");
	printLine('-',30);
    if(qtdDisciplina >= TAM_DISC) return LISTA_CHEIA;
	fflush(stdin);
	printf("\nDigite o nome da Disciplina: ");
	fgets(lista[qtdDisciplina].nome,49,stdin);
	fflush(stdin);

	int len = strlen(lista[qtdDisciplina].nome) - 1;
	if (lista[qtdDisciplina].nome[len] == '\n') lista[qtdDisciplina].nome[len] = '\0';

	printf("Digite o Codigo da disciplina(AAA000): ");
	fgets(lista[qtdDisciplina].codigo, 7, stdin);
	fflush(stdin);

	len = strlen(lista[qtdDisciplina].codigo) - 1;
	if (lista[qtdDisciplina].codigo[len] == '\n') lista[qtdDisciplina].codigo[len] = '\0';
	if(validarCodigo(lista[qtdDisciplina].codigo)==0) return ERRO_MATRICULA;

	int semestre;
	printf("Digite o Semestre(AAAAS): ");
	scanf("%d", &semestre);
	if(semestre<10001||semestre>99999) return ERRO_DATA_INVALIDA;
	if(semestre%10!=1&&semestre%10!=2) return ERRO_DATA_INVALIDA;
	lista[qtdDisciplina].semestre = semestre;
	
	getchar();
	if(atualizacao){
		int i = buscarPessoa(listaProfessor, lista[qtdDisciplina].professor.matricula);
		for (int l=i; l<listaProfessor[i].disCad; l++){
			strcpy(listaProfessor[i].disciplinas[l], listaProfessor[i].disciplinas[l+1]);
		}
		listaProfessor[i].disCad--;
	}
	int matricula;
	printf("Digite a matricula do Professor: ");
	scanf("%d", &matricula);
	int professor = buscarPessoa(listaProfessor, matricula);
	if(professor == NAO_ENCONTRADO) return NAO_ENCONTRADO;
	if(listaProfessor[professor].disCad >= MAX_DISC) return MAX_DISC_CAD;
	lista[qtdDisciplina].professor = listaProfessor[professor];
	strcpy(listaProfessor[professor].disciplinas[listaProfessor[professor].disCad], lista[qtdDisciplina].codigo);
	listaProfessor[professor].disCad++;
	
	int vagas;
	printf("Digite a quantidade de vagas: ");
	scanf("%d", &vagas);
	if(vagas<0|| vagas>MAX_VAGAS)return NUM_INVALIDO;
	lista[qtdDisciplina].vagas = vagas;
	if(!atualizacao){
		lista[qtdDisciplina].alunosCad = 0;
	}

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

int listarUmaDisciplina(Disciplina lista[], int qtdDisciplina){
	system ("cls");
	int esc;
	char codigo[7];
	int achou = 0;
	fflush(stdin);
	printf("Digite o codigo da disciplina a ser listada: ");
  	fgets(codigo, 7, stdin);
	fflush(stdin);

	int len = strlen(codigo) - 1;
	if (codigo[len] == '\n') codigo[len] = '\0';
	if(validarCodigo(codigo)==0) return ERRO_MATRICULA;
  
	for (int i = 0; i < qtdDisciplina; i++){
		if (strcmp(codigo, lista[i].codigo)==0){
			printLine('-',50);
        	printf("Nome:              \t|%s\n",lista[i].nome);
			printf("Codigo:            \t|%s\n",lista[i].codigo);
			printf("Semestre:          \t|%d\n",lista[i].semestre);
			printf("Professor:         \t|%s\n",lista[i].professor.nome);
			printf("Vagas:             \t|%d\n",lista[i].vagas);
			printf("Alunos:            \t|");
			for(int j = 0; j< lista[i].alunosCad; j++)printf("%s|", lista[i].alunos[j].nome);
			printf("\n");
			printLine('-',50);
    		achou = 1;
      		break;
  		}
  	}
	printf("Pressione ENTER para voltar para o menu: ");
	scanf("%c", &esc);
	system("cls");
  	if (achou) return SUCESSO_CONSULTA;
	return NAO_ENCONTRADO;
}

int inserirAluno(Disciplina lista[], Pessoa aluno[], int qtdDisciplina){
	system ("cls");
	int matricula;
	char codigo[7];
	int achou;
	printf("Digite a matricula do aluno a ser inserido: ");
	scanf("%d", &matricula);
	if(matricula<0) return ERRO_MATRICULA;

	for (int i=0; i < TAM_ALUNO; i++) {
		if (matricula == aluno[i].matricula) {
			fflush(stdin);
			printf("Digite o codigo da disciplina a ser pesquisada: ");
			fgets(codigo, 7, stdin);
			fflush(stdin);

			int len = strlen(codigo) - 1;
			if (codigo[len] == '\n') codigo[len] = '\0';
			if(validarCodigo(codigo)==0) return ERRO_MATRICULA;
		
			for (int j = 0; j < qtdDisciplina; j++){
				if (strcmp(codigo, lista[j].codigo)==0){
					if(lista[j].alunosCad< lista[j].vagas){
						if(aluno[i].disCad >= MAX_DISC) return MAX_DISC_CAD;
						strcpy(aluno[i].disciplinas[aluno[i].disCad], codigo);
						aluno[i].disCad++;
						lista[j].alunos[lista[j].alunosCad] = aluno[i];
						lista[j].alunosCad += 1;
						achou = 1;
					}else return LISTA_CHEIA;
					break;
				}
			}
			if (achou) return SUCESSO_CADASTRO;
			return NAO_ENCONTRADO;
		}
	}
	return NAO_ENCONTRADO;
}

int excluirAlunoDisciplina(Disciplina lista[], Pessoa aluno[], int qtdDisciplina){
	system ("cls");
	char codigo[7];
	int matricula;
	int achou;

	fflush(stdin);
	printf("Digite o codigo da disciplina a ser listada: ");
  	fgets(codigo, 7, stdin);
	fflush(stdin);

	int len = strlen(codigo) - 1;
	if (codigo[len] == '\n') codigo[len] = '\0';
	if(validarCodigo(codigo)==0) return ERRO_MATRICULA;
  
	for (int i = 0; i < qtdDisciplina; i++){
		if (strcmp(codigo, lista[i].codigo)==0){
			if(lista[i].alunosCad == 0) return LISTA_VAZIA;
			printf("Digite a matricula do aluno a ser excluido: ");
			scanf("%d", &matricula);
			if(matricula<0) return ERRO_MATRICULA;

			for (int j=0; j < lista[i].alunosCad; j++) {
				if (matricula == lista[i].alunos[j].matricula) {
					for (int k=0; k<TAM_ALUNO; k++){
						if (matricula == aluno[k].matricula){
							for (int l=k; l<aluno[k].disCad; l++){
								strcpy(aluno[k].disciplinas[l], aluno[k].disciplinas[l+1]);
							}
							aluno[k].disCad -=1;
						}
					}   
					for (int k=j; k<lista[i].alunosCad-1; k++){
						lista[i].alunos[k]=lista[i].alunos[k+1];
					}   
					lista[i].alunosCad -= 1;
					achou = 1;
					break;
				}
			}
			if (achou) return SUCESSO_EXCLUSAO;
			return NAO_ENCONTRADO;
		}
	}
	return NAO_ENCONTRADO;
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

int atualizarDisciplina(Disciplina lista[],Pessoa listaProfessor[], int qtdDisciplina) {
  	system ("cls");
	char codigo[7];
	fflush(stdin);
	printf("Digite o codigo da Disciplina a ser atualizada: ");
  	fgets(codigo, 7, stdin);
	fflush(stdin);

	int len = strlen(codigo) - 1;
	if (codigo[len] == '\n') codigo[len] = '\0';
	if(validarCodigo(codigo)==0) return ERRO_MATRICULA;
	fflush(stdin);
	for (int i = 0; i < qtdDisciplina; i++){
		if (strcmp(codigo, lista[i].codigo)==0){
      		return cadastrarDisciplina(lista, listaProfessor, i, 1);
  		}
  	}
	return NAO_ENCONTRADO;
}