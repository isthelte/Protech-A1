#include "pt_sorting.h"

void selection_sort(int a[], int length) {
    int min_pos, tmp;
    
    /* find the min value in a[i] to a[length-1], and swap it with a[i] */
    for (int i = 0; i < length; i++) {
        min_pos = i;
        /* find the minimum value in what is left of the array */
        for (int j = i+1; j < length; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        tmp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = tmp;
    }
    
}

//Nguyen Phuc Thinh - s3372765
void insertion_sort(int a[], int length) {

    for (int i = 1; i < length; i += 1)
    {
        int insPos = i;
        int insVal = a[i];

        while (insVal < a[insPos -1] && insPos > 0){
            a[insPos] = a[insPos - 1];
            insPos--;
        }

        a[insPos] = insVal;
    }

}

//Nguyen Phuc Thinh - s3372765
//To see the code in action, uncomment the following lines:
//55, 61, 85, 91 to 96, 101 to 107
int partition(int a[], int left, int right, int pivotIndex){

    //Get the value of the pivot
    int pivotValue = a[pivotIndex];

    //Move pivotValue to the end of the array
    int temp = pivotValue;
    a[pivotIndex] = a[right];
    a[right] = temp;
    //Loop through the subarray
    //And re-arrange the elements
    int storeIndex = left;
//printf("pivot = %i\n", pivotValue);

    for (int i = left; i < right; i += 1)
    {
        if (a[i] <= pivotValue) //If we find a value < pivot
        {
//            printf("found: %i\n", a[i]);
            //Swap it to the left most (and unused) of the array
            int temp2 = a[i];
            a[i] = a[storeIndex];
            a[storeIndex] = temp2;
            //Increment storeIndex because the old index is used
            //To make sure it is unsed for the next iteration
            storeIndex++;
        }
    }
    //After we completed rearranging:
    //a[right] would be where the pivot is (at the beginning)
    //a[storeIndex] would be the index where all index < storeIndex
    //has a value smaller than the pivot
    //Move pivot to its final place, which is storeIndex
    int temp3 = a[storeIndex];
    a[storeIndex] = a[right];
    a[right] = temp3;
    
    return storeIndex;
}

void quick_sort_hoare(int a[], int length){

//printf("length = %i\n", length);
    if (length >= 2)
    {
        //Chose the 1st pivot, according to Hoare
        int pivotIndex = 0;

//printf("Before\n");
//for (int i = 0; i < length; i += 1)
//        {
//            printf("%i ", a[i]);
//       }
//printf("\n");

        //Rearranging the array by using the pivot
        int pivotNewIndex = partition(a, 0, length - 1, pivotIndex);

//printf("pivotNewIndex = %i\n", pivotNewIndex);
//printf("After\n");
//        for (int i = 0; i < length; i += 1)
//        {
//            printf("%i ", a[i]);
//        }
//printf("\n");

        //Continuously calling quicksort until we reach length < 2
        quick_sort_hoare(&a[0], pivotNewIndex);
        quick_sort_hoare(&a[pivotNewIndex + 1], length - pivotNewIndex - 1);    
    }

}

