/**

*proj1.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, 
debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a 
violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. 
I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, 
or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines

*Daniel Badach
*dxb718
*CMPSC465
*Due Time: 23:59, Tuesday, September 16, 2025
*Time of Last Modification: 13:00, Tuesday, September 16, 2025
*Description: Determines whether a train can be reorganized from track A to track B.
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <vector> 
using namespace std;

int main() {
    ifstream fin("lab1in.txt");
    ofstream fout("lab1out.txt");

    int N;
    while (fin >> N) {
        if (N == 0) break;

        while (true) {
            int first;
            fin >> first;
            if (first == 0) {
                fout << endl;
                break;
            }

            vector<int> target(N);
            target[0] = first;
            for (int i = 1; i < N; i++) {
                fin >> target[i];
            }

            stack<int> st;
            int next = 1; 
            int i = 0; 
            bool ok = true;

            while (i < N) {
                while ((st.empty() || st.top() != target[i]) && next <= N) {
                    st.push(next);
                    next++;
                }
                if (!st.empty() && st.top() == target[i]) {
                    st.pop();
                    i++;
                } else {
                    ok = false;
                    break;
                }
            }

            if (ok) fout << "Yes" << endl;
            else fout << "No" << endl;
        }
    }

    return 0;
}

// OUTPUT IN lab1out.txt
