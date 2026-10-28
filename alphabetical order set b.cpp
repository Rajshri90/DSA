#include <stdio.h>
#include <string.h>

int main()
{
    char name[20][30], temp[30];
    int n, i, j;

    printf("Enter number of names: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for(i = 0; i < n; i++)
        scanf("%s", name[i]);

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(strcmp(name[j], name[j+1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", name[i]);

    
}
