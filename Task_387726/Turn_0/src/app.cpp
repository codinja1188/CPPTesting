#include "app.h"

std::vector<int> g(std::vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    
    bool changed = true;
    
    while (changed) {
        changed = false;
        
        // Scan for adjacent elements that are not relatively prime
        for (size_t i = 0; i < arr.size() - 1; i++) {
            if (std::gcd(arr[i], arr[i + 1]) > 1) {
                // Found a pair that is not relatively prime
                int new_value = std::lcm(arr[i], arr[i + 1]);
                
                // Remove the two elements and insert their LCM
                arr[i] = new_value;
                arr.erase(arr.begin() + i + 1);
                
                changed = true;
                break; // Restart scanning from the beginning
            }
        }
    }
    
    return arr;
}
