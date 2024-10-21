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

int cadastrarProfessor(Pessoa lista[], int qtdProfessor);
void listarProfessor(Pessoa lista[], int qtdProfessor);
int excluirProfessor(Pessoa lista[], int qtdProfessor);
int atualizarProfessor(Pessoa lista[], int qtdProfessor);

int gerarMatriculaP(){
	static int matriculaProfessor=2009000;// em homenagem a criação do curso de ADS ifba
	matriculaProfessor++;
	return matriculaProfessor;
}

int menuProfessor(){
	int opcao;
	printf("\n");
	printLine('-',30);
	printf("#### Modulo Professor ####\n");
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

int mainProfessor(Pessoa listaProfessor[], int qtdProfessor) { 
	int opcao = 1;
	while(1){
		switch(menuProfessor()){
			case 0:{
				system ("cls");
				return qtdProfessor;
				break;
			}
			case 1:{
				system ("cls");
				int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
				switch(retorno){
					case LISTA_CHEIA: 
						system("cls");
						error("Lista de professores Cheia"); break;
					case ERRO_CADASTRO_SEXO: 
						system("cls");
						error("Sexo invalido"); break;
					case ERRO_DATA_INVALIDA: 
						system("cls");
						error("Data invalida"); break;
					case ERRO_CPF_INVALIDO: 
						system("cls");
						error("Cpf invalido"); break;
					case SUCESSO_CADASTRO: sucess("Professor cadastrado com sucesso!"); qtdProfessor++; break;
				}
				break;
			}
			case 2:{
				system ("cls");
				listarProfessor(listaProfessor, qtdProfessor);
				break;
			}
			case 3:{
				system ("cls");
				int retorno = excluirProfessor(listaProfessor, qtdProfessor);
				switch(retorno){
					case ERRO_MATRICULA: 
						system("cls");
						error("Matricula Invalida"); break;
					case NAO_ENCONTRADO: 
						system("cls");
						error("Matricula Inexistente"); break;
					case SUCESSO_EXCLUSAO: sucess("Professor excluido com sucesso!"); qtdProfessor--; break;
				}
			break; 
			}
			case 4:{
				system ("cls");
				int retorno = atualizarProfessor(listaProfessor, qtdProfessor);
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
					case SUCESSO_CADASTRO: sucess("Professor atualizado com sucesso!");break;
				}
				break;
			}
			default:error("Opcao invalida");}	
	}
}

int cadastrarProfessor(Pessoa lista[], int qtdProfessor){
	system ("cls");
    printLine('-',30);
    printf("Cadastrando professor\n");
    printLine('-',30);
    if(qtdProfessor >= TAM_P) return LISTA_CHEIA;

	getchar();
	printf("\nDigite o nome: ");
	fgets(lista[qtdProfessor].nome, 49, stdin);
	fflush(stdin);

	int len = strlen(lista[qtdProfessor].nome) - 1;
	if (lista[qtdProfessor].nome[len] == '\n') lista[qtdProfessor].nome[len] = '\0';


	char sexo, getSexo[10];//caracteres excedentes
	printf("Digite o sexo (M/F): ");
	scanf("%c", &sexo);
	fflush(stdin);
	sexo = toupper(sexo);
	if(sexo!='M'&&sexo!='F')return ERRO_CADASTRO_SEXO;
	lista[qtdProfessor].sexo = sexo;
	

	int dia, mes, ano;
	printf("Digite o dia de nascimento (dd): ");
	scanf(" %d", &dia);
	printf("Digite o mes de nascimento (mm): ");
	scanf(" %d", &mes);
	printf("Digite o ano de nascimento (aaaa): ");
	scanf(" %d", &ano);
	if(validarData(dia,mes, ano)){
		lista[qtdProfessor].data_nascimento.dia = dia;
		lista[qtdProfessor].data_nascimento.mes = mes;
		lista[qtdProfessor].data_nascimento.ano = ano;
	}else return ERRO_DATA_INVALIDA;


	printf("Digite o CPF(apenas numeros): ");
	fflush(stdin);
	fgets(lista[qtdProfessor].cpf, TAM_CPF, stdin);
	fflush(stdin);
	if(validarCpf(lista[qtdProfessor].cpf)==0) return ERRO_CPF_INVALIDO;

	if(lista[qtdProfessor].matricula<=2009000||lista[qtdProfessor].matricula>2009000+TAM_P){
		lista[qtdProfessor].matricula = gerarMatriculaP();
		lista[qtdProfessor].disCad = 0;
	}
	return SUCESSO_CADASTRO;
}


void listarProfessor(Pessoa lista[], int qtdProfessor){
	char esc;
    system ("cls");
	printf("\n");
	if(qtdProfessor==0){
    	printLine('-',30);
		printf("Lista vazia.\n");
		printLine('-',30);
	}else{
		printLine('-',60);
		printf("Lista de Professores\t|Tamanho: %d\n",qtdProfessor);
    	printLine('-',60);
		for (int i = 0; i < qtdProfessor; i++){
			listarUmaP(lista, i);
			printLine('-',60);
		}     
	}
		printf("Pressione ENTER para voltar para o menu: ");
		getchar();
		scanf("%c", &esc);
		system("cls");  
}


int excluirProfessor(Pessoa lista[], int qtdProfessor){
    system ("cls");
	int matricula, achou = 0;
 
	printf("Digite a matricula do professor a ser excluido:");
  	scanf("%d",&matricula);
	if(matricula<0) return ERRO_MATRICULA;
  
	for (int i = 0; i < qtdProfessor; i++){
		if (matricula == lista[i].matricula){
			for (int j=i; j<qtdProfessor-1; j++){
				lista[j]=lista[j+1];
			}   
			achou = 1; 
			break;
		}	
  	}
	if (achou) return SUCESSO_EXCLUSAO;
	return NAO_ENCONTRADO;
} 

int atualizarProfessor(Pessoa lista[], int qtdProfessor){
    system ("cls");
	int matricula, achou = 0;

	printf("Digite a matricula do professor a ser atualizado: ");
	scanf("%d", &matricula);
	if(matricula<0) return ERRO_MATRICULA;

	for (int i=0; i < qtdProfessor; i++) {
		if (matricula == lista[i].matricula) {
			achou = 1;
			return cadastrarProfessor(lista, i);		
		}
	}
	return NAO_ENCONTRADO; 
}
