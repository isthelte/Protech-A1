#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pt_utils.h"
#include "pt_sorting.h"

#include <string.h>

//Make 2 arrays: 1 for pointers and 1 for names
void (* funcs[])(int[], int) = {selection_sort, insertion_sort
            , merge_sort, heap_sort, quick_sort_hoare
            , quick_sort_median, quick_sort_random};
char * f_names[] = {"selection_sort", "insertion_sort"
            , "merge_sort", "heap_sort", "quick_sort_hoare"
            , "quick_sort_median", "quick_sort_random"};

int find_func_num(char * func_name){

   for (int i = 0; i < 7; i += 1)
   {
       if (strcmp(func_name, f_names[i]) == 0){
           return ++i; 
       }
   }

    return -1; 

}

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
      
    char * sort_function_name = argv[1];
    int sort_function_number = find_func_num(sort_function_name);
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
            break;
        case 2: //Thinh 
            printf("-------Apply insertion sort-------\n");
            break;
        case 3: //Luan
            printf("-------Apply merge sort-------\n\n");
            break;
        case 4: //Luan
            printf("-------Apply heap sort-------\n\n");
            break;
        case 5: //Thinh
            printf("-------Apply quick sort (hoare)-------\n\n");
            break;
        case 6: //Hung
            printf("-------Apply quick sort (median)-------\n\n");
            break;
        case 7: //Hung
            printf("-------Apply quick sort (random)-------\n\n");
            break;
        default:
            printf("There is no function with that number.\n");
    }

    if (sort_function_number != -1)
    {
        //Run the selected function
        funcs[sort_function_number](arrayNums, length);
    } else {
        printf("Nothing is sorted\n\n");    
    }  
    
    //Print out the array after sorting
    printf("After sorting: ");
    print_int_array(arrayNums, length);  
    printf("\n");
}
