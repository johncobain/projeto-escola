#include <stdlib.h>

#include "utils.h"

// ===== Visual ===================================================

void printLine(char s, int tam){
  int i;
  for(i=1; i<tam; i++){
    printf("%c",s);
  }
  printf("\n");
}
void error(){printf("\033[1;101m");}
void warning(){printf("\033[1;103m");}
void sucess(){printf("\033[1;102m");}
void resetC(){printf("\033[0m");}

void invalido(){
    system ("cls");
    error();
    printf("Opcao Invalida!");
    resetC();
}

void cadastrado(){
    system ("cls");
    sucess();
    printf("Cadastrado com Sucesso!");
    resetC();
}

void excluido(){
    system ("cls");
    sucess();
    printf("Excluido com Sucesso!");
    resetC();
}

void atualizado(){
    system ("cls");
    sucess();
    printf("Atualizado com Sucesso!");
    resetC();
}
// ===== Validação ===================================================

int bissexto(int ano){

    if (ano%4 == 0 && ano%100 != 0 || ano%400 == 0)
        return 1;
    else
        return 0;
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
    if (diasNoMes(m,a)==2 && d>29)
        return 0;
    if (diasNoMes(m,a)==2 && d == 29 && bissexto(a) == 0)
        return 0;
    return 1;
}

int validarNumerosVerificadores(char cpf[TAM_CPF], int posicaoVerificador){
    int i, j;
    int digito = posicaoVerificador + 8;
    int pesosDigitos[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int verificador = 0, valorRecebido;
    int resto;

    for(i = 0, j = digito - 1; i < digito; i++, j--){
        verificador += (cpf[i] - '0') * pesosDigitos[j];
    }

    resto = verificador % 11;
    if(resto>=2) verificador = 11-resto;
    else verificador = 0;
    
    valorRecebido = (cpf[digito] - '0');

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

    if(validarNumerosVerificadores(cpf, 1)){
        return validarNumerosVerificadores(cpf, 2);
    }

    return 0;
}


/*
int calcularIdade(int dn, int mn, int an)
    {
        int da, ma, aa, qtdMes= 0, qtdAno=0, qtdDias=0;

         /*da= ca.dia_mes_atual();
         ma= ca.mes_atual();
         aa= ca.ano_atual();

         while(mn<ma-1 || an<aa){
            mn++;
            qtdMes++;
            if (qtdMes == 12) {
                qtdMes = 0;
                qtdAno ++;
            }
            if (mn == 12){
                an++;
                mn =0;
            }
         }
         if (dn == da){
            qtdMes++;
            qtdDias=0;
         }
         else if (dn <da){
            qtdMes++;
            qtdDias=da-dn;

         }
         else {
            qtdDias = diasNoMes(ma-1, aa)+ da-dn;
         }
         printf(qtdAno,"anos,",qtdMes,"meses e",qtdDias,"dia.\n");
    }
*/

