#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	const int N=n;
      struct list{
		char num[6];
		char name[14];
		int a[3];
		float aver;
	};
	struct list stu[N];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%s",stu[i].num);
		scanf("%s",stu[i].name);
		for(j=0;j<3;j++) scanf("%d",&stu[i].a[j]);
	}
	for(i=0;i<n;i++) stu[i].aver=(stu[i].a[0]+stu[i].a[1]+stu[i].a[2])/3.0;
	struct list temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(stu[j].aver<stu[j+1].aver){
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++) printf("%s %s %.1f\n",stu[i].num,stu[i].name,stu[i].aver);
	return 0;
}
