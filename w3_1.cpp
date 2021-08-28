#include <stdio.h>
#include <algorithm>
using namespace std;
int ar[110][110],n;
int f(int x,int y)
{
    if(x==n)
        return ar[x][y];
    return ar[x][y]+max(f(x+1,y),f(x+1,y+1));
}
main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&ar[i][j]);
    printf("%d",f(1,1));
}