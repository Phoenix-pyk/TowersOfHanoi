#include <iostream>
#include <vector>
using namespace std;

int nummove = 0;

int main() {
    vector<int> tower[3];
    int n, candidate, to, from;
    cout << "Please enter the amount of disks to move: ";
    cin >> n;
    cout << endl;

    //initialize 3 towers
 for (int i=n+1; i>0; i--) tower[0].push_back(i); // set one disk more than 1 as a sentinel value
    tower[1].push_back(n+1);//set sentinel values to other towers
    tower[2].push_back(n+1);

    //initialize candidates and to, from towers
    from = 0;
    to = 1;
    candidate =1; // set up to 1 because no move has been done yet and smallest disk is assured

    while (tower[1].size()<n+1) { //While there are still disks to move around.
        nummove++;
        cout << "Move number #" << nummove << " : Transfer disk " << candidate << " from tower " << char(from+65) <<
            " to tower " << char(to+65) <<"." << endl;
        // move the disk around
        tower[to].push_back(tower[from].back());
        tower[from].pop_back();

        //get the next "from" tower that is NOT the most recent "to" tower
        //Compare the disks from two other towers
        //set the index of the tower which has the smaller disk to "from".
        if (tower[(to+1)%3].back()<tower[(to+2)%3].back()) from = (to+1)%3;
        else from = (to+2)%3;

        //get the next "to" tower
        //We've already set the from tower atp. We need to figure out which one from other two towers
        //is valid to be a "to" tower
        if (tower[(from+1)%3].back()>tower[from].back()) to =(from+1)%3; // if the next tower from the "from" tower has bigger disk, then it is the "to" tower.
        else to = (from+2)%3; // if not, put the disk on other tower.

        //The next candidate.
        candidate = tower[from].back(); //the disk from "from" tower.
    }

    cout<< "The number of moves required for " << n << " disks is " << nummove;
    return 0;
}