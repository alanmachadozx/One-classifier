#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

vector<string> text_correction(string text);