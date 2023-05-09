#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int i;      //当前方块行号 
    int j;      //当前方块列号 
    int di;     //下一个可走的相邻方块的方位，di表示direction 
}Box;           //定义方块类型 

typedef struct
{
    Box data[1000];
    int top;        //栈顶指针 
}StType;            //定义顺序栈类型 

bool mazepath()       //求解路径 
{
    int i,j,k,di,DI=0,find;
    int m,n,xi,yi,xe,ye;
	scanf("%d %d",&m,&n);
	scanf("%d %d",&xi,&yi);
	scanf("%d %d",&xe,&ye);
	int maze[m+2][m+2];
	for(i=0;i<=m+1;i++)
		for(j=0;j<=n+1;j++)
			maze[i][j]=1;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&maze[i][j]);
    StType st;             //定义栈st 
    st.top=-1;             //初始化栈顶指针 
    st.top++;              //初始方块进栈 
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=1;////////// 
    maze[xi][yi]=-1;
    while(st.top>-1)                //栈不为空时循环 
    {
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;      //取栈顶方块 
        
        if(i==xe && j==ye)          //找到出口，输出路径 
        {
            //按照格式打印迷宫路径： 
            for(k=0; k<st.top; k++)
                printf("(%d,%d,%d),",st.data[k].i,st.data[k].j,st.data[k].di);
            printf("(%d,%d,1)",st.data[st.top].i,st.data[st.top].j);
            return true;
        }
        
        find=0;
        if(DI==0)
        {
        	while(di<=4&&find==0)       //找下一个可走方块 
        	{
           		switch(di)
            	{
            		case 1:
                		i=st.data[st.top].i;
                		j=st.data[st.top].j+1;
                		break;
            		case 2:
                		i=st.data[st.top].i+1;
                		j=st.data[st.top].j;
                		break;
            		case 3:
               	 		i=st.data[st.top].i;
               		 	j=st.data[st.top].j-1;
                		break;
            		case 4:
               			i=st.data[st.top].i-1;
                		j=st.data[st.top].j;
                		break;
         	    }
            		di++;
            		if(maze[i][j]==0||maze[i][j]==2)
               			find=1;               //找下一个可走相邻方块 
    		}
		}
		
        else
        {
        	di=1;
        	while(di<=4&&find==0)             //找下一个可走方块 
        	{
           		switch(di)
            	{
            		case 1:
                		i=st.data[st.top].i;
                		j=st.data[st.top].j+1;
                		break;
            		case 2:
               	 		i=st.data[st.top].i+1;
               	 		j=st.data[st.top].j;
               		 	break;
            		case 3:
                		i=st.data[st.top].i;
                		j=st.data[st.top].j-1;
                		break;
            		case 4:
               			i=st.data[st.top].i-1;
                		j=st.data[st.top].j;
                		break;
            	}
            		di++;
            		if(maze[i][j]==0)
               			find=1;               //找下一个可走相邻方块 
    		}
		}
    	
        if(find==1)                       //找到了下一个可走方块 
        {
            st.data[st.top].di=di-1;      //修改原栈顶元素的di值 
            st.top++;                     //下一个可走方块进栈 
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=1;
            maze[i][j]=-1;               //避免重复走到该方块 
        }
        else                             //没有路径可走则退栈 
        {
            maze[st.data[st.top].i][st.data[st.top].j]=2;  //在某方块发现无路可走,置2，方便别的路径经过这个块 
			st.top--;               //将该方块退栈 
			DI=st.data[st.top].di;
    	}
	}
    return false;
}

int main()
{
	
    if(!mazepath())
        printf("no");
    return 0;
}
