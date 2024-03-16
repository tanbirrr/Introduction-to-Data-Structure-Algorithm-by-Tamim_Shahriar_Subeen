//complexity O(n^2)
#include<stdio.h>
void bubble_sort(int a[],int n)
{
   int i,j,temp;
   for(i=0; i<n; i++)
   {
    for(j=0; j<n-i-1; j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
   }
}

int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements:\n",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Original Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    bubble_sort(a,n);
    
    printf("Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
