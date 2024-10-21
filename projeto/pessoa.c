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
    printf("Cpf:               \t|%s\n",lista[i].cpf);
    printf("Matricula:         \t|%d\n",lista[i].matricula);
    printf("Disciplinas:       \t|");
    for(int j = 0; j< lista[i].disCad; j++){
        printf("%s|", lista[i].disciplinas[j]);
    }
    printf("\n");    
}
