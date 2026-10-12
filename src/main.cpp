#include "../include/vectorizer.hpp"

int main(){
     string text;
     cout << "Insert something:" << endl;
     getline(cin, text); 
     
     const unordered_map<string, int>& model = dataset_map();
     vector<string> buffer = text_correction(text);
     frequency(buffer, model);
     
}

