#include "structHospede.c"
FILE *f;
    f = fopen("ListaHospede.txt", "w");

    if(f == NULL){
        printf("erro ao abrir arquivo!!!\n");
        return 1;
    }

    for (int i = 0; i < tamanho; ++i){
                    fprintf(f,"Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    fprintf(f,"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");

                

}
