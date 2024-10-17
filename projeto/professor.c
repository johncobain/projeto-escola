
#include <stdio.h>
#include <string.h>


#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"

int matriculaAtualProfessor=200;

int getProximaMatriculaProfessor();

int getProximaMatriculaProfessor(){
 static int matriculaAtualProfessor=200;
  matriculaAtualProfessor++;
  return matriculaAtualProfessor;
}


int cadastrarProfessor(Professor lista[], int qtdProfessor);
void listarProfessor(Professor lista[], int qtdProfessor);
int excluirProfessor(Professor lista[], int qtdProfessor);
int atualizarProfessor(Professor lista[], int qtdProfessor);

int menuProfessor(){
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

int mainProfessor(Professor listaProfessor[], int qtdProfessor) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuProfessor();
    
    switch(opcao){
      printf("\n");
      case 1:{
        system ("clear");
        qtdProfessor = cadastrarProfessor(listaProfessor, qtdProfessor);
        printf("\n");
        break;
      }
      case 2:{
        system ("clear");
        listarProfessor(listaProfessor, qtdProfessor);
        printf("\n");
        break;
      }
      case 3:{
        system ("clear");
        int retorno = excluirProfessor(listaProfessor, qtdProfessor);
        if (retorno != -1){
        qtdProfessor = retorno;
        printf("\n");  
        break;
      }
      case 4:{
        system ("clear");
        int retorno = atualizarProfessor(listaProfessor, qtdProfessor);
        printf("\n");  
        break;
      }
      default:{
       system ("clear");
       printf("Opcao Invalida!!\n");
      }
    }
    
  }
  return qtdProfessor;
}
  }
int cadastrarProfessor(Professor lista[], int qtdProfessor){
    system ("clear");
  printLine('=',20);
  printf("Cadastrando Professor\n");
  printLine('=',20); 
  lista[qtdProfessor].matricula = getProximaMatriculaProfessor();
  getchar();
  printf("\nDigite o nome: ");
  fgets(lista[qtdProfessor].nome,19,stdin);
  size_t ln = strlen(lista[qtdProfessor].nome) - 1; //size_t = unsigned integer type
        if (lista[qtdProfessor].nome[ln] == '\n')
          lista[qtdProfessor].nome[ln] = '\0';
  printf("Digite o sexo: ");
  scanf("%c", &lista[qtdProfessor].sexo);
  printf("Digite o dia de nascimento: ");
  scanf("%d", &lista[qtdProfessor].dataNasc.dia);
  printf("Digite o mês de nascimento: ");
  scanf("%d", &lista[qtdProfessor].dataNasc.mes);
  printf("Digite o ano de nascimento: ");
  scanf("%d", &lista[qtdProfessor].dataNasc.ano);
  getchar();
  printf("Digite o CPF: ");
  fgets(lista[qtdProfessor].cpf, 15, stdin);
        ln = strlen(lista[qtdProfessor].cpf) - 1;
        if (lista[qtdProfessor].cpf[ln] == '\n')
          lista[qtdProfessor].cpf[ln] = '\0';
  qtdProfessor++;
  return qtdProfessor;
    
}

void listarProfessor(Professor lista[], int qtdProfessor){
    system ("clear");
  printLine('=',20);
  printf("Lista de Professor....\tTamanho %d\n",qtdProfessor);
  for (int i = 0; i < qtdProfessor; i++){
    printf("\n");
    printf("Matrícula:         \t\t\t\t %d\n",lista[i].matricula);
    printf("Nome:              \t\t\t\t %s\n",lista[i].nome);
    printf("Sexo               \t\t\t\t %c\n",lista[i].sexo);
    printf("Data de Nascimento:\t\t\t\t %d/%d/%d\n",lista[i].dataNasc.dia,lista[i].dataNasc.mes,lista[i].dataNasc.ano);
    printf("Cpf                \t\t\t\t %s\n",lista[i].cpf);
    printLine('=',20);
  
    } 
      
}

int excluirProfessor(Professor lista[], int qtdProfessor){
    system ("clear");
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

int atualizarProfessor(Professor lista[], int qtdProfessor) {
  int matricula, achou = 0;
  printf("\nDigite a matrícula do Professor a ser atualizado: ");
  scanf("%d", &matricula);
int i = 0;
  for (int i=0; i < qtdProfessor; i++) {
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
    scanf("%d", &lista[i].dataNasc.dia);
    printf("Digite o mês de nascimento: ");
    scanf("%d", &lista[i].dataNasc.mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &lista[i].dataNasc.ano);
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
    printf("Professor atualizado com sucesso\n");
    return i;
  } else {
    printf("Professor não encontrado\n");
    return -1;
  }
  }