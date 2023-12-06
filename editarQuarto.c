void editarQuarto(Hospede array[], int *tamanho, char nomeHospede[], int novoQuarto, int quartosVazios[], int *tamanhoQuartos, int quartosOcupados[]) {
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(array[i].nome, nomeHospede) == 0) {
            // Adicionar o quarto anterior à lista de quartos disponíveis
            quartosVazios[*tamanhoQuartos] = array[i].quarto;
            (*tamanhoQuartos)++;
            qsort(quartosVazios, *tamanhoQuartos, sizeof(int), cmpfunc);

            // Atribuir o novo quarto ao hóspede
            array[i].quarto = novoQuarto;

            // Remover o novo quarto da lista de quartos disponíveis
            for (int j = 0; j < *tamanhoQuartos; j++) {
                if (quartosVazios[j] == novoQuarto) {
                    for (int k = j; k < *tamanhoQuartos - 1; k++) {
                        quartosVazios[k] = quartosVazios[k + 1];
                    }
                    //(*tamanhoQuartos)--;
                    break;
                }
            }

            // Adicionar o novo quarto à lista de quartos ocupados
            quartosOcupados[*tamanhoQuartos] = novoQuarto;
            (*tamanhoQuartos)++;
            qsort(quartosOcupados, *tamanhoQuartos, sizeof(int), cmpfunc);

            printf("Hospede editado com sucesso!\n");
        }
    }
    printf("Hospede com nome %s nao encontrado!\n", nomeHospede);
}