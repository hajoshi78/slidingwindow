/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on January 5, 2021, 8:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int getAsciiVal(char ch){
    return (int(ch));
}

int anagramCount(string srcString, string anagramString){
    int anagramCnt = 0;
    int start = 0;
    int end = 0;
    
    int anagramLength = anagramString.length();
    int srcStrLen = srcString.length();
    
    int asciiSum = 0;
    for( int i=0;i<anagramLength;i++){
        asciiSum+= getAsciiVal(anagramString[i]);
    }
    
    int checkSum = 0;
    while(end < srcStrLen){
        checkSum+= getAsciiVal(srcString[end]);
        if( end - start +1 <anagramLength){
            end++;
        }
        else if( end - start +1 == anagramLength){
            if(checkSum == asciiSum){
                anagramCnt++;
            }
            checkSum-= getAsciiVal(srcString[start]);
            start++;
            end++;
        }
    }
    return anagramCnt;
}
/*
 * 
 */
int main(int argc, char** argv) {
    string srcString="foxapofxofofxpqrxof";
    string anagramStr = "fox";
    cout<<"Number of Anagrams of fox in given string is " << anagramCount(srcString, anagramStr);
    return 0;
}

