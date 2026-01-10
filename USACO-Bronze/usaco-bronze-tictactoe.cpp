#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Read the 3x3 grid
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }

    // Sets to store unique winners
    set<char> individual_winners;
    set<set<char>> team_winners;

    // Helper to extract characters from the 8 possible winning lines
    vector<set<char>> lines;

    // Rows
    for (int i = 0; i < 3; i++) {
        lines.push_back({board[i][0], board[i][1], board[i][2]});
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        lines.push_back({board[0][i], board[1][i], board[2][i]});
    }

    // Diagonals
    lines.push_back({board[0][0], board[1][1], board[2][2]});
    lines.push_back({board[0][2], board[1][1], board[2][0]});

    // Evaluate each line
    for (const auto& s : lines) {
        if (s.size() == 1) {
            // Exactly one unique character: Individual win
            individual_winners.insert(*s.begin());
        } else if (s.size() == 2) {
            // Exactly two unique characters: Team win
            team_winners.insert(s);
        }
    }

    // Output results
    cout << individual_winners.size() << endl;
    cout << team_winners.size() << endl;

    return 0;
}