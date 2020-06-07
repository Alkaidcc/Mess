int Partition(SqList &L, int low, int high) {
    L.arr[0] = L.arr[low];
    int pivot = L.arr[low].info;
    while(low < high) {
        while(low < high && L.arr[high].info >= pivot)
            high--;
        L.arr[low] = L.arr[high];
        while(low < high && L.arr[low].info <= pivot)
            low++;
        L.arr[high] = L.arr[low];
    }
    L.arr[low] = L.arr[0];
    return low;
}

void QuickSort(SqList &L) {
    Sort(L, 1, L.length);
}
void Sort(SqList &L, int start, int end) {
    if(start < end) {
        int pivot = Partition(L, start, end);
        Sort(L,start, pivot - 1);
        Sort(L,pivot + 1, end);
    }
}