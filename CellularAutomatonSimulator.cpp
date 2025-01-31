#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 26; 
const double p = 0.4; 

void fillArray(vector<vector<int>> &A) {
    for (auto &row : A)
        for (auto &cell : row)
            cell = (double)rand() / RAND_MAX < p ? 1 : 0;
}
void printArray(const vector<vector<int>> &A) {
    for (const auto &row : A) {
        for (int cell : row)
            cout << (cell ? '*' : ' ') << ' ';
        cout << endl;
    }
}
vector<vector<int>> computeB(const vector<vector<int>> &A) {
    vector<vector<int>> B = A;

    for (int i = 1; i < N - 1; i++)
        for (int j = 1; j < N - 1; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++)
                for (int dj = -1; dj <= 1; dj++)
                    sum += A[i + di][j + dj];

            B[i][j] = sum;
        }
    
    return B;
}

void modifyB(vector<vector<int>> &B) {
    for (int i = 1; i < N - 1; i++)
        for (int j = 1; j < N - 1; j++)
            B[i][j] = (B[i][j] >= 5) ? 1 : 0;
}

bool isStable(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    return A == B;
}

int main() {
    srand(time(0));

    vector<vector<int>> A(N, vector<int>(N, 0));
    fillArray(A);

    cout << "Początkowa tablica A:\n";
    printArray(A);

    while (true) {
        vector<vector<int>> B = computeB(A);
        modifyB(B);

        if (isStable(A, B))
            break;

        A = B;
    }

    cout << "\nTablica A po stabilizacji:\n";
    printArray(A);

    return 0;
}
