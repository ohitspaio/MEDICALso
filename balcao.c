#include <balcao.h>
#include <cliente.h>

char name [30];
char sintomas [50];

void main() {

    printf("Bem vindo ao sistema Administrador");

    printf("Nome do utente");
    scanf("&d", &name);

    printf("Sintomas do utente");
    scanf("&d", &sintomas);

    printf("Nome do utente/", name);
    printf("Sintomas do utente/", sintomas);
};