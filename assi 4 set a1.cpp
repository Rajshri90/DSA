#include <stdio.h>

int main()
{
    int a[100], n, i, value, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to search: ");
    scanf("%d", &value);

    for(i = 0; i < n; i++)
    {
        if(a[i] == value)
        {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Value is present in the array");
    else
        printf("Value is not present in the array");

    
}
