#include <stdio.h>


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