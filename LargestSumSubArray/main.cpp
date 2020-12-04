/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 4, 2020, 10:54 PM
 */

#include <cstdlib>
#include <iostream>

#include <bits/stdc++.h>


using namespace std;


//This problem can be solved in o(n) using Kadane's algorithm

pair<int, pair<int,int>> getMaxSumSubArray(int arr[], int size){
    pair<int, pair<int,int>> result;
    int currentMax =arr[0];
    int currentMaxIndexStart=0;
    int currentMaxIndexEnd = 0;
    int globalMax =arr[0];
   
    
    for( int i=1;i< size;i++){
        if( arr[i]> currentMax + arr[i]){ 
            currentMax = arr[i];
            currentMaxIndexStart = i;
        }
        else{
            currentMax = currentMax+ arr[i];
            
        }
        if( currentMax > globalMax){
            globalMax = currentMax;
            currentMaxIndexEnd = i;
        }
    }
     result = make_pair(globalMax, make_pair(currentMaxIndexStart,currentMaxIndexEnd));
     return result;
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={-2,-3,2,-1,4,1,2};
    pair<int, pair<int,int>> result = getMaxSumSubArray(arr, 7);
    cout <<endl<< "Max Sum : " << result.first <<" Starting Index : " <<result.second.first << "  Ending Index " << result.second.second;
    return 0;
}

