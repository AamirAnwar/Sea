#include<stdio.h>
#include<stdlib.h>

// Quicksort algorithm. Sorting in O(n*log(n))

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int l, int r, int *a) {
	if (l>=r) {return r;} 

	int m = (r-l)/2 + l;
	int pivot = a[m];

	printf("Using %d as the pivot \n", pivot);
	swap(&a[0], &a[m]);

	int i = l+1;
	
	for (int j = i+1; j<=r; j++) {
		if (a[j] >= pivot) {continue;}
		else {
			printf("Swapping %d at index %d with %d at index %d\n",a[i+1],i+1 ,a[j], j);
			if (a[i] < pivot) {
				swap(&a[i+1], &a[j]);
			}
			else {
				swap(&a[i], &a[j]);	
			}
			i++;
		}
	}

	if (a[i] > pivot) {
		swap(&a[0], &a[i - 1]);
		return i-1;
	}
	else {
		swap(&a[0], &a[i]);
		return i;
	}



}

void quicksort(int l, int r, int *a) {
	if ( l>=r ) {
		printf("L is greater than R!\n");
		return;
	}

	int paritionIndex = partition(l,r,a);
	printf("paritionIndex - %d\n", paritionIndex);
	quicksort(0, paritionIndex - 1, a);
	quicksort(paritionIndex + 1, r, a);

}

void printArray(int *a, int size) {
	for(int i=0;i<size;i++){printf("%d ", a[i]);}
	printf("\n");

}


int main(void) {
	int a[] = {9,8,7,6,5,4,3,20,19,18,17,16,3,1};
	int size = (sizeof(a)/sizeof(a[0]));
	printf("Input array : \n");
	printArray(a, size);
	printf("\n");

	quicksort(0, size - 1, a);
	// partition(0,size-1,a);
	printArray(a, size);

	return 0;
}
