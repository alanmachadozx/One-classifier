#include "../../include/vectorizer.hpp"
#include <string>
#include <unordered_map>
#include <vector>
const json DATASET = read_dataset();
//Iterates through the words in the JSON file's values, 
//storing each word and its respective position in an unordered_map.
unordered_map<string, int> dataset_map(){
    unordered_map<string, int> string_id; //word, id
    int idx = 0;
    int str_total = 0; //total number of words in the training set
    
    for(auto& references : DATASET){
        for(const string& str: references){

            stringstream sentence(str);
            string word;
            while (sentence >> word) {
                if(string_id.find(word) == string_id.end()){
                    string_id.insert({word, idx});
                    idx++;
                }
            }
        }    

    }
    return string_id;
}

 unordered_map<double, int> idf_map(){
    const unordered_map<string, int>& trainer_map = dataset_map();
    unordered_map<double, int> idf_id; //word idf, word id
    int idx = 0; //total of sentences
    int w_in_str = 0; //how many sentences contain a specific word
    double idf;
    
    for(auto& reference : DATASET){
        for(auto it = trainer_map.begin(); it != trainer_map.end(); it++){
            for(const string& str: reference){
                if(str.find(it->first) != string::npos){
                    w_in_str++;
                }
            }
            //The minimum IDF value is 1.0, and the maximum value is proportional to the number of sentences in the training set.
            idf = log((1.0 + idx)/(1.0 + w_in_str)) + 1.0;
            idf_id.insert({idf, it->second});
        }
    }

    return idf_id;
}

bool is_trained(const string& word, const unordered_map<string, int>& string_id){
    return string_id.find(word) != string_id.end();
}

double tf_calculation(const unordered_map<string, int>& term_fr, const int& frequency){
    double current_fr = frequency;
    double all_fr = 0; 
    
    for(auto it = term_fr.begin(); it != term_fr.end(); it++){
        all_fr += it->second;
    }

    double tf = current_fr/all_fr;
    return tf;
}

void frequency(vector<string>& buffer, const unordered_map<string, int>& vec_model){
    unordered_map<string, int> term_fr; 
    for(const string& text: buffer){
        //selects only words that already exist in the vocabulary, discarding unknown words.
        if(is_trained(text, vec_model)){
            term_fr[text]++;
        }
    }

    for(auto it = term_fr.begin(); it != term_fr.end(); it++){
        cout << it->first << ":" << it->second << endl;
        double tf = tf_calculation(term_fr, it-> second);
    }
}