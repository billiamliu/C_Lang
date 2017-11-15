#include <stdlib.h>
#include <stdio.h>

int compare(int *i, int *j)
{
  return *i - *j;
}

int main()
{
  int arr[] = { 8, 4, 1, 3 };
  int i;

  qsort(arr, 4, sizeof(int), (int (*) (const void *, const void *)) &compare);

  for (i = 0; i < 4; i++)
    printf("number %d is %d\n", i, arr[i]);
  
}
