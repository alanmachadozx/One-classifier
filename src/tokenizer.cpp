#include "../include/tokenizer.hpp"

vector<string> text_correction(string text){
    //The function converts the string to lowercase from beginning to end. 
    //It begins overwriting the "text" variable from the start.
    transform(text.begin(), text.end(), text.begin(), [](unsigned char c){
         return tolower(c); });
    
    string word;
    vector<string> buffer;
    stringstream sentence(text);
   
    while(sentence >> word){
        buffer.push_back(word);
        cout << word << endl;
    }

    return buffer;
}