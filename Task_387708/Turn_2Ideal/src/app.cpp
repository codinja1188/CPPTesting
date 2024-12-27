
#include "../src/app.h"


std::string simplify_path(const std::string path) {
    std::vector<std::string> stack;
    std::string token;
    std::string result;
    int n = path.size();

    for (int i = 0; i < n; ++i) {
        if (path[i] == '/') {
            if (!token.empty()) {
                if (token == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else if (token != ".") {
                    stack.push_back(token);
                }
                token.clear();
            }
        } else {
            token += path[i];
        }
    }

    // Process the final token after the loop
    if (!token.empty() && token != "." && token != "..") {
        stack.push_back(token);
    } else if (token == ".." && !stack.empty()) {
        stack.pop_back();
    }

    // Reconstruct the simplified path
    for (const std::string& dir : stack) {
        result += "/" + dir;
    }
    
    return result.empty() ? "/" : result;
}
