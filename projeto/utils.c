#include "utils.h"


void printLine(char s, int tam){
  int i;
  for(i=1; i<tam; i++){
    printf("%c",s);
  }
  printf("\n");
}


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


int maindata(){
    int d,m,a;
    printf("Digite o dia de nascimento no formato dd\n");
    scanf("%d",&d);
    printf("Digite o mes de nascimento no formato mm\n");
    scanf("%d",&m);
    printf("Digite o ano de nascimento no formato aaaa\n");
    scanf("%d",&a);
    if (validarData(d,m,a)== 1){
    //        calcularIdade(d,m,a);
    printf("data valida!");
    }
    else
        printf("Data Invalida!\n");
    }


*/