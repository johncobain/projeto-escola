#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"
#include "pessoa.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"

int buscarPessoa(Pessoa lista[], int matricula){
    for(int i = 0; i< TAM_P; i++){
        if(lista[i].matricula==matricula) return i;
    }
    return NAO_ENCONTRADO;
}

int listarUmaP(Pessoa lista[], int i){
    printf("Nome:              \t|%s\n",lista[i].nome);
    printf("Sexo:              \t|%c\n",lista[i].sexo);
    printf("Data de Nascimento:\t|%02d/%02d/%d\n",lista[i].data_nascimento.dia,lista[i].data_nascimento.mes,lista[i].data_nascimento.ano);
    printf("Cpf:               \t|%c%c%c.%c%c%c.%c%c%c-%c%c\n",
        lista[i].cpf[0],lista[i].cpf[1],lista[i].cpf[2],
        lista[i].cpf[3],lista[i].cpf[4],lista[i].cpf[5],
        lista[i].cpf[6],lista[i].cpf[7],lista[i].cpf[8],
        lista[i].cpf[9],lista[i].cpf[10]);
    printf("Matricula:         \t|%d\n",lista[i].matricula);
    printf("Disciplinas:       \t|");
    for(int j = 0; j< lista[i].disCad; j++){
        printf("%s|", lista[i].disciplinas[j]);
    }
    printf("\n");    
}
