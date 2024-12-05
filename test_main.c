int main() {
    int number = 255;

    // Résultat attendu avec printf
    printf("Avec printf : %x\n", number);

    // Résultat avec votre propre fonction
    char *result = convert_base(number, 16, 0);
    printf("Avec convert_base : %s\n", result);
    free(result);

    return 0;
}