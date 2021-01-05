/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 6, 2021, 12:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

string getMaxToySelectionWithGivenCriteria(string toyArray, int typeCount){
    int start =0;
    int end = 0;
    int totalToyCount = toyArray.length();
    unordered_map<char,int> mpOfToyCats;
    string tempToyStr;
    string maxToyStr;
    int maxToyStrLen=0;
    
    while(end< totalToyCount){
        tempToyStr.push_back(toyArray[end]);
        mpOfToyCats[toyArray[end]]++;
        
        if(mpOfToyCats.size()<typeCount){
            end++;
        }
        else if(mpOfToyCats.size() ==typeCount){
            if(tempToyStr.length()> maxToyStrLen){
                maxToyStrLen = tempToyStr.length();
                maxToyStr = tempToyStr;
            }
            end++;
        }
        else if(mpOfToyCats.size() >typeCount){
            while(mpOfToyCats.size()>typeCount){
                mpOfToyCats[tempToyStr[0]]--;
                if(mpOfToyCats[tempToyStr[0]]==0){
                    mpOfToyCats.erase(tempToyStr[0]);
                }
                tempToyStr.erase(tempToyStr.begin()+0);
                start++;
            }
            end++;
        }
    }
    return maxToyStr;
}


/*
 * 
 */
int main(int argc, char** argv) {
    string toyArray="aabacbbbbbcccacacacagsgsgsgsxxxyyyyxyxyxyxygsgssssssscacacacaca";
    int toyCatCount=2;
    string result = getMaxToySelectionWithGivenCriteria(toyArray,toyCatCount);
    cout<<endl<<"Max Toys that can collected from the given toy collection and with Given Category Count (2) is " << result ;
    return 0;
}

