#include <stdio.h>
#include <string.h>

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[100],at[100],bt[100],ct[100],tt[100],wt[100],prior[100];

    int i,j,temp=0;
    float avg_wt=0,avg_tt=0;
    for (i = 0; i < n; i++) {
        printf("Enter the Process PID: ");
        scanf("%d", &pid[i]);
        printf("Enter the Process Burst time: ");
        scanf("%d", &bt[i]); 
        printf("Enter the Priority: ");
        scanf("%d", &prior[i]);  
                     
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (prior[j] > prior[j+1]) {
          
                temp = prior[j];
                prior[j] = prior[j+1];
                prior[j+1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }
      
    
    wt[0] = 0; 
    for (i = 1; i < n; i++) {
        wt[i]=wt[i-1]+bt[i-1];
        avg_wt = avg_wt + wt[i];        
    }
    for (i = 0; i < n; i++) {
        tt[i]=wt[i]+bt[i]; 
        avg_tt = avg_tt + tt[i];        
    }
    
    avg_wt= avg_wt/n; 
    avg_tt= avg_tt/n; 
    
    printf("AVERAGE WAITING TIME: %f\n", avg_wt);
    printf("AVERAGE TURN-AROUND TIME: %f\n", avg_tt);
    
    printf("GANTT CHART \n");
    printf("____________________________________________________________________________________ \n");
    for (i = 0; i < n; i++) {
    	printf("|	%d	",pid[i]);
    	printf("|");	
    }
    printf("\n");
    printf("_____________________________________________________________________________________ \n");
    for (i = 0; i < n; i++) {
    	printf("%d		",wt[i]);
    }
 }
    	
    


