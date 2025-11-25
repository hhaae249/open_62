#include <stdio.h>
int partition(int A[], int l, int r) {
    int pivot = A[l];
    int i = l; //0
    int j = r + 1;//8
    
    while (1) {
        do {
            i++;
        } while (i <= r && A[i] < pivot);
        
        do {
            j--;
        } while (j >= l && A[j] > pivot);
        
        if (i >= j) {
            break;
        }
        
        // 交换 A[i] 和 A[j]
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    if (l != j) {
        // 交换 A[l] 和 A[j]
        int temp = A[l];
        A[l] = A[j];
        A[j] = temp;
    }
    
    return j;
}

// 快速排序函数
void quicksort(int A[], int l, int r) {
    if (l < r) {
        int s = partition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[7];
    for(int i=0;i<8;i++){
        scanf("%d",&A[i]);
    }
    int n = sizeof(A) / sizeof(A[0]);
    printf("%d\n",n);
    printf("排序前: ");
    printArray(A, n);
    
    quicksort(A, 0, n - 1);
    
    printf("排序后: ");
    printArray(A, n);
    
    return 0;
}
