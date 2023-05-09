#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>                                     //λͼ�ṹ������Windows.hͷ�ļ��� 
//���û��ṩ���������в�����1.Ӧ�ó����� 2.����ͼƬ�ļ��� 3.Ҫ����Ϊ����ͼƬ�ļ���
int main(int* argc, char** argv)                         //���������в�����main����
{	

	FILE *fp1 = fopen("D:\\former.bmp", "rb");           //��ֻ����ʽ�򿪶������ļ����������ͼƬ�ļ���
	if (fp1 == NULL)
	{
		printf("\nerror on open %s file!",argv[1]);
		return 1;                                        //����ļ���ʧ�ܣ���ʾ��ʾ��Ϣ������1
	}
	
	int width, height, biBitCount;
	BITMAPFILEHEADER head1;                              //����bmp�ļ�ͷ���� 
	fread(&head1, sizeof(BITMAPFILEHEADER), 1, fp1);     //��head1�д��bmp�ļ�ͷ��Ϣ

	BITMAPINFOHEADER head2;                              //����bmp��Ϣͷ���� 
	fread(&head2, sizeof(BITMAPINFOHEADER), 1, fp1);     //��head2�д��bmp��Ϣͷ��Ϣ
	width = head2.biWidth;
	height = head2.biHeight;
	biBitCount = head2.biBitCount;                       //����������bmp��Ϣͷ�ṹ�е����� 
	printf("ԭͼ������: ��ȣ�%d �߶ȣ�%d λ����%d\n",width,height,biBitCount);
    //˵�����Ҷ�ͼ��biBitCount=8������ɫͼ��biBitCount=24��
    
	int lineByte = (biBitCount*width / 8 + 3) / 4 * 4;   //�����λͼ����ÿ��ռ���ٸ��ֽ�
	
	RGBQUAD *pColorTable;                                //�����ɫ��ָ��pColorTable
	pColorTable = new RGBQUAD[256];                      //�����ɫ�������ڴ�ռ� 
	fread(pColorTable, sizeof(RGBQUAD), 256, fp1);       //��pColorTable�д�ŵ�ɫ������ 
 
	unsigned char *pBmpBuf;
	pBmpBuf = new unsigned char[lineByte*height];        //����λͼ���������ڴ�ռ� 
	fread(pBmpBuf, lineByte*height, 1, fp1);             //��pBmpBuf�д��λͼ����
	fclose(fp1);                                         //�ɹ����ԭʼͼ�����Ϣ���ر�ͼ���ļ� 
	
	int i,j,k,greyvalue;                                 //����Ҷȷֲ� 
	double a[256] = {0};
	int b[256] = {0};
	for (i=0;i<height;i++)
	{
		for (j=0;j<width;j++)
		{
			greyvalue = *(pBmpBuf + i*lineByte + j);     //*(pBmpBuf + i*lineByte + j)����i��j�����صĻҶ�ֵ 
			a[greyvalue]++;                              //��ʱ����a������ԭͼ�Ҷȷֲ�
		}

	}

	for (i=0;i<256;i++)	                                 //���⻯����
		for(j=0;j<=i;j++)
			b[i] += a[j];                                //�׹�ʽ

	printf("���⻯֮��ĻҶȷֲ�Ϊ:\n");
	for(i=0;i<256;i++)
		{

			b[i] = int(255 * b[i] + 0.5);
			b[i] = round(b[i] / (width*height));
			printf("b[%d] = %d\n",i,b[i]);
//�׹�ʽ�����ڴ�ӡ������һ����ֵ����������һ��ֵ���ֵĴ������ڻҶ�ֵΪ��ֵ�����ص�ĸ���
		}

	unsigned char* pBmpBuf1;	                         //�õ���ͼ���λͼ����
	pBmpBuf1 = new unsigned char[lineByte*height];
	for (i=0; i<height;i++)
	{
		for (j=0;j<width;j++)
		{
			greyvalue = *(pBmpBuf + i*lineByte + j);
			*(pBmpBuf1 + i*lineByte + j) = b[greyvalue];
			
		}

	}
	
	FILE* fp2 = fopen("D:\\later.bmp", "wb");           //��ֻд��ʽ�򿪶������ļ���Ҫ���浽��ͼƬ�ļ��� 
	if (fp2 == NULL)
	{
		printf("\nerror on open %s file!",argv[2]);
		return 1;                                       //����ļ���ʧ�ܣ���ʾ��ʾ��Ϣ������1 
	}
	
	fwrite(&head1, sizeof(BITMAPFILEHEADER), 1, fp2);   //���µ�ͼ������ȫ��д����ͼ�� 
	fwrite(&head2, sizeof(BITMAPINFOHEADER), 1, fp2);
	fwrite(pColorTable, sizeof(RGBQUAD), 256, fp2);
	fwrite(pBmpBuf1, lineByte*height, 1, fp2);
	fclose(fp2);                                        //�������д�룬�ر��ļ� 

	system("pause");
	return 0;
}
