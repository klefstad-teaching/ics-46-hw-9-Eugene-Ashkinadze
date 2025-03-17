#include <gtest/gtest.h>
#include <string>
#include "dijkstras.h"
#include <iostream>
#include "ladder.h"
using namespace std;

TEST(test_is_adjacentAAA, Same_Values) {
  string word1 = "appl";
  string word2 = "apple";
  cout << word1 << endl;
  cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
  EXPECT_FALSE(is_adjacent(word1,word2));
}

// TEST(test_is_adjacent, Too_Large) {
//   string word1 = "aaa";
//   string word2 = "aaa";
//   cout << word1 << endl;
//   //cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
//   EXPECT_TRUE(is_adjacent(word1,word2));
// }

// TEST(test_is_adjacent_alt, Alt_Valueas) {
//   string word1 = "cat";
//   string word2 = "ito";
//   cout << word1 << endl;
//   cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
//   // EXPECT_TRUE(is_adjacent(word1,word2));
// }

// TEST(test_verify, multiple_tests) {
//   verify_word_ladder();
//   // cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
//   EXPECT_TRUE(true);
// }

// TEST(test_is_adjacent_alt, Alt_Values) {
//   string word1 = "abc";
//   string word2 = "aaa";
//   set<string> set_str = {"cat", "Ito", "cot", "cog", "dog"};
//   cout << word1 << endl;
//   vector<string> result = generate_word_ladder("cat", "dog", set_str);
//   print_word_ladder(result);
// }

// TEST(test_dijstras, Dijstras) {
//   Graph g;
//   file_to_graph("./small.txt", g);
//   vector<int> previous;
//   vector<int> result = dijkstra_shortest_path(g, 0, previous);
//   for (int i = 0;i < result.size(); ++ i){
//   vector<int> path = extract_shortest_path(result, previous, i);
//   print_path(path, result[i]);
//   }
// }


