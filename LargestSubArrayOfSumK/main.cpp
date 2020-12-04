/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 4, 2020, 7:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


pair<int, int> getLargestSubArrayOfSumK(int arr[], int size, int K){
    pair<int,int> result;
    int i=0;
    int j =0;
    int sum = 0;
    int max = INT_MIN;
    while( j<size){
        cout <<endl<<"i = " <<i <<", j= "<<j<<",  sum = "<<sum<< ", max = " <<max;
        sum = sum + arr[j];
        if( sum < K){
            j++;
        }
        else if( sum ==K){
            if( j-i+1> max){
                result.first = i;
                result.second = j;
                max = j-i+1;
                j++;
            }
        }
        else if(sum>K){
            if( arr[i]> 0){
                // following has to be done only if the element at index i is > 0
                while(sum >K){
                    sum = sum - arr[i];
                    i++;

                }
                if( sum ==K){
                    if( j-i+1> max){
                        result.first = i;
                        result.second = j;
                        max = j-i+1;
                    }
                }
            }
            j++;
        }
    }
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[] ={2,1,1,3,1,1,1,1,1,2,3,5};
    pair<int,int> result = getLargestSubArrayOfSumK(arr, 12,6);
    cout <<endl<<"Size of Largest Sub Array of sum 6 is "<<result.second - result.first +1 << " starting at index : " << result.first << " and Ending at : " << result.second;
    
    int arr1[] ={4,1,1,1,2,3,5};
    result = getLargestSubArrayOfSumK(arr1, 7,5);
    cout <<endl<<"Size of Largest Sub Array of size 5 is "<<result.second - result.first +1 << " starting at index : " << result.first << " and Ending at : " << result.second;
    
    int arr2[] ={-4,2,2,1,1,1,-1,-1,2,-3,-2,2,1,1,1,2,3,5};
    result = getLargestSubArrayOfSumK(arr2, 18,0);
    cout <<endl<<"Size of Largest Sub Array of sum 0 is "<<result.second - result.first +1 << " starting at index : " << result.first << " and Ending at : " << result.second;
    
    return 0;
}

