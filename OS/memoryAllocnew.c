#include<stdio.h>

int p,b,block[10],process[10],b_copy[10],remain[10];

void first_fit();
void best_fit();
void worst_fit();

void main() {
    int i;
    printf("How many process & blocks ? :");
    scanf("%d%d",&p,&b);
    
    printf("\nProcess sizes?\n");
    for(i=0;i<p;i++) {
        printf("P%d: ",i+1);
        scanf("%d",&process[i]);
    }
    
    printf("\nBlock sizes?\n");
    for(i=0;i<b;i++) {
        printf("B%d: ",i+1);
        scanf("%d",&block[i]);
    }
    
    printf("\nFIRST FIT:\n");
    first_fit();
    
    printf("\nBEST FIT:\n");
    best_fit();
    
    printf("\nWORST FIT:\n");
    worst_fit();
}

void first_fit() {
    int i,j,p_flg[10]={0},b_flg[10]={0};
    
    for(i=0;i<b;i++)
        remain[i]=b_copy[i]=block[i];
    
    printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
    
    for(i=0;i<p;i++) {
        for(j=0;j<b;j++)
            if(process[i]<=block[j] && b_flg[j]==0) {
                remain[j]=block[j]-process[i];
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],j+1,block[j],remain[j]);
                p_flg[i]=b_flg[j]=1;
                break;
            }
        
        if(p_flg[i]==0)
            printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
    }
}

void best_fit() {
    int i,j,p_flg[10]={0},b_flg[10]={0},b_index[10];
    
    for(i=0;i<b;i++) {
        b_index[i]=i+1;
        remain[i]=b_copy[i]=block[i];
    }
    
    for(i=1;i<b;i++)
        for(j=0;j<b-i;j++)
            if(block[j]>block[j+1]) {
                int temp=block[j];
                block[j]=block[j+1];
                block[j+1]=temp;
                temp=b_index[j];
                b_index[j]=b_index[j+1];
                b_index[j+1]=temp;
            }
    
    printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
    
    for(i=0;i<p;i++) {
        for(j=0;j<b;j++)
            if(process[i]<=block[j] && b_flg[j]==0) {
                remain[j]=block[j]-process[i];
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],b_index[j],block[j],remain[j]);
                p_flg[i]=b_flg[j]=1;
                break;
            }
        
        if(p_flg[i]==0)
            printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
    }
}

void worst_fit() {
    int i,j,p_flg[10]={0},b_flg[10]={0},b_index[10];
    
    for(i=0;i<b;i++) {
        b_index[i]=i+1;
        remain[i]=b_copy[i];
    }
    
    for(i=1;i<b;i++)
        for(j=0;j<b-i;j++)
            if(b_copy[j]<b_copy[j+1]) {
                int temp=b_copy[j];
                b_copy[j]=b_copy[j+1];
                b_copy[j+1]=temp;
                temp=b_index[j];
                b_index[j]=b_index[j+1];
                b_index[j+1]=temp;
            }
    
    printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
    
    for(i=0;i<p;i++) {
        for(j=0;j<b;j++)
            if(process[i]<=b_copy[j] && b_flg[j]==0) {
                remain[j]=b_copy[j]-process[i];
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],b_index[j],b_copy[j],remain[j]);
                p_flg[i]=b_flg[j]=1;
                break;
            }
        
        if(p_flg[i]==0)
            printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
    }
}
