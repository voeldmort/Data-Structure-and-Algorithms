#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;



//Take input but not in level wise
TreeNode *takeInput(){
  int data;
  cout<<"Enter data :";
  cin>>data;
  TreeNode *root=new TreeNode(data);
  int n;
  cout<<"Enter Number of children :";
  cin>>n;
  for(int i=0;i<n;i++){
    TreeNode *child=takeInput();
    root->children.push_back(child);
  }
  return root;
}
//Take input Level wise
TreeNode *takeInputLevelWise(){
  int rootData;
  cout<<"Enter the root data :";
  cin>>rootData;
  queue<TreeNode *> pending;
  TreeNode *root=new TreeNode(rootData);
  pending.push(root);
  while(!pending.empty()){
    TreeNode *firstNode=pending.front();
    pending.pop();
    cout<<"Enter the Number of child of "<<firstNode->data<<" :";
    int n;
    cin>>n;
    for(int i=0; i<n ;i++){
       cout<<"Enter the "<< i + 1 <<" Child of "<<firstNode->data << endl;
        int childData;
        cin>>childData;
          TreeNode *child=new TreeNode(childData);
          firstNode->children.push_back(child);//Pusing into children vector of the parent node(which was first node of the queue);
          pending.push(child);   //Pushing into the queue to take input levelwise;
    }
  }
  return root;

}
int numNodes(TreeNode *root){
  int ans=1;
  for(int i=0 ;i<root->children.size();i++){
    ans+=numNodes(root->children[i]);
  }
  return ans;
}


// display but not in the levelwise.....
void display(TreeNode *root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";

    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        display(root->children[i]);
    }

}
//Displat level wise
void displaylevelwise(TreeNode *root){
  if(root==NULL){
    return;
  }
  queue<TreeNode*> remainigNode;
  remainigNode.push(root);
  while(!remainigNode.empty()){
    TreeNode *front=remainigNode.front();
    remainigNode.pop();
    cout<<front->data<<":";
    for(int i=0; i < front->children.size();i++){
      cout<<front->children[i]->data<<" , ";
      remainigNode.push(front->children[i]);
    }
    cout<<endl;
  }
}

int getHeight(TreeNode *root) {
    if(root==NULL){
        return 0;
    }
    int minHeight=0;  //Here we are taking 0 as height because if ther is only 1 node present then it will return 0+1;
    for(int i=0; i<root->children.size();i++ ){
      int maxHeight=getHeight(root->children[i]);
        if(maxHeight>minHeight){
            minHeight=maxHeight;
        }
    }
    return minHeight+1;
}
void printLevelK(TreeNode *root,int k){
  if(k==0){
    cout<<root->data<<endl;
    return;
  }
  for(int i=0;i<root->children.size();i++){
    printLevelK(root->children[i],k-1);
  }
}

int main(){
    // TreeNode *root=new TreeNode(1);
    // TreeNode *child1=new TreeNode(2);
    // TreeNode *child2=new TreeNode(3);
    // TreeNode *child3=new TreeNode(4);
    // TreeNode *child11=new TreeNode(5);
    // TreeNode *child12=new TreeNode(6);
    // TreeNode *child21=new TreeNode(7);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // child1->children.push_back(child11);
    // child1->children.push_back(child12);
    // child2->children.push_back(child21);


    TreeNode *root=takeInputLevelWise();
    displaylevelwise(root);
    // insert();
    // insertLevelWise();
    int numOfNodes=numNodes(root);
    cout<<"Number of nodes are "<<numOfNodes;
    cout<<"The height of the tree is "<< getHeight(root);
    printLevelK(root,1);


    delete root; //When we call delete operation then we are calling destructor of that class

return 0;
}
