#include <stdio.h>

struct Student
{
    int rollno;
    char name[30];
    int age;
};

void swap(struct Student *a, struct Student *b)
{
    struct Student temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Student s[], int low, int high)
{
    int pivot = s[high].age;
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (s[j].age <= pivot)
        {
            i++;
            swap(&s[i], &s[j]);
        }
    }

    swap(&s[i + 1], &s[high]);

    return i + 1;
}

void quickSort(struct Student s[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(s, low, high);

        quickSort(s, low, p - 1);
        quickSort(s, p + 1, high);
    }
}

int main()
{
    FILE *fp;
    struct Student s[100];
    int n = 0, i;

    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!");
        return 0;
    }

    while (fscanf(fp, "%d %s %d",
                  &s[n].rollno,
                  s[n].name,
                  &s[n].age) != EOF)
    {
        n++;
    }

    fclose(fp);

    quickSort(s, 0, n - 1);

    printf("Students sorted by age:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\n",
               s[i].rollno,
               s[i].name,
               s[i].age);
    }

     
}
