#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define WIDTHBYTES(bits) (((bits)+31)/32*4)
#define BYTE    unsigned char
void bmp_gray()
{
	FILE *infile;

	if ((infile = fopen("ImgBW.bmp", "rb")) == NULL) {
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
	BYTE *lpImg = malloc(hInfo.biSizeImage);
	BYTE *newImg = malloc(hInfo.biWidth*hInfo.biHeight); //뉴이미지는 행의 순서 유지
	BYTE *newImg_2 = malloc(hInfo.biWidth*hInfo.biHeight);//뉴이미지_2는 행의순서 정반대
	fread(lpImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	int rwsize = WIDTHBYTES(hInfo.biBitCount * hInfo.biWidth); //printf("%d\n", rwsize);
	int minus = rwsize - hInfo.biWidth; //printf("%d\n", minus);
	int temp_; int i = 0; int j = 0;
	while (i<hInfo.biHeight)
	{
		j = 0;
		while (j<rwsize)
		{
			if (j + minus == rwsize - 1)
			{
				j = rwsize; i++;// printf("%d %d \n", i, j);4의 배수로 하기위해 만들어진 공백전에 도착시 행을 더하고 열크기를 최댓값으로 만들어 빠져나가게했다.

			}
			else
			{
				temp_ = i*rwsize + j;  //printf("%d   %d\n", i, j);
				newImg[i*hInfo.biWidth + j] = lpImg[temp_];
				j++;
			}
		}
	}
	i = hInfo.biHeight - 1;
	int i_ = 0;
	while (i>-1)
	{
		j = 0;
		while (j<rwsize)
		{
			if (j + minus == rwsize - 1)
			{
				j = rwsize; i--; i_++;// printf("%d %d \n", i, j);

			}
			else
			{
				temp_ = i*rwsize + j;  //printf("%d   %d\n", i, j);
				newImg_2[i_*hInfo.biWidth + j] = lpImg[temp_];
				j++;
			}
		}
	}
	FILE *outfile = fopen("ImgBWrev.pgm", "wb");
	fprintf(outfile, "P5\n");
	fprintf(outfile, "%d %d\n", hInfo.biWidth, hInfo.biHeight);
	fprintf(outfile, "255\n");
	for (i = 0; i < hInfo.biHeight; i++)
	{
		for (j = 0; j < hInfo.biWidth; j++)
			putc(newImg[i*hInfo.biWidth + j], outfile);
	}
	fclose(outfile);
	FILE *outfile_2 = fopen("ImgBW.pgm", "wb");
	fprintf(outfile_2, "P5\n");
	fprintf(outfile_2, "%d %d\n", hInfo.biWidth, hInfo.biHeight);
	fprintf(outfile_2, "255\n");
	for (i = 0; i < hInfo.biHeight; i++)
	{
		for (j = 0; j < hInfo.biWidth; j++)
			putc(newImg_2[i*hInfo.biWidth + j], outfile_2);
	}
	fclose(outfile_2);


}
void bmp_color()
{
	FILE *infile;

	if ((infile = fopen("ImgColor.bmp", "rb")) == NULL) {
		printf("No Image File");
		return;
	}

	// BMP Header Information
	BITMAPFILEHEADER hf;
	BITMAPINFOHEADER hInfo;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, infile);
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, infile);
	BYTE *lpImg = malloc(3 * hInfo.biSizeImage);
	BYTE *newImg = malloc(3 * hInfo.biWidth*hInfo.biHeight);//그냥
	BYTE *newImg_2 = malloc(3 * hInfo.biWidth*hInfo.biHeight);//행순서
	BYTE* newImg_3 = malloc(3 * hInfo.biWidth*hInfo.biHeight);//bgr ->rgb
	BYTE * temp_img = malloc(3 * hInfo.biSizeImage);
	fread(lpImg, 3 * sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);
	int rwsize = WIDTHBYTES(hInfo.biBitCount * hInfo.biWidth);
	int i = 0; int j = 0; int k;
	while (i < hInfo.biHeight)
	{
		j = 0;
		while (j<hInfo.biWidth)
		{
			for (k = 0; k < 3; k++)
				newImg[i*hInfo.biWidth * 3 + j * 3 + k] = lpImg[i*rwsize + j * 3 + k]; j++;
			if (k == 3 && j == hInfo.biWidth - 1)
			{
				i++; j = hInfo.biWidth; 
			}

		}
	}
	i = hInfo.biHeight-1;
	int i_ = 0;
	while (i>-1)
	{
		j = 0;
		while (j<hInfo.biWidth)
		{
			for (k = 0; k < 3; k++)
				newImg_2[i_*hInfo.biWidth * 3 + j * 3 + k] = lpImg[i*rwsize + j * 3 + k]; j++; 
			if (k == 3 && j == hInfo.biWidth - 1)
			{
				i--; j = hInfo.biWidth; i_++;
			}

		}
	}
	for (i = 0; i < hInfo.biHeight; i++)
	{
		for (j = 0; j < hInfo.biWidth; j++)
		{
			temp_img[i*rwsize + 3 * j] = lpImg[i*rwsize + 3 * j + 2];
			temp_img[i*rwsize + 3 * j + 1] = lpImg[i*rwsize + 3 * j + 1];
			temp_img[i*rwsize + 3 * j + 2] = lpImg[i*rwsize + 3 * j ];
		}
	}
	i = 0; j = 0;
	while (i < hInfo.biHeight)
	{
		j = 0;
		while (j<hInfo.biWidth)
		{
			for (k = 0; k < 3; k++)
				newImg_3[i*hInfo.biWidth * 3 + j * 3 + k] = temp_img[i*rwsize + j * 3 + k]; j++;
			if (k == 3 && j == hInfo.biWidth - 1)
			{
				i++; j = hInfo.biWidth;
			}

		}
	}

	FILE *outfile = fopen("ImgColorrev_bgr.ppm", "wb");
	fprintf(outfile, "P6\n");
	fprintf(outfile, "%d %d\n", hInfo.biWidth, hInfo.biHeight);
	fprintf(outfile, "255\n");
	for (i = 0; i < hInfo.biHeight; i++)
		for (j = 0; j < hInfo.biWidth; j++)
			for (int k = 0; k < 3; k++)
				putc(newImg[i*hInfo.biWidth * 3 + 3 * j + k], outfile);
	fclose(outfile);
	free(newImg);
	FILE *outfile_2 = fopen("ImgColor.ppm", "wb");
	fprintf(outfile_2, "P6\n");
	fprintf(outfile_2, "%d %d\n", hInfo.biWidth, hInfo.biHeight);
	fprintf(outfile_2, "255\n");
	for (i = 0; i < hInfo.biHeight; i++)
		for (j = 0; j < hInfo.biWidth; j++)
			for (int k = 0; k < 3; k++)
				putc(newImg_2[i*hInfo.biWidth * 3 + 3 * j + k], outfile_2);
	fclose(outfile_2);
	free(newImg_2);
	FILE *outfile_3 = fopen("ImgColorrev_rgb.ppm", "wb");
	fprintf(outfile_3, "P6\n");
	fprintf(outfile_3, "%d %d\n", hInfo.biWidth, hInfo.biHeight);
	fprintf(outfile_3, "255\n");
	for (i = 0; i < hInfo.biHeight; i++)
		for (j = 0; j < hInfo.biWidth; j++)
			for (int k = 0; k < 3; k++)
				putc(newImg_3[i*hInfo.biWidth * 3 + 3 * j + k], outfile_3);
	fclose(outfile_3);
}


int main(void)
{
	bmp_gray();
	bmp_color();




}