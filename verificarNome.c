//Recebe o input do quarto desejado e verifica se a entrada do quarto é valida.
int verificarNome(char nomeHospede[30], int tamanho, Hospede *listaHospedes){
    for (int i = 0; i < tamanho; ++i) {
        if(listaHospedes[i].nome == nomeHospede){
            return 1; //Eh valido
        }
    }
    return 0;

}