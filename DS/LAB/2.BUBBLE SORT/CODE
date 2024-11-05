#include<stdio.h>
void main()
{
    int i,n,arr[100];
    printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY: ");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF THE ARRAY: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("THE ARRAY: ");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
        printf("\n");
       
    int j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {   temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    
    printf("THE SWAPPED ARRAY: ");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}
