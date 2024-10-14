#include <stdio.h>
#define TAM_ALUNO 3

#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
typedef struct alu{
    int matricula;
    char sexo;
    int ativo;
} Aluno;

//protótipos das funções
int menuGeral();
int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);


int main(void){

    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
    int sair = 0;

    while(!sair){
        opcao = menuGeral();

        switch(opcao){
            case 0:
                sair = 1;
                break;
            case 1:
                printf("Modulo Aluno\n");
                int sairAluno = 0;
                int opcaoAluno;
                while(!sairAluno){
                    opcaoAluno = menuAluno();

                    switch(opcaoAluno){
                    case 0:sairAluno = 1;break;
                    case 1:{
                        int retorno=cadastrarAluno(listaAluno, qtdAluno);
                        switch(retorno){
                            case MATRICULA_INVALIDA: printf("Matricula invalida\n");break;
                            case LISTA_CHEIA: printf("Lista de alunos Cheia\n"); break;
                            case CAD_ALUNO_SUCESSO: printf("Cadastrado com sucesso!\n"); qtdAluno++; break;
                        }
                        break;
                        }
                    case 2:{
                        listarAluno(listaAluno, qtdAluno);
                        break;
                    }
                    case 3:{
                        int retorno=atualizarAluno(listaAluno, qtdAluno);
                        switch(retorno){
                            case MATRICULA_INVALIDA: printf("Matricula invalida\n");break;
                            case MATRICULA_INEXISTENTE: printf("Matricula inexistente\n"); break;
                            case ATUALIZACAO_ALUNO_SUCESSO: printf("Aluno Atualizado com Sucesso!\n"); break;
                        }
                        break;
                    }
                    case 4:{
                        int retorno=excluirAluno(listaAluno, qtdAluno);
                        switch(retorno){
                            case MATRICULA_INVALIDA: printf("Matricula invalida\n");break;
                            case MATRICULA_INEXISTENTE: printf("Matricula inexistente\n"); break;
                            case EXCLUSAO_ALUNO_SUCESSO: printf("Aluno Excluido com Sucesso!\n");qtdAluno--; break;
                        }
                        break;
                    }
                    default: printf("Opcao invalida\n");
                    }
                }
                break;
            case 2:
                printf("Modulo Professor\n");
                break;
            case 3:
                printf("Modulo Disciplina\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }
    return 0;
}

// funções
int menuGeral(){
    int opcao;
    printf("Projeto Escola\n");
    printf("-----------------------\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    scanf("%d", &opcao);
    
    return opcao;
}

int menuAluno(){
    int opcao;
    printf("-----------------------\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("%d", &opcao);

    return opcao;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
    printf("1 - Cadastrar Aluno\n");

    if(qtdAluno >= TAM_ALUNO) return LISTA_CHEIA;

    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if(matricula<0) return MATRICULA_INVALIDA;

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;
    return CAD_ALUNO_SUCESSO;
}

void listarAluno(Aluno listaAluno[], int qtdAluno){
    printf("2 - Listar Aluno\n");
    if(qtdAluno==0){
        printf("Lista vazia\n");
    }else{
        for(int i = 0; i < qtdAluno; i++){
            if(listaAluno[i].ativo==1){
                printf("Matricula: %d\n", listaAluno[i].matricula);
            }
        }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno){
    printf("3 - Atualizar Aluno\n");
    printf("Digite a matricula: ");
    int achou = 0;
    int matricula;
    scanf("%d", &matricula);
    if(matricula<0) return MATRICULA_INVALIDA;

    for(int i = 0; i < qtdAluno; i++){
        if(matricula== listaAluno[i].matricula&&listaAluno[i].ativo==1){
            printf("Digite a nova matricula: ");
            int novaMatricula;
            scanf("%d", &novaMatricula);
            if(novaMatricula<0) return MATRICULA_INVALIDA;

            listaAluno[i].matricula = novaMatricula;
            achou=1;
            break;
        }
    }
    if(achou) return ATUALIZACAO_ALUNO_SUCESSO; 

    return MATRICULA_INEXISTENTE;
}

int excluirAluno(Aluno listaAluno[], int qtdAluno){
    printf("4 - Excluir Aluno\n");
    printf("Digite a matricula: ");
    int achou = 0;
    int matricula;
    scanf("%d", &matricula);
    if(matricula<0) return MATRICULA_INVALIDA;

    for(int i = 0; i < qtdAluno; i++){
        if(matricula== listaAluno[i].matricula){
            listaAluno[i].ativo = -1;
            for(int j = i; j< qtdAluno-1; j++){
                listaAluno[j].matricula = listaAluno[j+1].matricula;
                listaAluno[j].sexo = listaAluno[j+1].sexo;
                listaAluno[j].ativo = listaAluno[j+1].ativo;
            }
            achou = 1;
            break;
        }
    }
    if(achou) return EXCLUSAO_ALUNO_SUCESSO; 

    return MATRICULA_INEXISTENTE;
}