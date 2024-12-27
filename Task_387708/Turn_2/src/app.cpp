
#include "app.h"

std::string simplify_path(std::string path) {
    std::vector<std::string> stack;
    std::stringstream ss(path);
    std::string token;

    while (std::getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue;
        } else if (token == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            stack.push_back(token);
        }
    }

    std::string result;
    if (stack.empty()) {
        result = "/";
    } else {
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
    }
    return result;
}