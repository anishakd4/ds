#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include <map>
#include<climits>
//climits for INT_MIN
#include <unordered_map>
using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }else if (pat[i] != pat[len]){
            if (len != 0) {
                len = lps[len - 1];
            }else if(len == 0){
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt){
    int M = pat.length();
    int N = txt.length();

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0){
                j = lps[j - 1];
            }else{
                i = i + 1;
            }
                
        }
    }
}

int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    KMPSearch(pat, txt);
    return 0;
}