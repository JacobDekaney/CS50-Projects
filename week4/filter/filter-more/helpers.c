#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gray = 0;
            gray += image[i][j].rgbtRed;
            gray += image[i][j].rgbtGreen;
            gray += image[i][j].rgbtBlue;
            gray /= 3;

            image[i][j].rgbtRed = round(gray);
            image[i][j].rgbtGreen = round(gray);
            image[i][j].rgbtBlue = round(gray);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int pos;
    //int posj;
    //int posi;
    RGBTRIPLE newimage[height][width];
    for (int i = 0; i <= height;
         i++) //Setting i equal to 1 and taking one away from height accounts for the black border around the image
    {
        for (int j = 0; j <= width;
             j++) //Setting j equal to 1 and taking one away from width accounts for the black border around the image
        {
            float blurr = 0;
            float blurg = 0;
            float blurb = 0;

            if (i >= 1 && j >= 1 && i <= height - 1 && j <= width - 1) //Argument is true when the pixel is in the middle of the image
            {
                for (int k = -1; k <= 1; k ++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        blurr += image[i + k][j + l].rgbtRed;
                        blurg += image[i + k][j + l].rgbtGreen;
                        blurb += image[i + k][j + l].rgbtBlue;
                    }
                }
                newimage[i][j].rgbtRed = round(blurr / 9);
                newimage[i][j].rgbtGreen = round(blurg / 9);
                newimage[i][j].rgbtBlue = round(blurb / 9);
            }
            else if ((i == 0 && j == 0) || (i == height - 1 && j == 0) || (i == 0 && j == width) || (i == height - 1 && j == width))
            {
                int posj = 0 - (j == width);
                int posi = 0 - (i == height);
                for (int k = pos; k <= (pos + 1); k++)
                {
                    for (int l = pos; l <= (pos + 1); l++)
                    {
                        blurr += image[i + k][j + l].rgbtRed;
                        blurg += image[i + k][j + l].rgbtGreen;
                        blurb += image[i + k][j + l].rgbtBlue;
                    }
                }
                newimage[i][j].rgbtRed = round(blurr / 4);
                newimage[i][j].rgbtGreen = round(blurg / 4);
                newimage[i][j].rgbtBlue = round(blurb / 4);
            }
            else if ((i == 0 || i == height - 1) && (j > 0 && j < width)) //argument is true if pixel is at the top or bottom edge
            {
                pos = 0 - (i == height);
                for (int k = pos; k <= (pos + 1); k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        blurr += image[i + k][j + l].rgbtRed;
                        blurg += image[i + k][j + l].rgbtGreen;
                        blurb += image[i + k][j + l].rgbtBlue;
                    }
                }
                newimage[i][j].rgbtRed = round(blurr / 6);
                newimage[i][j].rgbtGreen = round(blurg / 6);
                newimage[i][j].rgbtBlue = round(blurb / 6);
            }
            else if ((j == 0 || j == width) && (i > 0 && i < height))
            {
                pos = 0 - (j == width);
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = pos; l <= (pos + 1); l++)
                    {
                        blurr += image[i + k][j + l].rgbtRed;
                        blurg += image[i + k][j + l].rgbtGreen;
                        blurb += image[i + k][j + l].rgbtBlue;
                    }
                }
                newimage[i][j].rgbtRed = round(blurr / 6);
                newimage[i][j].rgbtGreen = round(blurg / 6);
                newimage[i][j].rgbtBlue = round(blurb / 6);
            }
        }
    }
    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            image[y][z] = newimage[y][z];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE edgeimage[height][width];
    int pos = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rx = 0, ry = 0;
            int gx = 0, gy = 0;
            int bx = 0, by = 0;

            if (i >= 1 && j >= 1 && i <= height - 1 && j <= width - 1) //Argument is true when the pixel is in the middle of the image
            {
                for (int k = -1; k <= 1; k ++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        rx += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        gx += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        bx += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];

                        ry += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                        gy += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        by += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }
            else if ((i == 0 || i == height - 1) && (j > 0 && j < width)) //argument is true if pixel is at the top or bottom edge
            {
                pos = 0 - (i == height);
                for (int k = pos; k <= (pos + 1); k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        rx += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        gx += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        bx += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];

                        ry += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                        gy += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        by += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }
            else if ((j == 0 || j == width) && (i > 0 && i < height))
            {
                pos = 0 - (j == width);
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = pos; l <= (pos + 1); l++)
                    {
                        rx += image[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        gx += image[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        bx += image[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];

                        ry += image[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                        gy += image[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        by += image[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                    }
                }
            }
            if (sqrt(rx * rx + ry * ry) > 255)
            {
                edgeimage[i][j].rgbtRed = 255;
            }
            else
            {
                edgeimage[i][j].rgbtRed = round(sqrt(rx * rx + ry * ry));
            }

            if (sqrt(gx * gx + gy * gy) > 255)
            {
                edgeimage[i][j].rgbtGreen = 255;
            }
            else
            {
                edgeimage[i][j].rgbtGreen = round(sqrt(gx * gx + gy * gy));
            }

            if (sqrt(bx * bx + by * by) > 255)
            {
                edgeimage[i][j].rgbtBlue = 255;
            }
            else
            {
                edgeimage[i][j].rgbtBlue = round(sqrt(bx * bx + by * by));
            }
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            image[y][z] = edgeimage[y][z];
        }
    }

    return;
}


int position(int i, int j, int width, int height)
{
    if ((i == 1 && j == 1) || (i == 1 && j == (width - 1)) || (i == (height - 1) && j == 1) || (i == (height - 1) && j == (width - 1)))
    {
        return 0;
    }
    else if ((i == 1) || (j == 1) || (i == (height - 1)) || (j == (width - 1)))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/*  switch(pos)
//            {
//               case corner:
            if ((i == 0 && j == 0) || (i == 0 && j == (width)) || (i == (height) && j == 1) || (i == (height) && j == (width)))
            {
                    for (int k = -1; k <= 1; k ++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if ((image[i + k][j + l].rgbtRed != 255) && (image[i + k][j + l].rgbtGreen != 255) && (image[i + k][j + l].rgbtBlue != 255))
                            {
                                blurr += image[i + k][j + l].rgbtRed;
                                blurg += image[i + k][j + l].rgbtGreen;
                                blurb += image[i + k][j + l].rgbtBlue;
                            }
                        }
                    }
                    newimage[i][j].rgbtRed = blurr / 4;
                    newimage[i][j].rgbtGreen = blurg / 4;
                    newimage[i][j].rgbtBlue = blurb / 4;
            }
//                   break;

            else if ((i == 0) || (j == 0) || (i == (height)) || (j == (width)))
            {
                    for (int k = -1; k <= 1; k ++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if ((image[i + k][j + l].rgbtRed != 0) && (image[i + k][j + l].rgbtGreen != 0) && (image[i + k][j + l].rgbtBlue != 0))
                            {
                                blurr += image[i + k][j + l].rgbtRed;
                                blurg += image[i + k][j + l].rgbtGreen;
                                blurb += image[i + k][j + l].rgbtBlue;
                            }
                        }
                    }
                    newimage[i][j].rgbtRed = blurr / 6;
                    newimage[i][j].rgbtGreen = blurg / 6;
                    newimage[i][j].rgbtBlue = blurb / 6;
            }

            else
            {
//                case middle:

                    for (int k = -1; k <= 1; k ++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            blurr += image[i + k][j + l].rgbtRed;
                            blurg += image[i + k][j + l].rgbtGreen;
                            blurb += image[i + k][j + l].rgbtBlue;
                        }
                    }
                    newimage[i][j].rgbtRed = blurr / 9;
                    newimage[i][j].rgbtGreen = blurg / 9;
                    newimage[i][j].rgbtBlue = blurb / 9;

//                    break;
            }
//                case edge:

//                    break;

//                default:
//                    break;
//            }*/