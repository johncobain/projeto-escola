
typedef struct{
int dia;
int mes;
int ano;
}datap;


typedef struct {
int matricula;
char nome[20];
char sexo;
datap dataNasc;
char cpf[15];
} Professor; 

int mainProfessor(Professor listaProfessor[], int qtdProfessor);

