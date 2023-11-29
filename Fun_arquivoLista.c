//FUNCAO PARA LER A LISTA DE HOSPEDE

void criaArquivo(Hospede *listaHospedes, int qtdHospedes){
    FILE *f;
    f = fopen("ListaHospedes.txt", "w");

    if(f == NULL){
        printf("erro ao abrir arquivo!!!\n");
        return 1;
    }

    for (int i = 0; i < qtdHospedes; ++i){
                    fprintf(f,"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
                    fprintf(f,"Nome:%s\nRG: %d\nQuarto: %d\n", listaHospedes[i].nome, listaHospedes[i].RG, listaHospedes[i].quarto);
                    fprintf(f,"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
    

    }
    fclose(f);
}

