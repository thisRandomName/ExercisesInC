#include<stdio.h>
#include<stdlib.h>

struct Node{
  
 int key; 
 char colour;
 struct Node*left,*right,*parent;
}; 

struct Node* root = NULL;

void RotateLeft(struct Node* x){  // left rotation of node x

struct Node* y;    //set y

y=x->right; 
x->right=y->left;   

if(y->left != NULL)

{  y->left->parent = x;   
	
}

y->parent= x->parent;  //link x's parent to y

if(x->parent=NULL)

{   root=y;

}

else if ((x->parent->left!=NULL)&&(x->key=x->parent->left->key))

{   x->parent->left = y;

}

else x->parent->right = y;

y->left = x ;    // put x on y's left
x->parent=y; 
return;

}

void RotateRight(struct Node*y){  // right rotation of node 

struct Node *x;

x=y->left;
y->left=x->right;    

if (x->right !=NULL)

{  x->right->parent = y;

}

x->parent=y->parent;    

if(y->parent ==NULL)

{ root=x;

}

else if ((y->parent->left != NULL)&&(y->key==y->parent->left->key))

{  y->parent->left = x;

}

else 

y->parent->right=x;

x->right=y;   
y->parent=x;

return;

}

void InsertFixup(struct Node*z){


struct Node*y = NULL;

while((z->parent!=NULL)&&(z->parent->colour=='r'))

{ 

if((z->parent->parent->left !=NULL)&&(z->parent->key==z->parent->parent->left->key)) //if z's parent is grandparent's left child

{ if (z->parent->parent->right !=NULL)

y= z->parent->parent->right;   

if((y!=NULL)&&(y->colour=='r'))  // case  : red 

{ z->parent->colour = 'b';

y->colour ='b';

z->parent->parent->colour='r';

if(z->parent->parent!=NULL)

z=z->parent->parent;

}

else

{ 

if((z->parent->right != NULL)&& (z->key==z->parent->right->key))

{ z=z->parent;

RotateLeft(z);

}

z->parent->colour='b';

z->parent->parent->colour='r';

RotateRight(z->parent->parent);

}

}

else

{ 

if(z->parent->parent->left != NULL)

y = z->parent->parent->left;   

if((y!=NULL)&&(y->colour=='r'))  // case  : red 

{ z->parent->colour='b';

y->colour='b';

z->parent->parent->colour = 'r';

if(z->parent->parent !=NULL)

z= z->parent->parent;

}

else

{
	
	if((z->parent->left != NULL) && (z->key==z->parent->left->key))
	
	{ z=z->parent;
	
	RotateRight(z);
	
	}

z->parent->colour='b';

z->parent->parent->colour='r';

RotateLeft(z->parent->parent);

}

}

} root->colour='b';

}

void Insert(int val){


struct Node*x,*y;

struct Node*z= (struct Node*)malloc(sizeof(struct Node));               //new node z 

z->key=val;                //initialize new node 

z->left=NULL;

z->right=NULL;

z->colour='r';         //new node is red

x=root;               //x=root

//if(search(val)==1)

//{ printf("already exists");

//return;

//}

if (root==NULL)                     //root=z

{ root=z;

root->colour='b';

return;

}

while(x!=NULL)                       //x not null
  
{ y=x;                                //y=x

if(z->key < x->key)                   // bst comparison

{ x=x->left;

}

else x= x->right;

}

z->parent = y;                            //y=z's parent

if (y==NULL)

{ root=z;                               

}

else if(z->key < y->key )

{ y->left=z;

}
else y->right = z;


InsertFixup(z);

return;

}

void InOrder(struct Node * root){


struct Node* temp= root;

if(temp!=NULL)

{ InOrder(temp->left);

printf("%d is %c    ",temp->key, temp->colour );

InOrder(temp->right);

}return;

}

void PostOrder(struct Node * root){


struct Node *temp= root;

if(temp!=NULL)

{ PostOrder(temp->left);

PostOrder(temp->right);

printf("  %d is %c,  ",temp->key, temp->colour );

}return;

}

void Traverse(struct Node * root){


if(root!=NULL)

{ printf("root: %d is %c",root->key,root->colour);

printf("\nIn order: \n");

InOrder(root);

printf("\nPost order: \n");

PostOrder(root);

}return;

}



struct Node* min(struct Node* x){

while(x->left)

{ x=x->left;

}return x;
}


struct Node* Successor (struct Node* x){

struct Node* y;

if (x->right)

{ return min(x->right);

} y=x->parent;

while(y && x==y->right)

{ x=y;

y=y->parent;

} return y;

}



//delete here:


void DeleteFixup(struct Node*x){

 while(x!=root && x->colour=='b')

{ struct Node* w =NULL;

if((x->parent->left!=NULL)&&(x==x->parent->left))

{ w=x->parent->right;

if((w!=NULL)&&(w->colour=='r'))

{ w->colour='b';

x->parent->colour='r';

RotateLeft(x->parent);

w=x->parent->right;

}

if((w!=NULL)&&(w->right!=NULL)&&(w->left!=NULL)&&(w->left->colour=='b')&&(w->right->colour=='b'))

{

w->colour='r';

x=x->parent;

}

else if((w!=NULL)&&(w->right->colour=='b'))

{ w->left->colour='b';

w->colour='r';

RotateRight(w);

w=x->parent->right;

}

if(w!=NULL)

{ w->colour=x->parent->colour;

x->parent->colour='b';

w->right->colour='b';

RotateLeft(x->parent);

x=root;

}

}

else if(x->parent!=NULL)

{ w=x->parent->left;

if((w!=NULL)&&(w->colour=='r'))

{
	
	w->colour='b';

x->parent->colour='r';

RotateLeft(x->parent);

if (x->parent!=NULL)

w=x->parent->left;

}

if((w!=NULL)&&(w->right!=NULL)&&(w->left!=NULL)&&(w->right->colour=='b')&&(w->left->colour=='b'))

{ 

x=x->parent;

}

else if((w!=NULL)&&(w->right!=NULL)&&(w->left!=NULL)&&(w->left->colour=='b'))

{

w->right->colour='b';

w->colour='r';

RotateRight(w);

w=x->parent->left;

}

if(x->parent!=NULL)

{ w->colour=x->parent->colour;

x->parent->colour='b';

}

if(w->left!=NULL)

w->left->colour='b';

if(x->parent!=NULL)

RotateLeft(x->parent);

x=root;

}

} x->colour='b';

}


struct Node* Delete(int var){
struct Node* x= NULL;
struct Node* y= NULL;
struct Node* z;

z=root;

if((z->left==NULL)&&(z->right==NULL)&&(z->key==var))

{ root=NULL;

printf("empty tree\n");


}

while(z->key != var && z!=NULL)

{ if(var< z->key)

z= z->left;

else

z=z->right;


}

if((z->left==NULL)||(z->right==NULL))

{ y=z;

}

else

{ y=Successor(z);

}

if(y->left!=NULL)

{ x=y->left;

}

else

{ if(y->right != NULL)

x=y->right;

}

if((x!=NULL)&&(y->parent != NULL))

x->parent = y->parent;

if((y != NULL)&&(x!=NULL)&&(y->parent==NULL))

{ root=x;

}

else if(y== y->parent->left)

{ y->parent->left = x;

}

else

{ y->parent->right = x;

}

if(y!=z)

{ z->key = y->key;

}

if((y!=NULL)&&(x!=NULL)&&(y->colour=='b'))

{ DeleteFixup(x);

}return y ;

}



//main here :


int main()

{ 

int nodekey=0;
int s=1000;

do{
printf("\n\nPlease select:\n1.Insert node\n2.Print\n3.Delete node\n4.Quit\n\n\n");

scanf("%d",&s);

switch(s)

{ case 1:printf("Insert node:\n");

scanf("%d",&nodekey);

Insert(nodekey);break;

case 2:
printf("Red Black Tree: \n");
Traverse(root);break;

case 3 : printf("Delete node:\n");

scanf("%d",&nodekey);

Delete(nodekey); break;

case 4:break;
}

}while(s!=4);


}




