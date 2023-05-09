#include<stdio.h>
#include<string.h>
struct student
{
	int num;
	int total;
	int attd;
	int work;
};
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	struct student stu[n];
	    for(i=0;i<n;i++)
	      {
	      	scanf("%d %d %d %d",&stu[i].num,&stu[i].total,&stu[i].attd,&stu[i].work);	      	
	      	if(stu[i].attd/stu[i].total<=0.75&&stu[i].work/stu[i].total<=0.5)
	      	count++;
		  }
	if(count==0) printf("No");
	else
	{   printf("%d\n",count);
		for(i=0;i<n;i++)
	      {
	      	
	      	if(stu[i].attd/stu[i].total<=0.75&&stu[i].work/stu[i].total<=0.5)
            printf("%d\n",stu[i].num);
		  }
		  
	}
	return 0;
}
