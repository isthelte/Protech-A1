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
    
    void merge(int a[],int start, int mid, int end){
        int left[mid - start +1];
        int right[end - mid];
        int i, j, k;
        
        for (i = 0; i < sizeof(left)/sizeof(*left); i += 1)
        {
            left[i] = a[start+i];
        }

        for (j = 0; j < sizeof(right)/sizeof(*right); j += 1)
        {
            right[j] = a[mid+1+j];
        }
        
        i = 0;
        j = 0;
        k = start;

        while(k <= end){
            while(i < sizeof(left)/sizeof(*left) && j < sizeof(right)/sizeof(*right) && left[i] <= right[j]){
                a[k] = left[i];
                i++;
                k++;
            }
            while(i < sizeof(left)/sizeof(*left) && j < sizeof(right)/sizeof(*right) && right[j] <= left[i]){
                a[k] = right[j];
                j++;
                k++;
            }
            if (i >= sizeof(left)/sizeof(*left)) {             
                while (j < sizeof(right)/sizeof(*right)) {
                    a[k] = right[j];
                    j++;
                    k++;
                }
            }
            if (j >= sizeof(right)/sizeof(*right)) {
                // copy the elements of left into a
                while (i < sizeof(left)/sizeof(*left)) {
                    a[k] = left[i];
                    i++;
                    k++;
                }
            }
        }
    }

    void merge_sort_recursive(int a[],int start, int end)
    {
    
        if(end - start < 1)
        {
            return;
        }

        int mid = start + (end - start) / 2;
           
        merge_sort_recursive(a,start, mid);
        merge_sort_recursive(a,mid+1, end);
        
        merge(a,start, mid, end);

    }   

    void merge_sort(int a[], int length)
    {
        int start = 0;
        int end = length - 1; 

        merge_sort_recursive(a,start,end); 
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
        
         if (list[start] > list[end]) {
            int temp = list[start];
                list[start] =list[end];
                list[end]= temp;
     
        } else if (list[start] > list[pivot]) {
            int temp2 = list[start];
                list[start]=list[pivot];
                list[pivot]= temp2;
        } else if (list[end] < list[pivot]) {
            int temp3 = list[end];
                 list[end] = list[pivot];
                 list[pivot]= temp3;
      
        }
        
        // This part will find the patition
        int x = list[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (list[j] < x) {
                i++;
                if (list[i] != list[j]) {
                   int temp5 = list[i];
                    list[i]=list[j];
                    list[j]=temp5;
                }
            }
        }
        
        if (list[i + 1] != list[end]) {
            int temp4 = list[i+1];
                list[i+1]= list[end];
                list[end] = temp4;
        }
          int patition = i+1;      

            //this part will run the recusive function            
            quicksort(list, start, patition - 1,type);
            quicksort(list, patition + 1, end,type);
        }
}

void quick_sort_median(int list[], int length){
        int end = length -1;
        int type = 1;
        quicksort(list,0,end,type);
}

void quick_sort_random(int list[], int length){
        int end = length -1;
        int type = 2;
        quicksort(list,0,end,type);
}

void quick_sort_hoare(int list[], int length){
        int end = length -1;
        int type = 3;
        quicksort(list,0,end,type);
}

