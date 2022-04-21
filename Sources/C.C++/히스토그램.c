#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define BYTE unsigned char

void histogram_equalization(void)
{
	FILE *infile;

	if ((infile = fopen("chest.bmp", "rb")) == NULL) {
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
	int histogram[256] = { 0 };
	float cdf[256] = { 0 };
	for (int i = 0; i < hInfo.biHeight; i++)	
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[lnImg[i*w + j]] += 1;
		
	for (int i = 0; i < 256; i++)
		cdf[i] = (float)histogram[i]/(h*w);
	for (int i = 1; i < 256; i++)
		cdf[i] += cdf[i - 1];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			lnImg[i*w + j] = (int)(cdf[lnImg[i*w + j]] * 255) + 0.5; 
	//핵심코드
	FILE *outfile = fopen("chest_e.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lnImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
}
void histogram_specification()
{
	FILE *infile;
	if ((infile = fopen("Room.bmp", "rb")) == NULL) {
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
	double d_cdf[256] = { 0 };
	int histogram[256] = { 0 };
	double cdf[256] = { 0 };
	int k = 0;
	for (int i = 0; i < 256; i++)
	{
		d_cdf[i] =  2*i/(double)65025;	//printf("%lf ", d_cdf[i]); 
	}
	for (int i = 1; i < 256; i++)
	{
		d_cdf[i] += d_cdf[i - 1]; //printf("%lf ", d_cdf[i]);
	}
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[lnImg[i*w + j]] += 1; 

	for (int i = 0; i < 256; i++)
		cdf[i] = (double)histogram[i] / (h*w);
	for (int i = 1; i < 256; i++)
		cdf[i] += cdf[i - 1];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{ //i행 j열의 픽셀에서
			for (int v = k; v < 256;v++)
			{ //해당밝기의 cdf를 알아내 작거나 같을 경우 변경
				if (cdf[lnImg[i*w + j]] < d_cdf[v] || cdf[lnImg[i*w + j]] == d_cdf[v])
				{
					outImg[i*w + j] = v; break;
				} // 변경후 더이상의 반복이 필요없어서 빠져나옴

			}
		}
	}
	//핵심코드
	FILE *outfile = fopen("Room_s.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);


}
int main(void)
{
	//histogram_equalization();
	histogram_specification();
}