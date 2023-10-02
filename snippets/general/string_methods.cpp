#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string& str) {
    for(size_t i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - i - 1]) return false;
     }
     return true;
}

bool is_vowel(char ch) {
    string v = "aeiouAEIOU";
    return v.find(ch) != (size_t)-1;
}

string to_lowercase(string& s) {
    for(size_t i = 0; i < s.size(); i++) 
        if(s[i] <= 'Z') s[i] += 32;
    return s;
}

vector<string> split(string& s) {
    // spilt by spaces
    vector<string> words;
    for(size_t i = 0, j = 0; i < s.size(); i = j+1) {
        string word = "";
        for(j = i; j < s.size() && s[j] != ' '; j++) {
            word += s[j];
        }
        words.emplace_back(word);
    }
    return words;
}

void ascii_value(char ch) {
    // '0' -> 48
    // 'A' -> 65
    // 'a' -> 97
    cout << int(ch) << "\n";
}

int main() {
    string s;
    getline(cin, s);
    vector<string> words = split(s);
    for(auto w : words) {
        cout << w.size() << "   " << w << "\n";
    }
}