#include <stdio.h>

typedef struct hospede {
    char nome[50];
    char quarto[10];
    char cpf[15];
} Hospede;

int inserirhospede(){
    Hospede hospede1;

    printf("Insira o nome do hospede:");
    scanf("%s", hospede1.nome);
    printf("Insira o numero do quarto:");
    scanf("%s", hospede1.quarto);
    printf("Insira o cpf do hospede:");
    scanf("%s", hospede1.cpf);

    printf("Hospede cadastrado com sucesso!!!");

    return 0;
}