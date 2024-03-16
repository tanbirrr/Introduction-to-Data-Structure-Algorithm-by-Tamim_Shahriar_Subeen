 //Binary search
 //complexity O(log n)
 #include<stdio.h>
 int binary_search(int a[],int n,int x)
 {
    int left,right,mid;
    left=0;
    right=n-1;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(a[mid]==x)return mid;
        if(a[mid]<x)left=mid+1;
        else right=mid-1;
    }
    return -1;
 }
 int main()
 {
     int arr[]={2,4,6,8,10,12,14,16,18,20};
     int n=sizeof(arr)/sizeof(arr[0]);
     int x=12;
     int result=binary_search(arr,n,x);

     if(result != -1)
     {
        printf("Element %d is present at index %d.\n",x,result);
     }
     else
     {
        printf("Element %d is not present in the array.\n",x);
     }
     return 0;
 }
 