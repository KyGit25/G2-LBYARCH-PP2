#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void imgCvtGrayFloatToInt(int size, float* floatPixels, int* intPixels);

void printResults(int height, int width, float* floatPixels, int* intPixels) {
    int i, j;
    printf("\nInput (Float values):\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatPixels[i * width + j]);
        }
        printf("\n");
    }
    
    printf("\nOutput (Integer values):\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d", intPixels[i * width + j]);
            if (j < width - 1) printf(", ");
        }
        printf("\n");
    }
}

void generateRandomPixels(float* pixels, int size) {
    int i;
    for (i = 0; i < size; i++) {
        pixels[i] = (float)rand() / RAND_MAX; 
    }
}

int main() {
    int height, width, size, test, testSize, side, i;
    float* floatPixels;
    int* intPixels;
    float* inputFloat;
    int* outputInt;
    clock_t start, end;
    double timeSpent;
    
    printf("Enter height and width: ");
    scanf("%d %d", &height, &width);
    size = height * width;
    
    inputFloat = (float*)malloc(size * sizeof(float));
    outputInt = (int*)malloc(size * sizeof(int));
    
    printf("Enter %d float pixel values:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%f", &inputFloat[i]);
    }
    
    imgCvtGrayFloatToInt(size, inputFloat, outputInt);
    printResults(height, width, inputFloat, outputInt);
    
    free(inputFloat);
    free(outputInt);

    int testSizes[] = {100, 10000, 1000000}; 
    int numTests = 3;
    
    srand(time(NULL));
    
    for (test = 0; test < numTests; test++) {
        testSize = testSizes[test];
        side = (int)sqrt(testSize);
        
        printf("\nTesting %dx%d image (%d pixels):\n", side, side, testSize);
        
        floatPixels = (float*)malloc(testSize * sizeof(float));
        intPixels = (int*)malloc(testSize * sizeof(int));
        
        if (!floatPixels || !intPixels) {
            printf("Memory allocation failed for size %d\n", testSize);
            continue;
        }
        
        generateRandomPixels(floatPixels, testSize);

        start = clock();
        imgCvtGrayFloatToInt(testSize, floatPixels, intPixels);
        end = clock();
        
        timeSpent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Assembly function execution time: %f seconds\n", timeSpent);
        
        free(floatPixels);
        free(intPixels);
    }
    
    return 0;
}