//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// max heap
class heap{
    public:
        int arr[100];
        int size = 0;
    
    heap(){
        arr[0] =-1;
        size=0;
    }
    void insert(int val){
        size++;
        int index =size;
        arr[index]= val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex <size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(51);
    h.insert(52);
    h.insert(78);
    h.insert(21);
    h.insert(12);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}