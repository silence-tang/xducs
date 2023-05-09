#include<stdio.h>
int H[100]={0};  //ȫ�ֱ��������㺯���ڵ��� 
int m, p, i, j;  //ȫ�ֱ��������㺯���ڵ��� 

int IsInHashTable(int n)
{
	int flag = 0;
	for(i=0;i<m;i++)
	{
		if(H[i] == n)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

void Insert(int n)
{
	int loc,temp;
	loc = n % p;
	if(H[loc] == 0)           //��λ��locδ��ռ�� 
	{
	 
		H[loc] = n;
		printf("%d\n",loc);   //��ӡ��ǰ����λ�� 
	}
	else                      //��λ��loc��ռ�ã���������̽����ɢ�н����ͻ 
	{
		for(i=1;i<m;i++)
		{
			temp = (loc + i) % m;     //ע�⣬����mod�Ǳ� 
			if(H[temp] == 0)          //�ҵ��˿�λ�� 
			{
				H[temp] = n;
				printf("%d\n",temp);  //��ӡ��ǰ����λ�� 
				break;                //����ѭ�� 
			}
		}
	}
}

int NumOfElem()  //ͳ�ƹ�ϣ����Ԫ�ظ��� 
{
	int num = 0;
	for(i=0;i<m;i++)
	{
		if(H[i] != 0)
			num++;
	}
	return num;
}

int LocateNum(int n)  //����n�ڹ�ϣ���е�λ�� 
{
	int loc;
	for(i=0;i<m;i++)
	{
		if(H[i] == n)
		{
			loc = i;
			break;
		}	
	}
	return loc;
}

int main()
{
	int n;
	scanf("%d %d",&m,&p);
	while(scanf("%d",&n) && n != -1)  //��n��Ϊ-1ʱѭ�����룬ÿ����һ��n����һ����ز��� 
	{
		if(IsInHashTable(n))          //��n�ڹ�ϣ���� 
			printf("%d\n",LocateNum(n));
		else                          //��n���ڹ�ϣ���� 
		{
			if(NumOfElem() == m - 1)  //����ǰ��ϣ���йؼ��ֵĸ�������m-1 
			{
				printf("Table full");
				return 0;             //������� 
			}
			else                      //����ǰ��ϣ���йؼ��ֵĸ���������m-1 
			{
				Insert(n);            //���ؼ��ֲ����ϣ��,������ùؼ��ֲ����ڹ�ϣ���е�λ�� 
			}
		}
	}
	return 0;
}

