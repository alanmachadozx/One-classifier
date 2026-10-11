#include "../../include/vectorizer.hpp"
#include <unordered_map>
#include <vector>

//Iterates through the words in the JSON file's values, 
//storing each word and its respective position in an unordered_map.
unordered_map<string, int> dataset_map(){
    json dataset = read_dataset();
    unordered_map<string, int> string_id;
    int idx = 0;
    for(auto& references : dataset){
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

bool is_trained(const string& word, const unordered_map<string, int>& string_id){
    return string_id.find(word) != string_id.end();
}

void frequency(vector<string>& buffer){
    unordered_map<string, int> term_fr; 
    const unordered_map<string, int>& vec_model = dataset_map(); 
    
    for(const string& text: buffer){
        //selects only words that already exist in the vocabulary, discarding unknown words.
        if(is_trained(text, vec_model)){
            term_fr[text]++;
        }
    }

    for(auto it = term_fr.begin(); it != term_fr.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }
}

float tf_calculation(const unordered_map<string, int>& term_fr){
    float size = term_fr.size();
    float fr; 
    for(auto it = term_fr.begin(); it != term_fr.end(); it++){
        fr += it->second;
    }

    float tf = size/fr;
    return tf;
}