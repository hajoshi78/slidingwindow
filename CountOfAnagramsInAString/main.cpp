/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 3, 2020, 1:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool anagramCheck(map<char,int> anagramCharMap, string toCheck){
    for(int i=0;i<toCheck.length();i++){
        if(anagramCharMap.find(toCheck[i])!= anagramCharMap.end()){
            anagramCharMap[toCheck[i]]--;
            if(anagramCharMap[toCheck[i]]==0){
                anagramCharMap.erase(toCheck[i]);
            }
        }
    }
    if(anagramCharMap.size()==0){
        return true;
    }
    return false;
}
int anagramCount(string a, string b){
    map<char,int> anagramCharMap;
    int anagramCount=0;
    int slidingWindowSize = b.length();
    for(int i=0; i< b.length();i++){
        anagramCharMap[b[i]]++;
    }
    int i=0;
    int j=0;
    string toCheck="";
    while(j<a.length()){
        toCheck.push_back(a[j]);
        if(j-i+1 <slidingWindowSize){
            j++;
        }
        else{
            if(anagramCheck(anagramCharMap, toCheck)){
                anagramCount++;
            }
            toCheck.erase(toCheck.begin()+0);
            i++;
            j++;
        }
    }
    return anagramCount;
}
/*
 * 
 */
int main(int argc, char** argv) {
    string a="foraxxorfcraofzfroorfxx";
    string b="for";
    cout<<endl<<"Anagram count : " << anagramCount(a,b);
    return 0;
}

