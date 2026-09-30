#pragma once
#include <string>

using namespace std;

int read_number(const string &prompt);
int read_choice(const string &prompt, const string &error_message, int from, int to);