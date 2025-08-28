
#include "app.h"

std::string g(std::string a) {
    std::stringstream ss(a);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        return "";
    }

    std::string best_sentence = "";
    size_t max_words = 0;
    for(size_t i = 0; i < words.size(); ++i) {
        for (int j = 0; j < (1 << words.size()); ++j) {
           std::vector<std::string> current_words;
           for(size_t k = 0; k < words.size(); k++) {
               if((j >> k) & 1) {
                   current_words.push_back(words[k]);
               }
           }
           if(current_words.empty()) continue;
           
           char first_char = current_words[0][0];
           bool all_same = true;
           for(const auto& w : current_words) {
               if(w[0] != first_char) {
                   all_same = false;
                   break;
               }
           }

           if(all_same && current_words.size() > max_words) {
              max_words = current_words.size();
               best_sentence = "";
               for(size_t k = 0; k < current_words.size(); ++k) {
                   best_sentence += current_words[k];
                   if (k < current_words.size() - 1) {
                       best_sentence += " ";
                   }
               }

           }
        }
    }

  return best_sentence;
}
