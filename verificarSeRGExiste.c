#include "structHospede.c"

int verificarSeRGExiste(Hospede *listaHospedes, int rgUsuario, int numeroHospedes){
    for (int i = 0; i < numeroHospedes; ++i) {
        if(rgUsuario == listaHospedes[i].RG){
            return 1; // RG Existe
        }
    }
    return 0; // RG Não existe
}
