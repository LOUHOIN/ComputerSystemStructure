#include <stdio.h>

void solvebomb(char *bomb, char*res, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(*(bomb + i*n + j) == '*') *(res + i*n + j) = 'F';
            else{
                char count = '0';
                for(int k = i - 1; k <= i + 1; k++){
                    for(int h = j - 1; h <= j + 1; h++){
                        if(k>=0 && h>=0 && k<m && h<n){
                            if(*(bomb + k*n + h) == '*') count++;
                        }
                    }
                }
                if(count == '0')  *(res + i*n + j) = '-';
                else *(res + i*n + j) = count;
            }
        }
    }
}

int main(){
    int m, n;
    scanf( "%d %d", &m, &n );
    char bomb[m][n];
    char res[m][n];
    for(int i = 0; i < m; i++ ){
        scanf( "%s", &bomb[i][0]);
    }
    solvebomb(*bomb, *res, m, n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
}