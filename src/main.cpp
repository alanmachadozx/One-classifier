#include "../include/vectorizer.hpp"

int main(){
     string text;
     cout << "Insert something:" << endl;
     getline(cin, text); 
     vector<string> buffer = text_correction(text);
}

