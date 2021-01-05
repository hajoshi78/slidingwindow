/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 5, 2021, 3:25 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

vector<int> getFrstNegNumInWndw(int arr[], int n, int k){
    vector<int> result;
    int start =0; 
    int end =0;
    list<int> negNumList;
    
    while( end< n){
        if( arr[end]<0){
            negNumList.push_back(arr[end]);
        }
        if( end - start +1 < k){
            end++;
        }
        else if(end - start +1 == k){
            if(negNumList.size()>0){
                result.push_back(negNumList.front());
            }
            else if( negNumList.size() == 0){
                result.push_back(0);
            }
            if(arr[start] == negNumList.front()){
                negNumList.pop_front();
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
    int arr[]={2,-1,-3,4,6,7,8,-4,-6,1,1,-1};
    int size = 12;
    int wndSize = 3;
    vector<int> result = getFrstNegNumInWndw(arr, size, wndSize);
    cout <<endl<< "First Negative Numbers in the list for window size  : "<< endl;
    for( auto x: result){
        cout << x<<"\t";
    }
    return 0;
}

