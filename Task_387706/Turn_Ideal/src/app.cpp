#include "app.h"

// Function to convert Roman numeral to integer with validation
int g(const std::string& a) {
    std::unordered_map<char, int> roman_map = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int prev_value = 0;
    int sub_count = 0;
    int repeat_count = 1;

    for (int i = a.length() - 1; i >= 0; --i) {
        char current_char = a[i];
        if (roman_map.find(current_char) == roman_map.end()) {
            return 0; // Invalid character
        }
        int current_value = roman_map[current_char];

        // Check for invalid repetition
        if (i < a.length() - 1 && current_char == a[i + 1]) {
            repeat_count++;
            if (repeat_count > 3 && (current_char == 'I' || current_char == 'X' || current_char == 'C' || current_char == 'M')) {
                return 0; // Invalid repetition for 'I', 'X', 'C', 'M'
            }
            if (repeat_count > 1 && (current_char == 'V' || current_char == 'L' || current_char == 'D')) {
                return 0; // Invalid repetition for 'V', 'L', 'D'
            }
        } else {
            repeat_count = 1;
        }

        if (current_value < prev_value) {
            if (sub_count > 0) {
                return 0;
            }
            if (current_char == 'I' && (prev_value == 5 || prev_value == 10)) {
                result -= current_value;
                sub_count++;
            } else if (current_char == 'X' && (prev_value == 50 || prev_value == 100)) {
                result -= current_value;
                sub_count++;
            } else if (current_char == 'C' && (prev_value == 500 || prev_value == 1000)) {
                result -= current_value;
                sub_count++;
            } else {
                return 0; // Invalid subtraction
            }
        } else {
            sub_count = 0;
            result += current_value;
        }

        prev_value = current_value;
    }

    // Check canonical form
    std::string canonical_roman = "";
    int num = result;
    if (num >= 1000) {
        canonical_roman += std::string(num / 1000, 'M');
        num %= 1000;
    }
    if (num >= 900) {
        canonical_roman += "CM";
        num -= 900;
    }
    if (num >= 500) {
        canonical_roman += "D";
        num -= 500;
    }
    if (num >= 400) {
        canonical_roman += "CD";
        num -= 400;
    }
    if (num >= 100) {
        canonical_roman += std::string(num / 100, 'C');
        num %= 100;
    }
    if (num >= 90) {
        canonical_roman += "XC";
        num -= 90;
    }
    if (num >= 50) {
        canonical_roman += "L";
        num -= 50;
    }
    if (num >= 40) {
        canonical_roman += "XL";
        num -= 40;
    }
    if (num >= 10) {
        canonical_roman += std::string(num / 10, 'X');
        num %= 10;
    }
    if (num >= 9) {
        canonical_roman += "IX";
        num -= 9;
    }
    if (num >= 5) {
        canonical_roman += "V";
        num -= 5;
    }
    if (num >= 4) {
        canonical_roman += "IV";
        num -= 4;
    }
    if (num >= 1) {
        canonical_roman += std::string(num, 'I');
    }

    if (canonical_roman != a) {
        return 0;
    }

    return result;
}