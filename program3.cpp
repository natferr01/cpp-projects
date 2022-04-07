//*************************************************
//          Natalie Ferraro
//          Program  #3
//          Due 02-08-2022 
//  Program 3 implements and tests three different
//  functions that operate on C-Strings.
//*************************************************

#include <cstring>
#include <iostream>
using namespace std;

/* method locates string s2 as a substring of s1,
returns a pointer to its first occurence in s1, 
or nullptr if s2 is not a substring of s1 */
void strStrTest()
{
    char s1[4] = "C++";
    char s2[2] = "C";
    char* result;
 
    result = strstr(s1,s2);

    //conditional statement executes if the substring is present
    if (result){
        cout << "Main string: " << s1 << endl;
        cout << "Substring: " << s2 << endl;
        cout << "Substring is present" << endl;
        cout << '\n'; //carraige return
    }
    //conditional statement executes if the substring is NOT present
    else{
        cout << "Substring not present" << endl;
        cout << '\n'; //carraige return
    }
}

/* method returns a pointer to the last occurence of the 
character ch in string s or nullptr if ch is not in s */
void strrChrTest()
{
    char s[] = "computer science";
    char* ptr;
    char ch = 'n';
 
    ptr = strrchr(s, ch);

    //conditional statement executes if the character is present in the string
    if (ptr){ 
        cout << "The last occurrence of " << ch << " in " << s << " is " << ptr - s << endl;
        cout << '\n'; //carraige return
    }
    //conditional statement executes if the character is NOT present in the string
    else{
        cout << ch << " is not present in " << s << endl;
        cout << '\n'; //carraige return
    }
}

/* method converts string s into an interger,
accepts a sign and stops after the first nondigit
is found */
void atoiTest()
{
    char s[] = "+911.01";
    int c;

    c = atoi(s);

    cout << "The string converted to an integer is " << c << endl;
    cout << '\n'; //carraige return
}

//main calls each function to test them
int main()
{
    strStrTest();
    strrChrTest();
    atoiTest();
    return 0;   
}