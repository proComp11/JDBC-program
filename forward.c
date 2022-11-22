/*** Program for newtons forward and backward interpolation ***/
#include<stdio.h>
void read_data(float x[20], float y[20][20], int num);
void forward_diff(float x[20], float y[20][20],int num);
void backward_diff(float x[20], float y[20][20],int num);
int main(){
    float x[20],y[20][20];
    int n;
    printf("\n Enter number of element:");
    scanf("%d", &n);
    read_data(x,y,n);
    forward_diff(x,y,n);
    backward_diff(x,y,n);
    return 0;
}
// function for reading data for x and y
void read_data(float x[20], float y[20][20], int num){    
    int i,j;
    for(i = 0; i< num; i++){
        printf("\n Enter x[%d] : ", i);
        scanf("%f", &x[i]);
        printf("\n Enter y[%d]", i);
        scanf("%f", &y[i][0]);
    }
}

// function for newton forward difference
void forward_diff(float x[20], float y[20][20],int num){
    int i, j;
    float a = 0.5; // interpolation point
    float h, u, sum, p;
    for (j = 1; j < num; j++) {
        for (i = 0; i < num - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\n The forward difference table is:\n");
    for (i = 0; i < num; i++) {
        printf("%f\t", x[i]);
        for (j = 0; j < num - i; j++) {
            printf("%f\t", y[i][j]);
        }
        printf("\n");
    }
  
    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;
    for (j = 1; j < num; j++) {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("\nThe value of y at x= %0.1f is %0.3f ", a, sum);

}
void backward_diff(float x[20], float y[20][20],int num){
    int i, j;
    float a = 0.5; // interpolation point
    float h, u, sum, p;
    for (j = 1; j < num; j++) {
        for (i = j; i < num; i++) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    printf("\n\n\n The backward difference table is:\n\n\n ");
    for (i = 0; i < num; i++) {
        printf("%f\t", x[i]);
        for (j = 0; j <= i; j++) {
            printf("%f\t", y[i][j]);
        }
        printf("\n");
    }
  
    p = 1.0;
    sum = y[num - 1][0];
    h = x[1] - x[0];
    u = (a - x[num - 1]) / h;
    for (j = 1; j < num; j++) {
        p = p * (u + j - 1) / j;
        sum = sum + p * y[num - 1][j];
    }
  
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}
