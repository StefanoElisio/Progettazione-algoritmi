//
// Created by stfne on 08/05/2024.
//
#include "iostream"
#include "vector"

struct Node{
    void add_children(std::vector<int> n){
        for (int i=0; i<n.size();i++) {
            Node* node = new Node();
            node->weight = n[i];
            this->children.push_back(node);
        }
    }
    Node* get_child(int i){
        return children[i];
    }
    int weight;
    std::vector<Node*> children;
};

Node* load_tree(){
    Node* root = new Node();
    root->weight = 2;
    root->add_children({4,1,3});
    Node* node = root->get_child(0);
    node->add_children({2,1,3,});
    node->get_child(0)->add_children({2,3});
    node->get_child(0)->get_child(1)->add_children({5});
    node->get_child(2)->add_children({2});
    node = root->get_child(2);
    node->add_children({1,5});
    node->get_child(0)->add_children({3});
    return root;
}

std::pair<int,int> dfs(Node* v)
{
    int opt_plus = v->weight;
    int opt_minus = 0;
    for(Node *u : v->children)
    {
        std::pair<int,int> opt_u = dfs(u);
        opt_plus += opt_u.second;
        opt_minus += std::max(opt_u.first, opt_u.second);
    }
    return std::make_pair(opt_plus, opt_minus);
}

int main(){
    Node* root = load_tree(); //Read T. Return a pointer to its root.
    std::pair<int,int> opt = dfs(root);
    std::cout<<std::max(opt.first, opt.second) << "\n";
    return 0;
}


