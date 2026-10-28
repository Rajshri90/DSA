#include <stdio.h>
#include <string.h>

void quicksort(char a[][20], int low, int high)
{
    int i, j;
    char pivot[20], temp[20];

    if (low < high)
    {
        strcpy(pivot, a[low]);
        i = low;
        j = high;

        while (i < j)
        {
            while (strcmp(a[i], pivot) <= 0 && i < high)
                i++;

            while (strcmp(a[j], pivot) > 0)
                j--;

            if (i < j)
            {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }

        strcpy(temp, a[low]);
        strcpy(a[low], a[j]);
        strcpy(a[j], temp);

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main()
{
    char month[12][20];
    int n, i;

    printf("Enter number of months: ");
    scanf("%d", &n);

    printf("Enter months:\n");
    for (i = 0; i < n; i++)
        scanf("%s", month[i]);

    quicksort(month, 0, n - 1);

    printf("Sorted months:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", month[i]);

    
}
