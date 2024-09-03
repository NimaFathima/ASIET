#include<stdio.h>
void main()
{  //MATRIX INPUT
   int a[100][100],b[100][100],r,c,p,q;
   printf("ENTER THE NUMBER OF ROWS AND COLOUMNS: ");
   scanf("%d %d",&r,&c);
   printf("ENTER THE ELEMENTS OF SPARSE MATRIX 1 : ");
   for(p=0;p<r;p++)
  	{
   	  for(q=0;q<c;q++)
		scanf("%d",&a[p][q]);
   	}
   	
   printf("ENTER THE ELEMENTS OF SPARSE MATRIX 2 : ");
   for(p=0;p<r;p++)
  	{
   	  for(q=0;q<c;q++)
		scanf("%d",&b[p][q]);
   	}
   //TUPLE CONVERSION
   int i=0,j=0,k=1,count=0,t1[100][100],t2[100][100],sum[100][100];
   while(i<r)
   {	while(j<c)
   	{
   	     if(a[i][j]!=0)
   	     {
   	     	t1[k][0]=i;
   	     	t1[k][1]=j;
   	     	t1[k][2]= a[i][j];
   	     	k+=1,count+=1;   	     
   	     }j+=1;
   	}i++;
   }
   
   while(i<r)
   {	while(j<c)
   	{
   	     if(a[i][j]!=0)
   	     {
   	     	t2[k][0]=i;
   	     	t2[k][1]=j;
   	     	t2[k][2]= a[i][j];
   	     	k+=1,count+=1;   	     
   	     }j+=1;
   	}i++;
   }
   // TUPLE ADDITION
   while(i<r)
   	while(j<c)
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
      	  
   	  if((t1[i][0]==t2[j][0])&& (t1[i][1] < t2[j][1]))
   	  {
   	  	sum[k][0]=t1[i][0];
   	  	sum[k][1]=t1[i][1];
   	  	sum[k][2]=t1[i][2];
   	  	i++,k++,count++;   	  
   	  }
   	  
   	  
   	  if((t1[i][0]==t2[j][0])&& (t1[i][1] > t2[j][1]))
   	  {
   	  	sum[k][0]=t1[j][0];
   	  	sum[k][1]=t1[j][1];
   	  	sum[k][2]=t1[j][2];
   	  	j++,k++,count++;   	  
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
   	sum[k][0]=t1[j][0];
   	sum[k][1]=t1[j][1];
   	sum[k][2]=t1[j][2];
   	j++,k++,count++ ;  	  
   }
   
   printf("SUM: ");
   for(i=0;i<r;i++)
   {
   	  for(j=0;j<c;j++)
   	  {	printf("%d",sum[i][j]);
	        printf("\t");	  
   	  }
   	  printf("\n");
    }
 }
   
   
   
