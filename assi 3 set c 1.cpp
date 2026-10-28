#include <stdio.h>
#include <string.h>

struct Person
{
    int personno;
    char name[30];
    int age;
};

void merge(struct Person a[], int low, int mid, int high)
{
    struct Person temp[100];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i].age <= a[j].age)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(struct Person a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    FILE *fp;
    struct Person p[100];
    int n = 0, i;

    fp = fopen("person.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!");
        return 0;
    }

    while (fscanf(fp, "%d %s %d",
                  &p[n].personno,
                  p[n].name,
                  &p[n].age) != EOF)
    {
        n++;
    }

    fclose(fp);

    mergeSort(p, 0, n - 1);

    printf("Person details sorted by age:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\n",
               p[i].personno,
               p[i].name,
               p[i].age);
    }

    
}
