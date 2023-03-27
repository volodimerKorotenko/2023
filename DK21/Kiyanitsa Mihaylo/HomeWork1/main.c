int main() {
    char str[100];
    char substr[100];
    int count;

    printf("Введите предложение: ");
    fgets(str, 100, stdin);

    printf("Введите искомую последовательность символов: ");
    fgets(substr, 100, stdin);

    // Удаляем символ новой строки из введенных строк
    str[strlen(str)-1] = '\0';
    substr[strlen(substr)-1] = '\0';

    count = countSubstring(str, substr);
    printf("Количество вхождений: %d\n", count);

    return 0;
}
