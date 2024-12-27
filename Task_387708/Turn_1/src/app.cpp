
#include "app.h"

std::string g(std::string a) {
    std::stringstream ss(a);
    std::string sentence;
    std::string result = "";
    bool firstSentence = true;


    while (std::getline(ss, sentence, '.')) {
        if (!firstSentence) result += ".";
        firstSentence = false;
        std::stringstream sentence_ss(sentence);
        std::string word;
        std::vector<std::string> words;

        while (sentence_ss >> word) {
            words.push_back(word);
        }

        if (words.empty()) continue;

        std::vector<std::string> best_words;
        int max_count = 0;

         for(int i=0; i < words.size(); ++i)
        {
           std::vector<std::string> current_words;
            current_words.push_back(words[i]);
            int current_count =1;
           for(int j=i+1; j < words.size(); j++)
           {
                if(words[j][0] == words[i][0])
                {
                    current_words.push_back(words[j]);
                    current_count++;
                }
           }

           if (current_count > max_count) {
              max_count = current_count;
              best_words = current_words;
            }
           
        }

        for (size_t i = 0; i < best_words.size(); ++i) {
             result += best_words[i];
             if(i < best_words.size() -1) result += " ";
         }
        
    }
    return result;
}