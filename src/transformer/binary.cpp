#include "../../include/binary.hpp"
#include <cstddef>
#include <fstream>

void Binary::save_file(const unordered_map<string, int>& vocabulary, const unordered_map<double, int> idf){
    ofstream file_b("binary/nlu_model.bin", ios::binary);

    if(!file_b.is_open()){
        return;
    }

    //Write the keys and values contained in the vocabulary to the binary file.
    size_t vocab_size = vocabulary.size();
    file_b.write(reinterpret_cast<const char* >(&vocab_size), sizeof(vocab_size));
    for(const auto& [word, id] : vocabulary){
        size_t w_size = word.size();
        file_b.write(reinterpret_cast<const char*>(&w_size), sizeof(w_size));
        file_b.write(word.data(), w_size);
        file_b.write(reinterpret_cast<const char*>(&id), sizeof(id));
    }
    
}