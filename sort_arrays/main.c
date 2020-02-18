#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i = 0;

void notDesc(int *arr, int size){
    for(i = 0; i < size; i++){
        arr[i] = i;
    }
}

void randArr(int *arr, int size){
    int liczba;
    for(i = 0; i < size; i++){
        liczba = rand()%100+1;
        arr[i] = liczba;
    }
}

void notAsc(int *arr, int size){
    int a = 0;
    for(i = size-1; i >= 0; i--){
        arr[i] = a;
        a++;
    }
}

void printArr(int *arr, int size){
    for(i = 0; i < size; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void copyArr(int *arr1, int *arr2, int size){
    for(i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }
}

void bubbleSort(int *arr, int size){
    int tmp;
    do{
        for(i = 0; i < size-1; i++){
            if(arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
        size--;
    }while(size > 1);
}

void insertSort(int *arr, int size){
    int j, tmp;
    for(i = 1; i < size; i++){
        tmp = arr[i];
        j = i-1;
        while(arr[j] > tmp && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}

void quickSort(int *arr, int left, int right){
    int tmp;
    int l = left;
    int r = right;
    int pivot = arr[(left+right)/2];
    do{
        while(arr[l] < pivot){
            l++;
        }
        while(arr[r] > pivot){
            r--;
        }
        if(l <= r){
            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }while(l <= r);

    if(left < r){
        quickSort(arr, left, r);
    }
    if(right > l){
        quickSort(arr, l, right);
    }
}

void call(int *tmp, int *arr, int size, int condition){
    clock_t start, stop;
    double counter;

    if(condition == 0){ /* Insert,Bubble < 60 */
        copyArr(arr, tmp, size);
        start = clock();
        insertSort(tmp, size);
        stop = clock();
        counter = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("INSERT-SORT: %.2f \n", counter);

        copyArr(arr, tmp, size);
        start = clock();
        bubbleSort(tmp, size);
        stop = clock();
        counter = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("BUUBLE-SORT: %.2f \n", counter);
    }else if(condition == 1){ /* Bubble > 60*/
        copyArr(arr, tmp, size);
        start = clock();
        insertSort(tmp, size);
        stop = clock();
        counter = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("INSERT-SORT: %.2f \n", counter);

        printf("BUBBLE-SORT: 60+\n");
    }else if(condition == 2){ /* Insert, Bubble > 60*/
        printf("INSERT-SORT: 60+\n");
        printf("BUBBLE-SORT: 60+\n");
    }else if(condition == 4){ /* Print 10^1 */
        copyArr(arr, tmp, size);
        start = clock();
        insertSort(tmp, size);
        stop = clock();
        counter = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("INSERT-SORT: %.2f \n", counter);
        printArr(tmp, size);

        copyArr(arr, tmp, size);
        start = clock();
        bubbleSort(tmp, size);
        stop = clock();
        counter = (stop - start)/(double)CLOCKS_PER_SEC;
        printf("BUUBLE-SORT: %.2f \n", counter);
        printArr(tmp, size);

    }

    copyArr(arr, tmp, size);
    start = clock();
    quickSort(tmp, 0, size-1);
    stop = clock();
    counter = (stop - start)/(double)CLOCKS_PER_SEC;
    printf("QUICK-SORT: %.2f \n", counter);
    (condition == 4) ? (printArr(tmp, size)) : (void) 0; /* Print 10^1 */

    free(arr);
}

int main(){
    int *tmp, *A01, *A02, *A03, *A04, *A05, *A06, *A07, *A08, *A09, *A10, *A11, *A12,
        *A13, *A14, *A15, *A16, *A17, *A18, *A19, *A20, *A21;
    int size = 10;
    srand((unsigned) time(NULL));

    printf("rozmiar: 10^1 \n");
    tmp = (int*)calloc(size, sizeof(int));

    A01 = (int*)calloc(size, sizeof(int));
    notDesc(A01, size);
    printf("niemalejaco:\n");
    printArr(A01, size);
    call(tmp, A01, size, 4);

    A02 = (int*)calloc(size, sizeof(int));
    randArr(A02, size);
    printf("losowo:\n");
    printArr(A02, size);
    call(tmp, A02, size, 4);

    A03 = (int*)calloc(size, sizeof(int));
    notAsc(A03, size);
    printf("nierosnaco:\n");
    printArr(A03, size);
    call(tmp, A03, size, 4);

    printf("rozmiar: 10^2 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A04 = (int*)calloc(size, sizeof(int));
    notDesc(A04, size);
    printf("niemalejaco:\n");
    call(tmp, A04, size, 0);

    A05 = (int*)calloc(size, sizeof(int));
    randArr(A05, size);
    printf("losowo:\n");
    call(tmp, A05, size, 0);

    A06 = (int*)calloc(size, sizeof(int));
    notAsc(A06, size);
    printf("nierosnaco:\n");
    call(tmp, A06, size, 0);

    printf("rozmiar: 10^3 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A07 = (int*)calloc(size, sizeof(int));
    notDesc(A07, size);
    printf("niemalejaco:\n");
    call(tmp, A07, size, 0);

    A08 = (int*)calloc(size, sizeof(int));
    randArr(A08, size);
    printf("losowo:\n");
    call(tmp, A08, size, 0);

    A09 = (int*)calloc(size, sizeof(int));
    notAsc(A09, size);
    printf("nierosnaco:\n");
    call(tmp, A09, size, 0);

    printf("rozmiar: 10^4 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A10 = (int*)calloc(size, sizeof(int));
    notDesc(A10, size);
    printf("niemalejaco:\n");
    call(tmp, A10, size, 0);

    A11 = (int*)calloc(size, sizeof(int));
    randArr(A11, size);
    printf("losowo:\n");
    call(tmp, A11, size, 0);

    A12 = (int*)calloc(size, sizeof(int));
    notAsc(A12, size);
    printf("nierosnaco:\n");
    call(tmp, A12, size, 0);

    printf("rozmiar: 10^5 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A13 = (int*)calloc(size, sizeof(int));
    notDesc(A13, size);
    printf("niemalejaco:\n");
    call(tmp, A13, size, 0);

    A14 = (int*)calloc(size, sizeof(int));
    randArr(A14, size);
    printf("losowo:\n");
    call(tmp, A14, size, 0);

    A15 = (int*)calloc(size, sizeof(int));
    notAsc(A15, size);
    printf("nierosnaco:\n");
    call(tmp, A15, size, 0);

    printf("rozmiar: 10^6 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A16 = (int*)calloc(size, sizeof(int));
    notDesc(A16, size);
    printf("niemalejaco:\n");
    call(tmp, A16, size, 1);

    A17 = (int*)calloc(size, sizeof(int));
    randArr(A17, size);
    printf("losowo:\n");
    call(tmp, A17, size, 2);

    A18 = (int*)calloc(size, sizeof(int));
    notAsc(A18, size);
    printf("nierosnaco:\n");
    call(tmp, A18, size, 2);

    printf("rozmiar: 10^7 \n");
    size *= 10;
    tmp = (int*)realloc(tmp, size * sizeof(int));

    A19 = (int*)calloc(size, sizeof(int));
    notDesc(A19, size);
    printf("niemalejaco:\n");
    call(tmp, A19, size, 1);

    A20 = (int*)calloc(size, sizeof(int));
    randArr(A20, size);
    printf("losowo:\n");
    call(tmp, A20, size, 2);

    A21 = (int*)calloc(size, sizeof(int));
    notAsc(A21, size);
    printf("nierosnaco:\n");
    call(tmp, A21, size, 2);

    free(tmp);
    return 0;
}
