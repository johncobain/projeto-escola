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


int cadastrarAluno(Pessoa lista[], int qtdAluno);
void listarAlunos(Pessoa lista[], int qtdAluno);
int excluirAluno(Pessoa lista[], int qtdAluno);
int atualizarAluno(Pessoa lista[], int qtdAluno);

int gerarMatriculaA(){
	static int matriculaAluno = 2024000;
	matriculaAluno++;
	return matriculaAluno;
}

int menuAluno(){
	int opcao;
	printf("\n");
	printLine('-',30);
	printf("#### Modulo Aluno ####\n");
	printLine('-',30);
	printf("0. Voltar\n");
	printf("1. Cadastrar\n");
	printf("2. Listar\n");
	printf("3. Excluir\n");
	printf("4. Atualizar\n");
	printLine('-',30);
	scanf("%d", &opcao);
	return opcao;
}

int mainAluno(Pessoa listaAluno[], int qtdAluno) { 
 	while(1){
		switch(menuAluno()){
			case 0: {
				system ("cls");
				return qtdAluno;
				break;
			}
			case 1:{
				system ("cls");
				int retorno = cadastrarAluno(listaAluno, qtdAluno);
				switch(retorno){
					case LISTA_CHEIA: 
						system("cls");
						error("Lista de alunos Cheia"); break;
					case ERRO_CADASTRO_SEXO: 
						system("cls");
						error("Sexo invalido"); break;
					case ERRO_DATA_INVALIDA: 
						system("cls");
						error("Data invalida"); break;
					case ERRO_CPF_INVALIDO: 
						system("cls");
						error("Cpf invalido"); break;
					case SUCESSO_CADASTRO: sucess("Aluno cadastrado com sucesso!"); qtdAluno++; break;
				}
				break;
			}
			case 2:{
				system ("cls");
				listarAlunos(listaAluno, qtdAluno);
				break;
			}
			case 3:{
				system ("cls");
				int retorno = excluirAluno(listaAluno, qtdAluno);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula Invalida"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula Inexistente"); break;
					case SUCESSO_EXCLUSAO: sucess("Aluno excluido com sucesso"); qtdAluno--; break;
				}
				break; 
			}
			case 4: {
				system ("cls");
				int retorno = atualizarAluno(listaAluno, qtdAluno);
				switch(retorno){
					case ERRO_CADASTRO_SEXO: 
						system("cls");
						error("Sexo invalido"); break;
					case ERRO_DATA_INVALIDA: 
						system("cls");
						error("Data invalida"); break;
					case ERRO_CPF_INVALIDO: 
						system("cls");
						error("Cpf invalido"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula Inexistente"); break;
					case SUCESSO_CADASTRO: sucess("Aluno atualizado com sucesso!");break;
				}
				break;
			}
			default:error("Opcao invalida");}
  	}
}

int cadastrarAluno(Pessoa lista[], int qtdAluno){
    system ("cls");
    printLine('-',30);
    printf("Cadastrando aluno\n");
    printLine('-',30);
    if(qtdAluno >= TAM_ALUNO) return LISTA_CHEIA;

	getchar();
	printf("\nDigite o nome: ");
	fgets(lista[qtdAluno].nome, 49, stdin);
	fflush(stdin);

	int len = strlen(lista[qtdAluno].nome) - 1;
	if (lista[qtdAluno].nome[len] == '\n') lista[qtdAluno].nome[len] = '\0';


	char sexo, getSexo[10];//caracteres excedentes
	printf("Digite o sexo (M/F): ");
	scanf("%c", &sexo);
	fflush(stdin);
	sexo = toupper(sexo);
	if(sexo!='M'&&sexo!='F')return ERRO_CADASTRO_SEXO;
	lista[qtdAluno].sexo = sexo;
	

	int dia, mes, ano;
	printf("Digite o dia de nascimento (dd): ");
	scanf("%d", &dia);
	printf("Digite o mes de nascimento (mm): ");
	scanf("%d", &mes);
	printf("Digite o ano de nascimento (aaaa): ");
	scanf("%d", &ano);
	fflush(stdin);
	if(validarData(dia,mes, ano)){
		lista[qtdAluno].data_nascimento.dia = dia;
		lista[qtdAluno].data_nascimento.mes = mes;
		lista[qtdAluno].data_nascimento.ano = ano;
	}else return ERRO_DATA_INVALIDA;


	printf("Digite o CPF(apenas numeros): ");
	fgets(lista[qtdAluno].cpf, TAM_CPF, stdin);
	fflush(stdin);
	if(validarCpf(lista[qtdAluno].cpf)==0) return ERRO_CPF_INVALIDO;

	if(lista[qtdAluno].matricula<=2024000||lista[qtdAluno].matricula>2024000+TAM_ALUNO){
		lista[qtdAluno].matricula = gerarMatriculaA();
		lista[qtdAluno].disCad = 0;
	}
	return SUCESSO_CADASTRO;
}


void listarAlunos(Pessoa lista[], int qtdAluno){
	char esc;
    system ("cls");
	printf("\n");
	if(qtdAluno==0){
    	printLine('-',30);
		printf("Lista vazia.\n");
		printLine('-',30);
	}else{
    	printLine('-',60);
		printf("Lista de Alunos    \t|Tamanho: %d\n",qtdAluno);
    	printLine('-',60);
		for (int i = 0; i < qtdAluno; i++){
			printf("Nome:              \t|%s\n",lista[i].nome);
			printf("Sexo:              \t|%c\n",lista[i].sexo);
			printf("Data de Nascimento:\t|%02d/%02d/%d\n",lista[i].data_nascimento.dia,lista[i].data_nascimento.mes,lista[i].data_nascimento.ano);
			printf("Cpf:               \t|%s\n",lista[i].cpf);
			printf("Matricula:         \t|%d\n",lista[i].matricula);
			printf("Disciplinas:       \t|");
			for(int j = 0; j< lista[i].disCad; j++){
				printf("%s|", lista[i].disciplinas[j]);
			}
			printf("\n");
			printLine('-',60);
		}     
	}
	printf("Pressione ENTER para voltar para o menu: ");
	getchar();
	scanf("%c", &esc);
	system("cls");
}


int excluirAluno(Pessoa lista[], int qtdAluno){
    system ("cls");
	int matricula, achou = 0;
 
	printf("Digite a matricula do aluno a ser excluido:");
  	scanf("%d",&matricula);
	if(matricula<0) return ERRO_MATRICULA;
  
	for (int i = 0; i < qtdAluno; i++){
		if (matricula == lista[i].matricula){
			for (int j=i; j<qtdAluno-1; j++){
				lista[j]=lista[j+1];
			}   
			achou = 1; 
			break;
		}	
  	}
	if (achou) return SUCESSO_EXCLUSAO;
	return NAO_ENCONTRADO;
}

int atualizarAluno(Pessoa lista[], int qtdAluno){
    system ("cls");
	int matricula, achou = 0;

	printf("Digite a matricula do aluno a ser atualizado: ");
	scanf("%d", &matricula);
	if(matricula<0) return ERRO_MATRICULA;

	for (int i=0; i < qtdAluno; i++) {
		if (matricula == lista[i].matricula) {
			achou = 1;
			return cadastrarAluno(lista, i);		
		}
	}
	return NAO_ENCONTRADO; 
}
