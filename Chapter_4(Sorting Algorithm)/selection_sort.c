//complexity O(n^2)
#include<stdio.h>
void selection_sort(int a[],int n)
{
   int i,j,index_min,temp;
   for(int i=0; i<n-1; i++)
   {
    index_min=i;
    for(j=i+1; j<n; j++)
    {
        if(a[j]  < a[index_min])
        {
            index_min=j;
        }
    }
    if(index_min != i)
    {
        temp=a[i];
        a[i]=a[index_min];
        a[index_min]=temp;
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

    selection_sort(a,n);
    
    printf("Sorted Array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
