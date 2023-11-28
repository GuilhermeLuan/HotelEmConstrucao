//Recebe o input do quarto desejado e verifica se a entrada do quarto é valida.
int verificarNome(char nomeHospede[30], int tamanho, Hospede *listaHospedes){
    for (int i = 0; i < tamanho; ++i){
        if(strcmp(listaHospedes[i].nome , nomeHospede)== 0);
            return 1; //Eh valido

        }
        
    return 0;

}