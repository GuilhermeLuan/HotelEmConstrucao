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
#include "criaArquivo.c"
#include "removerHospede.c"
#include "validandoTamanhoRG.c"
int main(){
    int quartosVazios[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int quartosOcupados[10];
    int opcaoUsuario;
    int qtdHospedes = 0;
    int tamanhoArray = 10;
    int rgHospede;
    Hospede hospede;
    Hospede *listaHospedes = (Hospede*) calloc(10, sizeof(hospede));

    do {
        imprimirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoUsuario);

        switch (opcaoUsuario) {
            case 1:
                if(qtdHospedes == 10){
                    printf("Hotel esta cheio!\n");
                    printf("Tente novamente amanha!\n");
                }
                else{
                    printf("Insira o nome do hospede: ");
                    fflush(stdin);
                    fgets(hospede.nome, 30, stdin);
                    hospede.nome[strcspn(hospede.nome,"\n")] = 0;

                    printf("Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                    fflush(stdin);
                    while(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes) || verificarRgValido(rgHospede) == 0){
                        if(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes)){
                            printf("RG ja existe no sistema!\n Insira novamente!\n");
                        } if (verificarRgValido(rgHospede) == 0) {
                            printf("Formato de RG invalido!\n Insira novamente!\n");
                        }

                        printf(" Digite o RG do hospede: ");
                        scanf("%d", &rgHospede);
                        fflush(stdin);
                    }
                    hospede.RG = rgHospede;
                    printf("Os quartos disponiveis sao: ");
                    for (int i = 0; i < tamanhoArray; ++i) {
                        printf("%d ", quartosVazios[i]);
                    }

                    printf("\nInsira o numero do quarto: ");
                    scanf("%d", &hospede.quarto);
                    fflush(stdin);



                    while (verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0 || verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                        if(verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0){
                            printf("Quarto nao eh valido!\n");
                        } else if(verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                            printf("Quarto ta ocupado!\n");
                        }
                        printf("Insira o numero do quarto: ");
                        scanf("%d", &hospede.quarto);
                        fflush(stdin);
                    }
                    listaHospedes[qtdHospedes] = hospede;
                    removerElemento(quartosVazios, &tamanhoArray, hospede.quarto);
                    printf("\n");
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    printf("Cadastro Registrado com sucesso !\n");
                    printf("Nome do Hospede:%s\nQuarto do Hospede: %d\nRG do Hospede: %d\n", hospede.nome, hospede.quarto, hospede.RG);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    quartosOcupados[qtdHospedes-1] = hospede.quarto;
                    qtdHospedes++;
                    sleep(1);
                }
                break;
            case 2:

                if(qtdHospedes == 0){
                    printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }
            
            
               else{printf("\n");
                printf("Lista de hospedes\n");

                for (int i = 0; i < qtdHospedes; ++i) {
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

                }
                sleep(1);
               }
                break;
            case 3:

                if(qtdHospedes == 0){
                    printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }

                else{printf("\n");
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("Buscar hospedes\n");
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);


                while(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes) == 0){
                    printf("RG nao existe no sistema!\n Insira novamente!\n");
                    printf(" Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                }

                printf("Informacoes do Hospede:\n");
                for (int i = 0; i < qtdHospedes; ++i) {
                    if(listaHospedes[i].RG == rgHospede){
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                        printf("Nome:%s\n RG: %d\n Quarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    }
                }
                }
                break;
            case 4:

                if(qtdHospedes == 0){
                    printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }

                   else{printf("\n");
                    printf("Voce escolheu editar um hospede\n");
                    printf("Escolha um hospede:\n");
                     for (int i = 0; i < qtdHospedes; ++i) {
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                        printf("Nome: %s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                    }
                    char nomeHospede[30];
                    printf("Digite o nome do hospede que voce gostaria de editar:\n");
                    fflush(stdin);
                    fgets(nomeHospede, 30, stdin);
                    nomeHospede[strcspn(nomeHospede,"\n")] = 0;

                    while(verificarNome(nomeHospede, qtdHospedes, listaHospedes) == 1){
                        printf("Nome nao pertence a um hospede! Escreva novamente\n");
                        fgets(nomeHospede, 30, stdin);
                        nomeHospede[strcspn(nomeHospede,"\n")] = 0;
                    }

                        printf("Voce escolheu editar o Hospede : %s\n", nomeHospede);
                        int posicaoNome = indicaPosicaoNome(nomeHospede, qtdHospedes, listaHospedes);
                        printf("Qual parametro voce quer editar? Escolha entre Nome =(1), R.G =(2), Quarto =(3):");
                        int parametro;
                        scanf("%d", &parametro);
                        fflush(stdin);

                        while(parametro > 3 || parametro < 1){
                            printf("Escreva um parametro valido!\n");
                            scanf("%d", &parametro);
                            fflush(stdin);
                        }


                        ///EDITAR NOME
                        if(parametro == 1){
                            printf("Edite o nome:\n");
                            fflush(stdin);
                            fgets(nomeHospede, 30, stdin);
                            nomeHospede[strcspn(nomeHospede,"\n")] = 0;
                            strcpy(listaHospedes[posicaoNome].nome , nomeHospede);


                        ///EDITAR RG
                        }else if(parametro == 2){
                            int rg;
                            printf("Edite o R.G:\n");
                            scanf("%d", &rg);
                            fflush(stdin);

                        while(verificarSeRGExiste(listaHospedes, rg, qtdHospedes) || verificarRgValido(rg) == 0){
                            if(verificarSeRGExiste(listaHospedes, rg, qtdHospedes)){
                                printf("RG ja existe no sistema!\n Insira novamente!\n");
                            } if (verificarRgValido(rg) == 0) {
                                printf("Formato de RG invalido!\n Insira novamente!\n");
                            }
                                scanf("%d", &rg);
                                fflush(stdin);
                            }  

                            listaHospedes[posicaoNome].RG = rg;

                        //EDITAR QUARTO
                        }else if(parametro == 3){
                            int quarto;
                            printf("Edite o quarto:\n");
                            scanf("%d", &quarto);

                            while (verificarQuartoValido(quarto, quartosVazios, quartosOcupados) == 0 || verificarQuartoOcupado(quarto, quartosOcupados) == 1){
                                if(verificarQuartoValido(quarto, quartosVazios, quartosOcupados) == 0){
                                    printf("Quarto nao eh valido!\n");
                                } else if(verificarQuartoOcupado(quarto, quartosOcupados) == 1){
                                    printf("Quarto ta ocupado!\n");
                                }
                                printf("Insira o numero do quarto: ");
                                scanf("%d", &quarto);
                            }
                            listaHospedes[posicaoNome].quarto = quarto;
                        }

                         printf("Hospede editado com sucesso!\n");
                   }
                break;
                // caso 5 da main
            case 5: // remover hospede

                if(qtdHospedes == 0){
                    printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }

                else{printf("\n");
                printf("Remover hospede\n");
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);

                while(verificarSeRGExiste(listaHospedes, rgHospede, qtdHospedes) == 0){
                    printf("RG nao existe no sistema!\n Insira novamente!\n");
                    printf(" Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                }

                removerHospede(listaHospedes, &qtdHospedes, rgHospede, quartosVazios, &tamanhoArray, quartosOcupados);
                }
                break;
            case 6:
                if(qtdHospedes == 0){
                printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }
                printf("Numero dos quartos vazios: %d");
                break;
            case 7:
                if(qtdHospedes == 0){
                printf("\nNenhum hospede no hotel! Que tal ser o primeiro ?\n");
                }            
                else{
                    if(criaArquivo(listaHospedes, qtdHospedes) == 0){
                    printf("Arquivo criado com sucesso!");
                    }
                }
                break;
        }
    } while (opcaoUsuario != 8);


    return 0;
}