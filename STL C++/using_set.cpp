set <int> s;
s.insert(5); // 5 is inserted into set
s.insert(2); // 2 is inserted into set
s.insert(3); // 3 is inserted into set
s.insert(2); // no new element inserted

set <int> :: iterator it;
it = s.find(5)
if (it != s.end())
    cout << "Element is present in set" << endl;
else
    cout << "Element is not present in set" << endl;
/* Output : Element is present in set */

it = s.find(9)
if (it != s.end())
    cout << "Element is present in set" << endl;
else
    cout << "Element is not present in set" << endl;
/* Output : Element is not present in set */
