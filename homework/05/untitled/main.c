#include <stdio.h>

int main()
{
    int num;
    int a[5]={90 ,21 ,132,-58,34};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i=1;i<=n;i++)
    {
        for(int x=0;x<=n-i;x++)
        {
            if(a[x] > a[x+1])
            {
                num=a[x+1];
                a[x+1]=a[x];
                a[x]=num;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        printf("%d\n",a[j]);
    }
    return 0;
}