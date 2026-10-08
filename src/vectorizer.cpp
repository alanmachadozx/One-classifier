#include "../include/vectorizer.hpp"


vector<int, string> vectorizer(vector<string> buffer){
    
    unordered_map<int, string> string_id;
    int idx = 0;
    for(string s: buffer){
        string_id.insert({0, s});
        idx++;
    }
    
}