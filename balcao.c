#include "balcao.h"
#include "cliente.h"

atendimento a;
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

    printf("Bem vindo ao sistema Administrador");

    printf("Nome do utente");
    scanf("&c", &a.nomeCliente);

    printf("Sintomas do utente");
    scanf("&c", &a.sintomasCliente);

    
    printf("Nome do utente: %s /n", a.nomeCliente);
    printf("Sintomas do utente: %s /n", a.sintomasCliente);
};