//program to convert string to keyboard specified sequence  : love babbar sheet problems

#include<bits/stdc++.h>
using namespace std;

string KeypadSequenceConverter(string str[], string input)
{
    int n=input.size();
    string output="";
    for (int i = 0; i < n;i++)
    {
        // CHARACTER IS SPACE THEN ADD 0 TO OUTPUT STRING
        if(input[i]==' ')
        {
            output = output + "0";
        }
        // otherwise add specified string on the basis of array 
        else
        {
            output = output + str[input[i] - 'A'];
        }
       
    }
    return output;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // storing the sequence in array
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
 
    string input = "RISHABH BHATT";
    cout << KeypadSequenceConverter(str, input);
    return 0;
}
