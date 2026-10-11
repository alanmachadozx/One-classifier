#include <unordered_map>
#include "../include/tokenizer.hpp"


unordered_map<string, int> dataset_map();
vector<vector<string>> model_trainer();
void frequency(vector<string>& buffer);
bool is_trained(const string& word, unordered_map<string, int>& string_id);
float tf_calculation(const unordered_map<string, int>& term_fr);