//Recebe o input do quarto desejado e verifica se esse quarto esta ocupado percorrendo um array.
int verificarQuartoOcupado(int quartoDesejado, int quartosOcupados[10]){
    for (int i = 0; i < 10; ++i) {
        if(quartosOcupados[i] == quartoDesejado){
            return 1;
        }
    }
    return 0;

}