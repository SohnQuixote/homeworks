#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define logB(x, base) log(x)/log(base)
#define BYTE unsigned char
void iterative()
{
	FILE *infile;

	if ((infile = fopen("hand.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

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
	int histogram[256] = { 0 };
	int thresholding = 127,prev =0;
	int u_1 =0, u_2 =0;
	int dev_1, dev_2;
	for (int i = 0; i < hInfo.biHeight; i++)
		for (int j = 0; j < hInfo.biWidth; j++)
			histogram[lnImg[i*w + j]] += 1;
	while (prev != thresholding)
	{
		u_1 = 0; u_2 = 0;
		prev = thresholding;
		dev_1 = 0; dev_2 = 0;
		for (int i = 0; i < 256; i++)
		{
			if (i <= thresholding)
			{
				u_1 += i*histogram[i];
				dev_1 += histogram[i];
			}
				
			else
			{
				u_2 += i*histogram[i];
				dev_2 += histogram[i];
			}
				
		}
		u_1 /= dev_1;
		u_2 /= dev_2;
		thresholding = (u_1 + u_2) / 2;
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (lnImg[i*w + j] > thresholding)
				outImg[i*w + j] = 0;
			else
				outImg[i*w + j] = 255;
		}
	}
	//핵심코드
	FILE *outfile = fopen("hand_iterative.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
}
void otsu()
{
	FILE *infile;

	if ((infile = fopen("hand.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

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
	double h_, w_;
	h_ = (double)h;
	w_ = (double)w;
	int histogram[256] = { 0 };
	double p_1, p_t,p_2 ,p; //p_2는 1-p_1
	double sigma[256]; //여기서 최댓값 도출 
	double u_1, u_2,u_t,u;
	double max =0;
	int thresholding;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			histogram[lnImg[i*w + j]] += 1;
	p_t = histogram[0] / (h_*w_);
	u_t = 0;
	u = 0;
	for (int i = 0; i < 256; i++)
	{
		u += i* histogram[i];
	}
	u /= (h * w);
	for (int t = 1; t < 256; t++)
	{
		p_1 = histogram[t]/ (h_*w_);
		p = p_1;
		p_1 += p_t;
		
		p_2 = 1 - p_1;
		u_1 = ((p_t*u_t) + t*p) / p_1;
		u_2 = (u - p_1*u_1) / p_2;

		sigma[t] = p_1*p_2*(u_1-u_2)*(u_1-u_2);

		if (max < sigma[t] )
		{
			max = sigma[t];
			thresholding = t;
		}
		u_t = u_1;
		p_t = p_1;
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (lnImg[i*w + j] > thresholding)
				outImg[i*w + j] = 0;
			else
				outImg[i*w + j] = 255;
		}
	}
	/*for (int i = 0; i < 256; i++)
	{
		printf("l%f\n", sigma[i]);
	}*/
	//핵심코드
	FILE *outfile = fopen("hand_otsu.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);
}
void kapur()
{
	FILE *infile;

	if ((infile = fopen("hand.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

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
	int histogram[256] = { 0 };
	double h_, w_;
	h_ = (double)h;
	w_ = (double)w;
	double h_1=0, h_2=0, max = 0;
	int thresholding;
	int div = 0; 
	double p;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			histogram[lnImg[i*w + j]] += 1;
	
	for (int t = 1; t < 255; t++)
	{
		div = 0;
		for (int i = 0; i <= t; i++)
		{
			div += histogram[i];
		}
		//printf("%d\n", div);
		h_1 = 0;
		
		for (int i = 0; i <= t; i++)
		{
			if (histogram[i] != 0)
			{
			
			p = (double)histogram[i] / (double)div;
			h_1 += -(double)((p)*logB(p, 2.0));

		}
			//printf("%lf\n", histogram[i] / div);
		}
		div = 0;
		for (int i = t + 1; i < 256; i++)
		{
			div += histogram[i];
		}
		if (div == 0)
			break;
		h_2 = 0;
		for (int i = t + 1; i < 256; i++)
		{
			if (histogram[i] != 0)
			{
				p = (double)histogram[i] / (double)div;
				h_2 += -(double)((p)*logB(p, 2.0));

			}
		}
		//printf("%f , %f \n", h_1, h_2);
		if (max < (h_1 + h_2))
		{
			max = h_1 + h_2;
			thresholding = t;
		}
	}
	printf("%d\n", thresholding);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (lnImg[i*w + j] <= thresholding)
				outImg[i*w + j] = 255;
			else
				outImg[i*w + j] = 0;
		}

	}
	//핵심코드
	FILE *outfile = fopen("hand_kapur.bmp", "wb");
	fwrite(&hf, sizeof(BITMAPFILEHEADER), 1, outfile);
	fwrite(&hInfo, sizeof(BITMAPINFOHEADER), 1, outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(outImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);
	free(lnImg);
	free(outImg);
}
void efficient_two_pass()
{
	FILE *infile;

	if ((infile = fopen("hand_iterative.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, infile);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, infile);
	RGBQUAD hRGB[256];
	fread(hRGB, sizeof(RGBQUAD), 256, infile);
	BYTE *lnImg = malloc(hInfo.biSizeImage);
	BYTE *outImg = malloc(hInfo.biSizeImage);
	BYTE *label = malloc(hInfo.biSizeImage);
	fread(lnImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	const long w = hInfo.biWidth; const long h = hInfo.biHeight;
	//핵심코드
	int label_ = 1;
	for (int i = 0; i < h; i++)
		for (int j = 1; j < w ; j++)
			label[i*w + j] = 0;
	for (int i = 0; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			if (lnImg[i*w + j] == 0)
			{
				if (label[i*w + j] == 0)
				{
					label[i*w + j] = label_;
					label_++;
				}
				//배경은 배당할필요없음
				if (lnImg[(i + 1)*w+j-1] == 0 )
				{
					label[(i + 1)*w + j - 1] = label[i*w + j];
				}
				if (lnImg[(i + 1)*w + j ] == 0 )
				{
					label[(i + 1)*w + j ] = label[i*w + j];
				}
				if (lnImg[(i + 1)*w + j + 1] == 0 )
				{
					label[(i + 1)*w + j +1] = label[i*w + j];
				}
				if (lnImg[i*w + j + 1] == 0 )
				{
					label[i*w + j +1] = label[i*w + j];
				}	
			}
		}
	}
	for (int i = h; i > 0; i--)
	{
		for (int j = w-2; j >0; j--)
		{
			if (lnImg[i*w + j] == 0)
			{
				if (label[i*w + j] == 0)
				{
					label[i*w + j] = label_;
					label_++;
				}
				//배경은 배당할필요없음
				if (lnImg[(i- 1)*w + j + 1] == 0)
				{
					label[(i -1)*w + j + 1] = label[i*w + j];
				}
				if (lnImg[(i -1)*w + j] == 0)
				{
					label[(i - 1)*w + j] = label[i*w + j];
				}
				if (lnImg[(i - 1)*w + j - 1] == 0)
				{
					label[(i -1)*w + j -1] = label[i*w + j];
				}
				if (lnImg[i*w + j - 1] == 0)
				{
					label[i*w + j - 1] = label[i*w + j];
				}
			}
		}
	}
	int max=0, max_=0;
	int ind, ind_;
	int pointer[2000];
	for (int i = 0; i < label_; i++)
		pointer[i] = 0;
	for (int i = 1; i < h-1; i++)
		for (int j = 1; j < w-1 ; j++)
			pointer[(int)label[i*w + j]] += 1;

	//최대 인덱스값 두개
	for (int i = 1; i < label_; i++)
	{
		if (max < pointer[i])
		{
			max = pointer[i];
			ind = i;
		}
		if (max_ < pointer[i] && pointer[i] < max)
		{
			max_ = pointer[i];
			ind_ = i;
		}
	}
	for (int i = 1; i < h-1; i++)
	{

		for (int j = 1; j < w-1 ; j++)
		{
			if (label[i*w + j] == ind_ || label[i*w + j] == ind)
				outImg[i*w + j] = 0;
			else
				outImg[i*w + j] = 255;
		}
	}
	//핵심코드
	FILE *outfile = fopen("hand_seperation.bmp", "wb");
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
	//iterative();
	//otsu();
	//kapur();
	efficient_two_pass();
}