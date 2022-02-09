

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
#include <string> 

//Implementing graph using linked list



using namespace std;

//template <typename T>


template<class T>
class MyGraph
{
public:

	struct Graph_Node
	{
		bool IsVisited = false;
		T val = NULL;
		bool IsRoot = true;
	};

	//Adjaceny List
	unordered_map<T, list<T>> adj_list;
	vector<Graph_Node> nodes;
	void addEdge(T v, T w);
	void addVertex(T v);
	void DisplayAdj_list();
	void Display_node_state();
	void B_Search();
	void Find_Roots();
	MyGraph(T root_vertex);
	~MyGraph();

private:

};

template<class T>
MyGraph<T>::MyGraph(T root_vertex)
{

	addVertex(root_vertex);

}

template<class T>
MyGraph<T>::~MyGraph()
{

}

template<class T>
void MyGraph<T>::addEdge(T v, T w) {

	typename unordered_map<T, list<T>>::iterator itv, itw;
	itw = adj_list.find(w);
	itv = adj_list.find(v);
	if (itv == adj_list.end() || itw == adj_list.end())
		cout << "first add this vertex to graph!" << endl;
	else
	{
		adj_list[v].push_back(w);
		typename vector<Graph_Node>::iterator itg;
		for (itg = nodes.begin(); itg != nodes.end(); itg++) {
			if (itg->val == w)
				itg->IsRoot = false;
		}

	}
}

template<class T>
void MyGraph<T>::addVertex(T v) {

	Graph_Node node;
	node.val = v;
	nodes.push_back(node);
	list<T> t_list;
	t_list.push_back(v);
	typename unordered_map<T, list<T>>::iterator it;
	it = adj_list.find(v);
	if (it == adj_list.end()) {
		adj_list.insert(pair<T, list<T>>(v, t_list));
	}

	else
		cout << "The vertex valued: " << v << " already in the graph!" << endl;
}

// Displays Graph as a Adj_list!!
template<class T>
void MyGraph<T>::DisplayAdj_list() {

	typename unordered_map<T, list<T>>::iterator it;

	for (it = adj_list.begin(); it != adj_list.end(); it++)
	{
		for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
			cout << *it1 << " ";
		}
		cout << endl;
	}


}

template<class T>
void MyGraph<T>::Display_node_state() {


	typename vector<Graph_Node>::iterator it;

	for (it = nodes.begin(); it != nodes.end(); it++)
	{
		cout << (it->val) << " " << (it->IsVisited) << endl;;

	}


}


//4.7 Build-Order
/*
   1.Create vertices
   2.Create Graph
   3.Traverse graph
*/
template<class T>
void MyGraph<T>::B_Search() {

	queue<Graph_Node> node_queue;
	typename vector<Graph_Node>::iterator itg;
	for (itg = nodes.begin(); itg != nodes.end(); itg++) {
		if (itg->IsRoot == true) {
			itg->IsVisited = true;
			node_queue.push(*itg);

		}
	}
	while (!node_queue.empty())
	{
		Graph_Node node;
		node = node_queue.front();
		cout << node.val << " ";
		node_queue.pop();
		typename list<T>::iterator i;
		for (i = adj_list[node.val].begin(); i != adj_list[node.val].end(); i++)
		{
			typename vector<Graph_Node>::iterator itg;
			for (itg = nodes.begin(); itg != nodes.end(); itg++)
			{
				if (itg->val == *i && itg->IsVisited == false) {
					itg->IsVisited = true;
					node_queue.push(*itg);
				}
			}
		}
	}

	/*
		GET THE ROOT NODE
		ADD ALL ADJ LIST TO QUEUE
		POP QUEUE AND SHOW
		ALL THAT NODES ADJ_LIST

	*/


}

template<class T>
void MyGraph<T>::Find_Roots() {


}

//4.2 Minimal Tree
//with given sorted list. create a tree with minimal height.

struct binary_tree_node
{
	int val = NULL;
	binary_tree_node* right = nullptr;
	binary_tree_node* left = nullptr;
	int depth = 0;
};

//4.2
binary_tree_node* create_minimal_tree(int arr[], int start, int end) {

	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;

	binary_tree_node* new_node = new binary_tree_node;
	new_node->val = arr[mid];

	new_node->right = create_minimal_tree(arr, mid + 1, end);
	new_node->left = create_minimal_tree(arr, start, mid - 1);

	return new_node;
}

binary_tree_node* create_normal_tree(int arr, binary_tree_node* head) {



	if (head == nullptr) {

		binary_tree_node* new_node = new binary_tree_node;
		new_node->val = arr;
		return new_node;
	}

	if (head->val >= arr) {

		head->left = create_normal_tree(arr, head->left);
	}
	if (head->val < arr) {

		head->right = create_normal_tree(arr, head->right);
	}


	return head;
}

void iterative_tree_traversal(binary_tree_node* head) {

	stack<binary_tree_node*> node_stack;

	if (head == NULL)
		return;

	node_stack.push(head);
	//binary_tree_node* tnode = head;
	while (!node_stack.empty()) {

		binary_tree_node* tnode = node_stack.top();
		cout << node_stack.top()->val << endl;
		node_stack.pop();

		if (tnode->left != nullptr)
			node_stack.push(tnode->left);

		if (tnode->right != nullptr)
			node_stack.push(tnode->right);

	}
}

void tree_traversal(binary_tree_node* head) {

	if (head == nullptr)
		return;

	cout << head->val << " depth:  " << head->depth << endl;
	tree_traversal(head->left);

	tree_traversal(head->right);



}
//4.3 list of depths
map< binary_tree_node*, int> mapofdepts(binary_tree_node* head, map< binary_tree_node*, int>& depth_map, int n = 1) {

	if (head == nullptr)
		return depth_map;

	depth_map[head] += n;
	n++;
	/*cout << head->val << endl;*/
	mapofdepts(head->left, depth_map, n);

	mapofdepts(head->right, depth_map, n);
	return depth_map;

}
vector<list<int>> listofdepts(binary_tree_node* head, map< binary_tree_node*, int>& depth_map, vector<list<int>>depth_list, int n = 1) {


	depth_map = mapofdepts(head, depth_map);
	for (auto p : depth_map) {
		/* cout << *reinterpret_cast<int*>(p.first) << " : " << p.second << endl;*/


		depth_list[p.second].push_back(*reinterpret_cast<int*>(p.first));
	}
	return depth_list;

}



//4.4 checkbalanced

int getheight(binary_tree_node* head) {
	if (head == nullptr) return -1;

	return max(getheight(head->right), getheight(head->left)) + 1;
}

bool Isbalancedv2(binary_tree_node* head) {

	if (head == nullptr) return true;

	int heightdiff = getheight(head->left) - getheight(head->right);
	if (abs(heightdiff) > 1) {
		return false;
	}
	else
	{
		return Isbalancedv2(head->left) && Isbalancedv2(head->right);
	}
}

//4.5 if we would only check the current node and its children!
bool IsBST(binary_tree_node* root, bool IsBst = true) {

	if (root == nullptr) return IsBst;

	if (root->left != nullptr && root->right != nullptr) {
		if (root->left->val > root->val || root->right->val <= root->val)
			IsBst = false;
		return (IsBst);
	}
	if (root->left == nullptr && root->right != nullptr) {
		if (root->right->val <= root->val)
			IsBst = false;
		return (IsBst);
	}
	if (root->left != nullptr && root->right == nullptr) {
		if (root->left->val > !root->val)
			IsBst = false;
		return (IsBst);
	}
	IsBST(root->left, IsBst);
	IsBST(root->right, IsBst);

	return IsBst;
}


//4.5 if we check entire tree is a binary tree or not.
binary_tree_node* create_arr_fromBST(binary_tree_node* root, vector<int>& arr) {

	if (root == nullptr) return nullptr;


	create_arr_fromBST(root->left, arr);
	arr.push_back(root->val);
	create_arr_fromBST(root->right, arr);

	return root;
}
bool IsBSTv2(binary_tree_node* root, vector<int> arr) {

	create_arr_fromBST(root, arr);
	return std::is_sorted(arr.begin(), arr.end());
}




//4.9 BST Sequence ????

void tree_traversal_4_9(binary_tree_node* root) {

	if (root == nullptr) {/* cout << "nullptr->";*/ return; }
	//if (root->left == nullptr && root->right == nullptr) { return; }
	//if(root->left == nullptr || root->right != nullptr) { cout << "nullptr->"; return; }
	

	cout << root->val << "->";
	tree_traversal_4_9(root->left);
	tree_traversal_4_9(root->right);
}
void traverse_and_swap(binary_tree_node* root, binary_tree_node* t_root) {

	if (t_root == nullptr)
		return;
	if (t_root->left == nullptr && t_root->right == nullptr)
		return;

	
	tree_traversal_4_9(root);
	std::swap(t_root->left, t_root->right);
	cout << endl;
	
	tree_traversal_4_9(root);
	std::swap(t_root->left, t_root->right);
	cout << endl;
	traverse_and_swap(root, t_root->left);
	traverse_and_swap(root, t_root->right);
}



//4.10 Check Sub-tree
void traverse_bt(binary_tree_node* root, vector<binary_tree_node*>& arr, int val) {

	if (root == nullptr)
		return;

	if (root->val == val) { arr.push_back(root); }


	traverse_bt(root->left, arr, val);
	traverse_bt(root->right, arr, val);

}
void double_traverse(binary_tree_node* root_small, binary_tree_node* root_big, bool& isEqual) {

	if (root_small != nullptr && root_big != nullptr) {
		if (root_small->val != root_big->val)
			isEqual = false;
	}

	if ((root_small != nullptr && root_big == nullptr) || (root_small == nullptr && root_big != nullptr))
		isEqual = false;


	if (root_small == nullptr || root_big == nullptr)
		return;

	double_traverse(root_small->left, root_big->left, isEqual);
	double_traverse(root_small->right, root_big->right, isEqual);


}
bool check_subtree(binary_tree_node* root_big, binary_tree_node* root_small) {

	vector<binary_tree_node*> equal_val_arr;
	int root_val = root_small->val;

	traverse_bt(root_big, equal_val_arr, root_val);

	vector<binary_tree_node*>::iterator it = equal_val_arr.begin();
	bool IsEqual = true;
	for (; it != equal_val_arr.end(); it++)
	{
		double_traverse(*it, root_small, IsEqual);
		if (IsEqual)
			return true;
	}

	return IsEqual;



}


//4.10 version2
void tree_traversal_for_4_10(binary_tree_node* root, string& s_arr) {

	if (root == nullptr) {
		s_arr.append("X");
		return;
	}

	s_arr.append(std::to_string(root->val));
	tree_traversal_for_4_10(root->left, s_arr);
	tree_traversal_for_4_10(root->right, s_arr);

}
bool check_subtree2(binary_tree_node* root_big, binary_tree_node* root_small) {

	string s_arr_big;
	string s_arr_small;
	tree_traversal_for_4_10(root_big, s_arr_big);
	tree_traversal_for_4_10(root_small, s_arr_small);
	cout << s_arr_big << endl;
	cout << s_arr_small << endl;
	return  s_arr_big.find(s_arr_small) != std::string::npos ? true : false;

}









struct graphNode {
	graphNode* source = NULL;
	graphNode* destination = NULL;
	char val = NULL;

};


// Driver code
int main()
{
	

	//

	binary_tree_node* root = nullptr;
	binary_tree_node* root2 = nullptr;
	binary_tree_node* root3 = nullptr;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	root = create_minimal_tree(arr, 0, 12);

	root2 = create_normal_tree(3, root2);
	create_normal_tree(5, root2);
	create_normal_tree(4, root2);
	create_normal_tree(6, root2);
	create_normal_tree(1, root2);
	create_normal_tree(2, root2);
	create_normal_tree(0, root2);


	root3 = create_normal_tree(3, root3);
	create_normal_tree(4, root3);
	create_normal_tree(1, root3);
	create_normal_tree(0, root3);
	create_normal_tree(2, root3);
	//cout << root->left->right->right->val << endl;;
	//cout << root2->val;
 /*   cout << check_subtree(root,root2);*/


	//binary_tree_node* root3_t = root3;
	//traverse_and_swap(root3, root3_t);



	//BSTSequence(root);
/*    tree_traversal(root);*/

   //MyGraph<char> g('c');

   ////g.addVertex('b');
   ////g.addVertex('d');
   ////g.addVertex('g');
   ////g.addVertex('a');

   ////g.addEdge('c', 'b');
   ////g.addEdge('c','d');  


   ////g.addEdge('b', 'a');
   ////g.addEdge('d', 'g');


   //g.addVertex('f');
   //g.addVertex('e');
   //g.addVertex('d');
   ////g.addVertex('c');
   //g.addVertex('b');
   //g.addVertex('a');

   //g.addEdge('a', 'd');
   //g.addEdge('f', 'b');
   //g.addEdge('b', 'd');
   //g.addEdge('f', 'a');
   //g.addEdge('d', 'c');

   //g.B_Search();

   //g.DisplayAdj_list();
   //g.Display_node_state();

 /*  binary_tree_node* root = nullptr;
   int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	 root =  create_minimal_tree(arr,0,12);

	 binary_tree_node* rootv2 = nullptr;

	 for (size_t i = 0; i < 13; i++)
	 {
		 rootv2 = create_normal_tree(arr[i], rootv2);

	 }*/
	 /*     cout<< IsBalanced(root)<<endl;
		 tree_traversal(root);*/
		 //cout << Isbalancedv2(root) << endl;

	   /*  binary_tree_node* head = new binary_tree_node;
		 head->val = 10;
		 head->left = new binary_tree_node;
		 head->left->val = 11;
		 bool x = true;

		 cout << IsBST(head) << endl;*/
		  vector<int> x;
		  cout<<IsBSTv2(root,x)<<endl;
		//cout << "" << endl;
		//tree_traversal(rootv2);
		//cout << "" << endl;
		//iterative_tree_traversal(root);


		  //4.3///////////////////////////////////////////
		//map< binary_tree_node*, int>depth_map;
		//depth_map = mapofdepts(root, depth_map);

		//for (auto p : depth_map)
		//    cout << *reinterpret_cast<int*>(p.first) << " : " << p.second << endl;



		//
		//vector<list<int>> list_of_depths(10);
		//list_of_depths= listofdepts(root, depth_map, list_of_depths);

		//for (auto& element : list_of_depths) {
		//    for (auto const& i : element) {
		//        std::cout << i<<"->";
		//    }
		//    cout << "" << endl;
		//}

	////////////////////////////////////////////////////////////


		/* cout<< IsBalanced(rootv2)<<endl;*/

		  //cout << a << " " << b << endl;

		  //tree_traversal(rootv2);
		 /* cout << x << " " << y << endl;*/
	   /* Graph graph;

		int V = 5;
		vector<int> adj[5];
		graph.addEdge( 0, 1);
		graph.addEdge(0, 4);
		graph.addEdge(1, 2);
		graph.addEdge(1, 3);
		graph.addEdge(1, 4);
		graph.addEdge(2, 3);
		graph.addEdge(3, 4);
		graph.DFS(0);*/
		/* printGraph(adj, V);*/
	return 0;
}