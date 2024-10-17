#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"


int cadastrarAluno(Pessoa lista[], int qtdAluno);
void listarAlunos(Pessoa lista[], int qtdAluno);
// int excluirAluno(Pessoa lista[], int qtdAluno);
// int atualizarAluno(Pessoa lista[], int qtdAluno);

int gerarMatricula(){
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
				return 0;
				break;
			}
			case 1:{
				system ("cls");
				int retorno = cadastrarAluno(listaAluno, qtdAluno);
				switch(retorno){
					case LISTA_CHEIA: printf("Lista de alunos Cheia\n"); break;
					case ERRO_CADASTRO_SEXO: printf("Sexo invalido\n"); break;
					case ERRO_DATA_INVALIDA: printf("Data invalida\n"); break;
					case ERRO_CPF_INVALIDO: printf("Cpf invalido\n"); break;
					case SUCESSO_CADASTRO: printf("Cadastrado com sucesso!\n"); qtdAluno++; break;
				}
				printf("\n");
				break;
			}
			case 2:{
				system ("cls");
				listarAlunos(listaAluno, qtdAluno);
				printf("\n");
				break;
			}
			/*
			case 3:{
				system ("cls");
				int retorno = excluirAluno(listaAluno, qtdAluno);
				if (retorno != -1){
					qtdAluno = retorno;
				}
				printf("\n");  
				break;
			}
			case 4: {
			int retorno = atualizarAluno(listaAluno, qtdAluno);

				break;
			}
			*/
			default:
				system ("cls");
				printf("\n");
				printf("Opcao Invalida!!\n");
				printLine('-',30);
    	}
  	}
    return qtdAluno;
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

	int len = strlen(lista[qtdAluno].nome) - 1;
	if (lista[qtdAluno].nome[len] == '\n') lista[qtdAluno].nome[len] = '\0';


	int sexo;
	printf("Digite o sexo (M/F): ");
	scanf("%c", &sexo);
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
	getchar();
	if(validarData(dia,mes, ano)){
		lista[qtdAluno].data_nascimento.dia = dia;
		lista[qtdAluno].data_nascimento.mes = mes;
		lista[qtdAluno].data_nascimento.ano = ano;
	}else return ERRO_DATA_INVALIDA;


	printf("Digite o CPF(xxx.xxx.xxx-xx): ");
	fgets(lista[qtdAluno].cpf, 15, stdin);
	len = strlen(lista[qtdAluno].cpf) - 1;
	if(validarCpf(lista[qtdAluno].cpf)==0) return ERRO_CPF_INVALIDO;

	lista[qtdAluno].matricula = gerarMatricula();
	return SUCESSO_CADASTRO;
}


void listarAlunos(Pessoa lista[], int qtdAluno){
	char esc;
    system ("cls");
    printLine('-',30);
	if(qtdAluno==0){
		printf("Lista vazia.\n");
		printLine('-',30);
	}else{
		printf("Lista de aluno\n");
		for (int i = 0; i < qtdAluno; i++){
			printf("\n");
			printf("Nome:              \t%s\n",lista[i].nome);
			printf("Sexo:              \t%c\n",lista[i].sexo);
			printf("Data de Nascimento:\t%02d/%02d/%d\n",lista[i].data_nascimento.dia,lista[i].data_nascimento.mes,lista[i].data_nascimento.ano);
			printf("Cpf:               \t%s\n",lista[i].cpf);
			printf("Matricula:         \t%d\n",lista[i].matricula);
			printLine('-',30);
		}     
	}
		printf("Pressione qualquer tecla para voltar para o menu: ");
		getchar();
		scanf("%c", &esc);
		system("cls");
}

/*
int excluirAluno(Pessoa lista[], int qtdAluno){
    system ("cls");
int matricula, achou = 0;
 
printf("Digite a matricula do aluno a ser excluido:");
  scanf("%d",&matricula);
  
for (int i = 0; i < qtdAluno; i++){
if (matricula == lista[i].matricula){
    achou = 1;
  
          for (int j =i; j<qtdAluno - 1; j++){
              lista[j]=lista[j+1];
  }   
      qtdAluno--;  
        break;
  }
     
  }
  if (achou == 1) {
    printf("Aluno excluido com sucesso\n");
    return qtdAluno;
  } else {
    printf("Aluno não encontrado\n");
    return -1;
  }
     }

int atualizarAluno(Pessoa lista[], int qtdAluno) {
  int matricula, achou = 0;
  printf("Digite a matrícula do aluno a ser atualizado: ");
  scanf("%d", &matricula);
int i = 0;
  for (int i=0; i < qtdAluno; i++) {
    if (matricula == lista[i].matricula) {
      achou = 1;
    printf("\n");
    printLine('=',30);
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
      
    printLine('=',30);  
    break;
    }
  }

  if (achou == 1) {
    printf("Aluno atualizado com sucesso\n");
    return i;
  } else {
    printf("Aluno não encontrado\n");
    return -1;
  }
}
*/

 


