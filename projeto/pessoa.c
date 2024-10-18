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
    for(int i = 0; i< TAM_PROFESSOR; i++){
        if(lista[i].matricula==matricula) return i;
    }
    return NAO_ENCONTRADO;
}