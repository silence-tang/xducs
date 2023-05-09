#include<stdio.h>
#include<windows.h> 
int main()
{
	printf("子进程开始运行...\n\n");
	const char *something = "这是一句话。";
	FILE *fp;
	if(fp = fopen("D:\\test.txt","w+"))//以可读写方式打开文件
	{
		printf("文件打开成功!\n\n");
		fwrite(something,strlen(something),1,fp);//将something写入文件中 
		fwrite("\n这是另一句话。",strlen("\n这是另一句话。"),1,fp);//将另一句话写入文件中 
		printf("写入数据成功!\n\n");
		fclose(fp);//关闭文件 
 		fp = fopen("D:\\test.txt","r");//以只读方式打开文件 
 		printf("当前文件中的内容如下：\n");
		char ch=fgetc(fp);//取第一个字符 
		while(ch!=EOF)//当该字符不为文件结束标志时 
		{
			putchar(ch);//输出该字符 
			ch=fgetc(fp);//继续从文件中获取字符 
		}
		fclose(fp);//关闭文件 
	}
	else
		printf("创建文件失败!\n");
	printf("\n\n");
	system("pause");
	return 0;
}
