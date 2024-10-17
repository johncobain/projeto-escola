/*
#include<stdio.h>

typedef struct{
int dia;
int mes;
int ano;
}data;

int main ()

{
 data data;
printf("Digite o dia:");
scanf("%d",&data.dia);
printf("Digite o mes:");
scanf("%d",&data.mes);
printf("Digite o ano:");
scanf("%d",&data.ano);


if (data.ano && data.mes && data.dia) {

  if (data.ano<2022 && data.ano>1900){

	  if ((data.mes<=0) || (data.mes>12)){
		  printf("Número não corresponde aos meses do ano. Inválido!");
      return 0;
                }
    if ((data.dia>31) || (data.dia<=0)){
		  printf("Data inválida!");
      return 0;
                }
    if ((data.dia>=30) && (data.mes==2)){
		  printf("Data inválida para o mês de fevereiro!");
      return 0; 
                }
    if ((data.dia==29) && (data.mes==2) && ((data.ano % 4) != 0)){
		  printf("Data inválida para fevereiro não bissexto!");
      return 0;
                }
    if ((data.dia==31) && ((data.mes==2) || (data.mes==4) || (data.mes==6) || (data.mes==9) || (data.mes==11))){
		  printf("Data inválida para os meses correspondentes a 31!");
      return 0;
                }
    if ( (1<=data.mes<=12) && (1<=data.dia<=31) ){
		  printf("Data válida!");
      return 1;
                }         				                                  
}
    
else {
	printf("Número invalido!");
  
  return 0; 
    }

  }
}
*/