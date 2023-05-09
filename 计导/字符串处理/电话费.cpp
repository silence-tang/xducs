#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    char ch[10];
    int s=0;
    float ans;
    long time=0;
    freopen("fee.txt","r",stdin);
    while(scanf("%s %d\n",&ch,&s)!=EOF)
    {
                    if(ch[0]=='O')
                    {
                                time+=s;
                    }
    }
    time=((time/180)+1);
    ans=time*0.17;
    printf("%.2f",ans);
    return 0;
}
