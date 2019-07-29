#include <iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* right;
        node* left;
        node(int d){
            data=d;
            right=NULL;
            left=NULL;
        }
};
///Accepts the old root node& data & returns the new root node
node* insertInBST(node* root,int data){
    ///Base Case
    if(root==NULL){
        return new node(data);
    }
    ///Rec case-Insert in subtree and update the pointer
    if(data<=root->data){
        root->left=insertInBST(root->left,data);
    }
    else{
        root->right=insertInBST(root->right,data);
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
///Inorder print
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node*  build(){
    ///Read a list till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}
bool search(node* root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(root->data<data){
        search(root->right,data);
    }
    else{
        search(root->left,data);
    }
}
int main() {
    node* root=build();
    inorder(root);
    cout<<endl;
    bfs(root);
    int s;
    cin>>s;
    if(search(root,s)){
        cout<<"present";
    }
    else{
        cout<<"not present";
    }
    return 0;
}
