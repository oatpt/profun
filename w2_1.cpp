#include<stdio.h>
int ar[10][10];
int n,x,y,temp_x,temp_y;
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        temp_x=x;
        while(temp_x>=1)ar[temp_x--][y]++;

        temp_x=x;
        while(temp_x<=8)ar[temp_x++][y]++;

        temp_y=y;
        while(temp_y>=1)ar[x][temp_y--]++;

        temp_y=y;
        while(temp_y<=8)ar[x][temp_y++]++;

        temp_y=y;
        temp_x=x;
        while(temp_x>=1&&temp_y>=1)ar[temp_x--][temp_y--]++;

        temp_y=y;
        temp_x=x;
        while(temp_x>=1&&temp_y<=8)ar[temp_x--][temp_y++]++;

        temp_y=y;
        temp_x=x;
        while(temp_x<=8&&temp_y>=1)ar[temp_x++][temp_y--]++;

        temp_y=y;
        temp_x=x;
        while(temp_x<=8&&temp_y<=8)ar[temp_x++][temp_y++]++;
    }
    int sum=0;
    for(int i=1;i<=8;i++)
        for(int k=1;k<=8;k++)
            if(!ar[i][k])
                sum++;
    printf("%d",sum);
}
