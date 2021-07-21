#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define BYTE unsigned char
void filter()
{
	FILE *infile;

	if ((infile = fopen("pentagon.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

	// BMP Header Information
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, infile);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, infile);
	RGBQUAD hRGB[256];
	fread(hRGB, sizeof(RGBQUAD), 256, infile);
	BYTE *lnImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//�ٽ��ڵ�
	int* outImg = malloc(h*w*sizeof(int));
	int *temp = malloc(h*w*sizeof(int));
	BYTE *low = malloc(hInfo.biSizeImage);
	int histogram[3][256] = { 0 };//0 : ���� ������׷� , 1 : ��� ������׷� , 2 : �����н����� 
	double cdf[256] = { 0 };
	double d_cdf[256] = { 0 };
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i*w + j] = lnImg[i*w + j];
		}
	} //���ϱ�� �̹���
	for (int i = 0; i < h; i++)
	{
		for (int j = 1; j < w; j++)
		{
			outImg[i*w + j] += outImg[i*w + j - 1];
		}
	} 
	for (int j = 0; j < w; j++)
	{
		for (int i = 1; i < h; i++)
		{
			outImg[i*w + j] += outImg[(i - 1)*w + j];
		}
	} // ���ϱ� �Ϸ�
	for (int i = 5; i < h; i++)
	{
		for (int j = 5; j < w; j++)
		{
			temp[(i - 2)*w + (j - 2)] = outImg[i*w + j] + outImg[(i - 5)*w + (j - 5)] - (outImg[(i - 5)*w + j] + outImg[i*w + j - 5]);
			temp[(i - 2)*w + (j - 2)] = temp[(i - 2)*w + j - 2] / (5*5);
			low[(i - 2)*w + (j - 2)] = (unsigned char)temp[(i - 2)*w + (j - 2)];
		}
	} //�����̹����� ���
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[0][lnImg[i*w + j]] += 1;
		
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[1][low[i*w + j]] += 1;
	for (int i = 0; i < 256; i++)
		histogram[2][i] = histogram[0][i] - histogram[1][i];
		//printf("%d\n", histogram[2][i]);
	for (int i = 0; i < 256; i++)
	{
		d_cdf[i] = (double)(histogram[0][i]) +(double)( 0.3* histogram[2][i]);
		
	}
	for (int i = 0; i < 256; i++)
	{
		d_cdf[i] /= (double)h * w;	
	}
	for (int i = 1; i < 256; i++)
	{
		d_cdf[i] += d_cdf[i - 1]; //printf("%f\n", d_cdf[i]);
	}

	for (int i = 0; i < 256; i++)
		cdf[i] = (double)histogram[0][i] / (h*w);
	for (int i = 1; i < 256; i++)
		cdf[i] += cdf[i - 1];
	int k = 0;
	for (int i = 2; i < h-2;i++)
	{
		for (int j = 2; j < w-2;j++)
		{ //i�� j���� �ȼ�����
			for (int v = k; v < 256; v++)
			{ //�ش����� cdf�� �˾Ƴ� �۰ų� ���� ��� ����
				if (cdf[lnImg[i*w + j]] < d_cdf[v] || cdf[lnImg[i*w + j]] == d_cdf[v])
				{
					lnImg[i*w + j] = v;  break;
				} // ������ ���̻��� �ݺ��� �ʿ��� ��������
				
			}
		}
	}
	//�ٽ��ڵ�
	FILE *outfile = fopen("pentagon_s.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lnImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(low);
}
int main(void)
{
	filter();
}