#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data){
        this->data=data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
    
};
