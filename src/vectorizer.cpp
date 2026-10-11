#include "../include/vectorizer.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

vector<vector<string>> model_trainer(){
    vector<vector<string>> dataset = {
        {"make test"},
        {"please test trainer"}
    };
    return dataset;
}

unordered_map<string, int> vectorizer(vector<vector<string>>& buffer){

    unordered_map<string, int> string_id;
    int idx = 0;
    for(const vector<string>& str: buffer){
        unordered_set<string> unic_words(str.begin(), str.end());

        for(const string& word: unic_words){
            string_id.insert({word, idx});
        }
        
        idx++;
    }
    return string_id;
}

bool is_trained(const string& word, unordered_map<string, int>& string_id){
    return string_id.find(word) != string_id.end();
}

void frequency(vector<string>& buffer){
    unordered_map<string, int> term_fr; 
    vector<vector<string>> model = model_trainer();
    unordered_map<string, int> vec_model = vectorizer(model); 
    
    for(const string& text: buffer){
        if(is_trained(text, vec_model)){
            term_fr[text]++;
        }
    }
}

