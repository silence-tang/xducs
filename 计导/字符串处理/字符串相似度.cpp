#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s1[100],s2[100],s[100];
	int i,j,k,len1,len2; float n;
	gets(s1); gets(s2); len1=strlen(s1); len2=strlen(s2);
      for(i=0,k=-1;i<len1;i++)
      {
      	 for(j=0;j<len2;j++)
		   {  
		      if((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z'))//�����Ӣ����ĸ 
		      {
		      	 if(s1[i]==s2[j]||abs(s1[i]-s2[j])==32)    //�����ִ�Сд 
		        {    k++; 
		      	     s[k]=s1[i];
		      	     break;
			    }

			  }
		      else                  //����Ӣ����ĸ 
		      {
		      	if(s1[i]==s2[j])    //�����ִ�Сд 
		        {    k++; 
		      	     s[k]=s1[i];
		      	     break;
			    }
		      	
			  }
		      
		   }
	  }                             //k+1�ʹ���s�ĳ��� 
	  n=2.0*(k+1)/(len1+len2);
	  printf("%.3f",n);
	  return 0;
}
