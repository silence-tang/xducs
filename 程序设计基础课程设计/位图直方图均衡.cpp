#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>                                     //位图结构储存在Windows.h头文件中 
//由用户提供三个命令行参数：1.应用程序名 2.待理图片文件名 3.要保存为的新图片文件名
int main(int* argc, char** argv)                         //带有命令行参数的main函数
{	

	FILE *fp1 = fopen("D:\\former.bmp", "rb");           //以只读方式打开二进制文件（待处理的图片文件）
	if (fp1 == NULL)
	{
		printf("\nerror on open %s file!",argv[1]);
		return 1;                                        //如果文件打开失败，显示提示信息并返回1
	}
	
	int width, height, biBitCount;
	BITMAPFILEHEADER head1;                              //定义bmp文件头变量 
	fread(&head1, sizeof(BITMAPFILEHEADER), 1, fp1);     //在head1中存放bmp文件头信息

	BITMAPINFOHEADER head2;                              //定义bmp信息头变量 
	fread(&head2, sizeof(BITMAPINFOHEADER), 1, fp1);     //在head2中存放bmp信息头信息
	width = head2.biWidth;
	height = head2.biHeight;
	biBitCount = head2.biBitCount;                       //定义变量存放bmp信息头结构中的数据 
	printf("原图像数据: 宽度：%d 高度：%d 位数：%d\n",width,height,biBitCount);
    //说明：灰度图像（biBitCount=8），彩色图像（biBitCount=24）
    
	int lineByte = (biBitCount*width / 8 + 3) / 4 * 4;   //计算出位图数据每行占多少个字节
	
	RGBQUAD *pColorTable;                                //定义调色板指针pColorTable
	pColorTable = new RGBQUAD[256];                      //申请调色板所需内存空间 
	fread(pColorTable, sizeof(RGBQUAD), 256, fp1);       //在pColorTable中存放调色板数据 
 
	unsigned char *pBmpBuf;
	pBmpBuf = new unsigned char[lineByte*height];        //申请位图数据所需内存空间 
	fread(pBmpBuf, lineByte*height, 1, fp1);             //在pBmpBuf中存放位图数据
	fclose(fp1);                                         //成功获得原始图像的信息，关闭图像文件 
	
	int i,j,k,greyvalue;                                 //计算灰度分布 
	double a[256] = {0};
	int b[256] = {0};
	for (i=0;i<height;i++)
	{
		for (j=0;j<width;j++)
		{
			greyvalue = *(pBmpBuf + i*lineByte + j);     //*(pBmpBuf + i*lineByte + j)代表i行j列像素的灰度值 
			a[greyvalue]++;                              //此时数组a保存了原图灰度分布
		}

	}

	for (i=0;i<256;i++)	                                 //均衡化过程
		for(j=0;j<=i;j++)
			b[i] += a[j];                                //套公式

	printf("均衡化之后的灰度分布为:\n");
	for(i=0;i<256;i++)
		{

			b[i] = int(255 * b[i] + 0.5);
			b[i] = round(b[i] / (width*height));
			printf("b[%d] = %d\n",i,b[i]);
//套公式，对于打印出来的一列数值，其中任意一个值出现的次数等于灰度值为该值的像素点的个数
		}

	unsigned char* pBmpBuf1;	                         //得到新图像的位图数据
	pBmpBuf1 = new unsigned char[lineByte*height];
	for (i=0; i<height;i++)
	{
		for (j=0;j<width;j++)
		{
			greyvalue = *(pBmpBuf + i*lineByte + j);
			*(pBmpBuf1 + i*lineByte + j) = b[greyvalue];
			
		}

	}
	
	FILE* fp2 = fopen("D:\\later.bmp", "wb");           //以只写方式打开二进制文件（要保存到的图片文件） 
	if (fp2 == NULL)
	{
		printf("\nerror on open %s file!",argv[2]);
		return 1;                                       //如果文件打开失败，显示提示信息并返回1 
	}
	
	fwrite(&head1, sizeof(BITMAPFILEHEADER), 1, fp2);   //把新的图像数据全部写入新图像 
	fwrite(&head2, sizeof(BITMAPINFOHEADER), 1, fp2);
	fwrite(pColorTable, sizeof(RGBQUAD), 256, fp2);
	fwrite(pBmpBuf1, lineByte*height, 1, fp2);
	fclose(fp2);                                        //完成数据写入，关闭文件 

	system("pause");
	return 0;
}
