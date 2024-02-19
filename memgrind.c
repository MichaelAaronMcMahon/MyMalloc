#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <sys/time.h>

#include <time.h>

#include "mymalloc.h"

/*

   Returns a random integer with the range of min and max

*/

int rand_lim(int min, int max){

 

    return ((double)rand() / (((double)RAND_MAX) + 1.0)) * (max-min+1) + min;

}

/*

   Removes the pointer at index and shifts the values in the array up to

   fill the vacancy.

*/

void deleteArrayItem( int index, int length, char ** array){

    int i;

    for (i = index; i < length - 1; i++ ){

         array[i] = array[i + 1];

    }

}

/*   All tests below are run 100 times per call */

/*   Calls malloc for 1 byte 3000 times. The pointers are stored in an array and then freed in the order that they were allocated. */

void test1(){

    char * op[5000];

    struct timeval tv1;

    struct timeval tv2;

    long avg=0;

    int successCounter = 0;

    int currentSuccessCount = 0;

    int freeCounter = 0;

    int totalMallocs = 0;

    int totalFrees = 0;

    printf("TEST 1, malloc 1 byte 3000 times:\n");

    //time_t begin;

    //time_t currtime;

    int i;

    int y;

    for (y=0; y<100; y++) {

        gettimeofday(&tv1, 0);

        for (i=0; i<3000; i++) {

            op[i] = malloc(1);

            totalMallocs++;

          

            if (op[i] != NULL){

               successCounter++;

                currentSuccessCount++;

            }

        }

        for (i = 0; i < currentSuccessCount; i++) {

            free(op[i]);

            freeCounter++;

            totalFrees++;

        }

        currentSuccessCount = 0;

         gettimeofday(&tv2, 0);

        avg += ((tv2.tv_sec-tv1.tv_sec)*1000000 + tv2.tv_usec-tv1.tv_usec);

    }

    printf("Total mallocs: %d\n", totalMallocs);

    printf("Successful mallocs: %d\n", successCounter);

    printf("Total frees: %d\n", totalFrees);

    printf("AVG Time Elasped: %ld microseconds.\n", avg/100);

     char * test = malloc(4998);

    if (test != NULL){

       printf("TEST PASSED\n");

    }

    free(test);

}

/*

   Calls malloc for 1 byte and then frees the pointer immediately 3000 times.

*/

void test2(){

    printf("TEST 2, malloc 1 byte 3000 times and free immediately:\n");

    char * ptr = NULL;

    int i;

    int y;

    int successCounter = 0;

    int freeCounter = 0;

    int totalMallocs = 0;

    int totalFrees = 0;

    long avg= 0;

    struct timeval tv1;

    struct timeval tv2;

    //time_t begin;

    //time_t currtime;

    for (y=0; y<100; y++) {

  

        gettimeofday(&tv1, 0);

        for (i=0; i<3000; i++) {

            ptr = malloc(1);

            totalMallocs++;

            if (ptr != NULL){

                 free(ptr);

                 successCounter++;

                 freeCounter++;

                 totalFrees++;

            }

        }

        gettimeofday(&tv2, 0);

        avg+=((tv2.tv_sec-tv1.tv_sec)*1000000 + tv2.tv_usec-tv1.tv_usec);

    }

    char * test = malloc(4998);

    printf("Total mallocs: %d\n", totalMallocs);

    printf("Successful mallocs: %d\n", successCounter);

    printf("Total frees: %d\n", totalFrees);

    printf("Successful frees: %d\n", freeCounter);

    printf("AVG Time Elasped: %ld microseconds.\n", avg/100);

    if (test != NULL){

       printf("TEST PASSED\n");

    }

    free(test);

}

void test3(){

    //int i;

    int mallocCounter = 0;

    int freeCounter = 0;

    int totalMallocs = 0;

    int successCounter = 0;

    char * pointers[3000];

    int length = 0;

    long avg= 0;

  

    struct timeval tv1;

    struct timeval tv2;

    //time_t t;

    //time_t begin;

    //time_t currtime;

    printf("TEST 3, Randomly choose between a malloc() of size 1 or free() 6000 times:\n");

    //srand((unsigned)time(&t));

    int y;

    for (y = 0; y < 100; y++){

       gettimeofday(&tv1, 0);

        while(mallocCounter < 3000){

            int pick = rand_lim(0, 1);

            if (pick == 0){

                int size = 1;       //random size

                void * ptr = malloc(size);

                totalMallocs++;

                if (ptr != NULL){

                    //printf("pointer is stored\n");

                    pointers[length] = ptr;

                    length++;

                    //printf("length: %d\n", length);

                    successCounter++;

                }

                mallocCounter++;

             

            }

            else {

                //free random pointer

                if (length > 0){

                   int index = rand_lim(0, length - 1);

                   free(pointers[index]);

                   char ** start = &pointers[0];

                      deleteArrayItem(index, length, start);

                    length--;

                    freeCounter++;

                }

            }

      

        }

   //if not enough frees called

        while (length > 0){

            int index = rand_lim(0, length - 1);

            free(pointers[index]);

            char ** start = &pointers[0];

            deleteArrayItem(index, length, start);

            length--;

            freeCounter++;

            //printf("length: %d\n", length);

        }

        mallocCounter = 0;

        gettimeofday(&tv2, 0);

        avg += ((tv2.tv_sec-tv1.tv_sec)*1000000 + tv2.tv_usec-tv1.tv_usec);

    }

  

    printf("Total mallocs: %d\n", totalMallocs);

    printf("Successful mallocs: %d\n", successCounter);

    printf("Frees: %d\n", freeCounter);

    printf("Avg Time Elasped: %ld microseconds.\n", avg/100);

    char * test = malloc(4998);

    if (test != NULL){

       printf("TEST PASSED\n");

    }

    free(test);

}
/*test 4 next*/

/* to be continued... */
