#include <iostream>
using namespace std;
 
/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile","samsung","nokia","apple","car","book","ball","bat","hello","boy","girl",
                            "red","good","bad","lovely", "nice","and","bad","bad","bad","bad","bad","bad","bad","bad","bad",
                            "go","are","love","ice","cream" 
                            };
                            
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
 
void wordBreakUtil(string str, int size, string result);
 
void wordBreak(string str)
{
    // last argument is prefix
    wordBreakUtil(str, str.size(), "");
}
 
// result store the current prefix with spaces between words
void wordBreakUtil(string str, int n, string result)
{
    cout<<"here";
    //Process all prefixes one by one
    for (int i=1; i<=n; i++)
    {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
 
        // if dictionary conatins this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix))
        {
            // if no more elements are there, print it
            if (i == n)
            {
                // add this element to previous prefix
                result += prefix;
                cout << result << endl; //print result
                return;
            }
            wordBreakUtil(str.substr(i, n-i), n-i,result + prefix + " ");
        }
    }//end for
}//end function
 
int main()
{
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");
 
    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}
