int countSubstring(const char *str, const char *substr) {
    int count = 0;
    int str_len = strlen(str);
    int substr_len = strlen(substr);

    char *temp_str = (char *) malloc((str_len + 1) * sizeof(char));
    char *temp_substr = (char *) malloc((substr_len + 1) * sizeof(char));

    if (temp_str == NULL || temp_substr == NULL) {
        printf("Ошибка выделения памяти\n");
        return -1;
    }

    strncpy(temp_str, str, str_len + 1);
    strncpy(temp_substr, substr, substr_len + 1);

    char *ptr = temp_str;

    while ((ptr = strstr(ptr, temp_substr)) != NULL) {
        count++;
        ptr += substr_len;
    }

    free(temp_str);
    free(temp_substr);

    return count;
}
