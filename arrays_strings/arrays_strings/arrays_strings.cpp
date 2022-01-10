// arrays_strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>


using namespace std;

//implement an algorithm to determine if a string has all unique characters(you cannot use  any other data structures.)
bool IsUniqueString(string str) {

    //First check str that, str has more than 128 characters. If it has, it cant be unique cuz we have 128 different char in ASCII string(Unicode may differ)
    if (str.size() > 128)
        return false;

    bool char_set[128];
    for (int i = 0; i < str.size();i++) {
        int val = str[i];
        if (char_set[val] == true)
            return false;

        char_set[val] = true;
    }

    return true;
}


bool CheckPermutation(string s1, string s2) {

    if (s1.size() != s2.size())
        return false;
    
    char *cset1 = new char[s1.size()];
    char *cset2 = new char[s1.size()];

    for (size_t i = 0; i < s1.size(); i++)
    {
        cset1[i] = s1[i];
        cset2[i] = s2[i];
    }

    sort(cset1, cset1+s1.size());
    sort(cset2, cset2 + s1.size());

    for (size_t i = 0; i < s1.size(); i++)
    {
        if (cset1[i] != cset2[i])
            return false;
    }
    
    return true;


}

//?????????????????
char* URLify(char s1[], int count) {

    int s1_size = count;
    char *Tchar = new char[count];
    for (size_t i = 0; i < s1_size; i++)
    {
        if (s1[i] != ' ')
            Tchar[i] = s1[i];
        else
            Tchar[i] = '%';
    }
    return Tchar;
}

bool palindromePermutation(string s) {
    
    if (s.size() == 1)
        return true;

    if (s.size() % 2 == 0)
        return false;

    int oddCharCount = 0;  
    string str, temp;
    str = s;
    int n = str.size();               //size of string str store in n
    for (int i = 0; i < n; i++)
    {
        temp += str[0];            //append(add) first character of str to string temp
        str.erase(std::remove(str.begin(), str.end(), str[0]), str.end());    //remove same character from string str eg. str[0] = 'a' ; then this line of code remove all 'a' character from string str.
    }
    str = temp;


   for (size_t j = 0; j < str.size(); j++)
   {
      if (count(s.begin(), s.end(), str[j]) % 2 != 0) 
         oddCharCount++;       
   }

    if (oddCharCount == 1)
        return true;
    else
        return false;
}



bool palindromePermutationMapVersion(string s) {

    if (s.size() == 1)
        return true;

    if (s.size() % 2 == 0)
        return false;

    int oddCharCount = 0;
    
    unordered_map<char, int>char_table;
    for (size_t i = 0; i < s.size(); i++)
        char_table[s[i]]++;
    

    for (auto& it : char_table) {
        if (it.second % 2 != 0)
            oddCharCount++;
    }

    if (oddCharCount > 1)
        return false;
    else
        return true;
}

bool onereplaceaway(string s, string p) {

    int diffcount = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != p[i])
            diffcount++;

        if (diffcount > 1)
            return false;
    }

    
        return true;

}

bool onedeleteaway(string s, string p) {
    int indexS = 0;
    int indexP = 0;

    while (indexP<p.size() && indexS<s.size())
    {
        if (s[indexS] != p[indexP]) {
            indexS++;
            while (indexP < p.size() && indexS < s.size())
            {
                if (s[indexS] != p[indexP])
                    return false;

                indexS++;
                indexP++;
            }
            return true;
            
        }
        indexS++;
        indexP++;
    }


    return true;
}

bool oneway(string s,string p) {

    if (abs((int)(s.size() - p.size())) > 1)
        return false;

    //onereplaceaway
    if (s.size() == p.size())
        return onereplaceaway(s, p);
    //onedeleteaway
    if (s.size() - 1 == p.size())
        return onedeleteaway(s, p);
    //oneinsertaway
    if (s.size() + 1 == p.size())
        return onedeleteaway(p,s);

}

string stringCompression(string s1) {

    unordered_map<char, int> char_Set;

    for (size_t i = 0; i < s1.size(); i++)
        char_Set[s1[i]]++;

    int profit=0;
    string compressedstring="";

    for (auto& it : char_Set) {
        if (it.second > 2)
            profit+=it.second - 1;
        if (it.second == 1)
            profit--;
        compressedstring += it.first + to_string (it.second);
   }

    if (profit > 0)
        return compressedstring;
    else
        return s1;

}

void zeromatrix(int matrix[3][4],int m, int n) {

    //create boolean array to hold zero positions.
    bool* row = new bool[m] {false};
    bool* column = new bool[n] {false};

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }

    //nullfiy columns
    for (size_t i = 0; i < n; i++)
    {
        if (column[i] == true) {
            for (size_t j = 0; j < m; j++)
                matrix[j][i] = 0;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        if (row[i] == true) {
            for (size_t j = 0; j < n; j++)
                matrix[i][j] = 0;
        }
    }
}

bool stringrotation(string s1, string rs1) {
       
    if (s1.size() != rs1.size())return false;

    string Crs1 = rs1 + rs1;

    if (Crs1.find(s1) != std::string::npos)
        return true;
    else
        return false;

}

int main()
{
   // cout << IsUniqueString("asdfghjklf") << endl;
   // cout << CheckPermutation("asospderti", "asdiertocp") << endl;

   // cout << palindromePermutation("ccaaabbxxoott") << endl;
   // cout << palindromePermutationMapVersion("ccaaabbxxoott") << endl;

  // cout << oneway("pale", "pal") << endl;

   // cout << stringCompression("asdasdasdlalsdladfksodgfjwopecqjwcxdjaudgasydgahjdxuyawhbdnaudasdsa") << endl;

   
    int a[3][4] = {
    {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
    {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
    {8, 9, 0, 11}   /*  initializers for row indexed by 2 */
    };
   /* for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    zeromatrix(a, 3, 4);
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    

    cout << stringrotation("batuhan", "hanbatu") << endl;
}
