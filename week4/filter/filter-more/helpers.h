#include "bmp.h"

#define corner 0
#define middle 1
#define edge 2
#define top 12
#define left 22
#define bottom 32
#define right 42

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

// Checks position of pixel
int position(int i, int j,int width, int height);

// Check which corner a pixel is in
//int corner(int i, int j,int width, int height);

// Checks which edge a pixel is on
//int edge(int i, int j,int width, int height);
