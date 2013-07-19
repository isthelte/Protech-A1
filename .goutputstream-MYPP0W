#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pt_utils.h"
#include "pt_sorting.h"


int main(int argc, char * argv[]) {
  
    //For testing only  
//    int size = 50;
  //  int nbits = 7;
//
  //  int * arrays = gen_rand_int_array(size, nbits);
    //printf("Array of size = %i and nbits = %i\n",size, nbits);
    //print_int_array(arrays, 10);
    //quick_sort_hoare(arrays, size);
    //selection_sort(arrays, size);
    //insertion_sort(arrays, size);
    //print_int_array(arrays, size);
      
    int sort_function_number = atoi(argv[1]);
    int length = atoi(argv[2]);
    int nbits = atoi(argv[3]);

    //If there is an argument to specify the seed
    if(argc > 4){
        // set the PRNG seed
        int seed = atoi(argv[4]);
        srand(seed);
    }

    //Generate an array
    int * arrayNums = gen_rand_int_array(length, nbits);

    //Print out the info of the array
    printf("\nRandom array of length %i and nbits %i\n\n", length, nbits);
    printf("Before sorting: ");
    print_int_array(arrayNums, length);
    printf("\n");   

    switch(sort_function_number){
        case 1: //Denis
            printf("-------Apply selection sort-------\n");
            selection_sort(arrayNums, length);
            break;
        case 2: //Thinh 
            printf("-------Apply insertion sort-------\n");
            insertion_sort(arrayNums, length);
            break;
        case 3: //Luan
            printf("-------Apply merge sort-------\n\n");
            merge_sort(arrayNums, length);
            break;
        case 4: //Luan
            printf("-------Apply heap sort-------\n\n");
            heap_sort(arrayNums, length);
            break;
        case 5: //Thinh
            printf("-------Apply quick sort (hoare)-------\n\n");
            quick_sort_hoare(arrayNums, length);
            break;
        case 6:
            printf("-------Apply quick sort (median)-------\n\n");
            quick_sort_median(arrayNums, length);
            break;
        case 7:
            printf("-------Apply quick sort (random)-------\n\n");
            //quick_sort_random(arrayNums, length);
            break;
        default:
            printf("There is no function with that number.\n\n");
    }
    
    //Print out the array after sorting
    printf("After sorting: ");
    print_int_array(arrayNums, length);  
    printf("\n");
}
