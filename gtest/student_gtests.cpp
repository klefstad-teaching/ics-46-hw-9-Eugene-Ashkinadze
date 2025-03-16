#include <gtest/gtest.h>
#include <string>
#include "dijkstras.h"
#include <iostream>
#include "ladder.h"
using namespace std;

TEST(test_is_adjacentAAA, Same_Values) {
  string word1 = "aaa";
  string word2 = "aaa";
  cout << word1 << endl;
  cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
  EXPECT_TRUE(is_adjacent(word1,word2));
}

TEST(test_is_adjacent, Too_Large) {
  string word1 = "sean";
  string word2 = "seen";
  cout << word1 << endl;
  cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
  EXPECT_TRUE(is_adjacent(word1,word2));
}

TEST(test_is_adjacent_alt, Alt_Values) {
  string word1 = "abc";
  string word2 = "aaa";
  cout << word1 << endl;
  cout << "Value is: " << (is_adjacent(word1,word2)) << endl;
  EXPECT_TRUE(is_adjacent(word1,word2));
}
