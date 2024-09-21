#include<stdio.h>
void main()
{  //MATRIX INPUT
   int a[100][100],b[100][100],r,c,i,j;
   printf("ENTER THE NUMBER OF ROWS AND COLOUMNS: ");
   scanf("%d %d",&r,&c);
   
   printf("ENTER THE ELEMENTS OF SPARSE MATRIX 1 : ");
   for(i=0;i<r;i++){
   	  for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
   }
   	
   printf("ENTER THE ELEMENTS OF SPARSE MATRIX 2 : ");
   for(i=0;i<r;i++)
  	{
   	  for(j=0;j<c;j++)
		scanf("%d",&b[i][j]);
   	}
   
   //TUPLE CONVERSION
   i=0;j=0;
   int k=1;
   int count=0,t1[100][100],t2[100][100],sum[100][100];
   
   for(i=0;i<r;i++){
       for(j=0;j<c;j++){
           if(a[i][j]!=0){
               t1[k][0]=i;
   	     	   t1[k][1]=j;
   	     	   t1[k][2]= a[i][j];
   	     	   k++,count++;
           }
       }
  }
        
    t1[0][0]=r;
    t1[0][1]=c;
    t1[0][2]=count;
   
   printf("tuple 1: \n");
   for(i=0;i<count+1;i++)
   {
   	  for(j=0;j<3;j++)
   	  {	printf("%d", t1[i][j]);
	        printf("\t");	  
   	  }
   	  printf("\n");
   }
   
   i=0;j=0;k=1;count=0;
   for(i=0;i<r;i++){
       for(j=0;j<c;j++){
           if(a[i][j]!=0){
               t2[k][0]=i;
   	     	   t2[k][1]=j;
   	     	   t2[k][2]= b[i][j];
   	     	   k++,count++;
           }
       }
  }
   t2[0][0]=r;
   t2[0][1]=c;
   t2[0][2]=count;
   
   printf("tuple 2: \n");
   for(i=0;i<count+1;i++)
   {
   	  for(j=0;j<3;j++)
   	  {	printf("%d", t2[i][j]);
	        printf("\t");	  
   	  }
   	  printf("\n");
   }
   
  
   // TUPLE ADDITION
   i=1;j=1;k=1;count=0;
   while(i<=r)
   	while(j<=c)
   	{
   	  if(t1[i][0]< t2[j][0])
   	  {
   	  	sum[k][0]=t1[i][0];
   	  	sum[k][1]=t1[i][1];
   	  	sum[k][2]=t1[i][2];
   	  	i++,k++,count++;   	  
   	  }
   	  
   	  
   	  if(t1[i][0]> t2[j][0])
   	  {
   	  	sum[k][0]=t2[j][0];
   	  	sum[k][1]=t2[j][1];
   	  	sum[k][2]=t2[j][2];
   	  	j++,k++,count++;   	  
   	  }
   	  
   	  if((t1[i][0]==t2[j][0])&& (t1[i][1]==t2[j][1]))
   	  {
   	  	sum[k][0]=t1[i][0];
   	  	sum[k][1]=t1[i][1];
   	  	sum[k][2]=t1[i][2]+t2[j][2];
   	  	i++,j++,k++,count++;     	  
   	  }
      	  
   	  if ((t1[i][0]==t2[j][0])&& (t1[i][1] < t2[j][1]))
   	  {
   	  	sum[k][0]=t1[i][0];
   	  	sum[k][1]=t1[i][1];
   	  	sum[k][2]=t1[i][2];
   	  	i++,k++,count++;   	  
   	  }
   	  
   	  
   	  if((t1[i][0]==t2[j][0])&& (t1[i][1] > t2[j][1]))
   	  {
   	  	sum[k][0]=t2[j][0];
   	  	sum[k][1]=t2[j][1];
   	  	sum[k][2]=t2[j][2];
   	  	j++,k++,count++;   	  
   	  }
   	}
   	  
   	  
   while(i<r)
   {
   	sum[k][0]=t1[i][0];
   	sum[k][1]=t1[i][1];
   	sum[k][2]=t1[i][2];
   	i++,k++,count++;  
   }
   
   while(j<c)
   {
   	sum[k][0]=t2[j][0];
   	sum[k][1]=t2[j][1];
   	sum[k][2]=t2[j][2];
   	j++,k++,count++ ;  	  
   }
   
   sum[0][0]=r;
   sum[0][1]=c;
   sum[0][2]=count;
   
   printf("SUM: \n");
   for(i=0;i<count+1;i++)
   {
   	  for(j=0;j<3;j++)
   	  {	printf("%d", sum[i][j]);
	        printf("\t");	  
   	  }
   	  printf("\n");
    }
  
}  
