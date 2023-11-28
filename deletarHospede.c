// Função para remover um hóspede de um quarto ocupado
void deletarHospede(int quartoDesejado, int quartosOcupados[10], int quartosVazios[10]) {
    for (int i = 0; i < 10; ++i) {
        if (quartosOcupados[i] == quartoDesejado) {
            // Libera o quarto
            quartosVazios[i] = quartoDesejado;
            quartosOcupados[i] = 0; // Marca como quarto vago
            printf("Hospede removido do quarto %d.\n", quartoDesejado);
            return;
        }
    }
    
    }
