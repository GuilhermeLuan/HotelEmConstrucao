//Recebe o input do quarto desejado e verifica se a entrada do quarto é valida.
int verificarQuartoValido(int quartoDesejado, int quartosVazios[10], int quartosOcupados[10]){
    for (int i = 0; i < 10; ++i) {
        if(quartosVazios[i] == quartoDesejado || quartosOcupados[i] == quartoDesejado){
            return 1; //Eh valido
        }
    }
    return 0;

}