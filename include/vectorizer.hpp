#include <unordered_map>
#include "../include/tokenizer.hpp"

unordered_map<string, int> dataset_map();
vector<vector<string>> model_trainer();
void frequency(vector<string>& buffer, const unordered_map<string, int>& vec_model);
bool is_trained(const string& word, unordered_map<string, int>& string_id);
double tf_calculation(const unordered_map<string, int>& term_fr, const int& frequency);
unordered_map<double, int> idf_map();