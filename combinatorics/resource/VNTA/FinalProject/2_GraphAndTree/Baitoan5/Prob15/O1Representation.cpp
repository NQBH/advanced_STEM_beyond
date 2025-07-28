#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* firstChild;
    Node* nextSibling;
    int child_count;
    vector<Node*> children_list;

    Node(int val) {
        data=val;
        parent=nullptr;
        firstChild=nullptr;
        nextSibling=nullptr;
        child_count=0;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree(int root_val) {
        root=new Node(root_val);
    }

    Node* get_root() {
        return root;
    }

    Node* add_child(Node* parent, int val) {
        Node* child=new Node(val);
        child->parent=parent;

        //gắn vào danh sách con
        if (!parent->firstChild)
            parent->firstChild=child;
        else {
            Node* temp=parent->firstChild;
            while (temp->nextSibling)
                temp=temp->nextSibling;
            temp->nextSibling=child;
        }

        //cập nhật child count và children list
        parent->child_count++;
        parent->children_list.push_back(child);

        return child;
    }

    int number_of_children(Node* node) {
        return node->child_count;
    }

    vector<Node*> children(Node* node) {
        return node->children_list;
    }

    void print_children(Node* node) {
        cout<<"Children of "<<node->data<<": ";
        for (Node* child : node->children_list)
            cout<<child->data<<" ";
        cout<<"\n";
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Tree T(1); //root là 1
    Node* root=T.get_root();

    Node* a=T.add_child(root, 2);
    Node* b=T.add_child(root, 3);
    Node* c=T.add_child(root, 4);

    T.add_child(a, 5);
    T.add_child(a, 6);

    cout<<"Number of children of root: "<<T.number_of_children(root)<<"\n";
    cout<<"Number of children of node 2: "<<T.number_of_children(a)<<"\n";

    T.print_children(root);
    T.print_children(a);

    return 0;
}
