#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct box{
    int V,i;
}temp;
int mem[10010],Max,k,n,m,a,b;
vector <int> v [10010];
queue <box> q;
main()
{
    scanf("%d %d %d",&k,&n,&m);
    while(m--)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
    }
    temp.V=1;
    temp.i=k;
    q.push(temp);
    while(!q.empty())
    {
        a=q.front().V;
        b=q.front().i;
        if(a>Max)
            Max=a;
        if(mem[a]<b)
        {
            mem[a]=b;
            if(q.front().i>0)
            {
              for(int j=0;j<v[a].size();j++)
              {
                  temp.i=b-1;
                  temp.V=v[a][j];
                  q.push(temp);
              }
            }
        }
        q.pop();
    }
    printf("%d",Max);
}