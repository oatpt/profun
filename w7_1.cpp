#include <stdio.h>
main(){
    int n,j=0,temp=0,ar[1000];
    scanf("%d",&n);
    ar[6]=1,ar[9]=1,ar[20]=1;
    if(n>=6)
    for(int i=6;i<=n;i++)
        if(ar[i]==1)
        {
            printf("%d\n",i);
            ar[i+6]=1;
            ar[i+9]=1;
            ar[i+20]=1;
        }
    if(n<6)
        printf("no");
}
