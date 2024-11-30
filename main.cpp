#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tower[3];
    int n, candidate, to, from, move=0;
    cout << "Please enter the amount of disks to move: ";
    cin >> n;
    cout << endl;

    //initialize 3 towers
 for (int i=n+1; i>0; i--) tower[0].push_back(i); // set one disk more than 1 as a sentinel value
    tower[1].push_back(n+1);//set sentinel values to other towers
    tower[2].push_back(n+1);






    return 0;
}