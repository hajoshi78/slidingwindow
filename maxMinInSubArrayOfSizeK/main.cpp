
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>


using namespace std;

vector<int> getMaxInSubArray( int arr[], int n, int k){
    int start =0;
    int end = 0;
    list<int> listOfMax;
    vector<int> result;
    
    while(end< n){
        if(listOfMax.size()==0){
           listOfMax.push_back(arr[end]); 
        }
        if( listOfMax.size()!=0 && listOfMax.front()<arr[end]){
            while(listOfMax.size()!=0 && listOfMax.front()<arr[end] ){
                listOfMax.pop_front();
            }
            listOfMax.push_back(arr[end]);
        }
        if( end -start +1 < k){
            end++;
        }
        else if( end - start +1 ==k){
            result.push_back(listOfMax.front());
            if(listOfMax.front()== arr[start]){
                listOfMax.pop_front();
            }
            start++;
            end++;
        }
    }
    return result;
}


vector<int> getMinInSubArray( int arr[], int n, int k){
    int start =0;
    int end = 0;
    list<int> listOfMin;
    vector<int> result;
    
    while(end< n){
        if(listOfMin.size()==0){
           listOfMin.push_back(arr[end]); 
        }
        if( listOfMin.size()!=0 && listOfMin.front()>arr[end]){
            while(listOfMin.size()!=0 && listOfMin.front()>arr[end] ){
                listOfMin.pop_front();
            }
            listOfMin.push_back(arr[end]);
        }
        if( end -start +1 < k){
            end++;
        }
        else if( end - start +1 ==k){
            result.push_back(listOfMin.front());
            if(listOfMin.front()== arr[start]){
                listOfMin.pop_front();
            }
            start++;
            end++;
        }
    }
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {

    int arr[]={4,2,5,6,3,1,7,9,6,2};
    int size = 10;
    int windowSize= 3;
    vector<int> maxElemInSubArray = getMaxInSubArray(arr,size, windowSize);
    
    vector<int> minElemInSubArray = getMinInSubArray(arr,size, windowSize);
    
    cout<<"Max Element in the subArray for each window of size K : "<<endl;
    for(auto x:maxElemInSubArray ){
        cout<<x<<"\t";
    }
    
    cout<<endl<<"Min Element in the subArray for each window of size K : "<<endl;
    for(auto x:minElemInSubArray ){
        cout<<x<<"\t";
    }
    
    return 0;
}

