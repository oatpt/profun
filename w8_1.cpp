#include <stdio.h>
#include <vector>
#include<algorithm>
using namespace std;
vector <int> v[20000];
int k,n,m,a,b,mem[20000];
int Max;
void dp(int now,int a)
{
    
    if(mem[now]<=a+1&&mem[now])
        return;
    mem[now]=a+1;
    Max=max(Max,now); 
    if(a==k)
        return;
    for(int i=0;i<v[now].size();i++)
    {
        dp(v[now][i],a+1);
    }
}
main()
{
    scanf("%d %d %d",&k,&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
    }
    dp(1,0);
    printf("%d",Max);
}