#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"
using namespace std; 
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    vector<string> first_word; 
    queue<vector<string>> ladder_queue;
    first_word.push_back(begin_word);
    ladder_queue.push(first_word);
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                visited.insert(word);
                vector<string> new_ladder;
                new_ladder = ladder;
                new_ladder.push_back(word);
                if (word == end_word) return new_ladder;
                ladder_queue.push(new_ladder);
            }
        }
    }
    //Fix this 
    vector<string> empty_vecpt;
    return empty_vecpt;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int str1_size = str1.size() + 1;
    int str2_size = str2.size() + 1;
    //if (str1_size > str2_size + d || str1_size < str2_size + d) return false;
    vector<int> prev;
    vector<int> current_row; 
    for (int i = 0; i < str2_size; ++i) {
        if (prev.size() == 0) {
            for (int m = 0; m < str1_size; ++m) {
                current_row.push_back(m);
              // cout << "Added to Prev" << endl;
            }
            prev = current_row;
            //cout << "Prev set" << endl;
            continue;
        }
        for (int j = 0; j < str1_size; ++j) {
            int t = j - 1;
            if (t >= 0 && (t < str1_size - 1) && (t < str2_size - 1) && str1[t] == str2[t]) {
                current_row[j] = prev[j - 1];
                //cout << "IS EQUAL" << endl;
                continue;
            }
            current_row[j] = prev[j];
            if (j >= 1 && current_row[j] > prev[t]) current_row[j] = prev[t];
            else if ((j < (str1_size - 1) && current_row[j] > prev[j + 1])) current_row[j] = prev[j + 1];
           // cout << "Outside the loop" << endl;
        }
        swap(prev, current_row);
        //cout << "AfterSwap" << endl;
        // cout << "Min value is" << prev[(str1_size - 1)] << endl;
        // if (prev[(str2_size - 1)] > d) return false;
        //cout << "Current i is " << i << endl;
        //cout << "Last value is" << prev[str1_size - 1] << endl;
    }
   cout << "Min value is" << prev[str1_size - 1] << endl;
    return (prev[str1_size - 1] < d);
}

void load_words(set<string> & word_list, const string& file_name) {
    
}