
#include <stdio.h>
#define TAM 3

#include "aluno.h"
#include "professor.h"
#include "utils.h"
#include "disciplina.h"

int imprimeMenu();

int imprimeMenu(){
  int opcao;
  printLine('=',20);
  printf("Digite a opção\n");
  printf("0. Sair\n");
  printf("1. Aluno\n");
  printf("2. Professor\n");
  printf("3. Disciplina\n");
  printLine('=',20);
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  Aluno listaAluno[TAM];
  int qtdAluno = 0;
  Professor listaProfessor[TAM];
  int qtdProfessor = 0;
  Disciplina listaDisciplina[TAM];
  int qtdDisciplina=0;
  
  
do{
    
      switch(imprimeMenu()){
        case 0: {
          system ("clear");
           return 0;
                break;
          }
      
      case 1:{
          system ("clear");
          printf("\n");
          printLine('=',20);
          printf(" Modulo Aluno\n");
          printLine('=',20);
          qtdAluno = mainAluno(listaAluno, qtdAluno);
          printf("\n");
          break;

      }
      case 2:{
          system ("clear");
          printf("\n");
          printLine('=',20);
          printf("Modulo Professor\n");
          printLine('=',20);
          qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
          printf("\n");
          break;
      }
      case 3:{
          system ("clear");
          printf("\n");
          printLine('=',20);
          printf("Modulo Disciplina\n");
          printLine('=',20);
          qtdDisciplina = mainDisciplina(listaDisciplina, qtdDisciplina);
          printf("\n");
          break;
      }
      default:{
          system ("clear");
          printf("\n");
          printf("Opção Invalida!!\n");
          printLine('=',20);
      }    
    }

  }while(1);
  
  
  return 0;
}



