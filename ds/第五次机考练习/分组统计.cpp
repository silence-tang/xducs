#include<stdio.h>
#include<map>
#include<set>
#include<vector>
using namespace std;

int main()
{
    int cishu;
    scanf("%d",&cishu);
    while(cishu--)
    {
        int n,an[100000]={0},ans[100][100]={0};
        set<int> S,G;
        map<int,int> mp,group;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&an[i]);
            if(mp[an[i]])
                continue;
            else   
            {
                mp[an[i]]=i;
                S.insert(an[i]);
            }              
        }
        for(int i=1;i<=n;i++)
        {
            int n;
            scanf("%d",&n);
            if(!group[n])
            {
                G.insert(n);
                group[n]=i;
            }                
            ans[group[n]][mp[an[i]]]++;
        }
        set<int>::iterator it;
        for(it=G.begin();it!=G.end();it++)
        {
            printf("%d={",*it);
            set<int>::iterator in;
            for(in=S.begin();in!=S.end();in++)
            {
                if(in!=S.begin())
                    putchar(',');
                printf("%d=%d",*in,ans[group[*it]][mp[*in]]);
            }
            printf("}\n");
        }
    }
    return 0;
}
