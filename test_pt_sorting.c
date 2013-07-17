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

    //Generate an array
    int * arrayNums = gen_rand_int_array(length, nbits);

    //Print out the info of the array
    printf("Random array of length %i and nbits %i\n", length, nbits);
    printf("Before sorting: ");
    print_int_array(arrayNums, length);    

    switch(sort_function_number){
        case 1:
            selection_sort(arrayNums, length);
            break;
        case 2:
            insertion_sort(arrayNums, length);
            break;
        case 3:
            merge_sort(arrayNums, length);
            break;
        case 4:
            heap_sort(arrayNums, length);
            break;
        case 5:
            quick_sort_hoare(arrayNums, length);
            break;
        case 6:
            //quick_sort_median(int arrayNums, length);
            break;
        case 7:
            //quick_sort_random(arrayNums, length);
            break;
        default:
            printf("There is no function with that number.\n");
    }
    
    //Print out the array after sorting
    printf("After sorting: ");
    print_int_array(arrayNums, length);  

}
