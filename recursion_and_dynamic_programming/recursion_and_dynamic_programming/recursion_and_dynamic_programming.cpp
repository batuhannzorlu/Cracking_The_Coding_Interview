
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>


using namespace std;
//8.1 TripleStep

//TOPDOWN APPROACH
int how_many_hop(int n) {

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    
        return how_many_hop(n - 1) + how_many_hop(n - 2) + how_many_hop(n - 3);

}

int how_many_hop_v2(int n) {
    if (n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else {
        return how_many_hop_v2(n - 1) + how_many_hop_v2(n - 2) + how_many_hop_v2(n - 3);
    }
}

int how_many_hop_memoization(int n,vector<int>& arr) {
   
    if (arr[n-1] == 0) {
        if (n == 1) {
            arr[n - 1] = 1;
            return 1;
        }
            
        if (n == 2) {
            arr[n - 1] = 2;
            return 2;
        }
            
        if (n == 3) {
            arr[n - 1] = 4;
            return 4;
        }
            arr[n-1] = how_many_hop_memoization(n - 1,arr) + how_many_hop_memoization(n - 2,arr) + how_many_hop_memoization(n - 3, arr);
            return arr[n-1];
    }
    
    return arr[n-1];
}


//8.2 RobotInaGrid
bool find_path(vector<vector<int>>my_grid,int r,int c) {

    if (r - 1 < 0 || c - 1 < 0)
        return false;
    if ((r - 1) == 0 & (c - 1) == 0)
        return true;
    if (my_grid[r-1][c-1] == -1)
        return false;

    return find_path(my_grid, r-1, c) || find_path(my_grid, r, c-1);
}



//8.3 magic index
//array is sorted

bool magic_index(vector<int> arr, int upper_b,int lower_b) {
   
    
    int mid = ((upper_b - lower_b) / 2) + lower_b;

    if (mid == arr[mid])
        return true;
    
    if (mid == upper_b || mid == lower_b)
        return false;
    
    if (mid >= arr[mid])
       return magic_index(arr, upper_b, mid+1);
    else
        return magic_index(arr, mid - 1, lower_b);

    return false;
}
//8.4 Find All Subsets(not completed yet)
void subset_creator(vector<int>&set_,int stage_counter=0) {


    if (set_.empty())
        return;

    vector<int>::iterator it;
    vector<int>:: iterator it2;
    for (it = set_.begin(); it !=set_.end(); it++)
    {
        for (it2 = it; it2 != set_.end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
    set_.erase(set_.end()-1);
    stage_counter++;
    subset_creator(set_, stage_counter);

}

//8.5 recursive_multiply
int recursive_multiply(int num, int m_num) {

    
    if (m_num <= 0)
        return 0;

    m_num--;
    num += recursive_multiply(num, m_num);
    return num;
}

// decrease multiply number 1 by 1 untill it is power of 2
//then find the power and shift the bits
//
int recursive_multuply_bit_shifting(int num, int m_num) {

   
    if ((m_num & (m_num - 1)) == 0)
        return num << static_cast<int>(log2(m_num));

    m_num--;
    num += recursive_multuply_bit_shifting(num, m_num);
 
    return num;
}

//8.7 permutations_without_dups

void permutations_without_dups(string my_str) {

  
    string::iterator it;
   sort(my_str.begin(), my_str.end());

   it =unique(my_str.begin(), my_str.end());
   my_str.resize(std::distance(my_str.begin(), it));

   do {
       std::cout << my_str << endl;
   } while (std::next_permutation(my_str.begin(), my_str.end()));

}
//8.11 coins
int coins(int n, vector<int>&storage_) {

    if (n < 0)
        return 0;

    if (storage_[n] != -1)
        return storage_[n];

    if (n == 0) {
        storage_[n] = 1;
        return storage_[n];
    }

     storage_[n] = coins(n - 1, storage_) + coins(n - 5, storage_) + coins(n - 10, storage_) + coins(n - 25, storage_);
     
     return storage_[n];
}

//8.12 EightQueen

void locate_eight_queen(int chess_board[8][8],int r,int c) {

    fill_with_one(chess_board, r, c);
   


}

void fill_with_one(int chess_board[8][8],int r,int c) {


        for (size_t j = 0; j < 8; j++)
        {
            chess_board[r][j] = 1;
        }
        for (size_t i = 0; i < 8; i++)
        {
            chess_board[i][c] = 1;
        }
        for (size_t i = 0; i < 8; i++)
        {
            if(r+i<8 && c + i < 8)
                chess_board[r+i][c+i] = 1;
        }
}

int main()
{
    int chess_board[8][8];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            chess_board[i][j] = 0;
        }
    }

    vector<vector<int>> arr_(3);
    fill(arr_.begin(), arr_.end(), vector<int>(3,0));

    vector<vector<int>>::iterator it1;
    vector<int>::iterator it2;
    arr_[1][1] = -1;
    arr_[0][1] = -1;
    arr_[1][0] = -1;
    cout<<find_path(arr_, 3, 3);
    //for ( it1= arr_.begin(); it1 != arr_.end(); it1++)
    //{
    //    for (it2 = it1->begin(); it2 != it1->end(); it2++)
    //    {
    //        *it2 = 0;
    //        cout << *it2<<" ";
    //    }
    //    cout << endl;
    //}


    //vector<int> arr(100);
    //fill(arr.begin(), arr.end(), -1);

    //cout<<coins(60,arr);
    //permutations_without_dups("batuhan");
    //cout << recursive_multiply(3, 4)<<endl;
    //cout << recursive_multuply_bit_shifting(3, 9) << endl;
   // vector<int> a = {1,2,3,4,5,6,6,9,10};
   //bool b = magic_index(a, a.size()-1, 0);
 /*   cout<<b<<endl;*/
    //vector<int> a = { 1,2,3,4};
    //subset_creator(a);
    //queue<int> q;
    //vector<int> v;
    
   /* std::cout << how_many_hop(35)<<endl;*/
 /*   std::cout << how_many_hop_v2(5)<<endl;*/

    //vector<int> arr(35);
    //fill(arr.begin(), arr.end(), 0);
    //cout << how_many_hop_memoization(35,arr) << endl;

    //cout << "asdasdsd" << endl;
    //vector<int> px = { 1,2,3,11 };
    //vector<int> o = { 11,12,13,14 };
    //vector<vector<int>> w = { {1,2},{1,3} };
    ////cout<<w.begin(
    //vector<int> intersec(4);
    //set_intersection(o.begin(), o.end(), px.begin(), px.end(), intersec.begin());

    //cout << *intersec.begin() << endl;

    //_CrtDumpMemoryLeaks();
}


