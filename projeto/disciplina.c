
#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"
#include "utils.h"


int codigoDisciplina=300;

int getProximaDisciplina();


int getProximaDisciplina(){
 static int DisciplinaAtual=300;
  DisciplinaAtual++;
  return DisciplinaAtual;
}


int cadastrarDisciplina(Disciplina lista[], int qtdDisciplina);
void listarDisciplina(Disciplina lista[], int qtdDisciplina);
int excluirDisciplina(Disciplina lista[], int qtdDisciplina);
int atualizarDisciplina(Disciplina lista[], int qtdDisciplina);


int menuDisciplina(){
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

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) { 
  int opcao = 1;

  while(opcao != 0){
    opcao = menuDisciplina();
    
    switch(opcao){
      printf("\n");
      case 1:{
        system ("clear");
        qtdDisciplina = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
        printf("\n");
        break;
      }
      case 2:{
        system ("clear");
        listarDisciplina(listaDisciplina, qtdDisciplina);
        printf("\n");
        break;
      }
      case 3:{
        system ("clear");
        int retorno = excluirDisciplina(listaDisciplina, qtdDisciplina);
         if (retorno != -1){
         qtdDisciplina = retorno;
      } 
        break;
      }
       case 4: {
       int retorno = atualizarDisciplina(listaDisciplina, qtdDisciplina);

        break;
    }
     
    }
    
  }
  return qtdDisciplina;
}

int cadastrarDisciplina(Disciplina lista[], int qtdDisciplina){
    system ("clear");
  printLine('=',20);
  printf("Cadastrando Disciplina\n");
  printLine('=',20);
 lista[qtdDisciplina].codigo = getProximaDisciplina();
  getchar();
  printf("\nDigite o nome da Disciplina: ");
  fgets(lista[qtdDisciplina].nome,19,stdin);
  printf("\nDigite o Semestre: ");
  scanf("%d", &lista[qtdDisciplina].semestre);
  getchar();
  printf("\nDigite o Professor: ");
  fgets(lista[qtdDisciplina].professor,19,stdin);
  
  qtdDisciplina++;
  return qtdDisciplina;
    
}

void listarDisciplina(Disciplina lista[], int qtdDisciplina){
    system ("clear");
  printLine('=',20);
  printf("Lista de Disciplina....\n");
    for (int i = 0; i < qtdDisciplina; i++){
    printf("\n");
    printf("Codigo:    \t\t\t\t %d\n",lista[i].codigo);
    printf("Nome:      \t\t\t\t %s\n",lista[i].nome);
    printf("Semestre:  \t\t\t\t %d\n",lista[i].semestre);
    printf("Professor: \t\t\t\t %s\n",lista[i].professor);
    printLine('=',20);
  
    } 
    }
  
int excluirDisciplina(Disciplina lista[], int qtdDisciplina){
    system ("clear");
int codigo, achou = 0;
 
printf("Digite o codigo da disciplina a ser excluido:");
  scanf("%d",&codigo);
  
for (int i = 0; i < qtdDisciplina; i++){
if (codigo == lista[i].codigo){
    achou = 1;
  
          for (int j =i; j<qtdDisciplina - 1; j++){
              lista[j]=lista[j+1];
  }   
      qtdDisciplina--;  
        break;
  }
     
  }
  if (achou == 1) {
    printf("Disciplina excluida com sucesso\n");
    return qtdDisciplina;
  } else {
    printf("Disciplina não encontrada\n");
    return -1;
  }
     }

int atualizarDisciplina(Disciplina lista[], int qtdDisciplina) {
  int codigo, achou = 0;
  printf("Digite o codigo da Disciplina a ser atualizada: ");
  scanf("%d", &codigo);
int i = 0;
  for (int i=0; i < qtdDisciplina; i++) {
    if (codigo == lista[i].codigo) {
      achou = 1;
    printf("\n");
    printLine('=',20);
    getchar();
    printf("\nDigite o nome da Disciplina: ");
    fgets(lista[i].nome,19,stdin);
    printf("\nDigite o Semestre: ");
    scanf("%d", &lista[qtdDisciplina].semestre);
      getchar();
    printf("\nDigite o nome do Professor: ");
    fgets(lista[i].nome,19,stdin);   
    printLine('=',20);  
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




