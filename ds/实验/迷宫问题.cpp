#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int i;      //��ǰ�����к� 
    int j;      //��ǰ�����к� 
    int di;     //��һ�����ߵ����ڷ���ķ�λ��di��ʾdirection 
}Box;           //���巽������ 

typedef struct
{
    Box data[1000];
    int top;        //ջ��ָ�� 
}StType;            //����˳��ջ���� 

bool mazepath()       //���·�� 
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
    StType st;             //����ջst 
    st.top=-1;             //��ʼ��ջ��ָ�� 
    st.top++;              //��ʼ�����ջ 
    st.data[st.top].i=xi;
    st.data[st.top].j=yi;
    st.data[st.top].di=1;////////// 
    maze[xi][yi]=-1;
    while(st.top>-1)                //ջ��Ϊ��ʱѭ�� 
    {
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;      //ȡջ������ 
        
        if(i==xe && j==ye)          //�ҵ����ڣ����·�� 
        {
            //���ո�ʽ��ӡ�Թ�·���� 
            for(k=0; k<st.top; k++)
                printf("(%d,%d,%d),",st.data[k].i,st.data[k].j,st.data[k].di);
            printf("(%d,%d,1)",st.data[st.top].i,st.data[st.top].j);
            return true;
        }
        
        find=0;
        if(DI==0)
        {
        	while(di<=4&&find==0)       //����һ�����߷��� 
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
               			find=1;               //����һ���������ڷ��� 
    		}
		}
		
        else
        {
        	di=1;
        	while(di<=4&&find==0)             //����һ�����߷��� 
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
               			find=1;               //����һ���������ڷ��� 
    		}
		}
    	
        if(find==1)                       //�ҵ�����һ�����߷��� 
        {
            st.data[st.top].di=di-1;      //�޸�ԭջ��Ԫ�ص�diֵ 
            st.top++;                     //��һ�����߷����ջ 
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=1;
            maze[i][j]=-1;               //�����ظ��ߵ��÷��� 
        }
        else                             //û��·����������ջ 
        {
            maze[st.data[st.top].i][st.data[st.top].j]=2;  //��ĳ���鷢����·����,��2��������·����������� 
			st.top--;               //���÷�����ջ 
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
