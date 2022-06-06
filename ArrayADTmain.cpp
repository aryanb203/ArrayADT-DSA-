#include <iostream>
using namespace std;

class Array{
private:
    int *A;
    int size;
    int length;
    void Swap(int *x, int *y);

public:
    Array()//constructor
    {
      size=10;
      length=0;
      A=new int[size];
    }

    Array(int sz){//constructor with input size
        size=sz;
        length=0;
        A=new int[size];
    }
    
    ~Array()
    {
        delete []A;
    }
void Display();
void Append(int x);
void Insert(int index, int x);
int Delete(int index);
int LinearSearch(int key);
int BinSearch(int key);
int Get(int index);
void Set(int index, int x);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void InsertSort(int x);
int IsSorted();
void Rearrange();
Array* Merge(Array arr2);
Array* Union(Array arr2);
Array* Intersection(Array arr2);
Array* Difference(Array arr2);
};

void Array::Display(){
    int i;
    cout<<"\nElements are: ";
    for(int i=0; i<length; i++){
     cout<<A[i]<<" ";
    } 
}

void Array::Append(int x){ //appending elements in array
    if(length<size)
     A[length++]=x;

}

void Array::Insert(int index, int x){ //Inserts an element x in the array at the specified index
    int i;
    if(index>=0 && index<=length){
        for(i=length; i>index; i--)
         A[i]=A[i-1];

        A[index]=x;
        length++; 
    }

}

void Array::Swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int Array::Delete(int index){ //deletes the element and returns the deleted element if deleted else 0
    int x=0;
    if(index>=0 && index<length){
        x=A[index];
        for(int i=index; i<length-1;i++)
         A[i]=A[i+1];
        length--;
        return x;
    }
    return 0;
}

int Array::LinearSearch(int key){ //linear search
    for(int i=0; i<length; i++){
        if(A[i]==key)
         return true;
    }
    return false;
}

int Array::BinSearch(int key){ //binary search
int l=0, h=length-1, mid; 
    while(l<=h){
    mid=(l+h)/2;
    if(A[mid]==key)
        return mid;
    else if(A[mid]<key)
        l=mid+1;
    else 
        h=mid-1;
    }
return -1;    
}

int Array::Get(int index){ //gets the value of array at an index, returns -1 if index invalid
    if(index>=0 && index<length)
        return A[index];
    return -1;
} 

void Array::Set(int index, int x){//sets element at given index(replacement if index posses value)
    if(index>=0 && index<length)
        A[index]=x;    
}

int Array::Max(){ // returns maximum valued element in the array
    int max=A[0];
    for(int i=1; i<=length; i++){
        if(A[i]>max)
         max=A[i];
    }
    return max;
}

int Array::Min(){ // returns minimum valued element in the array
    int min=A[0];
    for(int i=1; i<=length; i++){
        if(A[i]<min)
         min=A[i];
    }
    return min;
}

int Array::Sum(){ //returns sum of all elements
    int sum=0;
    for(int i=0; i<length; i++)
     sum+=A[i];

    return sum; 
}

float Array::Avg(){
     return (float)Sum()/length;
}

void Array::Reverse(){ //reversing elemnts of the array 
    int i,j;
    for(i=0, j=length-1; i<j; i++, j--){
        Swap(&A[i], &A[j]);
    }
}

void Array::InsertSort(int x){ //inserting element in a sorted array
    if(length==size)
        return;

    int i=length-1;
    while(i>=0 && A[i]>x){
        A[i+1]=A[i];
        i--;
    }
    A[i]=x;
    length++;
}

int Array::IsSorted(){ //returns 1 if array is sorted in ascending order
for(int i=0;i<length-1;i++)
    if(A[i]>A[i+1])
        return 0;

    return 1;    
}

void Array::Rearrange(){ //all -ve numbers on the left side
int i=0,j=length-1;
while(i<j){
    while(A[i]<0){ i++;}
    while(A[j]>=0){ j--;}
    if(i<j){
        Swap(&A[i], &A[j]);
    }
}
}



Array* Array::Merge(Array arr2){ //merging 2 arrays into 3rd
int i=0, j=0, k=0;
Array *arr3 = new Array(length + arr2.length);

while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j])
        arr3->A[k++]=A[i++];
    else 
        arr3->A[k++]=arr2.A[j++];
}

for(;i<length; i++){
    arr3->A[k++]=A[i];
}

for(;j<arr2.length; j++){
    arr3->A[k++]=arr2.A[i];
}

arr3->length=length + arr2.length;
return arr3;
}



Array* Array::Union(Array arr2){ //union of 2 sets
int i=0, j=0, k=0;
Array *arr3 = new Array(length + arr2.length);

while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j])
        arr3->A[k++]=A[i++];
    else if(A[i]>arr2.A[j])
        arr3->A[k++]=arr2.A[j++];
    else{
        arr3->A[k++]=A[i++];
        j++;
    }
}

for(;i<length; i++){
    arr3->A[k++]=A[i];
}

for(;j<arr2.length; j++){
    arr3->A[k++]=arr2.A[i];
}

arr3->length=k;
return arr3;
}

Array* Array::Intersection(Array arr2){//intersection of 2 sets
int i=0, j=0, k=0;
Array *arr3 = new Array(length + arr2.length);

while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j])
        i++;
    else if(A[i]>arr2.A[j])
        j++;
    else{
        arr3->A[k++]=A[i++];
        j++;
    }
}

arr3->length=k;
return arr3;
}


Array* Array::Difference(Array arr2){ //difference of 2 sets
int i=0, j=0, k=0;
Array *arr3 = new Array(length + arr2.length);

while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j])
        arr3->A[k++]=A[i++];
    else if(arr2.A[j]<A[i])
        j++;
    else{
        i++;
        j++;
    }
}

for(;i<length; i++){
    arr3->A[k++]=A[i];
}

arr3->length=k;
return arr3;
}

int main(){

    Array *arr1;
    int ch, sz;
    int x, index;

    cout<<"Enter size of the Array:";
    cin>>sz;
    arr1 = new Array(sz);

do
 {
 cout<<"\n\nMenu\n";
 cout<<"1. Insert\n";
 cout<<"2. Delete\n";
 cout<<"3. Search\n";
 cout<<"4. Sum\n";
 cout<<"5. Display\n";
 cout<<"Press any other number to exit"; 
 
cout<<"Enter you choice ";
cin>>ch;
 
switch(ch)
{
    case 1: cout<<"Enter an element and index ";
     cin>>x>>index;
     arr1->Insert(index,x);
    break;
    case 2: cout<<"Enter index ";
     cin>>index;
     x=arr1->Delete(index);
     cout<<"Deleted Element is"<<x;
    break;
    case 3:cout<<"Enter element to search ";
     cin>>x;
     index=arr1->LinearSearch(x);
     cout<<"Element index "<<index;
    break;
    case 4:cout<<"Sum is "<<arr1->Sum();
    break;
    case 5:arr1->Display();
 
    }
}while(ch<6);

return 0;
}
