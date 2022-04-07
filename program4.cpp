//*************************************************
//          Natalie Ferraro
//          Program  #4
//          Due 02-22-2022 
//  Program 4 implements and tests different
//  functions that operate on an object of 
//  the IntegerSet class.
//*************************************************

#include <iostream>

using namespace std;

//class IntegerSet
class IntegerSet
{
public:
    int n;
    bool *a;
    IntegerSet(int n); //size of set intitially set to zero
    IntegerSet(const IntegerSet&);
    ~IntegerSet();
    IntegerSet operator+(IntegerSet set);
    IntegerSet operator*(IntegerSet set);
    IntegerSet& operator=(const IntegerSet& set);
    bool operator==(IntegerSet set);
    bool operator<(const IntegerSet& set);
    void insert(int n);
    void remove(int n);
    friend ostream& operator<<(ostream& out, const IntegerSet set);
};

//constructor
IntegerSet::IntegerSet(int n)
{
    this->n = n;
    
    a = new bool[n];

    for(int i = 0; i < n; i++){
        a[i] = {false};
    }

    this->n = n;
}

//copy constructor
IntegerSet::IntegerSet(const IntegerSet& set)
{
    //IntegerSet set(n);

    n = set.n;

    a = new bool[n];

    for(int i = 0; i < n; i++)
    {
       a[i] = set.a[i];
    }
}

//destructor
IntegerSet::~IntegerSet() { delete[] a; }


//creates a set that is the union of two existing sets
IntegerSet IntegerSet::operator+(IntegerSet set)
{
    int temp;

    if(n < set.n)
        temp = set.n;
    else
        temp = n;

    IntegerSet setU(temp);

    for(int i = 0; i < temp; i++){
        if(a[i] == true)
            setU.insert(i);
        else if(set.a[i] == true)
            setU.insert(i);            
    } 

    return setU;      
}

//creates a set that is the intersection of two existing sets 
IntegerSet IntegerSet::operator*(IntegerSet set)
{
    int temp;

    if(n > set.n)
        temp = set.n;
    else
        temp = n;

    IntegerSet setI(temp);

    for(int i =0; i < n; i++)
    {
        if(a[i] == true && set.a[i] == true)
            setI.insert(i);
    }

    return setI;
}

//makes two sets equal to one another
IntegerSet& IntegerSet::operator=(const IntegerSet& set)
{
    n = set.n;
    
    for(int i = 0; i< n; i++)
    {
        a[i] = set.a[i];
    }

    return *this;
}

//checks if two sets have the same elements
bool IntegerSet::operator==(IntegerSet set)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] != set.a[i])
            return false;
    }

    return true;
}

//checks if the current set is a subset of set
bool IntegerSet::operator<(const IntegerSet& set)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] != set.a[i])
            return false;
    }

    return true;
}

//inserts a new integer into a set
void IntegerSet::insert(int n)
{
    a[n] = true;
}

//deletes an integer from the set
void IntegerSet::remove(int n)
{
    a[n] = false;
}

//prints the list of elements present in the set
ostream& operator<<(ostream& out, const IntegerSet set) 
{
    bool flag = false;

    out << "{";
    
    for(int i = 0; i < set.n; i++)
    {
        if(set.a[i] == true)
            out << i << ' '; 
            flag = true; 
    }

    if(flag == false)
        out << "---" << endl;
    
	out << "}" << endl;

    return out;
}

int main()
{
    IntegerSet a1(5), a2(10), a3(15);

    a1.insert(2);
    a1.insert(3);

    a2.insert(2);
    a2.insert(3);

    a3.insert(2);
    a3.insert(3);
    a3.insert(5);

    cout << a1 << a2 << a3 << endl;

    cout << (a1 == a2) << ' ' << (a1 == a3) << endl;

    cout << (a1 < a2) << " ⊆ " << (a1 < a3) << endl;

    cout << (a1 + a2) << " ∪ " << (a1 + a3) << endl;

    cout << (a1 * a2) << " ∩ " << (a1 * a3) << endl;
    
    return 0;
}