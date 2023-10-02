#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string& str) {
    for(int i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - i - 1]) return false;
     }
     return true;
}

bool is_vowel(char ch) {
    string v = "aeiouAEIOU";
    return v.find(ch) != -1;
}

string to_lowercase(string& s) {
    for(int i = 0; i < s.size(); i++) 
        if(s[i] <= 'Z') s[i] += 32;
    return s;
}

void ascii_value(char ch) {
    // '0' -> 48
    // 'A' -> 65
    // 'a' -> 97
    cout << int(ch) << "\n";
}

int main() {


}