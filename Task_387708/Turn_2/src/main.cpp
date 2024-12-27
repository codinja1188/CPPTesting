#include "app.h"
#include <iostream>
#include <cassert>
#include <string>


void test_simplify_path() {
    assert(simplify_path("/home/") == "/home");
    assert(simplify_path("/home//foo/") == "/home/foo");
    assert(simplify_path("/home/../foo/") == "/foo");
    assert(simplify_path("/a/./b/../../c/") == "/c");
    assert(simplify_path("/../") == "/");
    assert(simplify_path("/a/./b/c/") == "/a/b/c");
    assert(simplify_path("/a/../../b/../c//.//") == "/c");
    assert(simplify_path("/a//b//c//////d") == "/a/b/c/d");
    assert(simplify_path("/abc/...") == "/abc/...");
    assert(simplify_path("/...") == "/...");
    assert(simplify_path("///") == "/");
    assert(simplify_path("/") == "/");
}

int main() {
    test_simplify_path();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}