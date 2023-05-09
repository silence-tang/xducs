#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct STU
{
	char name[20];
	int score,age;
}stu[100];

bool compare(STU stu1, STU stu2)
{
	if(stu1.score!=stu2.score)
		return stu1.score>stu2.score;
	else if(strcmp(stu1.name,stu2.name)!=0)
		return strcmp(stu1.name,stu2.name)<0;
	else
		return stu1.age<stu2.age;
}

int main()
{
	int n,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s %d %d",stu[i].name,&stu[i].age,&stu[i].score);
	sort(stu,stu+n,compare);
	for(i=0;i<n;i++)
		printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
	return 0;
}
