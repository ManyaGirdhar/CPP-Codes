#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// clock_t t;
int counter = 0; //counting no. of solutions

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensFunction(vector<vector<int>>& board, int row, int N) {

    if (row == N) {
        // All queens have been placed, print the board
        counter++;
        cout << "Solution:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            res = solveNQueensFunction(board, row + 1, N) || res;

            board[row][col] = 0;                                         // backtrack
        }
    }

    return res;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensFunction(board, 0, N)) {
        cout << "No solution exists for N = " << N << endl;
    }
}

int main() {
    int N;
    cout<<endl<<endl;
    cout<<"<------------------------------------------NQUEENS PROBLEM--------------------------------------->"<<endl;
    cout << "Enter the value of N: ";
    cin >> N;

    // t=clock();
    
    high_resolution_clock::time_point start = high_resolution_clock::now();
    solveNQueens(N);
    // t=clock()-t;
    
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> timeTaken = duration_cast<duration<double>>(end - start);
    

    cout<<"time taken for " <<N;
    cout<<" queens is: "<<timeTaken.count() <<"seconds";
    cout<<endl;
    cout<<"no. of solutions: "<<counter;
    
    
    return 0;
}
