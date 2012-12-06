#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <cctype>
#include <stdlib.h>


using namespace std;
char Cezar (char *s, int key) {
     int size;
     char result[1000]; 
     size = strlen(s);
     if( key > size) {
     key = key-size;
     }
     int count = key; 
     for (int i = 0; i < size; i++) {
         label:
         while (count > 1) {
               result[i] = s[size-key+i];
               count--;
               i++;
               goto label;
               }
           result[i]= s[i-key+1];
           }
                for (int i = 0; i < size; i++) 
                cout << result[i];
           return *result;
     }

int main (int argc, char*argv[]) {
char *stroka;
int key;
char code[] = "code";
    if (strcmp(argv[1], code)==0) {
                stroka = argv[2];
                key = atoi(argv[3]);
                Cezar(stroka, key);
                return 0;
                }            
                cout << "dfhb";    
                return 0;
                }
                
    
                
    