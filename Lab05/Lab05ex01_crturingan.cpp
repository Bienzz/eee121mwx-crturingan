#include <iostream> 
#include <algorithm>
#include <string>   
using namespace std;

// Function to recursively generate and print all combinations of characters
void backTrack(string curr, string rem) {
    // Base case: If there are no remaining characters, print the current combination and return
    if (rem.size() == 0) { // constant
        cout << curr << endl;
        return;
    } 

    // Iterate through each char of the remaining characters
    for (int i = 0; i < rem.size(); i++) { // O(n)
        // Skip adding a char if it's the same as the previous char
        if (i > 0 && rem[i] == rem[i - 1]) {
            continue;
        }
        // Add the current char to the current combination
        curr.push_back(rem[i]);
        // Make a copy of the remaining chars and remove the current char from it
        string new_rem = rem;
        new_rem.erase(i, 1);
        // Recursively call backTrack with updated current combination and remaining chars
        backTrack(curr, new_rem); // n * T(n-1)
        // Backtrack by removing the last character added for exploring other combinations
        curr.pop_back();
    }
}

// Function to sort the input string and initiate the combination generation process
void printCombi(string s) {
    // Sort the input string to ensure duplicate characters are grouped together
    sort(s.begin(), s.end());
    string curr; // Initialize an empty string to store the current combination
    backTrack(curr, s); // Call the backTrack function to generate combinations
}

// Main function
int main() {
    string s;
    cin >> s;
    printCombi(s);
    return 0;          
}

/*
Recursive Backtracking Time Complexity

T(n) = n * T(n-1) + O(n)

Assume that each recursive call explores O(n) characters which is the upper bound
T(n) = n * T(n-1) + O(n) <= n! * O(n)

TIME COMPLEXITY: O(n!)
*/

/*
Space Complexity
    - O(n) for the function "backTrack" called recursively for each character input string
    - O(n) for recursively creating new string "new_rem" which is repeated n times

S(n) = S_rec + S_str = O(n) + O(n) = O(n)

SPACE COMPLEXITY: O(n)
*/