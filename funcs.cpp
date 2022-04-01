#include <iostream>
#include "funcs.h"
#include <array> 
#include <cctype> 
#include <cmath> 
#include <climits> 



const std::array<char, 26> UP =
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const std::array<char, 26> DOWN = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


const std::array<double, 26> FREQUENCIES =
{.084966, .020720, .045388, .033844, .111607, .018121, .024705, .030034, .075448, .001964, .011016, .054893, .030129, .066544, .071635, .031671, .001962, .075809, .057351, .069509, .036308, .010074, .012899, .002902, .017779, .002722};


char shift_char(char c, int rshift)
{
    for(int z = 0; z < 26; z++){
        if(c == UP[z] || c == DOWN[z]){
            return isupper(c) ? UP[(z + rshift) % 26] : DOWN[(z+rshift) % 26];
        }
    }
    return c;
}

std::string caesar_encrypted(std::string plaintext, int rshift)
{
    std::string result = "";

    for(int z =0; z < plaintext.length(); z++){
        result += shift_char(plaintext.at(z), rshift);
    }
    return result;
}



char shift_char_uncipher(char c, int rshift){
    int shifter = rshift % 26; 
    shifter = 26 - shifter; 

    if(shifter < 0){
        for(int z = 0; z < 26; z++){
            if(c == UP[z] && z - shifter > 25){
                return UP[(z - shifter) - 26];
            }else if(c == UP[z] && z - shifter > 25){
                return DOWN[(z-shifter) - 26];
            }else if(UP[z] ==  c){
                return UP[z - shifter];
            }else if(DOWN[z] == c){
                return DOWN[z - shifter];
            }
        }
    }else{
        for(int z = 0; z < 26; z++){
            if(c == UP[z] && z - shifter < 0){
                return UP[26 - (shifter - z)];
            }else if(c == DOWN[z] && z - shifter < 0){
                return DOWN[26 - (shifter - z)];
            }else if(UP[z] == c){
                return UP[z - shifter];
            }else if(DOWN[z] == c){
                return DOWN[z - shifter];
            }
        }
    }
    return c; 
}

std::string solve(std::string encrypted_string) { 
    int min;
    double letter_count = 0;
    double rotation_total = 0;
    std::string result = "";
    std::string test_string = "";
    double smallest = INT_MAX;

    std::array<double, 26> letter_freq = 
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    for(int i = 0; i < 26; i++) { 
        test_string = caesar_encrypted(encrypted_string, i);
        for(int j = 0; j < 26; j++) { 
            for(int k = 0; k < encrypted_string.length(); k++) {
                if(test_string[k] == UP[j] || test_string[k] == DOWN[j]) {
                    letter_freq[j]++;
                    letter_count++;
                }
            }
        }

        for(int i = 0; i < 26; i++) { 
            letter_freq[i] = letter_freq[i] / letter_count; 
            letter_freq[i] = std::fabs(letter_freq[i] - FREQUENCIES[i]); 
            rotation_total += letter_freq[i]; 

            letter_freq[i] = 0;
        }

        if(rotation_total < smallest) { 
            smallest = rotation_total; 
            min = i; 
        }

        rotation_total = 0; 
        letter_count = 0;         
    }
    
    for(int i = 0; i < encrypted_string.length(); i++) { 
        result += shift_char_uncipher(encrypted_string[i], min);
    }

    return result; 
}
