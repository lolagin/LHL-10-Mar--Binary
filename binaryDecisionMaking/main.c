//
//  main.c
//  binaryDecisionMaking
//
//  Created by Jeffrey C Rosenthal on 3/10/15.
//  Copyright (c) 2015 Jeffreycorp. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int firstSighting;
    int numCount;
} bCounter;

int sidecheck (int array[], int key, int mid, int max);

bCounter binarySearch (int key, int array[], int min, int max);


int count = 0;

#pragma mark - Functions

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    int lulz[]={2,4,5,10,15,19,20,22,25,26,31};
//     int lulz[] = {23,23,23,23,23,23,23,23,23,23,23};
    
    bCounter lulDex =  binarySearch(5, lulz, 0, 10);
    printf("thing was spotted at %d index, %d times. Checked %d indexes",lulDex.firstSighting, lulDex.numCount, count);
    
    
    return 0;
}


int sidecheck (int array[], int key, int mid, int max) {

    int sideCount = 0;
    
    int i = mid;
    while (i <= max) {
        if (array[i] == key) {
            sideCount++;
        }
    
        i++;
    }
    
    return sideCount;
};


bCounter binarySearch (int key, int array[], int min, int max){
    if (max == min) {
        bCounter counter;
        counter.firstSighting = min;
        counter.numCount = 1;
        return counter;
    }
    else if (max<min){
        bCounter counter;
        counter.firstSighting = -1;
        counter.numCount = 0;
        return counter;
    }
    else {
        count++;
        int mid = min + (max - min) / 2;
        printf("mid :%i\n", mid);
        
        bCounter counter;
        
        if (array[mid] < key)
        {
            return binarySearch(key, array, mid + 1, max);
        }
        else if (array[mid] > key) {
            return binarySearch(key, array, min, mid - 1);
        } else {
            
            
            int leftSide = sidecheck(array, key, min, mid-1);
            int rightSide = sidecheck(array, key, mid+1, max);
            
            counter.firstSighting = mid;
            counter.numCount = 1 + leftSide + rightSide;
            
        }
        
        return counter;
    }
}


