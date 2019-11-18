#ifndef QUICKSORT_H
#define QUICKSORT_H

/************************************************************
* quicksort: Sorts an array of integers recursively from    *
*            the smallest elements to the largest.          *
*************************************************************/

void quicksort(int array[], int low, int high);

/************************************************************
* split: Partitions the array of integers. Returns position *
*        of middle element.                                 *
*************************************************************/

int split(int array[], int low, int high);

#endif
