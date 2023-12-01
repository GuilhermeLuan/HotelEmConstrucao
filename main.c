#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "menu.c"
#include "verificarQuartoOcupado.c"
#include "verificarQuartoValido.c"
#include "structHospede.c"
#include "verificarNome.c"
#include "indicaPosicaoNome.c"
#include "removerElemento.c"
#include "verificarSeRGExiste.c"
#include "deletarHospede.c"
#include "Fun_arquivoLista.c"
#include "removerHospede.c"
#include "cmpfunc.c"
int main(){
    //CODIGO ABAIXO É APENAS UM TESTE
    int quartosVazios[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int quartosOcupados[10];
    int opcaoUsuario;
    int qtdHospedes = 0;
    int tamanhoArray = 10;
    Hospede hospede;
    Hospede *listaHospedes = (Hospede*) calloc(10, sizeof(hospede));

    do {
        imprimirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoUsuario);

        switch (opcaoUsuario) {
            case 1:
                printf("Insira o nome do hospede: ");
                fflush(stdin);
                fgets(hospede.nome, 30, stdin);
                hospede.nome[strcspn(hospede.nome,"\n")] = 0;

                //Valida RG
                printf("Digite o RG do hospede: ");
                scanf("%d", &hospede.RG);
                fflush(stdin);

                printf("Os quartos disponiveis sao: ");
                for (int i = 0; i < tamanhoArray; ++i) {
                    printf("%d ", quartosVazios[i]);
                }

                printf("\nInsira o numero do quarto: ");
                scanf("%d", &hospede.quarto);
                int quartoDesejado = hospede.quarto;


                while (verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0 || verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                    if(verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0){
                        printf("Quarto nao eh valido!\n");
                    } else if(verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                        printf("Quarto ta ocupado!\n");
                    }
                    printf("Insira o numero do quarto: ");
                    scanf("%d", &hospede.quarto);
                }
                listaHospedes[qtdHospedes] = hospede;
                removerElemento(quartosVazios, &tamanhoArray, hospede.quarto);
                printf("\n");
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("Cadastro Registrado: \n");
                printf("Nome do Hospede:%s\nQuarto do Hospede: %d\nRG do Hospede: %d\n", hospede.nome, hospede.quarto, hospede.RG);
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                quartosOcupados[qtdHospedes] = hospede.quarto;
                qtdHospedes++;
                sleep(1);
                break;
            case 2:
                printf("\n");
                printf("Lista de hospedes\n");

                for (int i = 0; i < qtdHospedes; ++i) {
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

                }
                sleep(1);
                break;
            case 3:
                printf("\n");
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("Buscar hospedes\n");
                int rgHospede;
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);


                while(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes) == 0){
                    printf("RG ano existe no sistema!\n Insira novamente!\n");
                    printf(" Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                }

                printf("\nInformações do Hospede:");
                for (int i = 0; i < qtdHospedes; ++i) {
                    if(listaHospedes[i].RG == rgHospede){
                        printf("Nome:%s\n RG: %d\n Quarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    }
                }

                break;
            case 4:
                    printf("\n");
                    printf("Voce escolheu editar um hospede\n");
                    printf("Escolha um hospede:\n");
                     for (int i = 0; i < qtdHospedes; ++i) {
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                        printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                    }
                    char nomeHospede[30];
                    printf("Digite o nome do hospede que voce gostaria de editar:\n");
                    fflush(stdin);
                    fgets(nomeHospede, 30, stdin);
                    nomeHospede[strcspn(nomeHospede,"\n")] = 0;
                    if(verificarNome(nomeHospede, qtdHospedes, listaHospedes) == 0){
                        printf("Voce escolheu editar o Hospede : %s\n", nomeHospede);
                        int posicaoNome = indicaPosicaoNome(nomeHospede, qtdHospedes, listaHospedes);
                        printf("Qual parametro voce quer editar? Escolha entre Nome=(1), R.G=(2), Quarto=(3)");
                        int parametro;
                        scanf("%d", &parametro);
                        if(parametro == 1){
                            printf("Edite o nome:\n");
                            fflush(stdin);
                            fgets(nomeHospede, 30, stdin);
                            nomeHospede[strcspn(nomeHospede,"\n")] = 0;
                            strcpy(listaHospedes[posicaoNome].nome , nomeHospede);
                        }else if(parametro == 2){
                            int rg;
                            printf("Edite o R.G:\n");
                            scanf("%d", &rg);
                            //talvez coloca uma mensagem de confirmação : Aqui está o nome/rg/... é isso mesmo ?
                            printf("%d", posicaoNome);
                            listaHospedes[posicaoNome].RG = rg;
                        }else if(parametro == 3){
                            int quar;
                            printf("Edite o quarto:\n");
                            scanf("%d", &quar);
                            listaHospedes[posicaoNome].quarto = quar;
                        }

                    }
                break;
                // caso 5 da main
            case 5: // remover hospede
                printf("\n");
                printf("Remover hospede\n");
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);

                while(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes) == 0){
                    printf("RG ano existe no sistema!\n Insira novamente!\n");
                    printf(" Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                }

                removerHospede(listaHospedes, &qtdHospedes, rgHospede);
                quartosVazios[tamanhoArray - 1] = hospede.quarto;
                qsort(quartosVazios, 10, sizeof(int), cmpfunc);

                break;
            case 7:

                for (int i = 0; i < qtdHospedes; ++i){
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                        printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                    }

                criaArquivo(listaHospedes, qtdHospedes);
                break;
        }
    } while (opcaoUsuario != 8);


    return 0;
}