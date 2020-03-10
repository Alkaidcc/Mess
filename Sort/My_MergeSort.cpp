void My_MergeSort(int arr[],const int length){      //转换接口
    int reg[length];

    Merge_Sort_Recursive(arr,reg,0,length-1);

}

void Merge_Sort_Recursive(int arr[],int reg[],int start,int end){
    //递归出口
    if(start >= end)
        return;
    int len = end - start;
    int mid = len/2 + start;
    int start1 = start,start2 = mid+1;
    int end1 = mid,end2 = end;
    int k = start;

    Merge_Sort_Recursive(arr,reg,start1,end1);
    Merge_Sort_Recursive(arr,reg,start2,end2);

    while(start1 <= end1 && start2 <= end2)
        reg[k++]=arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while(start1 <= end1)
        reg[k++] = arr[start1++];
    while(start2 <= end2)
        reg[k++] = arr[start2++];
    for(k=start;k<=end;k++)
        arr[k] = reg[k];
}