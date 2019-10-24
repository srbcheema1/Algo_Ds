//Game of nim ...
// Given a number of piles in which each pile contains some numbers of stones/coins. In each turn,
//a player can choose only one pile and remove any number of stones from that pile 
//The player who can't move is considered to lose the game.
//solution
//If both A and B play optimally , then the player starting first is guaranteed to win if the Nim-sum at
//the beginning of the game is non-zero . Otherwise , if the Nim-sum evaluates to zero, then player A will lose.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int nim_sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        nim_sum^=arr[i];
    }
    if(nim_sum!=0)
    cout<<"A wins\n";
    else
    {
        cout<<"B wins\n";
    }
    
}