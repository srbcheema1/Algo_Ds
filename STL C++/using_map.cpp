map <int, int> m;
map <int, int> :: iterator it;

m[1] = 2;
m[2] = 3;
m[6] = 4;
m[5] = 5;

it = m.find(5);
if (it != m.end())
    cout << "5 is present as key" << endl;
else
    cout << "5 is not present as key" << endl;
/* Output: 5 is present as key */


it = m.find(3);
if (it != m.end())
    cout << "3 is present as key" << endl;
else
    cout << "3 is not present as key" << endl;
/* Output: 3 is not present as key */
