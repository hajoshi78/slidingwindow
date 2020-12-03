/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 3, 2020, 11:17 AM
 */

#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

vector<pair<int,pair<int,int>>> getMaxInSubArray(int arr[], int size, int windowSize){
    int i=0,j=0;
    vector<pair<int,pair<int,int>>> result;
    list<int> maxElemInWindowList;
    while( i<(size-windowSize+1)){
        //Caluclation
        while(maxElemInWindowList.size()> 0 && arr[j]>maxElemInWindowList.back()){
            maxElemInWindowList.pop_back();
        }
        maxElemInWindowList.push_back(arr[j]);
        //Check for the first window Size
        if( j-i +1 < windowSize){
            j++;
        }
        else{
            //Answer and then slide the window
            result.push_back(make_pair(maxElemInWindowList.front(), make_pair(i,j)));
            if( arr[i]== maxElemInWindowList.front()){
                maxElemInWindowList.pop_front();
            }
            i++;
            j++;
        }
    }
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {

    int arr[]={1,-1,2,-3,4,-5,6,3,6,8,-8,7,10};
    vector<pair<int,pair<int,int>>> result = getMaxInSubArray(arr, 13,3);
    for (auto x: result){
        cout<<endl<<"Max Element is : " <<x.first << ", Start Index : " <<x.second.first <<  ", End Index : " <<x.second.second; 
    }
    
//    pair<int, pair<int,int>> maxRow = getMax(result);
//    cout<<endl<<" Max sum is " <<maxRow.first << ", Start Index : " <<maxRow.second.first <<  ", End Index : " <<maxRow.second.second; 
    return 0;
}