#include <iostream>
#include <vector>

using namespace std;

/**
 * USACO Bronze: Circular Barn
 * Goal: Find the minimum total distance cows travel when entering through one door.
 */
int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // N = number of rooms in the barn
    int n;
    if (!(cin >> n)) return 0;

    // Vector to store the number of cows required for each room i
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }

    // Initialize min_dis with a very large value (10^9)
    int min_dis = 1000000000;

    // Outer loop: Try opening each door 'i' (starting point)
    for (int i = 0; i < n; i++) {
        int dis = 0;
        
        // Inner loop: Calculate distance for cows to reach each room 'j' from door 'i'
        for (int j = 0; j < n; j++) {
            /** * Distance formula for circular array:
             * (target_index - start_index + total_elements) % total_elements
             */
            dis += ((j - i + n) % n) * cows[j];
        }

        // Update the global minimum distance
        if (dis < min_dis) {
            min_dis = dis;
        }
    }

    // Output only the result as required by USACO graders
    cout << min_dis << endl;

    return 0;
}