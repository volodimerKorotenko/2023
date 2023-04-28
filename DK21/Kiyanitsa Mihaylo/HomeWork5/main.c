#include <stdio.h>
#include "trees.c"

int main() {
    struct node* root = NULL;
    int choice, data;

    do {
        printf("\n1. Вставити елемент");
        printf("\n2. Видалити елемент");
        printf("\n3. Пошук елемента");
        printf("\n4. Вивести дерево");
        printf("\n5. Видалити дерево");
        printf("\n6. Вийти");
        printf("\nВиберіть опцію: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nВведіть число, яке потрібно додати: ");
                scanf("%d", &data);
                root = insert_node(root, data);
                break;
            case 2:
                printf("\nВведіть число, яке потрібно видалити: ");
                scanf("%d", &data);
                root = delete_node(root, data);
                break;
            case 3:
                printf("\nВведіть число, яке потрібно знайти: ");
                scanf("%d", &data);
                if (search_node(root, data) == NULL) {
                    printf("\n%d не знайдено в дереві", data);
                } else {
                    printf("\n%d знайдено в дереві", data);
                }
                break;
            case 4:
                printf("\nДерево: ");
                print_tree(root);
                break;
            case 5:
                printf("\nВидалення дерева...");
                delete_tree(root);
                root = NULL;
                break;
            case 6:
                printf("\nДо побачення!");
                break;
            default:
                printf("\nВведено неправильну опцію!");
                break;
        }
    } while (choice != 6);

    return 0;
}
