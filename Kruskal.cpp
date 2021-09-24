#include<stdio.h>
#include<queue>
using namespace std;
int head[1000],n,m,sum;
struct box{
    int a,b,w;
    bool operator<(const box &x)const
    {
        return x.w<w;
    }

}temp;
priority_queue <box> q;
int findhead(int x)
{
    if(head[x]==x)
        return x;
    return head[x]=findhead(head[x]);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&temp.a,&temp.b,&temp.w);
        q.push(temp);
    }
    for(int i=0;i<n;i++)
        head[i]=i;
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        if(findhead(temp.a)!=findhead(temp.b))
        {
            sum+=temp.w;
            head[findhead(temp.a)]=findhead(temp.b);
        }
    }
    printf("%d",sum);
}
