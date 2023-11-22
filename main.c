#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.c"
#include "verificarQuartoOcupado.c"
#include "verificarQuartoValido.c"
#include "structHospede.c"

int main(){
    //CODIGO ABAIXO É APENAS UM TESTE
    int quartosVazios[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int quartosOcupados[10] = {100};
    int opcaoUsuario;
    int tamanho = 0;
    Hospede hospede;
    Hospede *listaHospedes = (Hospede*) malloc(10 * sizeof(hospede));

    do {
        imprimirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoUsuario);

        switch (opcaoUsuario) {
            //Inserir um novo hospede.
            case 1:
                printf("Insira o nome do hospede: ");
                scanf("%s", &hospede.nome);

                //Verificar RG.
                printf("Digite o RG do hospede: ");
                scanf("%d", &hospede.RG);

                printf("Os quartos disponiveis sao: ");
                for (int i = 0; i < sizeof(quartosVazios) / sizeof(quartosVazios[0]); ++i) {
                    printf("%d ", quartosVazios[i]);
                }

                printf("\nInsira o numero do quarto: ");
                scanf("%d", &hospede.quarto);

//                do {
//                    if(!verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados)){
//                        printf("Quarto nao eh valido!\n");
//                    }
//                    if(verificarQuartoOcupado(hospede.quarto, quartosOcupados)){
//                        printf("Quarto ta ocupado!\n");
//                    }
//                    if(!verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) || verificarQuartoOcupado(hospede.quarto, quartosOcupados) ){
//                        printf("Insira o numero do quarto: ");
//                        scanf("%d", &hospede.quarto);
//                    }
//
//                } while (!verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) ||verificarQuartoOcupado(hospede.quarto, quartosVazios) );\

                listaHospedes[tamanho] = hospede;

                printf("\n");
                printf("Cadastro Registrado: \n");
                printf("Nome do Hospede:%s\nQuarto do Hospede: %d\nRG do Hospede: %d", hospede.nome, hospede.quarto, hospede.RG);


                tamanho++;
                Sleep(1000);
                break;
            case 2:
                printf("\n");
                printf("Lista de hospedes\n");

                for (int i = 0; i < tamanho; ++i) {
                    printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");

                }
                break;
            case 3:
                printf("\n");
                printf("Buscar hospedes\n");
                int rgHospede;
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);

                for (int i = 0; i < tamanho; ++i) {
                    if(listaHospedes[i].RG == rgHospede){
                        printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    }
                }

                break;
        }
    } while (opcaoUsuario != 8);


    return 0;
}