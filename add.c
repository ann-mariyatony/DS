#include <stdio.h>
int main()
{
int r,c,t,i,j,k;
int MAX=100;
int a[MAX][3];
printf("Enter the no.of row,column and the non-zero value:);
scanf("%d,%d,%d",r,c,t);
a[0][0] = r; 
a[0][1] = c; 
a[0][2] = t; 

printf ("Enter row, column and value for each non-zero element:\n");
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    
int b[MAX][3];
printf("Enter the no.of row,column and the non-zero value:);
scanf("%d,%d,%d",r,c,t);
b[0][0] = r; 
b[0][1] = c; 
b[0][2] = t; 

 printf("Enter row, column and value for each non-zero element:\n");
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    }

int C[MAX][3];
 int r1 = a[0][0], c1 = a[0][1], t1 = a[0][2];
 int r2 = b[0][0], c2 = b[0][1], t2 = b[0][2];

 if (r1 != r2 || c1 != c2) {
        printf("Can,t perform  matrix sizes for addition.\n");
        C[0][2] = 0;
        return;
    }
    
int m = 1, n = 1, k = 1;
   if  (r1 = a[0][0] == r2 = b[0][0])
    {
      if  (c1 = a[0][1] == c2 = b[0][1])
      { 
       int val = a[m][2] + b[n][2];
            if (val != 0) {
                C[k][0] = a[m][0];
                C[k][1] = a[m][1];
                C[k][2] = val;
                k++;m++;n++;
                          }
          else if ((c1 = a[0][1] < c2 = b[0][1])
             {
                C[k][0] = a[m][0];
                C[k][1] = a[m][1];
                C[k][2] = a[m][2];
                m++; k++;
             }
            else
            {
             C[k][0] = b[m][0];
            C[k][1] = b[m][1];
             C[k][2] = b[m][2];
             m++; k++;
            }
        else if(r1 = a[0][0] < r2 = b[0][0])
            {
             C[k][0] = a[m][0];
                C[k][1] = a[m][1];
                C[k][2] = a[m][2];
                m++; k++;
           }
          else
          {
          C[k][0] = b[m][0];
            C[k][1] = b[m][1];
             C[k][2] = b[m][2];
             m++; k++;
             }
             
        }
     }
     int rows = a[0][0];
    int cols = a[0][1];
    int t = a[0][2];

    int fullMat[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fullMat[i][j] = 0;


    for (int i = 1; i <= t; i++) {
        int r = C[i][0];
        int c = C[i][1];
        fullMat[r][c] = C[i][2];
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", fullMat[i][j]);
        printf("\n");
    }
    printf("\n");
}
return 0;
