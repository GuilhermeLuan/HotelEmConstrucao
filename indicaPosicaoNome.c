//#include "structHospede.c"

int indicaPosicaoNome(char nomeHospede[30], int tamanho, Hospede *listaHospedes){
    for (int i = 0; i < tamanho; ++i) {
        if(strcmp(listaHospedes[i].nome, nomeHospede) == 0){
            return i; //Indica a posicao do nome no array
        }
    }
    return -1;

}