#include "../include/vectorizer.hpp"
#include <unordered_map>
#include <unordered_set>

vector<string> model_trainer(){
    vector<string> dataset = {
        "trainer",
        "test"
    };
    return dataset;
}

unordered_map<string, int> vectorizer(vector<string> buffer){

    unordered_map<string, int> string_f;
    int idx = 0;
    for(string s: buffer){
        string_f.insert({s, idx});
        idx++;
    }
    return string_f;
}    

void frequency(vector<string> buffer){
    unordered_map<string, int> term_fr; 
    for(string text: buffer){
        unordered_set<string> unic_words(text.begin(), text.end());
        for(string word: unic_words){
            term_fr[word]++;
        }
    }
}