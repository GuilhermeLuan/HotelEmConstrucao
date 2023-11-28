// 7.Salvar lista de hóspedes com respectivos quartos em arquivo

#include "Fun_arquivoLista.c"

int main(){
    FILE *f;
    f = fopen("ListaHospede.txt", "w");

    if(f == NULL){
        printf("erro ao abrir arquivo!!!\n");
        return 1;
    }
    

    fputs("Hospede 889997\n", f);
    fputs("hospede 788459\n", f);

    fclose(f);

    return 0;
}
