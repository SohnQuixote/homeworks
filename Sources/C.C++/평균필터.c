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

	if ((infile = fopen("snow.bmp", "rb")) == NULL) {
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
	//핵심코드
	int filter_size = 21;
	BYTE *outImg = malloc(hInfo.biSizeImage);
	int *temp = malloc(w*h*sizeof(int));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i*w + j] = lnImg[i*w + j]; 
			//temp[i*w + j] = (int)outImg[i*w+j];
		}
	}
	for (int i = filter_size/2; i < h - filter_size/2; i++)
	{
		for (int j = filter_size/2; j < w - filter_size/2; j++)
		{	
			temp[i*w + j] = 0;
			for (int k = i - filter_size/2; k < i + filter_size/2+1; k++)
			{
				for (int l = j - filter_size/2; l < j + filter_size/2+1; l++)
				{
					temp[i*w + j] +=lnImg[k *w + l]; //	printf("%d \n", temp[i*w + j]);
				}
			}
			temp[i*w + j] /= filter_size*filter_size;
			outImg[i*w + j] = (unsigned char)temp[i*w+j];
		}
	}
	//핵심코드
	FILE *outfile = fopen("Snow_s.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);
}
void filter_s()
{
	FILE *infile;

	if ((infile = fopen("Snow.bmp", "rb")) == NULL) {
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
	long w = hInfo.biWidth; long h = hInfo.biHeight;
	//핵심코드
	BYTE *outImg = malloc(hInfo.biSizeImage);
	int *temp = malloc(h*w*sizeof(int));
	int *temp_ = malloc(h*w*sizeof(int));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i*w + j] = lnImg[i*w + j]; 
		}
	}
	for (int i = 0; i < h; i++)
	{ 
		if (i > h) break;
		for (int j = 10; j < w - 10; j++)
		{
			temp[i*w + j] = 0;
			for (int l = j - 10; l < j + 11; l++)
			{
				temp[i*w + j] += lnImg[i*w + l];
			}
			temp[i*w + j] /= 21;
		}
	}

	for (int j = 10; j < w -10; j++)
	{
		for (int i = 10; i < h-10; i++)
		{
			temp_[i*w + j] = 0;
			for (int l = i - 10; l < i + 11; l++)
			{
				temp_[i*w + j] += temp[l*w + j ];
			}
			temp_[i*w + j] /= 21;
			outImg[i*w + j] = (unsigned char)temp_[i*w + j];
		}
	}



	//핵심코드
	FILE *outfile = fopen("Snow_s_.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);
}
void integral()
{
	FILE *infile;

	if ((infile = fopen("Snow.bmp", "rb")) == NULL) {
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
	long w = hInfo.biWidth; long h = hInfo.biHeight;
	//핵심코드
	int *outImg = malloc(h*w*sizeof(int));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i*w + j] = lnImg[i*w + j];
		}
	}
	// 인트형에다가 복사
	for (int i = 0; i < h; i++)
	{
		for (int j = 1; j < w;j++)
		{
			//printf("%d\n", outImg[i*w + j]);
			outImg[i*w + j] += outImg[i*w + j - 1];
			//printf("%d\n", outImg[i*w + j]);

		}
		

	}
	for (int j = 0; j < w; j++)
	{
		for (int i = 1; i < h;i ++)
		{
			outImg[i*w + j] += outImg[(i-1)*w + j ];
		}


	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			lnImg[i*w+j] = (unsigned char)outImg[i*w + j];
		}
	} //0~255로 정규화

	//핵심코드
	FILE *outfile = fopen("Snow_i.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lnImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);



}
void filter_i()
{
	FILE *infile;

	if ((infile = fopen("Snow.bmp", "rb")) == NULL) {
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
	long w = hInfo.biWidth; long h = hInfo.biHeight;
	//핵심코드
	int* outImg = malloc(h*w*sizeof(int));
	int *temp = malloc(h*w*sizeof(int));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i*w + j] = lnImg[i*w + j];
		}
	}
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
	}
	for (int i = 21; i < h; i++)
	{
		for (int j = 21; j < w;j++)
		{
				temp[(i - 10)*w + (j - 10)] = outImg[i*w + j] + outImg[(i - 21)*w + (j - 21)] - (outImg[(i - 21)*w + j] + outImg[i*w + j - 21]);
				temp[(i - 10)*w + (j - 10)] = temp[(i - 10)*w + j - 10] /( 21 * 21);
				lnImg[(i - 10)*w + (j - 10)] = (unsigned char)temp[(i - 10)*w + (j - 10)];
		}
	}






	//핵심코드
	FILE *outfile = fopen("Snow_if.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lnImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);




}

int main(void)
{
	float difference[3];
	time_t start, finish;

	start = clock();
	filter();
	finish = clock();
	difference[0] = (float)(finish - start);

	start = clock();
	filter_s();
	finish = clock();
	difference[1] = (float)(finish - start);

	//integral();
	
	start = clock();
	filter_i();
	finish = clock();
	difference[2] = (float)(finish - start);

	for (int i = 0; i < 3; i++)
	{
		printf(" 걸린시간 : %f초\n", difference[i] / CLOCKS_PER_SEC); //21*21 ,분할, 적분 순으로 시간이 짧게드는걸 알 수 있다.
	}
}