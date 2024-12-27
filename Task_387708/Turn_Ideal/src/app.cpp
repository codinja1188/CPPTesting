#include "app.h"

// Helper function to trim leading and trailing whitespace
std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Core function to process a single sentence
std::string process_sentence(std::string a) {
    std::stringstream ss(a);
    std::string word;
    std::unordered_map<char, std::vector<std::string>> word_groups;

    // Group words by starting letter
    while (ss >> word) {
        char first_char = word[0];
        word_groups[first_char].push_back(word);
    }

    std::string best_sentence;
    int max_words = 0;
    int max_groups = 0;  // Track the number of groups with max size

    // Find the largest group of words with the same starting letter
    for (const auto& group : word_groups) {
        if (group.second.size() > max_words) {
            max_words = group.second.size();
            max_groups = 1;  // Reset the count for new max size
            best_sentence = "";
            for (const auto& w : group.second) {
                best_sentence += w + " ";
            }
        } else if (group.second.size() == max_words) {
            max_groups++;  // Increment count for equal max-sized groups
        }
    }

    // Trim the trailing space
    if (!best_sentence.empty()) {
        best_sentence.pop_back();
    }

    // If multiple groups of the same size exist, return the original sentence
    if (max_groups > 1 || max_words == 1) {
        return trim(a);  // Return the original trimmed sentence
    }

    return best_sentence;
}

// Main function to process full input with multiple sentences
std::string g(std::string a) {
    std::stringstream ss(a);
    std::string sentence;
    std::vector<std::string> results;

    // Process each sentence separated by '.'
    while (std::getline(ss, sentence, '.')) {
        sentence = trim(sentence);  // Trim each sentence
        if (!sentence.empty()) {
            results.push_back(process_sentence(sentence));
        }
    }

    // Reconstruct the final result
    std::string final_result;
    for (size_t i = 0; i < results.size(); i++) {
        final_result += results[i];
        if (i < results.size() - 1) {
            final_result += ". ";  // Add period and space between sentences
        }
    }

    return final_result;
}
