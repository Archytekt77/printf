#include <stdio.h>
#include <stdlib.h>

char *convert_base(unsigned int num, int base, int uppercase) {
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    char buffer[50]; // Assez grand pour stocker le résultat
    int i = 0;

    // Gestion du cas zéro
    if (num == 0) {
        buffer[i++] = '0';
    }

    // Conversion en base donnée
    while (num > 0) {
        buffer[i++] = digits[num % base];
        num /= base;
    }

    buffer[i] = '\0';

    // Inverser la chaîne pour obtenir le bon ordre
    int len = i;
    char *result = malloc(len + 1);
    for (int j = 0; j < len; j++) {
        result[j] = buffer[len - 1 - j];
    }
    result[len] = '\0';

    return result;
}

int main() {
    unsigned int number = 255;
    char *hex_lower = convert_base(number, 16, 0);
    char *hex_upper = convert_base(number, 16, 1);

    printf("Hexadecimal (minuscule) : %s\n", hex_lower);
    printf("Hexadecimal (majuscule) : %s\n", hex_upper);

    free(hex_lower);
    free(hex_upper);

    return 0;
}






