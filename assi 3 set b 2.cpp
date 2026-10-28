#include <stdio.h>
#include <string.h>

void merge(char a[][20], int low, int mid, int high)
{
    char temp[20][20];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (strcmp(a[i], a[j]) < 0)
            strcpy(temp[k++], a[i++]);
        else
            strcpy(temp[k++], a[j++]);
    }

    while (i <= mid)
        strcpy(temp[k++], a[i++]);

    while (j <= high)
        strcpy(temp[k++], a[j++]);

    for (i = low, k = 0; i <= high; i++, k++)
        strcpy(a[i], temp[k]);
}

void mergesort(char a[][20], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    char words[20][20];
    int n, i;

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter words:\n");
    for (i = 0; i < n; i++)
        scanf("%s", words[i]);

    mergesort(words, 0, n - 1);

    printf("Sorted words:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", words[i]);

}
