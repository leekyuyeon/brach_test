
#ifndef SORT_H
#define SORT_H


#ifdef __cplusplus
extern "C" {
#endif


void Exchange(float *Data, int x, int y);
int Partition(float *Data, int Left, int Right);
void QuickSort(float *Data, int Left, int Right);
void InsertionSort(float *Data, int Number);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_XINTF_H definition

//===========================================================================
// No more.
//===========================================================================
