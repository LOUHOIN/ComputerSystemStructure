#include<stdio.h>
#include<cstring>
using namespace std;
const long max=10000;

int main () {
    int m, n;
    char s[max][max],out[max][max];
    memset(s, 0, sizeof s);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++){
        getchar();
        for (int j = 0; j < n; j++)
        {
            s[i][j] = getchar();
        } 
        s[i][n+1]='\0';    
    }
    /*if(n==1)
    {
        if(s[1][0]=='.') out[0][0]='-';
        if(s[1][0]=='*') out[0][0]='1';
        for (int i = 1; i < m-1; i++)
        {
            if(s[i-1][0]=='.' && s[i+1][0]=='.') out[i][0]='-';
            if((s[i-1][0]=='.' && s[i-1][0]=='*') || (s[i-1][0]=='*' && s[i-1][0]=='.')) out[i][0]='1';
            if(s[i-1][0]=='*' && s[i-1][0]=='*') out[i][0]='2';
        }
        
        if(s[m-2][0]=='*') out[m-1][0]='1';
        if(s[m-2][0]=='.') out[m-1][0]='-';
    }
    else if(m==1)
    {
        if(s[0][1]=='.') out[0][0]='-';
        if(s[0][1]=='*') out[0][0]='1';     
        for (int i = 1; i < n-1; i++)
        {      
            if(s[0][i-1]=='.' && s[0][i+1]=='.') out[0][i]='-';
            if((s[0][i-1]=='.' && s[0][i+1]=='*') || (s[0][i-1]=='*' && s[0][i+1]=='.')) out[0][i]='1';
            if(s[0][i-1]=='*' && s[0][i+1]=='*') out[0][i]='2';
        }
        if(s[0][n-2]=='*') out[0][n-1]='1';
        if(s[0][n-2]=='.') out[0][0]='-';
    }
    else{
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                return 0;
            }    
        }
    }*/
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            putchar(s[i][j]);
        } 
        putchar('\n');    
    }
    return 0;
}