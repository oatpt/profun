#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
char name[1000000];
stack <int> bit;
vector <int> temp;
vector <char> ans;
main()
{
    scanf("%[^\n]", name);
    for(int i = 0; name[i] != '\0';i++)
    {
        for(int k=0;k<8;k++)
        {
            bit.push(name[i]%2);
            name[i]/=2;
        }
        while(!bit.empty())
        {
            temp.push_back(bit.top());
            bit.pop();
        }  
    }
    for(int i = 0; i<temp.size();i+=6)
    {
        int dec=0;
        for(int k=0;k<6;k++)
        {
            dec*=2;
            if(i+k<temp.size())
                dec+=temp[i+k];
            else
                dec+=0;
        }
        if(dec<26)
            ans.push_back('A'+dec);
        else if (dec<52)
            ans.push_back('a'+dec-26);
        else if (dec<62)
            ans.push_back('0'+dec-52);
        else if (dec==62)
            ans.push_back('+');
        else if (dec==62)
            ans.push_back('/'); 
        if(i+6>temp.size()) 
            for(int k=0;k<(i+6-temp.size())/2;k++)
                ans.push_back('='); 
    }
    for(int i = 0; i<ans.size();i++)
        printf("%c",ans[i]);
}