#include <unordered_map>
#include "../include/tokenizer.hpp"

unordered_map<string, int>vectorizer(vector<vector<string>>& buffer);
vector<vector<string>> model_trainer();
void frequency(vector<string>& buffer);
bool is_trained(const string& word, unordered_map<string, int>& string_id);