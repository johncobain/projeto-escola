#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"

int cadastrarProfessor(Pessoa lista[], int qtdProfessor);
void listarProfessor(Pessoa lista[], int qtdProfessor);
// int excluirProfessor(Pessoa lista[], int qtdProfessor);
// int atualizarProfessor(Pessoa lista[], int qtdProfessor);

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
						error();printf("Lista de professores Cheia"); resetC(); break;
					case ERRO_CADASTRO_SEXO: 
						system("cls");
						error();printf("Sexo invalido"); resetC(); break;
					case ERRO_DATA_INVALIDA: 
						system("cls");
						error();printf("Data invalida"); resetC(); break;
					case ERRO_CPF_INVALIDO: 
						system("cls");
						error();printf("Cpf invalido"); resetC(); break;
					case SUCESSO_CADASTRO: cadastrado(); qtdProfessor++; break;
				}
				break;
			}
			case 2:{
				system ("cls");
				listarProfessor(listaProfessor, qtdProfessor);
				break;
			}
			// case 3:{
			// 	system ("cls");
			// 	int retorno = excluirProfessor(listaProfessor, qtdProfessor);
			// 	if (retorno != -1){
			// 	qtdProfessor = retorno;
			// 	printf("\n");  
			// 	break;
			// }
			// case 4:{
			// 	system ("cls");
			// 	int retorno = atualizarProfessor(listaProfessor, qtdProfessor);
			// 	printf("\n");  
			// 	break;
			// }
			default:invalido();}	
	}
}

int cadastrarProfessor(Pessoa lista[], int qtdProfessor){
	system ("cls");
    printLine('-',30);
    printf("Cadastrando professor\n");
    printLine('-',30);
    if(qtdProfessor >= TAM_PROFESSOR) return LISTA_CHEIA;

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
	scanf("%d", &dia);
	printf("Digite o mes de nascimento (mm): ");
	scanf("%d", &mes);
	printf("Digite o ano de nascimento (aaaa): ");
	scanf("%d", &ano);
	fflush(stdin);
	if(validarData(dia,mes, ano)){
		lista[qtdProfessor].data_nascimento.dia = dia;
		lista[qtdProfessor].data_nascimento.mes = mes;
		lista[qtdProfessor].data_nascimento.ano = ano;
	}else return ERRO_DATA_INVALIDA;


	printf("Digite o CPF(xxx.xxx.xxx-xx): ");
	fgets(lista[qtdProfessor].cpf, 15, stdin);
	len = strlen(lista[qtdProfessor].cpf) - 1;
	if(validarCpf(lista[qtdProfessor].cpf)==0) return ERRO_CPF_INVALIDO;

	if(lista[qtdProfessor].matricula<=2009000||lista[qtdProfessor].matricula>2009000+TAM_PROFESSOR){
		lista[qtdProfessor].matricula = gerarMatriculaP();
	}
	return SUCESSO_CADASTRO;
}


void listarProfessor(Pessoa lista[], int qtdProfessor){
	char esc;
    system ("cls");
	printf("\n");
    printLine('-',50);
	if(qtdProfessor==0){
		printf("Lista vazia.\n");
		printLine('-',50);
	}else{
			printf("Lista de Professores\t|Tamanho: %d\n",qtdProfessor);
    	printLine('-',50);
		for (int i = 0; i < qtdProfessor; i++){
			printf("Nome:               \t|%s\n",lista[i].nome);
			printf("Sexo:               \t|%c\n",lista[i].sexo);
			printf("Data de Nascimento: \t|%02d/%02d/%d\n",lista[i].data_nascimento.dia,lista[i].data_nascimento.mes,lista[i].data_nascimento.ano);
			printf("Cpf:                \t|%s\n",lista[i].cpf);
			printf("Matricula:          \t|%d\n",lista[i].matricula);
			printLine('-',50);
		}     
	}
		printf("Pressione ENTER para voltar para o menu: ");
		getchar();
		scanf("%c", &esc);
		system("cls");  
}
/*
int excluirProfessor(Pessoa lista[], int qtdProfessor){
    system ("cls");
int matricula, achou = 0;
 
printf("Digite a matricula do Professor a ser excluido:");
  scanf("%d",&matricula);
  
for (int i = 0; i < qtdProfessor; i++){
if (matricula == lista[i].matricula){
    achou = 1;
  
          for (int j =i; j<qtdProfessor - 1; j++){
              lista[j]=lista[j+1];
  }   
      qtdProfessor--;  
        break;
  }
     
  }
  if (achou == 1) {
    printf("Professor excluido com sucesso\n");
    return qtdProfessor;
  } else {
    printf("Professor não encontrado\n");
    return -1;
  }
     } 

int atualizarProfessor(Pessoa lista[], int qtdProfessor) {
  int matricula, achou = 0;
  printf("\nDigite a matrícula do Professor a ser atualizado: ");
  scanf("%d", &matricula);
int i = 0;
  for (int i=0; i < qtdProfessor; i++) {
    if (matricula == lista[i].matricula) {
      achou = 1;
    printf("\n");
    printLine('-',30);
    getchar();
    printf("\nDigite o nome: ");
    fgets(lista[i].nome,19,stdin);
    size_t ln = strlen(lista[i].nome) - 1; //size_t = unsigned integer type
        if (lista[i].nome[ln] == '\n')
          lista[i].nome[ln] = '\0';
    printf("Digite o sexo: ");
    scanf("%c", &lista[i].sexo);
    printf("Digite o dia de nascimento: ");
    scanf("%d", &lista[i].data_nascimento.dia);
    printf("Digite o mês de nascimento: ");
    scanf("%d", &lista[i].data_nascimento.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &lista[i].data_nascimento.ano);
    getchar();
    printf("Digite o CPF: ");
    fgets(lista[i].cpf, 15, stdin);
        ln = strlen(lista[i].cpf) - 1;
        if (lista[i].cpf[ln] == '\n')
          lista[i].cpf[ln] = '\0';
      
    printLine('-',30);  
    break;
    }
  }

  if (achou == 1) {
    printf("Professor atualizado com sucesso\n");
    return i;
  } else {
    printf("Professor não encontrado\n");
    return -1;
  }
  }
*/