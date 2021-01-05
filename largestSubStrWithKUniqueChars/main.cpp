/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 5, 2021, 11:40 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include <map>


using namespace std;

int condCheck(string str){
    map<char, int>  mapOfUniqueChars;
    if(str.length()==0){
        return 0;
    }
    for( int i=0;i< str.length();i++){
        mapOfUniqueChars[str[i]]++;
    }
    return mapOfUniqueChars.size();
}

string getLargestSubStrWithkUniqeChars(string input, int k){
    int start =0;
    int end = 0;
    int len = input.length();
    string tmpStr;
    string maxLenStrWithGivenCond;
    int maxLen= 0;
    
    while( end < len){
        tmpStr.push_back(input[end]);
        if(condCheck(tmpStr)<k){
            //do nothing
        }
        if(condCheck(tmpStr)==k){
            if(tmpStr.length()> maxLen){
                maxLenStrWithGivenCond = tmpStr;
                maxLen = maxLenStrWithGivenCond.length();
            }
        }
        if(condCheck(tmpStr)>k){
            while(condCheck(tmpStr)> k){
                tmpStr.erase(tmpStr.begin()+0);
                start++;
            }
        }
        end++;
    }
    return maxLenStrWithGivenCond;
}

string getLargestSubStrWithkUniqeCharsV2(string input, int k){
    int start =0;
    int end = 0;
    int len = input.length();
    map<char,int> mp;
    mp.clear();
    string maxLenStrWithGivenCond;
    int maxLen= 0;
    string tmpStr;
    while( end < len){
        tmpStr.push_back(input[end]);
        mp[input[end]]++;
        if(mp.size()<k){
            //do nothing
        }
        if(mp.size()==k){
            if(tmpStr.length()> maxLen){
                maxLenStrWithGivenCond = tmpStr;
                maxLen = maxLenStrWithGivenCond.length();
            }
        }
        if(mp.size()>k){
            while(mp.size()> k){
                mp[tmpStr[0]]--;
                if(mp[tmpStr[0]] ==0){
                    mp.erase(tmpStr[0]);
                }
                tmpStr.erase(tmpStr.begin()+0);
                start++;
            }
        }
        end++;
    }
    return maxLenStrWithGivenCond;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string srcString="aabacbebebe";
    uint uniqueCharCount =3;
   
    cout<<"String with max length with 3 unique chars is " << getLargestSubStrWithkUniqeChars(srcString, uniqueCharCount); 
    cout<<endl<<"String with max length with 3 unique chars ( usinng api v2)  is " << getLargestSubStrWithkUniqeCharsV2(srcString, uniqueCharCount); 
    return 0;
}

