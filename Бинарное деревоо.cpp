

/*Дано бинарное дерево. Найти все поддеревья, 
структура которых совпадает с заданной.*/

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

 struct Node {
    int inf;
    Node* left;
    Node* right;
    Node(int value) : inf(value), left(nullptr), right(nullptr) {}
};

 class Tree {
 private:
     Node* root;
     size_t size;
 public:
     size_t Size() { return size; }
     Node* Root() { return root; }
     Tree() :root(nullptr),size(0){}

     void push(Node* current, int value) {
         Node*newNode = new Node(value);
         if (!root) {
             
             root = newNode;
             return;
          }
         if (value < current->inf) {
             if (current->left != nullptr) {
                 current = current->left;
                 push(current, value);
             }
             else {
                 current->left = newNode;
                 return;
             }
         }
         if (value > current->inf) {
             if (current->right != nullptr) {
                 current = current->right;
                 push(current, value);
             }
             else {
                 current->right = newNode;
                 return;
             }
         }
         size++;
     }
     void Push(int& value) {
         push(root, value);
         return;
     }

  
     void printTree(Node* node, int level = 0) {
         if (!node) { return;}
         printTree(node->right, level + 1);
         for (int i = 0; i < level; i++) {
             cout << "   ";
         }
         cout << node->inf << endl;
         printTree(node->left, level + 1);
     }
     void print() {
         printTree(root);
     }


     bool Comperison(Node*a, Node*b){
         if (!a && !b) return true;
         if (!a || !b) return false;
         if (a->inf != b->inf) return false;
         return Comperison(a->left, b->left) && Comperison(a->right, b->right);
     }

  

     void Searh(Node* A,Node* b,int& all) {
         if (A == nullptr) return;
             if (Comperison(A, b) == true) {
                 all++;
                 return;

             }

             Searh(A->left, b, all);

             Searh(A->right, b, all);
            
     }

 };

     int main()
     {
         int w,all=0;
         Tree q,b;
         cout << "Choose input mode:" << endl;
         cout << "1 - console " << endl;
         cout << "2 - file " << endl;

         int mode = 0;
         while (mode < 1 || mode>2) {
             cout << "Your choice: ";
             cin >> mode;
             while (cin.fail()) {
                 cin.clear();
                 cin.ignore(10000, '\n');
                 cout << "Invalid input. Please enter a number: ";
                 cin >> mode;
             }
             if (mode == 2) {
                 {
                     ifstream in("inputQ.txt");
                     if (!in.is_open()) {
                         return 0;
                     }
                     while (in) {
                         in >> w;
                         q.Push(w);
                     }
                 }
                 {
                     ifstream in("inputB.txt");
                     if (!in.is_open()) {
                         return 0;
                     }
                     while (in) {
                         in >> w;
                         b.Push(w);
                     }
                 }
             }
             if (mode == 1) {
                 cout << "Enter the elements of the binary tree 'q' (enter 'X' to finish):" << endl;
                 string input;
                 while (true) {
                     cin >> input;
                     if (input == "x" || input == "X") {
                         break;
                     }

                     try {
                         w = stoi(input);
                     }
                     catch (...) {
                         cout << "Invalid input. Please enter a number or 'X' to finish: ";
                         continue;
                     }
                     q.Push(w);
                 }
                 cout << "Enter the elements of the binary tree 'b' (enter 'X' to finish):" << endl;
                 while (true) {
                     cin >> input;
                     if (input == "x" || input == "X") {
                         break;
                     }

                     try {
                         w = stoi(input);
                     }
                     catch (...) {
                         cout << "Invalid input. Please enter a number or 'X' to finish: ";
                         continue;
                     }
                     b.Push(w);
                 }
             }
         }
         cout << "tree-b:" << endl;
         b.print();
         cout << "tree-q:" << endl;
         q.print();
         q.Searh(q.Root(), b.Root(), all);
         cout <<"number of matches: "<< all << endl;
     };

     //50 20 70 15 25 65 75 12 17 22 27 62 67 72 77 11 13 16 18 21 23 26 27 61 63 66 68 71 73 76 78