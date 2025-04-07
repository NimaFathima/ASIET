#include<stdio.h>
void main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d",&n);
    int pid[100],at[100],bt[100];
    int i,j;
    for(i=0;i<n;i++){
        printf("%d ENTER THE PROCESSES_ID: ",i+1);
        scanf("%d",&pid[i]);
        printf("   ENTER THE ARRIVAL TIME: ");
        scanf("%d",&at[i]);
        printf("   ENTER THE BURST TIME: ");
        scanf("%d",&bt[i]);
    }
    int ct[100],tt[100],wt[100];
    int total_tt=0;
    int total_wt=0;
    float avg_tt=0;
    float avg_wt=0;
    int current_time;
  
    //swap
    int temp;
    for(j=0;j<n-1;j++){
        for(i=0;i<n-j-1;i++){
            if(at[i]>at[i+1]){
                temp=at[i];
                at[i]=at[i+1];
                at[i+1]=temp;
                
                temp=bt[i];
                bt[i]=bt[i+1];
                bt[i+1]=temp;
                
                temp=pid[i];
                pid[i]=pid[i+1];
                pid[i+1]=temp;
            }
        }
    }
    
    //scheduling
    current_time=0;
    for(i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }//idle time
        current_time=current_time+bt[i];
        ct[i]=current_time;
        tt[i] =ct[i]-at[i];
        wt[i]=tt[i]-bt[i];
    }
    for(i=0;i<n;i++){
        total_tt += tt[i];
    }
    printf("\n %d",total_tt);
    avg_tt=(float)total_tt/n;
    printf("\n AVERAGE TURNAROUND TIME:%f",avg_tt);
   
    for(i=0;i<n;i++){
       total_wt += wt[i];
    }
    printf("\n %d",total_wt);
    avg_wt=(float)total_wt/n;
    printf("\n AVERAGE WAITING TIME:%f",avg_wt);
    
    //process table
    printf("\n|   PID |   AT  |   BT  |   CT  |   TT  |   WT  |");
    for(i=0;i<n;i++){
        printf("\n|   %d  |   %d  |   %d  |   %d  |   %d  |   %d  |\n",pid[i],at[i],bt[i],ct[i],tt[i],wt[i]);
    }
    //gantt chart
    current_time=0;
    for(i=0;i<n;i++){
        if(current_time<at[i]){
            printf("|idle|");
        }
        printf("| %d |",pid[i]);
        current_time=ct[i];
    }
    //timestamp
    current_time=0;
    printf("\n %d",current_time);
    for(i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
            printf("%d",current_time);
        }
        current_time+=bt[i];
        printf("%d",current_time);
    }
    
    
}
