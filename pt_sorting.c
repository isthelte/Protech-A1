#include "pt_sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//Trinh Luan - s3372775

//////////////////////////////MERGE SORT///////////////////////////////////////
    
    void merge(int a[], int start, int mid, int end){
        //declare 2 array: left store first half and right store second half       
        int left[mid + 1 - start];
        int right[end - mid];
        int i = 0;
        int j = 0;

        //left array take first half elements
        for (int i = 0; i < sizeof(left)/sizeof(*left); i += 1)
        {
            left[i] = a[start+i];
        }
        
        //right array take second half elements
        for (int j = 0; j < sizeof(right)/sizeof(*right); j += 1)
        {
            right[j] = a[mid+1+j];
        }
        
        //loop from start to end
        while(start <= end)
        {           
            //check the index on right sub-array
            if(j < sizeof(right)/sizeof(*right))
            {
                //loop through all elements then take smaller elements from
                //the left array compare to right array and store in array a
                while(left[i] <= right[j] && i < sizeof(left)/sizeof(*left))
                {                        
                    a[start] = left[i];
                    i++;
                    start++;
                        //if the index on left sub-array greater than left array's length'
                        //then array a will store elements from right array
                        if (i >= sizeof(left)/sizeof(*left)) 
                        {                                    
                            for (;j < sizeof(right)/sizeof(*right); j += 1)
                            {
                                a[start] = right[j];
                                start++;
                            }
                        }
                }
            }
            
            //check the index on left sub-array
            if(i < sizeof(left)/sizeof(*left))
            {
                //loop through all elements then take smaller elements from
                //the right array compare to left array and store in array a
                while(right[j] <= left[i] && j < sizeof(right)/sizeof(*right))
                {
                    a[start] = right[j];
                    j++;
                    start++;
                        //if the index on right sub-array greater than right array's length
                        //then array a will store elements from left array
                        if (j >= sizeof(right)/sizeof(*right)) 
                        {                          
                            for (; i < sizeof(left)/sizeof(*left) ; i += 1)
                            {
                                a[start] = left[i];
                                start++;
                            }
                        }
                }

            }       
            
        }
    }

    void merge_sort_recursive(int a[],int start, int end)
    {   
        //check the length of array must greater than 0
        if(end - start >= 1)
        {
            merge_sort_recursive(a,start, start + (end - start) / 2);
            merge_sort_recursive(a,(start + (end - start) / 2) + 1, end);     
            merge(a,start, start + (end - start) / 2, end);
        }     
    }   

    void merge_sort(int a[], int length)
    {
        merge_sort_recursive(a, 0 ,length - 1); 
    }


//////////////////////////////////HEAP SORT///////////////////////////////////
    
    void sortHeap(int a[], int arr){
        int i, j;
        int leftChild, rightChild, midChild, root, temp;
        
        root = (arr - 1) / 2;
        
        for (j = root; j >= 0; j -= 1)
        {
            for (i = root; i >= 0; i -= 1)
            {
                leftChild = (2*i) + 1;
                rightChild = (2*i) + 2;
                if((leftChild <= arr) && (rightChild <= arr))
                {
                    if(a[rightChild] >= a[leftChild])
                    {
                        midChild = rightChild;
                    }
                    else
                    {
                        midChild = leftChild;
                    }
                }
                else
                {
                    if(rightChild >= arr)
                    {
                        midChild = leftChild;
                    }
                    else
                    {
                        midChild = rightChild;
                    }
                }
                if(a[i] < a[midChild])
                {
                    temp = a[i];
                    a[i] = a[midChild];
                    a[midChild] = temp;
                }
            }
        }
        temp = a[0];
        a[0] = a[arr];
        a[arr] = temp;
        return;
    }    

    void heap_sort(int a[], int length)
    {            
        for (int i = length; i > 1; i -= 1)
        {
            sortHeap(a, i-1);
        }       
    }
    
	
//Cao Phi Hung - s3372748

void quicksort(int list[],int start, int end,int type){
        if (start < end) {
       
        int pivot = 0;
        // median
        if (type == 1)
        {
             pivot = (start + end) / 2;
        // random        
        }else if (type == 2)
        {
            pivot = (rand() % (end + 1 -start)) + start;
        
         // hoare        
        }else if (type == 3)
        {
            pivot = start;
        }             
        
        int temp =0;
         if (list[start] > list[end]) {
                temp = list[start];
                list[start] =list[end];
                list[end]= temp;
     
        } else if (list[start] > list[pivot]) {
                temp = list[start];
                list[start]=list[pivot];
                list[pivot]= temp;
        } else if (list[end] < list[pivot]) {
                 temp = list[end];
                 list[end] = list[pivot];
                 list[pivot]= temp;
      
        }
        
        // This part will find the patition
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (list[j] < list[end]) {
                i++;
                if (list[i] != list[j]) {
                    temp = list[i];
                    list[i]=list[j];
                    list[j]=temp;
                }
            }
        }
        
        if (list[i + 1] != list[end]) {
                temp = list[i+1];
                list[i+1]= list[end];
                list[end] = temp;
        }
          
          //int patition = i+1;      

            //this part will run the recusive function            
            //quicksort(list, start, patition - 1,type);
            //quicksort(list, patition + 1, end,type);

               // For competition only 
              quicksort(list, start, i + 1 - 1,type);
              quicksort(list, i + 1 + 1, end,type);
        }
}

void quick_sort_median(int list[], int length){
        quicksort(list,0,length - 1,1);
}

void quick_sort_random(int list[], int length){
        quicksort(list,0,length -1 ,2);
}

void quick_sort_hoare(int list[], int length){
        quicksort(list,0,length - 1,3);
}

