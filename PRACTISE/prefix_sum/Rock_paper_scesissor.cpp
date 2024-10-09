#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>

using namespace std;

 
int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    
    int N;
    cin >> N;
    vector<char> opponent(N);
    
    for (int i = 1; i <= N; i++) {
        cin >> opponent[i];
    }
    
    // Arrays to store prefix wins for each move
    vector<int> hoofWins(N + 1, 0), paperWins(N + 1, 0), scissorsWins(N + 1, 0);
    
    // Fill prefix win arrays
    for (int i = 1; i <= N; i++) {
        hoofWins[i] = hoofWins[i - 1] + (opponent[i] == 'S');
        paperWins[i] = paperWins[i - 1] + (opponent[i] == 'H');
        scissorsWins[i] = scissorsWins[i - 1] + (opponent[i] == 'P');
    }
    
    int maxWins = 0;
    
    // Try to find the best point to switch strategies
    for (int i = 1; i <= N; i++) {
        // Case 1: Hoof before i, Paper after i
        maxWins = max(maxWins, hoofWins[i] + (paperWins[N] - paperWins[i-1]));
        
        // Case 2: Hoof before i, Scissors after i
        maxWins = max(maxWins, hoofWins[i] + (scissorsWins[N] - scissorsWins[i-1]));
        
        // Case 3: Paper before i, Hoof after i
        maxWins = max(maxWins, paperWins[i] + (hoofWins[N] - hoofWins[i-1]));
        
        // Case 4: Paper before i, Scissors after i
        maxWins = max(maxWins, paperWins[i] + (scissorsWins[N] - scissorsWins[i-1]));
        
        // Case 5: Scissors before i, Hoof after i
        maxWins = max(maxWins, scissorsWins[i] + (hoofWins[N] - hoofWins[i-1]));
        
        // Case 6: Scissors before i, Paper after i
        maxWins = max(maxWins, scissorsWins[i] + (paperWins[N] - paperWins[i-1]));
    }
    
    cout << maxWins << endl;
    
    return 0;
}
