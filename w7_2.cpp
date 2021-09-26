#include <stdio.h>
int mem[200];
int topdown(int x)
{
    if(mem[x])
        return mem[x];
    if(x==6||x==9||x==20)
        return mem[x]=1;
    if(x-6>0)
        return mem[x]=topdown(x-6);
    if(x-9>0)
        return mem[x]=topdown(x-9);
    if(x-20>0)
        return mem[x]=topdown(x-20);
}
main(){
    int n;
    scanf("%d",&n);
    if(n>=6)
        for(int i=6;i<=n;i++)
            if(topdown(i)==1)
            {
                printf("%d\n",i);
            }
    if(n<6)
        printf("no");
}
