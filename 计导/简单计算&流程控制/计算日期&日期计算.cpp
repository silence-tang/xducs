#include<stdio.h>
int main()
	{
		int years,days;
		scanf("%d %d",&years,&days);
		if(years%4==0&&years%100!=0||years%400==0)
		{
			if(days<=31){printf("1 %d",days);}
			if(days<=60&&days>31){printf("2 %d",days-31);}
			if(days<=91&&days>60){printf("3 %d",days-60);}
			if(days<=121&&days>91){printf("4 %d",days-91);}
			if(days<=152&&days>121){printf("5 %d",days-121);}
			if(days<=182&&days>152){printf("6 %d",days-152);}
			if(days<=213&&days>182){printf("7 %d",days-182);}
			if(days<=244&&days>213){printf("8 %d",days-213);}
			if(days<=274&&days>244){printf("9 %d",days-244);}
			if(days<=305&&days>274){printf("10 %d",days-274);}
			if(days<=335&&days>305){printf("11 %d",days-305);}
			if(days<=366&&days>335){printf("12 %d",days-335);}
		}
		else
		{
			if(days<=31){printf("1 %d",days);}
			if(days<=59&&days>31){printf("2 %d",days-31);}
			if(days<=90&&days>59){printf("3 %d",days-59);}
			if(days<=120&&days>90){printf("4 %d",days-90);}
			if(days<=151&&days>120){printf("5 %d",days-120);}
			if(days<=181&&days>151){printf("6 %d",days-151);}
			if(days<=212&&days>181){printf("7 %d",days-181);}
			if(days<=243&&days>212){printf("8 %d",days-212);}
			if(days<=273&&days>243){printf("9 %d",days-243);}
			if(days<=304&&days>273){printf("10 %d",days-273);}
			if(days<=334&&days>304){printf("11 %d",days-304);}
			if(days<=365&&days>334){printf("12 %d",days-334);}
		}
	}
