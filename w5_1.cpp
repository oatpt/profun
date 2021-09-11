#include <stdio.h>
#include <algorithm>
using namespace std;
int n,ar[1000][1000],x,y,mem[1000][1000];
char input[100];
int dp(int x,int y)
{
    int mini=99999;
    mem[x][y]=1;
    for(int i=-1;i<=1;i++)
    {
        for(int k=-1;k<=1;k++)
        {
            if(x+i>=0&&y+k>=0&&x+i<n&&y+k<n&&ar[x+i][y+k]!=0&&mem[x+i][y+k]==0)
            {
                mini=min(mini,dp(x+i,y+k)+ar[x][y]);
            }
        }
    }
    mem[x][y]=0;
    if(mini==99999)
        return ar[x][y];
    return mini;
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            scanf(" %s",input);
            int negative=1;
            for(int j=0;input[j]!='\0';j++)
            {
                if(input[j]=='-')
                {
                    negative=-1;
                }
                else if(input[j]=='S')
                {
                    x=i,y=k;
                    break;
                }
                else
                {
                    ar[i][k]*=10;
                    ar[i][k]+=input[j]-48;
                }
            }
            ar[i][k]*=negative;
        }
    }
    printf("%d",dp(x,y));
}