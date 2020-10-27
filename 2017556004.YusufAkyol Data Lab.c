#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//Ýnsertion Sort
void insertionSort(int arr[], int n)
{
    int i, file, j;
    for (i = 1; i < n; i++) {
        file = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > file) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = file;
    }
}
//insertion sort

void insertionSortChar(char arr[], int n)
{
    int i, j;
    char file;
    for (i = 1; i < n; i++) {
        file = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > file) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = file;
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//integer array for selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}

//Char array for selection sort
void selectionSortChar(char arr[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swapChar(&arr[min], &arr[i]);
    }
}

//bubble sort for integers
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

//bubble sort for chars
void bubbleSortChar(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapChar(&arr[j], &arr[j + 1]);
}

// Merge sort algorithm
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void mergeChar(char arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortChar(char arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);

        mergeChar(arr, l, m, r);
    }
}

int main()
{

    printf("NAME: YUSUF AKYOL, ID NUMBER: 2017556004\n\n");
    int idnumber[] = {2,0,1,7,5,5,6,0,0,4 };
    char name[] = "YUSUF AKYOL";
    int numSize = sizeof(idnumber) / sizeof(idnumber[0]);
    int nameSize = strlen(name);
    clock_t start, end;
    double totaltime;

    //time for insertion sort. 

    start = clock();
    insertionSort(idnumber, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion sort__number array :");
    printArray(idnumber, numSize);
    

    start = clock();
    insertionSortChar(name, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nInsertion sort__name array :");
    printf("%s", name);
    
    printf("\n");
    //time for selection sort

    int idnumber2[] = { 2,0,1,7,5,5,6,0,0,4 };
    char name2[] = "YUSUF AKYOL";

    start = clock();
    selectionSort(idnumber2, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort__number array : ");
    printArray(idnumber2, numSize);
    

    start = clock();
    selectionSortChar(name2, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSelection sort__name array : ");
    printf("%s\n", name2);
    

    
    //time for bubble sort
    int idnumber3[] = { 2,0,1,7,5,5,6,0,0,4 };
    char name3[] = "YUSUF AKYOL";

    start = clock();
    bubbleSort(idnumber3, numSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble sort__number array : ");
    printArray(idnumber3, numSize);
    

    start = clock();
    bubbleSortChar(name3, nameSize);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble sort__name array : ");
    printf("%s\n", name3);
    
    printf("\n");
    
    //time for merge sort
    
    int idnumber4[] = { 2,0,1,7,5,5,6,0,0,4};
    char name4[] = "YUSUF AKYOL";

    start = clock();
    mergeSort(idnumber4, 0, numSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Merge sort__int array : ");
    printArray(idnumber4, numSize);
    

    start = clock();
    mergeSortChar(name4, 0, nameSize - 1);
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMerge sort__name array : ");
    printf("%s", name4);
    

    return 0;
} 
