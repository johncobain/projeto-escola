#include<stdio.h>
#define TAM_CPF 12


void printLine(char c, int tam);
int bissexto( int ano);
int validarData(int d, int m, int a);
int validarCpf(char cpf[]);

void error(char *str);
void sucess(char *str);