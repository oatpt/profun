#include<stdio.h>
#include <queue>
using namespace std;
struct box{
    int x,y;
}temp;
queue<box> q;
int area[1000][1000];
main()
{
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&area[i][j]);
        }
    }
    temp.x=0,temp.y=0;
    q.push(temp);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        a=temp.x,b=temp.y;
        area[a][b]=3;
        if(a>0&&!area[a-1][b])
        {
            temp.x=a-1;
            temp.y=b;
            q.push(temp);
        }
        if(b>0&&!area[a][b-1])
        {
            temp.x=a;
            temp.y=b-1;
            q.push(temp);
        }
        if(a<n-1&&!area[a+1][b])
        {
            temp.x=a+1;
            temp.y=b;
            q.push(temp);
        }
        if(b<m-1&&!area[a][b+1])
        {
            temp.x=a;
            temp.y=b+1;
            q.push(temp);
        }
    }
    area[n-1][m-1]==3 ? printf("Yes") : printf("No");
}