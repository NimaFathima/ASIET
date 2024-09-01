#include <stdio.h>

void main()
{
    // Matrix input
    int a[100][100], b[100][100], r, c, p, q;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of sparse matrix 1: ");
    for (p = 0; p < r; p++)
    {
        for (q = 0; q < c; q++)
        {
            scanf("%d", &a[p][q]);
        }
    }

    printf("Enter the elements of sparse matrix 2: ");
    for (p = 0; p < r; p++)
    {
        for (q = 0; q < c; q++)
        {
            scanf("%d", &b[p][q]);
        }
    }

    // Tuple conversion
    int i = 0, j = 0, k = 1, count = 0;
    int t1[100][3], t2[100][3], sum[100][3];

    t1[0][0] = r;
    t1[0][1] = c;
    t1[0][2] = 0;

    t2[0][0] = r;
    t2[0][1] = c;
    t2[0][2] = 0;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                t1[k][0] = i;
                t1[k][1] = j;
                t1[k][2] = a[i][j];
                k++;
                t1[0][2]++;
            }
        }
    }

    k = 1;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (b[i][j] != 0) {
                t2[k][0] = i;
                t2[k][1] = j;
                t2[k][2] = b[i][j];
                k++;
                t2[0][2]++;
            }
        }
    }

    // Tuple addition
    i = 1;
    j = 1;
    k = 1;
    sum[0][0] = r;
    sum[0][1] = c;
    sum[0][2] = 0;

    while (i <= t1[0][2] && j <= t2[0][2])
    {
        if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1]))
        {
            sum[k][0] = t1[i][0];
            sum[k][1] = t1[i][1];
            sum[k][2] = t1[i][2];
            i++;
        } 
        else if (t1[i][0] > t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] > t2[j][1]))
        {
            sum[k][0] = t2[j][0];
            sum[k][1] = t2[j][1];
            sum[k][2] = t2[j][2];
            j++;
        } 
        else
        {
            sum[k][0] = t1[i][0];
            sum[k][1] = t1[i][1];
            sum[k][2] = t1[i][2] + t2[j][2];
            i++;
            j++;
        }
        k++;
        sum[0][2]++;
    }

    while (i <= t1[0][2])
    {
        sum[k][0] = t1[i][0];
        sum[k][1] = t1[i][1];
        sum[k][2] = t1[i][2];
        i++;
        k++;
        sum[0][2]++;
    }

    while (j <= t2[0][2])
    {
        sum[k][0] = t2[j][0];
        sum[k][1] = t2[j][1];
        sum[k][2] = t2[j][2];
        j++;
        k++;
        sum[0][2]++;
    }

    printf("Sum: \n");
    for (i = 0; i <= sum[0][2]; i++)
    {
        printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
    }
}
