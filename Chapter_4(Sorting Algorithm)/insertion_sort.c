//complexity O(n^2)/O(n)
#include<stdio.h>
void insertion_sort(int a[],int n)
{
   int i,j,item;
   for(i=1; i<n; i++)
   {
    item=a[i];
    j=i-1;
    
    while(j>=0 && a[j]>item)
    {
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=item;
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

    insertion_sort(a,n);
    
    printf("Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
