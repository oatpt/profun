#include <stdio.h>
int x,y,ar[10][10];
char temp;
main()
{
    for(int i=1;i<=8;i++)
    {
        for(int k=1;k<=8;k++)
        {
            scanf("%c",&temp);
            if(temp == 'Q')
            {
                for(int j=1;j<=8;j++)
                {
                    ar[j][k]++;
                    ar[i][j]++;
                }
                for(int j=-7;j<=7;j++)
                {
                    if(i+j<=8&&i+j>=1&&k+j<=8&&k+j>=1)
                        ar[i+j][k+j]++;
                }
                for(int j=-7;j<=7;j++)
                {
                    if(i+j<=8&&i+j>=1&&k-j<=8&&k-j>=1)
                        ar[i+j][k-j]++;
                }
            }
            if(temp == 'R')
            {
                for(int j=1;j<=8;j++)
                {
                    ar[j][k]++;
                    ar[i][j]++;
                }
            }
            if(temp == 'P')
            {
                ar[i-1][k+1]++;
                ar[i-1][k-1]++;
            }
            if(temp == 'B')
            {
                for(int j=-7;j<=7;j++)
                {
                    if(i+j<=8&&i+j>=1&&k+j<=8&&k+j>=1)
                        ar[i+j][k+j]++;
                }
                 for(int j=-7;j<=7;j++)
                {
                    if(i+j<=8&&i+j>=1&&k-j<=8&&k-j>=1)
                        ar[i+j][k-j]++;
                }
            }
            if(temp == 'N')
            {
                if(i-2>=0&&k-1>=0)
                    ar[i-2][k-1]++;
                if(i-1>=0&&k-2>=0)
                    ar[i-1][k-2]++;
                if(i+1<=8&&k-2>=0)
                    ar[i+1][k-2]++;
                if(i+2<=8&&k-1>=0)
                    ar[i+2][k-1]++;
                if(i-2>=0&&k+1<=8)
                    ar[i-2][k+1]++;
                if(i-1>=0&&k+2<=8)
                    ar[i-1][k+2]++;
                if(i+1<=8&&k+2<=8)
                    ar[i+1][k+2]++;
                if(i+2<=8&&k+1<=8)
                    ar[i+2][k+1]++;
            }
            if(temp == 'K')
            {
                x=i,y=k;
            }
        }
        scanf("%c",&temp);
    }
    if(ar[x][y]==0) printf("NO");
    else printf("YES");
}