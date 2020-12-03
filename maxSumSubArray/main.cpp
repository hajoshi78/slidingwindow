/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 3, 2020, 10:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


vector<pair<int,pair<int,int>>> getMaxSumSubArray(int arr[], int size, int windowSize){
    int i=0;
    int j=0;
    int sum=0;
    vector<pair<int , pair<int,int>>> result;
    while(i<(size -windowSize +1)){ // or  j< size
        
        //till you hit the window size increment j and get intermediate answers
        sum = sum+ arr[j];
        if((j-i+1)!=windowSize){
            j++;
        }
        else{
            result.push_back(make_pair(sum,make_pair(i,j)));
            sum = sum - arr[i];
            i++;
            j++;
            
        }
    }
    return result;
}
pair<int, pair<int,int>> getMax(vector<pair<int,pair<int,int>>> inputData){
    int maxIndex= INT_MIN;
    pair<int, pair<int,int>> result;
    int index =0;
    int max =INT_MIN;
    
    for (auto x: inputData){
        if( x.first> max){
            maxIndex = index;
            max = x.first;
                    
        }
        index++;
    }
    return inputData[maxIndex];
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,-1,2,-3,4,-5,6,3,6,8,-8,7,10};
    vector<pair<int,pair<int,int>>> result = getMaxSumSubArray(arr, 13,3);
    for (auto x: result){
        cout<<endl<<"Sum : " <<x.first << ", Start Index : " <<x.second.first <<  ", End Index : " <<x.second.second; 
    }
    
    pair<int, pair<int,int>> maxRow = getMax(result);
    cout<<endl<<" Max sum is " <<maxRow.first << ", Start Index : " <<maxRow.second.first <<  ", End Index : " <<maxRow.second.second; 
    return 0;
}

