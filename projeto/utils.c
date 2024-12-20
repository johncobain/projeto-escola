#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "utils.h"
#include "pessoa.h"
#include "disciplina.h"

int getDias(int dia, int mes, int ano);
// ===== Visual ===================================================

void printLine(char s, int tam){
  int i;
  for(i=1; i<tam; i++){
    printf("%c",s);
  }
  printf("\n");
}
void error(char *str){system("cls||clear"); printf("\033[1;101m%s\033[0m", str);}
void sucess(char *str){system("cls||clear"); printf("\033[1;102m%s\033[0m", str);}

// ===== Validação ===================================================

int bissexto(int ano){
    if (ano%4 == 0 && ano%100 != 0 || ano%400 == 0)return 1;
    else return 0;
}

int diasNoMes(int m, int a){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else {
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        else if(m==2) {
            if (bissexto(a) == 1)
                return 29;
            else
                return 28;
        }else{
            return 0;
        }
    }
}

int validarData(int d, int m, int a){
    if (d<1 || d>31 || m<1 || m>12)
        return 0;
    if (d == 31 && diasNoMes(m,a)!=31)
        return 0;
    if (m==2 && d>29)
        return 0;
    if (m==2 && d == 29 && bissexto(a) == 0)
        return 0;
    if (getDias(d,m,a)<0)
        return 0;
    return 1;
}

int validarVerificadores(char cpf[TAM_CPF], int posicaoVerificador){
    int i, j;
    int digito = posicaoVerificador + 8;
    int pesosDigitos[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int verificador = 0, valorRecebido;
    int resto;

    for(i = 0, j = digito - 1; i < digito; i++, j--){
        verificador += (cpf[i] + ASCII2NUM) * pesosDigitos[j];
    }

    resto = verificador % 11;
    if(resto>=2) verificador = 11-resto;
    else verificador = 0;
    
    valorRecebido = (cpf[digito] + ASCII2NUM);

    if(verificador != valorRecebido)return 0;
    return 1;
}

int validarCpf(char cpf[TAM_CPF]){
    int numerosIguais = 1;

    for(int i = 0; i < TAM_CPF - 1; i++){
        if(cpf[i] == '\n' || (cpf[i] < '0' || cpf[i] > '9'))return 0;
    }
    if(cpf[TAM_CPF-1] != '\0')return 0;

    for(int i = 1; i < TAM_CPF -  1; i++){
        if(cpf[0] == cpf[i])numerosIguais++;
    }
    if(numerosIguais == TAM_CPF - 1)return  0;

    if(validarVerificadores(cpf, 1)){
        return validarVerificadores(cpf, 2);
    }

    return 0;
}

int validarCodigo(char codigo[7]){
    for(int i = 0; i < 7 - 1; i++){
        if(i<3 && (toupper(codigo[i])<'A'||toupper(codigo[i])>'Z')){
            return 0;
        }
        if(i<3){
            codigo[i] = toupper(codigo[i]);
        }
        if((i>=3&&i<7) && (codigo[i]<'0'||codigo[i]>'9')){
            return 0;
        }
    }
    return 1;
}

// ===== Utilidades ===================================================
int getDias(int dia, int mes, int ano){

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    int totDias = 0;
    int aAno = tm.tm_year + 1900;
    int aMes = tm.tm_mon + 1;
    int aDia = tm.tm_mday;

    totDias+= (aDia+(aMes*30)+(aAno*365))-(dia+(mes*30)+(ano*365));
 
    return totDias;
}

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}