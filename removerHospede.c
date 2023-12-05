#include "cmpfunc.c"

void removerHospede(Hospede array[], int *tamanho, int hospedeRG, int quartosVazios[], int *tamanhoQuartos, int quartosOcupados[]) {
    // Procurar o elemento no array
    for (int i = 0; i < *tamanho; i++) {
        if (array[i].RG == hospedeRG) {
            // Adicionar o quarto de volta aos quartos vazios
            quartosVazios[*tamanhoQuartos] = array[i].quarto;
            (*tamanhoQuartos)++;
            qsort(quartosVazios, *tamanhoQuartos, sizeof(int), cmpfunc);

            // Remover o quarto dos quartos ocupados
            int quartoARemover = array[i].quarto;
            for (int j = 0; j < *tamanhoQuartos; j++) {
                if (quartosOcupados[j] == quartoARemover) {
                    for (int k = j; k < *tamanhoQuartos - 1; k++) {
                        quartosOcupados[k] = quartosOcupados[k + 1];
                    }
                    (*tamanhoQuartos)--;
                    break;
                }
            }

            // Deslocar os elementos para preencher o espaço
            for (int j = i; j < *tamanho - 1; j++) {
                array[j] = array[j + 1];
            }

            // Atualizar o tamanho do array
            (*tamanho)--;
            // O elemento foi removido, podemos sair do loop
            printf("Hospede removido com sucesso!");
            break;
        }
    }
}
