#include<stdio.h>
struct student
{
	int num;
	char name[20];
	int score1;
	int score2;
	int score3;
	float aver;
};
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	struct student stu[n];	struct student temp;
	for(i=0;i<n;i++)
	  scanf("%d %s %d %d %d",&stu[i].num,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
         for(i=0;i<n;i++)
		 {
		 	stu[i].aver=(stu[i].score1+stu[i].score2+stu[i].score3)/3.0;
		 }	
	for(i=0;i<n-1;i++)
	{
	    k=i;
		for(j=i+1;j<n;j++)
		{
			if(stu[j].aver>stu[k].aver)
			{
				k=j;
				temp=stu[k];stu[k]=stu[i];stu[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	  printf("%d %s %f\n",stu[i].num,stu[i].name,stu[i].aver);	

	return 0;
}
