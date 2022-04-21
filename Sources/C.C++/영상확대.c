#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define BYTE unsigned char
void zoom_0()
{
	FILE *infile;
	int h = 512; int w = 512;
	if ((infile = fopen("lena.raw", "rb")) == NULL) {
		printf("No Image File");
		return;
	}
	BYTE * lnImg = malloc(sizeof(unsigned char) * h*w);
	fread(lnImg, sizeof(unsigned char), h*w, infile);
	BYTE* outImg = malloc(sizeof(unsigned char) * 4*h*w);
	for (int i = 0; i < 2*h; i++)
	{
		for (int j = 0; j < 2*w; j++)
		{
			outImg[i*w + j] = 0;
		}
	}
	for (int  i= 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[ i*2*(w*2) + 2 * j] = lnImg[i*w + j];
			//printf("%d %d %d %d\n", i, j, 2 * i, 2 * j);
		}
	}
	for (int i = 1; i < 2*h; i++)
	{
		for (int j = 1; j < 2*w; j++)
		{
			if(i%2==1 ||j%2 ==1)
			{
				outImg[i*(w*2) + j] = lnImg[i* w / 2 + j / 2];
			}
		}
	}
	FILE * outfile = fopen("lena_2.raw", "wb");
	fwrite(outImg, sizeof(unsigned char),  4*h*w, outfile);
	free(lnImg);
	free(outImg);
	fclose(outfile);


	FILE *ifile;
	h = 1024; w = 1024;
	if ((ifile = fopen("lena_2.raw", "rb")) == NULL) {
		printf("No Image File");
		return;
	}
	BYTE * lImg = malloc(sizeof(unsigned char) * h*w);
	fread(lImg, sizeof(unsigned char), h*w, ifile);
	BYTE* otImg = malloc(sizeof(unsigned char) * 4*h*w);
	for (int i = 0; i < 2 * h; i++)
	{
		for (int j = 0; j < 2 * w; j++)
		{
			otImg[i*w + j] = 0;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			otImg[i * 2 * (w * 2) + 2 * j] = lImg[i*w + j];
			//printf("%d %d %d %d\n", i, j, 2 * i, 2 * j);
		}
	}
	for (int i = 1; i < 2 * h; i++)
	{
		for (int j = 1; j < 2 * w; j++)
		{
			if (i % 2 == 1 || j % 2 == 1)
			{
				otImg[i*(w * 2) + j] = lImg[i* w / 2 + j / 2];
			}
		}
	}
	FILE * otfile = fopen("lena_4.raw", "wb");
	fwrite(otImg, sizeof(unsigned char), 4 * h*w, otfile);
	free(otImg);
	fclose(otfile);

}
void zoom_1()
{
	FILE *infile;
	int h = 512; int w = 512;
	if ((infile = fopen("lena.raw", "rb")) == NULL) {
		printf("No Image File");
		return;
	}
	BYTE * lnImg = malloc(sizeof(unsigned char) * h*w);
	fread(lnImg, sizeof(unsigned char), h*w, infile);
	BYTE* outImg = malloc(sizeof(unsigned char) * 4 * h*w);
	for (int i = 0; i < 2 * h; i++)
	{
		for (int j = 0; j < 2 * w; j++)
		{
			outImg[i*w + j] = 0;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			outImg[i * 2 * (w * 2) + 2 * j] = lnImg[i*w + j];
			//printf("%d %d %d %d\n", i, j, 2 * i, 2 * j);
		}
	}
	for (int i = 1; i < 2 * h; i++)
	{
		for (int j = 0; j < 2 * w; j++)
		{
			if (i % 2 == 1)
			{
				outImg[i * 2 * w + j] = (outImg[(i - 1) * 2 * w + j] + outImg[(i + 1) * 2 * w + j]) / 2;
			}

		}

	}
	for (int i = 0; i < 2 * h; i++)
	{
		for (int j = 1; j < 2 * w; j++)
		{
			if (j % 2 == 1)
			{
				outImg[i * 2 * w + j] = (outImg[(i) * 2 * w + j-1] + outImg[(i ) * 2 * w + j+1]) / 2;
			}

		}

	}
	FILE * outfile = fopen("lena_2_1.raw", "wb");
	fwrite(outImg, sizeof(unsigned char), 4 * h*w, outfile);
	free(lnImg);
	free(outImg);
	fclose(outfile);
	FILE *ifile;
	 h = 1024; w = 1024;
	if ((infile = fopen("lena_2_1.raw", "rb")) == NULL) {
		printf("No Image File");
		return;
	}
	BYTE * lImg = malloc(sizeof(unsigned char) * h*w);
	fread(lImg, sizeof(unsigned char), h*w, infile);
	BYTE* otImg = malloc(sizeof(unsigned char) * 4 * h*w);
	for (int i = 0; i < 2 * h; i++)
	{
		for (int j = 0; j < 2 * w; j++)
		{
			otImg[i*w + j] = 0;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			otImg[i * 2 * (w * 2) + 2 * j] = lImg[i*w + j];
			//printf("%d %d %d %d\n", i, j, 2 * i, 2 * j);
		}
	}
	for (int i = 1; i < 2 * h; i++)
	{
		for (int j = 0; j < 2 * w; j++)
		{
			if (i % 2 == 1)
			{
				otImg[i * 2 * w + j] = (otImg[(i - 1) * 2 * w + j] + otImg[(i + 1) * 2 * w + j]) / 2;
			}

		}

	}
	for (int i = 0; i < 2 * h; i++)
	{
		for (int j = 1; j < 2 * w; j++)
		{
			if (j % 2 == 1)
			{
				otImg[i * 2 * w + j] = (otImg[(i)* 2 * w + j - 1] + otImg[(i)* 2 * w + j + 1]) / 2;
			}

		}

	}
	FILE * otfile = fopen("lena_4_1.raw", "wb");
	fwrite(otImg, sizeof(unsigned char), 4 * h*w, otfile);
	free(lImg);
	free(otImg);
	fclose(otfile);
}
int main(void)
{
	zoom_0();
	zoom_1();

}