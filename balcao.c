#include "balcao.h"

balcao a;
char *maxMedicosChar, *maxClientesChar;
int maxMedicos, maxClientes;
void main() {

    maxClientesChar = getenv("MAXCLIENTES");
    if(!maxClientesChar)
    {
        printf("Erro na leitura das variaveis de ambiente.\n");
        return 0;
    }
    else
    maxClientes = atoi(maxClientesChar);

    maxMedicosChar = getenv("MAXMEDICOS");
    if(!maxMedicosChar)
    {
        printf("Erro na leitura das variaveis de ambiente.\n");
        return 0;
    }
    else
    maxMedicos = atoi(maxMedicosChar);

    printf("maxclientes: %d", maxClientes);
    printf("maxmedicos: %d", maxMedicos);

    printf("Bem vindo ao sistema Administrador");

};