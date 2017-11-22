#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// Function declarations
void bubbleSort(int *list, int size);
void printArray(int *array, int size);

void bubbleSort(int *list, int size) {
  int i,j;
  bool didSwap = false;
  for(i=0;i<size;i++) {
    for(j=i;j<size;j++) {
      if (list[j] > list[j+1]) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
}

// Function definitions
void printArray(int *array, int size) {
  for(int i=0; i<size; i++) {
    printf("%i ", array[i]);
  }
}

// Main function called with no params passed
int main(void) {
  int list[] = {5,4,3,2,1,0};
  int size = sizeof(list)/sizeof(list[0]);
  bubbleSort(list, size);
  printArray(list, size);
  return 0;
}
