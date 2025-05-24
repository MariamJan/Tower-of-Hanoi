#include <iostream>
#include <stack>
using namespace std;

void towerOfHanoiDivideConquer(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    towerOfHanoiDivideConquer(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoiDivideConquer(n - 1, auxiliary, source, destination);
}



/********************************************************************************************************************************************************************/




void printMove(int disk, char source, char dest)
{
    cout << "Move disk " << disk << " from peg " << source << " to peg " << dest << endl;
}

// if the current state is the solution
bool isSolution(const stack<int> pegs[], int numDisks)
{
    // If all disks are in the last peg (C), it's a solution
    return pegs[2].size() == numDisks;
}

void towerOfHanoiBruteForce(int numDisks)
{
    // stack to represent pegs
    stack<int> pegs[3];

    // Initialize source peg with disks
    for (int i = numDisks; i >= 1; --i)
    {
        pegs[0].push(i);
    }

    // Brute force approach: try all possible moves
    int totalMoves = 1 << numDisks; // Total number of possible moves (2^n)
    for (int move = 1; move < totalMoves; ++move)
    {
        int from = (move & (move - 1)) % 3; // Source peg
        int to = ((move | (move - 1)) + 1) % 3; // Destination peg
        if (pegs[from].empty() || (!pegs[to].empty() && pegs[to].top() < pegs[from].top()))
        {
            swap(from, to);
        }
        printMove(pegs[from].top(), 'A' + from, 'A' + to);
        pegs[to].push(pegs[from].top());
        pegs[from].pop();
    }
}




int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    cout << endl;
    cout << "******DivideConquer******" << endl;
    towerOfHanoiDivideConquer(numDisks, 'A', 'B', 'C');
    cout << endl;
    cout << "******BruteForce******" << endl;
    towerOfHanoiBruteForce(numDisks);
    return 0;
}





