#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayFloatToInt(int size, float* floatPixels, int* intPixels);

void printResults(int height, int width, float* floatPixels, int* intPixels) 
{
    int i, j;
    
    printf("\nOutput (Integer values):\n");

    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            printf("%d", intPixels[i * width + j]);

            if (j < width - 1)
            {
                printf(", ");
            }

        }
        printf("\n");
    }
}

int main() 
{
    int height, width, size, i;
    float* inputFloat;

    int* outputInt;
    clock_t start, end;

    double timeSpent;
    
    printf("\nEnter height and width: ");
    scanf("%d %d", &height, &width);

    size = height * width;
    
    inputFloat = (float*)malloc(size * sizeof(float));
    outputInt = (int*)malloc(size * sizeof(int));
    
    printf("\nEnter %d float pixel values:\n", size);

    for (i = 0; i < size; i++) 
    {
        scanf("%f", &inputFloat[i]);
    }

    if (size == 100 || size == 10000 || size == 1000000) 
    {
        start = clock();
        imgCvtGrayFloatToInt(size, inputFloat, outputInt);

        end = clock();
        timeSpent = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nAssembly function execution time: %f seconds\n", timeSpent);
    } 

    else imgCvtGrayFloatToInt(size, inputFloat, outputInt);
    
    printResults(height, width, inputFloat, outputInt);
    
    free(inputFloat);
    free(outputInt);
    
    return 0;
}
