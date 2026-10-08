#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> text_correction(string text){
    string word;
    vector<string> buffer;
    stringstream sentence(text);
   
    while(sentence >> word){
        buffer.push_back(word);
        cout << word << endl;
    }

    return buffer;
}

int main(){
     string text;
     cout << "Insert something:" << endl;
     getline(cin, text);

    //The function converts the string to lowercase from beginning to end. 
    //It begins overwriting the "text" variable from the start.
    transform(text.begin(), text.end(), text.begin(), [](unsigned char c){
         return tolower(c); });
    
     text_correction(text);
     
}

