#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define BYTE unsigned char
#define logB(x, base) log(x)/log(base)
void sobel()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	double *tempImg = malloc(h*w*sizeof(double)); 
	int sobel_x[][3] = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };
	int sobel_y[][3] = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
	float temp_x, temp_y;
	float max = 0 ; 
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{	
			temp_x = 0;
			temp_y = 0;
			
				for (int l = -1; l < 2; l++)
				{
					for (int o = -1; o < 2; o++)
					{
						temp_x += (float)(sobel_x[1+l][o+1] * lnImg[(i + l)*w + (j + o)]);
						temp_y += (float)(sobel_y[l+1][o+1] * lnImg[(i + l)*w + (j + o)]);
						if (temp_x < 0)
							temp_x = -temp_x;
						if (temp_y < 0)
							temp_y = -temp_y;

					}
				}
				tempImg[i*w + j] = (double)(temp_x + temp_y); 
				if (max < tempImg[i*w + j])
					max = tempImg[i*w + j];
		}

	}
	printf("max : %f ", max);
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			outImg[i*w + j] = (BYTE)(tempImg[i*w + j] / (max) * 255);
			
		}

	}
	//핵심코드
	//히스토그램정렬
	int histogram[256] = { 0 };
	float cdf[256] = { 0 };
	BYTE threshold;
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[(int)outImg[i*w + j]] += 1;

	for (int i = 0; i < 256; i++)
		cdf[i] = (float)histogram[i] / (h*w);
	for (int i = 1; i < 256; i++)
	{
		cdf[i] += cdf[i - 1];
		if (cdf[i] <= 0.75) 
			threshold = i; 
	}
	//printf("문턱값 : %d\n", threshold);
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			if (outImg[i*w + j] <= threshold)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}

	}
	//히스토그램정렬
	FILE *outfile = fopen("lena_sobel.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
}
void nonlin_max()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	BYTE max;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			max = lnImg[i*w + j];
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					if (max < lnImg[(i + l)*w + j + o])
						max = lnImg[(i + l)*w + j + o];
				}
			}
			outImg[i*w + j] = max - lnImg[i*w + j];
		}

	}
	//핵심코드
	//히스토그램정렬
	int histogram[256] = { 0 };
	float cdf[256] = { 0 };
	BYTE threshold;
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[outImg[i*w + j]] += 1;

	for (int i = 0; i < 256; i++)
		cdf[i] = (float)histogram[i] / (h*w);
	for (int i = 1; i < 256; i++)
	{
		cdf[i] += cdf[i - 1];
		if (cdf[i] <= 0.75)
			threshold = i; 
	}
	printf("문턱값 : %d\n", threshold);
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			if (outImg[i*w + j] <= threshold)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}

	}
	//히스토그램정렬
	FILE *outfile = fopen("lena_max.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
}
void nonlin_min()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	BYTE min;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			min = lnImg[i*w + j];
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					if (min > lnImg[(i + l)*w + j + o])
						min = lnImg[(i + l)*w + j + o];
				}
			}
			outImg[i*w + j] = lnImg[i*w + j] - min;
		}

	}
	//핵심코드
	//히스토그램정렬
	int histogram[256] = { 0 };
	float cdf[256] = { 0 };
	BYTE threshold;
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[outImg[i*w + j]] += 1;

	for (int i = 0; i < 256; i++)
		cdf[i] = (float)histogram[i] / (h*w);
	for (int i = 1; i < 256; i++)
	{
		cdf[i] += cdf[i - 1];
		if (cdf[i] <= 0.75)
			threshold = i; 
	}
	printf("문턱값 : %d\n", threshold);
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			if (outImg[i*w + j] <= threshold)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}

	}
	//히스토그램정렬
	FILE *outfile = fopen("lena_min.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);

}
void nonlin_lapla()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	BYTE *outImg_2 = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	char * tempImg = malloc(h*w*sizeof(char));
	BYTE min, max;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			min = lnImg[i*w + j];
			max = lnImg[i*w + j];
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					if (min > lnImg[(i + l)*w + j + o])
						min = lnImg[(i + l)*w + j + o];
					if (max < lnImg[(i + l)*w + j + o])
						max = lnImg[(i + l)*w + j + o];
				}
			}
			tempImg[i*w + j] = max + min - 2 * lnImg[i*w + j];
		}

	}
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			if (tempImg[i*w + j] * tempImg[i*w + j + 1] < 0 || tempImg[i*w + j] * tempImg[i*w + j - 1] < 0)
			{
				if (tempImg[i*w + j] * tempImg[(i + 1)*w + j] < 0 || tempImg[i*w + j] * tempImg[(i - 1)*w + j] < 0)
					outImg[i*w + j] = 255;
			}
			else if (tempImg[i*w + j] = 0)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}
	}
	BYTE average; 
	BYTE average_;
	double tem_a;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			outImg_2[i*w + j] = outImg[i*w + j];
			tem_a = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					tem_a += lnImg[(i + l)*w + j + o];
				}
			}
			average = (BYTE)(tem_a / 25);
			tem_a = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					tem_a += (lnImg[(i + l)*w + j + o] - average) * (lnImg[(i + l)*w + j + o] - average);
				}
			}
			average_ = (BYTE)(tem_a / 25);
			if (average_ < average)
				outImg_2[i*w + j] = 255;
		}
	}
	//핵심코드
	FILE *outfile = fopen("lena_lap.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	FILE *outfile_2 = fopen("lena_lap_average.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile_2);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile_2);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile_2);
	fwrite(outImg_2, sizeof(char), hInfo.biSizeImage, outfile_2);
	fclose(outfile_2);
}
void entropy()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	double *tempImg = malloc(sizeof(double) * h* w);
	double *tempImg_2 = malloc(sizeof(double) * h* w);
	double temp;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			temp = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					temp += lnImg[(i + l)*w + j + o];
				}
			}
			//printf("%f\n", temp);
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					tempImg[(i+l)*w + j+o] =  lnImg[(i+l)*w + j+o]/temp;
				}
			}
			/*for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					printf("%lf ", tempImg[(i + l)*w + j + o]);
				}
				printf("\n");
			}*/
			tempImg_2[i*w + j] = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					tempImg_2[i *w + j] += tempImg[(i + l)*w + j + o] * logB(tempImg[(i + l)*w + j + o] , 2.0);
					tempImg_2[i*w + j] = -tempImg_2[i*w + j];
				}
			}
			if (tempImg_2[i*w + j] <= 0.2)
			{
				outImg[i*w + j] = 255;
			}
			else
				outImg[i*w + j] = 0;

		}

	}
	//핵심코드
	FILE *outfile = fopen("lena_entropy.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
}
void dp()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	BYTE *sumImg = malloc(hInfo.biSizeImage);
	double *tempImg = malloc(h*w*sizeof(double));
	double temp;
	BYTE max;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			temp = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					temp += lnImg[(i + l)*w + j + o];
				}
			}
			sumImg[i*w + j] = temp / 25;
			max = lnImg[i*w + j];
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					if (max < lnImg[(i + l)*w + j + o])
						max = lnImg[(i + l)*w + j + o];
				}
			}
			tempImg[i*w + j] = (double)(max - lnImg[i*w + j]) / (double)sumImg[i*w + j];
			//printf("%lf", tempImg[i*w + j]);
			if (tempImg[i*w + j] >=0.2)
				outImg[i*w + j] = 0;
			else
				outImg[i*w + j] = 255;
		}
	}

	//핵심코드
	FILE *outfile = fopen("lena_dp.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
}
void dip()
{
	FILE *infile;

	if ((infile = fopen("lena.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	BYTE *sumImg = malloc(hInfo.biSizeImage);
	double *tempImg = malloc(h*w*sizeof(double));
	double temp;
	BYTE max;
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			temp = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					temp += lnImg[(i + l)*w + j + o];
				}
			}
			sumImg[i*w + j] = temp / 25;
			max = lnImg[i*w + j];
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					if (max < lnImg[(i + l)*w + j + o])
						max = lnImg[(i + l)*w + j + o];
				}
			}
			tempImg[i*w + j] = (double)sumImg[i*w + j] / (double)lnImg[i*w + j] - (double)sumImg[i*w + j] / (double)max;
			//printf("%lf", tempImg[i*w + j]);
			if (tempImg[i*w + j] >= 0.2)
				outImg[i*w + j] = 0;
			else
				outImg[i*w + j] = 255;
		}
	}

	//핵심코드
	FILE *outfile = fopen("lena_dip.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
}
void corner()
{
	FILE *infile;

	if ((infile = fopen("ctest.bmp", "rb")) == NULL) {
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
	BYTE *outImg = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	int sobel_x[][3] = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };
	int sobel_y[][3] = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
	double *xImg = malloc(sizeof(double) * h*w);
	double *yImg = malloc(sizeof(double) * h*w);
	double *xyImg = malloc(sizeof(double) * h*w);
	double *xImg_a = malloc(sizeof(double) * h*w);
	double *yImg_a = malloc(sizeof(double) * h*w);
	double *xyImg_a = malloc(sizeof(double) * h*w);
	double *dImg = malloc(sizeof(double) * h*w);
	double temp_x, temp_y;
	double x, y, xy;
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			temp_x = 0;
			temp_y = 0;

			for (int l = -1; l < 2; l++)
			{
				for (int o = -1; o < 2; o++)
				{
					temp_x += (double)(sobel_x[l+1][o+1] * lnImg[(i + l)*w + (j + o)]);
					temp_y += (double)(sobel_y[l+1][o+1] * lnImg[(i + l)*w + (j + o)]);
					if (temp_x < 0)
						temp_x = -temp_x;
					if (temp_y < 0)
						temp_y = -temp_y;
				}
			}
;			xImg[i*w + j] = temp_x*temp_x;
			yImg[i*w + j] = temp_y*temp_y;
			xyImg[i*w + j] = temp_x*temp_y;
		}

	}
	for (int i = 2; i < h - 2; i++)
	{
		for (int j = 2; j < w - 2; j++)
		{
			x = 0;
			y = 0;
			xy = 0;
			for (int l = -2; l < 3; l++)
			{
				for (int o = -2; o < 3; o++)
				{
					x += xImg[(i + l) *w + j + o];
					y += yImg[(i + l) *w + j + o];
					xy += xyImg[(i + l) *w + j + o];
				}
			}
			xImg_a[i*w + j] = x / 25;
			yImg_a[i*w + j] = y / 25;
			xyImg_a[i*w + j] = xy / 25;
			dImg[i*w + j] = (xImg_a[i*w + j] * yImg_a[i*w + j]) - (xyImg_a[i*w + j] * xyImg_a[i*w + j]) - 0.05*((xImg_a[i*w + j] + yImg_a[i*w + j])*(xImg_a[i*w + j] + yImg_a[i*w + j]));
			if (dImg[i*w + j] >0.01)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}
	}
	//핵심코드
	FILE *outfile = fopen("ctest_corner.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);

}
int main(void)
{
	sobel();
	nonlin_max();
	nonlin_min();
	nonlin_lapla();
	entropy();
	dp();
	dip();
	corner();
}