#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> setmatrixzero(vector<vector<int>>& matrix, int m, int n) {
    vector<int> col(m, 0);
    vector<int> row(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t j = 0; j < row.size(); j++) {
            cout << row[j] << (j + 1 == row.size() ? ' ' : ' ');
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> matrix{{1,1,1,1}, {1, 0, 1, 1}, {0, 1,1,1}};
    int n = static_cast<int>(matrix.size());
    int m = n == 0 ? 0 : static_cast<int>(matrix[0].size());
    setmatrixzero(matrix, m, n);
    printMatrix(matrix);
    return 0;
}
