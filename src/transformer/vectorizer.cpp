#include "../../include/vectorizer.hpp"
#include <unordered_map>
#include <vector>

unordered_map<string, int> dataset_map(){
    json datset = read_dataset();
    unordered_map<string, int> string_id;
    int idx = 0;
    for(auto& [intention, references] : datset.items()){
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

bool is_trained(const string& word, unordered_map<string, int>& string_id){
    return string_id.find(word) != string_id.end();
}

void frequency(vector<string>& buffer){
    unordered_map<string, int> term_fr; 
    unordered_map<string, int> vec_model = dataset_map(); 
    
    for(const string& text: buffer){
        if(is_trained(text, vec_model)){
            term_fr[text]++;
        }
    }

    for(auto it = term_fr.begin(); it != term_fr.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }
}

