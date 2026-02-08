#include "ft_rev_int_tab.h"
#include <stdio.h>

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *tab = arr;

    ft_rev_int_tab(tab, size);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        // Add a comma and space if it's not the last element
        if (i < size - 1) {
            printf(", ");
        }
    }

    return 0;
}