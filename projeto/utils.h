#include<stdio.h>
#define ASCII2NUM -48

void printLine(char c, int tam);
int bissexto( int ano);
int validarData(int d, int m, int a);
int validarCpf(char cpf[]);
int validarCodigo(char codigo[]);

void error(char *str);
void sucess(char *str);

int getDias(int dia, int mes, int ano);

void to_lower(char *str);