#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "cliente.h"
#include "medicos.h"

typedef struct balcao{
    medicos med;
    clientes cl;
    int upipeBCl[2], upipeClB[2];
}balcao;