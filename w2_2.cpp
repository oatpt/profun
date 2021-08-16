#include<stdio.h>
int ar[10][10];
main(){
    int n,x,y,sum,ans=0,temp_x,temp_y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        ar[x][y]++;
    }
     for(int i=1;i<=8;i++)
        for(int k=1;k<=8;k++)
        {
            sum=0,x=i,y=k;

            temp_x=x;
            while(temp_x>=1)sum+=ar[temp_x--][y];

            temp_x=x;
            while(temp_x<=8)sum+=ar[temp_x++][y];

            temp_y=y;
            while(temp_y>=1)sum+=ar[x][temp_y--];

            temp_y=y;
            while(temp_y<=8)sum+=ar[x][temp_y++];

            temp_y=y;
            temp_x=x;
            while(temp_x>=1&&temp_y>=1)sum+=ar[temp_x--][temp_y--];

            temp_y=y;
            temp_x=x;
            while(temp_x>=1&&temp_y<=8)sum+=ar[temp_x--][temp_y++];

            temp_y=y;
            temp_x=x;
            while(temp_x<=8&&temp_y>=1)sum+=ar[temp_x++][temp_y--];

            temp_y=y;
            temp_x=x;
            while(temp_x<=8&&temp_y<=8)sum+=ar[temp_x++][temp_y++];

            if(!sum)
                ans++;
        }
    printf("%d",ans);
}
