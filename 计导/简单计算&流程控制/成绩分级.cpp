# include <stdio.h>
int main()

{
	int x;
	char A=65; char B=66; char C=67; char D=68; char E=69;
	scanf("%d",&x);
		
	if(x>=90)
	{
	 printf("%c",A);
	}
	
	else if(x>=80&&x<=89)
	{
     printf("%c",B);
	}
	
	else if(x>=70&&x<=79)
	{
     printf("%c",C);
	} 

    else if(x>=60&&x<=69)
	{
     printf("%c",D);
	} 
	
	else
    printf("%c",E);
	

	return 0;
	
}
