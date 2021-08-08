#include<stdio.h>
int area[1000][1000];
bool check;
int n,m;
void dfs(int x,int y)
{
    area[x][y] = 3;
    if(x>0&&!area[x-1][y])  dfs(x-1,y);
    if(y>0&&!area[x][y-1])  dfs(x,y-1);
    if(x<n-1&&!area[x+1][y])dfs(x+1,y);
    if(y<m-1&&!area[x][y+1])dfs(x,y+1);
}
main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&area[i][j]);
        }
    }
    dfs(0,0);
    area[n-1][m-1]==3 ? printf("Yes") : printf("No");
}