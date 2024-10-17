#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"

int matriculaAtualAluno=100;

int getProximaMatricula();
int cadastrarAluno(Aluno lista[], int qtdAluno);
void listarAlunos(Aluno lista[], int qtdAluno);
int excluirAluno(Aluno lista[], int qtdAluno);
int atualizarAluno(Aluno lista[], int qtdAluno);

int getProximaMatricula(){
	static int matriculaAtualAluno=100;
	matriculaAtualAluno++;
	return matriculaAtualAluno;
}

int menuAluno(){
  int opcao;
  printLine('=',20);
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  printLine('=',20);
  scanf("%d", &opcao);
  return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuAluno();
    
    switch(opcao){
        printf("\n");
      case 1:{
        system ("clear");
        qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
        printf("\n");
        break;
      }
      case 2:{
         system ("clear");
     
        listarAlunos(listaAluno, qtdAluno);
        printf("\n");
        break;
      }
      case 3:{
         system ("clear");
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
    }
    
  }
      return qtdAluno;
}

int cadastrarAluno(Aluno lista[], int qtdAluno){
    system ("clear");
    printLine('=',20);
    printf("Cadastrando aluno\n");
    printLine('=',20);
    lista[qtdAluno].matricula = getProximaMatricula();
  getchar();
  printf("\nDigite o nome: ");
  fgets(lista[qtdAluno].nome,19,stdin);
  size_t ln = strlen(lista[qtdAluno].nome) - 1; //size_t = unsigned integer type
        if (lista[qtdAluno].nome[ln] == '\n')
          lista[qtdAluno].nome[ln] = '\0';
  printf("Digite o sexo: ");
  scanf("%c", &lista[qtdAluno].sexo);
  printf("Digite o dia de nascimento: ");
  scanf("%d", &lista[qtdAluno].data_nascimento.dia);
  printf("Digite o mês de nascimento: ");
  scanf("%d", &lista[qtdAluno].data_nascimento.mes);
  printf("Digite o ano de nascimento: ");
  scanf("%d", &lista[qtdAluno].data_nascimento.ano);
  getchar();
  printf("Digite o CPF: ");
  fgets(lista[qtdAluno].cpf, 15, stdin);
        ln = strlen(lista[qtdAluno].cpf) - 1;
        if (lista[qtdAluno].cpf[ln] == '\n')
          lista[qtdAluno].cpf[ln] = '\0';
  qtdAluno++;
  return qtdAluno;
    
}

void listarAlunos(Aluno lista[], int qtdAluno){
    system ("clear");
    printLine('=',20);
    printf("Lista de aluno\n");
  for (int i = 0; i < qtdAluno; i++){
    printf("\n");
    printf("Matrícula:         \t\t\t\t%d\n",lista[i].matricula);
    printf("Nome:              \t\t\t\t%s\n",lista[i].nome);
    printf("Sexo:              \t\t\t\t%c\n",lista[i].sexo);
    printf("Data de Nascimento:\t\t\t\t %d/%d/%d\n",lista[i].data_nascimento.dia,lista[i].data_nascimento.mes,lista[i].data_nascimento.ano);
    printf("Cpf: %s\n",lista[i].cpf);
    printLine('=',20);
  
    } 
       
}

int excluirAluno(Aluno lista[], int qtdAluno){
    system ("clear");
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

int atualizarAluno(Aluno lista[], int qtdAluno) {
  int matricula, achou = 0;
  printf("Digite a matrícula do aluno a ser atualizado: ");
  scanf("%d", &matricula);
int i = 0;
  for (int i=0; i < qtdAluno; i++) {
    if (matricula == lista[i].matricula) {
      achou = 1;
    printf("\n");
    printLine('=',20);
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
      
    printLine('=',20);  
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

 


