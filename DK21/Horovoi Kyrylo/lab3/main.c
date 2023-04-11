#include <stdio.h>
#include "tree.h"
#include "dk_tool.h"
#include <stdbool.h>
int main(int argc, char *argv[])
{
    FloatTree *Tree = createFloatTree();
    int choice;
    float value;
    while(1)
    {
        printf("1 - Додати елемент, 2 - Знайти елемент, 3 - Видалити елемент, 4 - Завершення роботи ");
        do
        {
            choice = get_inttext(":");
        }while(choice<1||choice>4);
        switch(choice)
        {
        case 1:
            value = get_floattext("Введіть дані: ");
            insertFloatValueToTree(Tree, value);
            break;
        case 2:
            value = get_floattext("Введіть дані: ");
            FloatNode *tmp = findNodeWithValue(Tree, value);
            if(tmp == NULL)
            {
                printf("Елемент не знайдено\n");
            }
            else
                printNode(tmp);
            break;
        case 3:
            value = get_floattext("Введіть дані: ");
            deleteNodeWithValue(Tree, value);
            break;
        case 4:
            destroyTree(Tree);
            return 0;
        }
       printTree(Tree);
    }
}

