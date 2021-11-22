#include "balcao.h"
#define TAM 50

balcao b;
char *maxMedicosChar, *maxClientesChar;
int maxMedicos, maxClientes;
char analise[TAM];
char sintomas[TAM];
int main(int argc, char **argv[])
{

    maxClientesChar = getenv("MAXCLIENTES");
    if (!maxClientesChar)
    {
        printf("Erro na leitura das variaveis de ambiente.\n");
        return 0;
    }
    else
        maxClientes = atoi(maxClientesChar);

    maxMedicosChar = getenv("MAXMEDICOS");
    if (!maxMedicosChar)
    {
        printf("Erro na leitura das variaveis de ambiente.\n");
        return 0;
    }
    else
        maxMedicos = atoi(maxMedicosChar);

    printf("maxclientes: %d", maxClientes);
    printf("maxmedicos: %d", maxMedicos);

    printf("Bem vindo ao sistema Administrador");
    fflush(stdin);
    fflush(stdout);

    pipe(b.upipeBCl);
    pipe(b.upipeClB);

    int pid = fork();
    if (pid == 0)
    {
        close(STDIN_FILENO);
        dup(b.upipeBCl[0]);
        close(b.upipeBCl[0]);
        close(b.upipeBCl[1]);
        close(STDOUT_FILENO);
        dup(b.upipeClB[1]);
        close(b.upipeClB[1]);
        close(b.upipeClB[0]);
        execl("classificador", "classificador", NULL);
        fprintf(stderr, "EU não devia estar aqui \n");
        return -1;
    }
    else
    {
        close(b.upipeBCl[0]);
        close(b.upipeClB[1]);
    }
    while(1)
    {
        //strcpy(analise, "");
        printf("\nIndique os seus sintomas: ");
        fgets(sintomas, sizeof(sintomas), stdin);
        sintomas[strlen(sintomas) - 1] = '\0';
        if(strcmp(sintomas, "utentes") == 0)
        {
            printf("a ser implementado \n");
        }
        else if(strcmp(sintomas, "especialistas") == 0)
        {
            printf("a ser implementado \n");
        }
        else if(strcmp(sintomas, "delut x") == 0)
        {
            printf("a ser implementado \n"); 
        }
        else if(strcmp(sintomas, "delesp x") == 0)
        {
            printf("a ser implementado \n"); 
        }
        else if(strcmp(sintomas, "freq N") == 0)
        {
            printf("a ser implementado \n"); 
        }
        else if(strcmp(sintomas, "encerra") == 0)
        {
            write(b.upipeBCl[1], "#fim\n", strlen("#fim\n"));
            break;
        }
        else{


            strcat(sintomas, "\n");
            write(b.upipeBCl[1], sintomas, strlen(sintomas));
            int tmp = read(b.upipeClB[0], analise, TAM);
            analise[tmp - 1] = '\0';
            printf("O classificador retornou: %s", analise);
            fflush(stdout);
            fflush(stdin);
        }
    }
    wait(NULL);
    return 0;
};