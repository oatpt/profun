#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
char name[1000000],temp[100];
vector <char> ans;
main()
{
    scanf("%[^\n]", name);
    int num=strlen(name);
    for(int i = 0; i+2<strlen(name);i+=3)
    {
        for(int j = 0;j<3;j++)
        {
            for(int k = 7; k >= 0 ; k--)
            {
                temp[j*8+k]=name[i+j]%2;
                name[i+j]/=2;
            }
        }
        for(int j = 0;j<4;j++)
        {
            int dec=0;
            for(int k = 0; k < 6  ; k++)
            {
                dec*=2;
                dec+=temp[j*6+k];
            }
            if(dec<26)
                printf("%c",'A'+dec);
            else if (dec<52)
                printf("%c",'a'+dec-26);
            else if (dec<62)
                printf("%c",'0'+dec-52);
            else if (dec==62)
                printf("+");
            else if (dec==62)
                printf("/");
        }
    }
   
    if(num%3==2)
    {
        int now=strlen(name)-2;
        for(int j = 0;j<2;j++)
        {
            for(int k = 7; k >= 0 ; k--)
            {
                temp[j*8+k]=name[now+j]%2;
                name[now+j]/=2;
            }
        }
        for(int k=16;k<18;k++)
            temp[k]=0;
        for(int j = 0;j<3;j++)
        {
            int dec=0;
            for(int k = 0; k < 6  ; k++)
            {
                dec*=2;
                dec+=temp[j*6+k];
            }
            if(dec<26)
                printf("%c",'A'+dec);
            else if (dec<52)
                printf("%c",'a'+dec-26);
            else if (dec<62)
                printf("%c",'0'+dec-52);
            else if (dec==62)
                printf("+");
            else if (dec==62)
                printf("/");
        }
        printf("=");
    }
    
    if( num%3 == 1 )
    {
        int now=strlen(name)-1;
        for(int k = 7; k >= 0 ; k--)
        {
            temp[k]=name[now]%2;
            name[now]/=2;
        }
        for(int k=8;k<12;k++)
            temp[k]=0;
        for(int j = 0;j<2;j++)
        {
            int dec=0;
            for(int k = 0; k < 6  ; k++)
            {
                dec*=2;
                dec+=temp[j*6+k];
            }
            if(dec<26)
                printf("%c",'A'+dec);
            else if (dec<52)
                printf("%c",'a'+dec-26);
            else if (dec<62)
                printf("%c",'0'+dec-52);
            else if (dec==62)
                printf("+");
            else if (dec==62)
                printf("/");
        }
        printf("==");
    }
}