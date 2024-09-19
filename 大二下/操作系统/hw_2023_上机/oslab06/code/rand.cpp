#include <cstdlib>
#include <ctime>
#include <iostream>
#define RequestNumber 8
int main() {
    int Request[8];
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < RequestNumber; i++) {
            Request[i] = rand() % 200;  // 假设磁道号范围为0-199
        }
        for (int j = 0; j < RequestNumber; j++) {
            std::cout << Request[j] << " ";
        }
        std::cout << std::endl;
    }
}