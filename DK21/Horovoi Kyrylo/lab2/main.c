#include "dk_tool.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    Ring *my = createRing();
    int choice;
    while(true)
    {
        printf("1 - Додати наступний елемент, 2 - Додати попередній елемент, 3 - Вивести елемент, 4 - Повернути список вправо, 5 - Повернути список вліво, 6 - Очищення списку, 7 - Видалення  3-й елементу, 8- Завершення роботи");
        do
        {
            choice = get_inttext(":");
        }while(choice<1||choice>8);
        int tmp;
        switch(choice)
        {
        case 1:
            tmp=get_inttext("Введіть дані:");
            pushNext(my, tmp);
            break;
        case 2:
            tmp=get_inttext("Введіть дані:");
            pushPrev(my, tmp);
            break;
        case 3:
            printf("%d\n", pull(my));
            break;
        case 4:
            goNext(my);
            break;
        case 5:
            goPrev(my);
            break;
        case 6:
            clearRingList(my);
            break;
        case 7:
            while(my->current->next != my->current->prev)
            {
                delelmord(my, 3);
                printRing(my);
            }
            break;
        case 8:
            deleteRingList(my);
            return 0;
    }
    printRing(my);
}
}
