#include <iostream>
#include <vector>
#include <cstdlib>

const int SIZE = 1000000;  
int ITERATIONS = 3000;   

__attribute__((noinline))
long long calculateDotProduct(std::vector<int>& A, const std::vector<int>& B) {
    long long total_sum = 0;

    for (int iter = 0; iter < ITERATIONS; ++iter) {
        A[0] = iter;  
        long long current_sum = 0;

        for (int i = 0; i < SIZE; ++i) {
            current_sum += A[i] * B[i];
        }

        total_sum += current_sum;
    }
    return total_sum;
}

int main(int argc, char** argv) {
    if (argc > 1) ITERATIONS = std::atoi(argv[1]);

    std::vector<int> A(SIZE, 2);
    std::vector<int> B(SIZE, 3);

    std::cout << "Starting...\n";
    long long result = calculateDotProduct(A, B);
    std::cout << "Result: " << result << "\n";
    return 0;
}
