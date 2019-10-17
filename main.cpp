#include <iostream>
#include <vector>



void merge(std::vector<int>& arr, int l, int m, int r){
    int lC=l, rC=m+1;
    int cursor = 0;
    int tempArr[r-l+1];
    while(lC<=m && rC<=r){
        if(arr[lC]<=arr[rC]){
            tempArr[cursor++] = arr[lC];
            lC++;
        }else{
            tempArr[cursor++] = arr[rC];
            rC++;
        }
    }
    while(lC<=m){
        tempArr[cursor++] = arr[lC++];
    }
    while(rC<=r){
        tempArr[cursor++] = arr[rC++];
    }
    int paste = 0;
    for(int i = l;i<=r;i++){
        arr[i] =  tempArr[paste++];
    }
}
void mergeSort(std::vector<int>& arr,int l, int r){

    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }



}

int main() {
    std::vector<int> test = {1,2,3,4};
    mergeSort(test,0,test.size()-1);
    int i = 0;

    return 0;
}