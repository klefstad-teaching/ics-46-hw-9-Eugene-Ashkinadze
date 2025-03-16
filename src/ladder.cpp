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
   vector<string> empty_vec;
   if (begin_word == end_word) return empty_vec;
    queue<vector<string>> ladder_queue;
    vector<string> word_graph;
    word_graph.push_back(begin_word);
    ladder_queue.push(word_graph);
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        word_graph = ladder_queue.front();
        ladder_queue.pop();
        string last = word_graph.back();
        // cout << "Last: " << last << endl;
        for (const string &word: word_list) {
            // cout << word << endl;
            // cout << is_adjacent(last, word) << endl;
            if (is_adjacent(last, word)){
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_word_graph = word_graph;
                    new_word_graph.push_back(word);
                    if (word == end_word) {
                        return new_word_graph;
                    }
                    ladder_queue.push(new_word_graph);
                }
            }
        }
    }

   return empty_vec;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int column = str1.size() + 1;
    int row = str2.size() + 1;
    if (abs(column - row) > d) return false;
    vector<int> current, previous;
    for (int size = 0; size < column; ++size) {
        current.push_back(size);
        previous = current;
    }
    for (int i = 1; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (j == 0) {
                current[j] = previous[j] + 1;
                continue;
            }
            if (str1[j - 1] == str2[i - 1]) current[j] = previous[j - 1];
            else { 
                current[j] = (min(min(previous[j], current[j - 1]), previous[j - 1])) + 1; 
            }
        }
        swap(current, previous);
    }
    return previous[column - 1] <= d; 
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for (string word; (in >> word);) {
        word_list.insert(word);
    }
}


void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() == 0) cout << "No word ladder found." << endl;
    else {
        cout << "Word ladder found: ";
        for (string word: ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
}

void error(string word1, string word2, string msg) {
    cerr << word1 << word1 << msg << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": "failed") << endl;}
void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    // cout << "IS EMpty" << word_list.empty() << endl;
    vector<string> test1= generate_word_ladder("cat", "dog", word_list);
    my_assert((test1).size() == 4);
    // cout << "Size is" << test1.size() << endl;
    // for (auto c : test1) {
    //     cout << c  << endl;
    // }
    // cout << word_list[0] << endl;
    // print_word_ladder(word_list);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}