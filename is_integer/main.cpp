//
//  main.cpp
//  is_integer
//
//  Created by Mateus Mesturini Meruvia on 2/19/16.
//  Copyright © 2016 Mateus Mesturini Meruvia. All rights reserved.
//

#include <iostream>
#include <string>

bool is_integer(std::string str){
    int n,i, current=0;
    n = str.length();
    
    for(i=0; i<n; i++){

        if( str[i]=='0'   // check if the char is a digit
           || str[i]=='1'
           || str[i]=='2'
           || str[i]=='3'
           || str[i]=='4'
           || str[i]=='5'
           || str[i]=='6'
           || str[i]=='7'
           || str[i]=='8'
           || str[i]=='9'){
            
                current++; // if char = digit use this variable to skip the next if
        }
        
        if (i == 0) { // +/- signs are only allowed in the position [0] of the string
            if( str[i]=='+' || str[i]=='-'){ // check if is a +/- sign
                if (current == i) { // check if the current position is equal to the 'i' position, if not skips
                    current++;
                }
            }
        }
        
        if(current == i) { // if 'current' and 'i' have the same value at this point it means that
            return false;  // none of the previous conditions were fullfilled, so its not a integer, returns FALSE
        }
        
        
    }
    return true;
}

int main(int argc, const char * argv[]) {

        std::string integer;
    
    while (1) {
        
        std::cout << "Input: ";
        std::getline (std::cin,integer); // reads a string from the standart input
    
    
        if(is_integer(integer)==true){
            printf("Output: ACCEPTED\n\n");
        }else{
            printf("Output: NOT ACCEPTED\n\n");}
    }
    return 0;
}
