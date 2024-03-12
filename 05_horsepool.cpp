#include<bits/stdc++.h>
using namespace std;

void badCharHeuristics(string str, int size, int badChar[256]) {
    int i;
    for(i=0; i<256; i++){
        badChar[i]=-1;
    }
    for(i=0; i<size; i++){
        badChar[(int) str[i]] = i;
    }
}

void search(string text, string pattern){
    int n=text.size();
    int m=pattern.size();
    int badChar[256];

    badCharHeuristics(pattern, m, badChar);

    int shift = 0;

    while(shift <= (n-m)){
        int j=m-1;
        // Compare pattern characters with text characters
        while(j>=0 && pattern[j]==text[shift+j]){
            j--;
        }
        // If the pattern is found
        if (j < 0) {
            cout << "Pattern occurs at shift = " <<  shift << endl;
            // Update shift using max of 1 or difference with bad character heuristic
            shift += (shift + m < n)? m-badChar[text[shift + m]] : 1;
        }
        // If a mismatch occurs, update shift using bad character heuristic
        else{
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main()
{
    string text= "ABAAABCD";
    string pattern = "ABC";    
    search(text, pattern);
    
    return 0;
}
