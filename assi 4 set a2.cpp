#include <stdio.h>

int binarySearch(int a[], int low, int high, int value)
{
    int mid;

    if(low > high)
        return -1;

    mid = (low + high) / 2;

    if(a[mid] == value)
        return mid;
    else if(value < a[mid])
        return binarySearch(a, low, mid - 1, value);
    else
        return binarySearch(a, mid + 1, high, value);
}

int main()
{
    int a[100], n, i, value, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to search: ");
    scanf("%d", &value);

    result = binarySearch(a, 0, n - 1, value);

    if(result != -1)
        printf("Value is present at position %d", result + 1);
    else
        printf("Value is not present in the array");

    
}
