#include<stdio.h>
#include<windows.h> 
int main()
{
	printf("�ӽ��̿�ʼ����...\n\n");
	const char *something = "����һ�仰��";
	FILE *fp;
	if(fp = fopen("D:\\test.txt","w+"))//�Կɶ�д��ʽ���ļ�
	{
		printf("�ļ��򿪳ɹ�!\n\n");
		fwrite(something,strlen(something),1,fp);//��somethingд���ļ��� 
		fwrite("\n������һ�仰��",strlen("\n������һ�仰��"),1,fp);//����һ�仰д���ļ��� 
		printf("д�����ݳɹ�!\n\n");
		fclose(fp);//�ر��ļ� 
 		fp = fopen("D:\\test.txt","r");//��ֻ����ʽ���ļ� 
 		printf("��ǰ�ļ��е��������£�\n");
		char ch=fgetc(fp);//ȡ��һ���ַ� 
		while(ch!=EOF)//�����ַ���Ϊ�ļ�������־ʱ 
		{
			putchar(ch);//������ַ� 
			ch=fgetc(fp);//�������ļ��л�ȡ�ַ� 
		}
		fclose(fp);//�ر��ļ� 
	}
	else
		printf("�����ļ�ʧ��!\n");
	printf("\n\n");
	system("pause");
	return 0;
}
