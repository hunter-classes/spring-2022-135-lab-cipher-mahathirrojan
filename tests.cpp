#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Checking if Caesar Cipher works:" ) { 
    CHECK(caesar_encrypted("Hello, World!" , 10) == "Rovvy, Gybvn!");
    CHECK(caesar_encrypted("This works!", 400) == "Drsc gybuc!");
}

TEST_CASE("Checking for solve solution: ") { 
    CHECK(solve("Testing if a regular string works") == "Testing if a regular string works");
    CHECK(solve(caesar_encrypted("For each of the 26 rotations of encrypted string: Make a 26 space vector with the frequencies of all the letters based on encrypted_string. Note that entries will be 0 for letters that dont appear in the input string. Calculate the distance between this vector and the vector of letter frequencies for English.", 5)) == "For each of the 26 rotations of encrypted string: Make a 26 space vector with the frequencies of all the letters based on encrypted_string. Note that entries will be 0 for letters that dont appear in the input string. Calculate the distance between this vector and the vector of letter frequencies for English.");
}
