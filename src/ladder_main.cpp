int main() {
    return 0;
}

    // //greater than 1 or less than 1 
    // if (word1.size() >= word2.size() + 2 || word1.size() <= word2.size() + 2) return false;
    // if (word1.size() == word2.size()) {
    //     int differences = 0;
    //     for (int i = 0; i < word1.size(); ++i) {
    //         if (differences > 1) return false;
    //         if (word1[i] != word2[i]) ++differences;
    //     }
    //     return true;
    // } 
    // else {
    //     int differences = 0;
    //     int j = 0;
    //     for (int i = 0; i < word1.size(); ++i,++j) {
    //         if (differences > 1) return false;
    //         if (word1[i] != word2[j]) {
    //             ++differences;
    //             if (word1.size() > word2.size()) {
    //                 --j;
    //                 ++differences;
    //             }
    //             else {
    //                 ++i;
    //                 ++differences;
    //             }
    //         }
    //     }
    //     return true;
    // }
    // // High igh