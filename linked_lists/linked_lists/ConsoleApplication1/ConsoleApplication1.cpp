// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


//SINGLE LINK LIST!!!!
template<class T>
 class Node {

    
public:
    Node* next = nullptr;
    T value;
    Node(T value) {
        this->value = value;
    }
    Node() {
        this->value = NULL;
    }
    void AddElement(Node<T>**ref ,T val);
    void RemoveElement(Node<T>* root,Node<T>*node);
};

 template<class T>
void Node<T>:: AddElement(Node<T>** ref,T val) {
    Node<T>* node = new Node<T>(val);
     
    *ref = node;
    
}

template<class T>
void Node<T>::RemoveElement(Node<T>* root,Node<T>* node) {
    Node<T>* Troot = root;
    Node<T>* prev = new Node<T>();

    while (Troot != nullptr&& Troot !=node) {
        prev = Troot;
        Troot = Troot->next;
    }

    if (Troot == nullptr)
        break;

    prev->next = Troot->next;
    
    delete Troot;
}
void printlinklist(Node<int>* root) {
    Node<int>* troot = root;
    while (troot != nullptr) {
        cout << troot->value << " ";
        troot = troot->next;
    }
    cout << "" << endl;
}


//2.1
void removedups(Node<int>* root) {
    unordered_map<int, int> val_set;
    Node<int>* Troot = root;
    Node<int>* prev=nullptr;
    while (Troot != nullptr) {
        if (val_set.find(Troot->value) != val_set.end()) {
            prev->next = Troot->next;
        }
        else {
            val_set[Troot->value]++;
            prev = Troot;
        }
        
        Troot = Troot->next;
    }
     
    delete Troot;
}


//2.2
Node<int>* returnkthtolast(Node<int>* root, int k,int &i) {

    if (root == nullptr) return nullptr;
    
    Node<int>* node = returnkthtolast(root->next, k, i);
    i++;
    if (k == i)
        return root;

    return node;
}

bool deletenode(Node<int>* node) {

    Node<int>* next = node->next;
    node->value = next->value;
    node->next = next->next;
       
    return true;
}
//2.4v1
void partitionv1(Node<int>* node, int threshold) {
    map<int, int> n_set;
    Node<int>* tnode = node;
    bool IsExceeded = false;
    while (tnode != nullptr)
    {
        n_set[tnode->value]++;
        tnode = tnode->next;
    }

    for (auto it : n_set) {
        
        if (!IsExceeded && it.first >= threshold) {
            cout << "     ->       ";
            IsExceeded = true;
        }
            
        cout << it.first << "->";
    }

}
//2.4v2
void partitionv2(Node<int>* node, int threshold) {

    //creating two diff lists
    Node<int>* head=nullptr;
    Node<int>* tail=nullptr;

    //temporary node
    Node<int>* tnode = node;
    while (tnode != nullptr)
    {

        if (tnode->value < threshold) {
            head->AddElement(&head, tnode->value);
        }
        else {
            tail->AddElement(&tail, tnode->value);
        }
        tnode = tnode->next;
    }
    cout << "head:" << endl;
    printlinklist(head);
    cout << "tail:" << endl;
    printlinklist(tail);
}

//2.5
Node<int>* sumlist(Node<int>* l1, Node<int>* l2,int carry=0) {

    if (l1 == nullptr && l2 == nullptr && carry == 0)
        return nullptr;

    Node<int>* result = new Node<int>;
    int value = carry;
    if (l1 != nullptr)
        value +=l1->value ;

    if (l2 != nullptr)
         value +=l2->value;

    result->value = value % 10;
    if (l1 != nullptr || l2 != nullptr) {
        Node<int>* more = sumlist(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, value >= 10 ? 1 : 0);
        result->next = more;
    }

    return result;
}

Node<int>* getkthnode(Node<int>* list, int k) {

    if (k <= 0) return nullptr;

    while (k > 0 && list != nullptr)
    {
        list = list->next;
        k--;
    }
    return list;
}

bool  Ispalindromelist(Node<int>* mylist) {
    //use stack
    //u have ur link list solve it recursively
    //permutation a->x->mid->y->b 
    //returning multiple object?

    if (mylist == nullptr)
        return false;

    //Node<int>* prev=nullptr;
    //Node<int>* current=mylist;
    //Ispalindromelist(current->next);

    //return nullptr;

    
    Node<int>* slow_runner=mylist;
    Node<int>* fast_runner=mylist;
    Node<int>* t_list = mylist;
    stack<int> first_half;
    int l_size = 0;
    while (t_list != nullptr) {
      
        l_size++;
        t_list = t_list->next;
    }
    if (l_size % 2 == 0)
        return false;

    while (fast_runner->next != nullptr) {

        first_half.push(slow_runner->value);
        fast_runner = fast_runner->next->next;
        slow_runner = slow_runner->next;
    
    }
    slow_runner = slow_runner->next;
    while (slow_runner !=nullptr)
    {
   
        if (slow_runner->value != first_half.top()) {
            cout << "asdd" << endl;
            return false;
        }
           
        first_half.pop();
        slow_runner = slow_runner->next;
    }


    return true;
}

bool Ispalindromelistv2(Node<int>* my_list) {
    

    //reverse list
    Node<int>* prev = nullptr;
    Node<int>* current = my_list;
    Node<int>* next = nullptr;
    //while (current !=nullptr) {
    //    next =
    //}

    //compare those two lists

    return false;

}

//2.7
Node<int>* intersection(Node<int>*l1, Node<int>* l2) { 
    
    //check that re they null or not
    if (l1 != nullptr || l2 != nullptr) return nullptr;

    int sizel1 = 0;
    int sizel2 = 0;
    Node<int>* tail1 = nullptr;
    Node<int>* tail2 = nullptr;
    //find the shortest list
    while (l1 != nullptr) {
        sizel1++;
        tail1 = l1;
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        sizel2++;
        tail2 = l2;
        l2 = l2->next;
    }

    if (tail1 != tail2) return nullptr;

    Node<int>* longone = sizel1 > sizel2 ? l1 : l2;
    Node<int>* shortone = sizel1 < sizel2 ? l1 : l2;
    longone = getkthnode(longone, abs(sizel1 - sizel2));

        while (longone != shortone &&longone !=nullptr && shortone !=nullptr) {
            longone = longone->next;
            shortone = shortone->next;
     }
        //either of them re okay because they re pointing the same node.
        return longone;
}

//2.8
//slow runner and fast runner approach.
Node<int>* loopdetection(Node<int>* mylist) {
    
    if (mylist == nullptr)return nullptr;

    unordered_map<Node<int>*, int> my_map;

    while (mylist != nullptr) {
        my_map[mylist]++;
        if (my_map[mylist] > 1)
            return mylist;

        mylist = mylist->next;
    }

    //Node<int>* slow_runner=mylist;
    //Node<int>* fast_runner = mylist;

    //while (slow_runner != nullptr && fast_runner != nullptr) {

    //    if (fast_runner == slow_runner)
    //        return slow_runner;// either of them re okay.

    //    slow_runner = slow_runner->next;
    //    fast_runner = fast_runner->next->next;
    //}
    return nullptr;
}


//
//Node<int>* reverselist(Node<int>* head, Node<int>* node) {
//   
//    if (node == NULL)
//        return NULL;
//    if (node->next == NULL) {
//        head = node;
//        return node;
//    }
//    Node<int>* node1 = reverselist(head,node->next);
//    node1->next = node;
//    node->next = NULL;
//    return node;
// }

int main()
{
    Node<int>* root = new Node<int>(1);
    Node<int>* second = new Node<int>(2);
    Node<int>* third = new Node<int>(3);
    Node<int>* forth = new Node<int>(2);
    Node<int>* fifth = new Node<int>(1);
   
    
    //root->next = second;
    //root->next->next = third;
    //root->next->next->next = forth;
    //root->next->next->next->next = fifth;


    //Node<int>* root1 = new Node<int>(1);
    //Node<int>* second1 = new Node<int>(2);
    //Node<int>* third1 = new Node<int>(3);
    //Node<int>* forth1 = new Node<int>(4);
    //Node<int>* fifth1 = new Node<int>(4);

    //root1->next = second1;
    //root1->next->next = third;

    //cout << sizeof(int*) << endl;
    //cout << sizeof(Node<int>) << endl;


   cout<< Ispalindromelist(root)<<endl;
    /*root->next->next->next = forth1;*/
    //root->next->next->next->next = fifth1;
   /* deletenode(forth);
    printlinklist(root);*/

  /*  partitionv2(root, 12);*/


   
   // printlinklist(sumlist(root,root1));

    //cout<<loopdetection(root)->value << endl;


   /* int i = 0;
    cout << returnkthtolast(root, 4, i)->value << endl;;
    cout << i << endl;*/

   /* printlinklist(root);
    removedups(root);
    printlinklist(root);*/
   /*delete root, second, third, forth, fifth;*/
  /* delete root1, second1, third1, forth1, fifth1;*/
   delete root;
   delete second;
   delete third;
   delete forth;
   delete fifth;
   
   _CrtDumpMemoryLeaks();

}

