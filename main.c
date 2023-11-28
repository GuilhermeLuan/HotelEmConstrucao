#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.c"
#include "verificarQuartoOcupado.c"
#include "verificarQuartoValido.c"
#include "structHospede.c"
#include "verificarNome.c"
#include "indicaPosicaoNome.c"
#include "removerElemento.c"
#include "verificarSeRGExiste.c"
int main(){
    //CODIGO ABAIXO É APENAS UM TESTE
    int quartosVazios[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int quartosOcupados[10] = {0,1};
    int opcaoUsuario;
    int tamanho = 0;
    int tamanhoArray = 10;
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
                fflush(stdin);
                fgets(hospede.nome, 30, stdin);
                hospede.nome[strcspn(hospede.nome,"\n")] = 0;

                //Verificar RG.
                printf("Digite o RG do hospede: ");
                scanf("%d", &hospede.RG);

                printf("Os quartos disponiveis sao: ");
                for (int i = 0; i < sizeof(quartosVazios) / sizeof(quartosVazios[0]); ++i) {
                    printf("%d ", quartosVazios[i]);
                }

                printf("\nInsira o numero do quarto: ");
                scanf("%d", &hospede.quarto);


                while (verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0 || verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                    if(verificarQuartoValido(hospede.quarto, quartosVazios, quartosOcupados) == 0){
                        printf("Quarto nao eh valido!");
                    } else if(verificarQuartoOcupado(hospede.quarto, quartosOcupados) == 1){
                        printf("Quarto ta ocupado!");
                    }
                    printf("\nInsira o numero do quarto: ");
                    scanf("%d", &hospede.quarto);
                }
                listaHospedes[tamanho] = hospede;
                removerElemento(quartosVazios, &tamanhoArray, hospede.quarto);
                printf("\n");
                printf("Cadastro Registrado: \n");
                printf("Nome do Hospede:%s\nQuarto do Hospede: %d\nRG do Hospede: %d", hospede.nome, hospede.quarto, hospede.RG);
                quartosOcupados[tamanho] = hospede.quarto;
                tamanho++;
                for (int i = 0; i < 10; ++i) {
                    printf("\n%d ", quartosOcupados[i]);
                }
                break;
            case 2:
                printf("\n");
                printf("Lista de hospedes\n");

                for (int i = 0; i < tamanho; ++i) {
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                    printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

                }
                break;
            case 3:
                printf("\n");
                printf("Buscar hospedes\n");
                int rgHospede;
                printf("Digite o RG do hospede: ");
                scanf("%d", &rgHospede);

//                do{
//                    printf("Digite o RG do hospede: ");
//                    scanf("%d", &rgHospede);
//                } while (verificarSeRGExiste(listaHospedes, rgHospede, tamanho) == 0);

                while(verificarSeRGExiste(listaHospedes, rgHospede, tamanho) == 0){
                    printf("RG no sistema!\nInsira novamente!\n");
                    printf("Digite o RG do hospede: ");
                    scanf("%d", &rgHospede);
                }


                for (int i = 0; i < tamanho; ++i) {
                    if(listaHospedes[i].RG == rgHospede){
                        printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    }
                }

                break;
                case 4:
                    printf("\n");
                    printf("Voce escolheu editar um hospede\n");
                    printf("Escolha um hospede:\n");
                     for (int i = 0; i < tamanho; ++i) {
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                        printf("Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                    }
                    char nomeHospede[30];
                    printf("Digite o nome do hospede que voce gostaria de editar:\n");
                    fflush(stdin);
                    fgets(nomeHospede, 30, stdin);
                    nomeHospede[strcspn(nomeHospede,"\n")] = 0;
                    if(verificarNome(nomeHospede, tamanho, listaHospedes) == 1){
                        printf("Voce escolheu editar Hospede : %s\n", nomeHospede);
                        int posicaoNome = indicaPosicaoNome(nomeHospede, tamanho, listaHospedes);
                        printf("Qual parametro voce quer editar? ecolha entre Nome=(1), R.G=(2), Quarto=(3)");
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
     
    

        }
    } while (opcaoUsuario != 8);


    return 0;
}