//#include "structHospede.c"

int indicaPosicaoNome(char nomeHospede[30], int tamanho, Hospede *listaHospedes){
    for (int i = 0; i < tamanho; ++i) {
        if(listaHospedes[i].nome == nomeHospede){
            return i; //Eh valido
        }
    }
    return 0;

}