int verificarRgValido(int rg) {
    int digitos = 0;
    int temp = rg;

    // Conta o número de dígitos
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }

    return (digitos == 7); // RG deve ter exatamente 7 dígitos
}
