void removerHospede(Hospede array[], int *tamanho, int hospedeRG) {
    // Procurar o elemento no array
    for (int i = 0; i < *tamanho; i++) {
        if (array[i].RG == hospedeRG) {
            // Deslocar os elementos para preencher o espaço
            for (int j = i; j < *tamanho - 1; j++) {
                array[j] = array[j + 1];
            }
            // Atualizar o tamanho do array
            (*tamanho)--;
            // O elemento foi removido, podemos sair do loop
            break;
        }
    }
}