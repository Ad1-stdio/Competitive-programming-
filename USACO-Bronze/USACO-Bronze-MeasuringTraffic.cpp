#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


//QUESTION LINK : https://usaco.org/index.php?page=viewproblem2&cpid=917//
/**
 * USACO Bronze: Measuring Traffic
 * Problem Logic: Interval Arithmetic / Sensor Fusion
 * This solution uses forward and backward passes to narrow down 
 * the most specific possible traffic ranges.
 */

int main() {
    // Optimize I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> type(n);
    vector<int> low(n);
    vector<int> high(n);
    // Read all sensor data into parallel vectors
    for (int i = 0; i < n; i++) {
        cin >> type[i] >> low[i] >> high[i];
    }

    // ---------------------------------------------------------
    // FORWARD PASS: Determine traffic range AFTER Mile N
    // ---------------------------------------------------------
    // Start with a wide range that will be restricted by the first 'none' sensor
    int L = 0, H = 1000000; 

    for (int i = 0; i < n; i++) {
        if (type[i] == "none") {
            // Intersection: Traffic must satisfy both current range and sensor range
            L = max(L, low[i]);
            H = min(H, high[i]);
        } 
        else if (type[i] == "on") {
            // Addition: Traffic increases by the specified range
            L += low[i];
            H += high[i];
        } 
        else if (type[i] == "off") {
            // Subtraction (Extreme Cases): 
            // New min = smallest start - largest exit. New max = largest start - smallest exit.
            L -= high[i];
            H -= low[i];
            L = max(0, L); // Traffic cannot drop below zero
        }
    }
    int finalL = L, finalH = H;

    // ---------------------------------------------------------
    // BACKWARD PASS: Determine traffic range BEFORE Mile 1
    // ---------------------------------------------------------
    // Reset range to find the state prior to the first sensor
    L = 0, H = 1000000;

    for (int i = n - 1; i >= 0; i--) {
        if (type[i] == "none") {
            L = max(L, low[i]);
            H = min(H, high[i]);
        } 
        else if (type[i] == "on") {
            // Reverse Logic: Since we are going backward, an 'on' ramp acts like an 'off' ramp
            L -= high[i];
            H -= low[i];
            L = max(0, L);
        } 
        else if (type[i] == "off") {
            // Reverse Logic: Since we are going backward, an 'off' ramp acts like an 'on' ramp
            L += low[i];
            H += high[i];
        }
    }

    // Output per problem requirement: Prior range followed by Post range
    cout << L << " " << H << endl;
    cout << finalL << " " << finalH << endl;

    return 0;
}
