#include <stdio.h>
#define N 50

int main()
{
    int arr[N], size;
    printf("Enter the size of array :\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element :: ", i + 1);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    printf("Array ::\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    int item;
    printf("\n");
    printf("Enter the item to search :");
    scanf("%d", &item);
    int flag = 1, temp;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==item)
        {
            temp=i+1;
            flag = 2;
            break;
        }
    }
    if (flag==2)
    {
        printf("Element found at %d position!", temp);
    }
    else
        printf("Sorry! Element not found!!");
    return 0;
}