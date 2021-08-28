#include <stdio.h>
#include <algorithm>
using namespace std;
int ar[110][110],n,sum[110][110];
main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&ar[i][j]);

    for(int i=1;i<=n;i++)
        sum[n][i]=ar[n][i];

    for(int i=n;i>1;i--)
        for(int j=1;j<=i;j++)
        {
            if(j!=i&&sum[i][j]+ar[i-1][j]>sum[i-1][j])
                sum[i-1][j]=sum[i][j]+ar[i-1][j];
            
            if(j!=1&&sum[i][j]+ar[i-1][j-1]>sum[i-1][j-1])
                sum[i-1][j-1]=sum[i][j]+ar[i-1][j-1];
        }
    printf("%d",sum[1][1]);       
}