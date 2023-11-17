#include <stdio.h>

//Recebe o input do quarto desejado e verifica se esse quarto esta ocupado percorrendo um array.
int verificarQuartoOcupado(int quartoDesejado, int quartosOcupados[10]){
    for (int i = 0; i < 10; ++i) {
        if(quartosOcupados[i] == quartoDesejado){
            return 1;
        }
    }
    return 0;

}

int main(){
    //CODIGO ABAIXO É APENAS UM TESTE
    int quartosVazios[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int quartosOcupados[10] = {100};
    int quartoDesejado = 101;

    if(verificarQuartoOcupado(quartoDesejado, quartosOcupados)){
        printf("Quarto Ocuapdo!");
    } else {
        printf("Quarto livre!");
    }

    return 0;
}