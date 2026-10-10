#include "../include/vectorizer.hpp"
#include <unordered_map>
#include <unordered_set>

vector<string> model_trainer(){
    vector<string> dataset = {
        {"make", "test"},
        {"please", "test trainer"}
    };
    return dataset;
}

unordered_map<string, int> vectorizer(vector<string> buffer){

    unordered_map<string, int> string_id;
    int idx = 0;
    for(const string& s: buffer){
        string_id.insert({s, idx});
        idx++;
    }
    return string_id;
}

bool view_dataset(const string& word, unordered_map<string, int> string_id = vectorizer(model_trainer())){
    for(auto it = string_id.begin(); it != string_id.end(); it++){
        if (it->first == word){
            return true;
        }
    }
    return false;
}

void frequency(vector<string> buffer){
    unordered_map<string, int> term_fr; 
    
    for(const string& text: buffer){
        unordered_set<string> unic_words(text.begin(), text.end());
        
        for(const string& word: unic_words){
            if(view_dataset(word)){
                term_fr[word]++;
            }
        }
    }
}

