#include <stdio.h>
#include <memory.h>
int num[1005];
int main()
{
    int n,i,j,flag=0;
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++)
    {
        int up=0;
        int down=0;
        for(j=0;j<n;j++)
        {
            if(num[j]>num[i])
            {
                up++;
            }
            if(num[j]<num[i])
            {
                down++;
            }
        }
        if(up==down)
        {
            flag=1;
            printf("%d\n",num[i]);
            break;
        }
    }
    if(flag==0)
    {
        printf("-1\n");
    }
    return 0;
}
