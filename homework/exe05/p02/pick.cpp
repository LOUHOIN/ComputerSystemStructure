#include<stdio.h>
#include<stdlib.h>

void pickup(int b[][5],int x,int y){
    int **a,temp[5],cout=0;
    a=(int **)calloc(4,sizeof(int*));
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j< 5;j++){
            if(x<=b[i][j] && b[i][j]<=y){
                temp[cout++]=b[i][j];
            }
            else continue;
        }
        printf("[");
        a[i]=(int *)calloc(cout,sizeof(int));    
        for(int k=0;k<cout;k++) {
            a[i][k]=temp[k];
            if(k==cout-1) printf("%d",a[i][k]);
            else printf("%d, ",a[i][k]);
        } 
        printf("]\n");
        cout=0;      
    }   
    for(int i=0;i<4;i++) free(a[i]);
    free(a);
}
int main(){
    int b[4][5]={{1,-2,0,3,0},{2,-4,0,1,8},{0,0,10,0,0},{0,18,0,0,0}};
    pickup(b,1,10);
    return 0;
}