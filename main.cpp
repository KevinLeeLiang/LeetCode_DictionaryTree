#include <iostream>
#include "test_factory.h"
int main(int argc, char *argv[]) {
    string title = argv[1];
    test_factory test(title);
    test.test();
}
