#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

Node *CreateNode()
{
    Node* newNode;
    newNode = new Node;
    cout << "\nIevadiet skaitli, kuru pievienot:  ";
    cin >> newNode->data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void PrintTree(Node* cur)
{
    if (!cur) return;
    PrintTree(cur->left);
    cout << cur->data;
    PrintTree(cur->right);
}

void AddNode(Node* root) {
    Node* newNode, * temp;
    newNode = CreateNode();
    temp = root;
    while ((temp->data > newNode->data && temp->left != NULL) || (temp->data <= newNode->data && temp->right != NULL)) {
        while (temp->data > newNode->data && temp->left != NULL) {
            temp = temp->left;//left side
        }

        while (temp->data <= newNode->data && temp->right != NULL) {
            temp = temp->right;//right side
        }
    }//while(big one)
    if (temp->data > newNode->data && temp->left == NULL)
        temp->left = newNode; //insert node in tree

    if (temp->data <= newNode->data && temp->right == NULL)
        temp->right = newNode; //insert node in tree
}

void PreOrder(Node* p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void InOrder(Node* p)
{
    if (p != NULL)
    {
        InOrder(p->left);
        cout << p->data << " ";
        InOrder(p->right);
    }
}

void InOrder_not(Node* p)
{
    Node* stack[100];
    int top;
    top = -1;
    if (p != NULL)
    {
        top++;
        stack[top] = p;
        p = p->left;
        while (top >= 0)
        {
            while (p != NULL)
                /* left child to stack*/
            {
                top++;
                stack[top] = p;
                p = p->left;
            }
            p = stack[top];
            top--;
            cout << p->data << "";
            p = p->right;
            if (p != NULL)
                /* right child to stack*/
            {
                top++;
                stack[top] = p;
                p = p->left;
            }
        }
    }
}

void PostOrder(Node* p)
{
    if (p != NULL)
    {
        PostOrder(p->left);
        PostOrder(p->right);
        cout << p->data << " ";
    }
}

Node *find(Node *p, int key)
{
    Node *temp;
    temp = p;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        else
            if (temp->data > key)
                temp = temp->left;
            else temp = temp->right;
    }
    return NULL;
}

Node *find1(Node *p, int key, Node *y)
{
    Node *temp;
    if (p == NULL) return (NULL);
    temp = p;
    y = NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        else
        {
            y = temp;
            if (temp->data > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    return NULL;
}
Node *delete_node(Node *p, int val) {
    Node *x, *y=0, *temp;
    x = find1(p, val, y);
    if (x == NULL)
    {
        printf("This node does not exist !\n");
        return(p);
    }
    else {
        if (x == p) {
            if (x->left == NULL && x->right == NULL) {
                free(x);
                printf("\nThe tree is down !!!\n");
                return NULL;
            }

            if (x->left == NULL) {
                p = x->right;
                free(x);
                return p;
            }
            temp = x->left;
            y = x->right;
            p = temp;
            while (temp->right != NULL)
                temp = temp->right;
            temp->right = y;
            free(x);
            return(p);
        }
        if (x->left != NULL && x->right != NULL) {
            if (y->left == x) {
                temp = x->left;
                y->left = x->left;
                while (temp->right != NULL)
                    temp = temp->right;
                temp->right = x->right;
                x->left = NULL;
                x->right = NULL;
            }
            else
            {
                temp = x->right;
                y->left = x->right;
                while (temp->left != NULL)
                    temp = x->right;
                temp->left = x->left;
                x->left = NULL;
                x->right = NULL;
            } free(x); return(p);
        }
        if (x->left == NULL && x->right != NULL) {
            if (y->left == x) y->left = x->right;
            else  y->right = x->right;
            x->right = NULL;
            free(x);
            return(p);
        }
        if (x->left != NULL && x->right == NULL) {
            if (y->left == x) y->left = x->left;
            else   y->right = x->left;
            x->left = NULL;
            free(x); return(p);
        }
        if (x->left == NULL && x->right == NULL) {
            if (y->left == x)
                y->left = NULL;
            else
                y->right = NULL;
            free(x);
            return(p);
        }
    }
}
//===================Swapping Tree
Node *swaptree(Node *p)
{
    Node *temp1 = NULL, *temp2 = NULL;
    if (p != NULL)
    {
        temp1 = swaptree(p->left);
        temp2 = swaptree(p->right);
        p->right = temp1;
        p->left = temp2;
    }
    return p;
}

int main()
{
    Node* root = NULL;
    int choice;
    root = CreateNode();
  
    do {
        system("cls");
        cout << "\t\tProgram about Data Structure: Binary Search Tree\n";
        cout << "\n10. Print Root";
        cout << "\n1. Create Root";
        cout << "\n2. Print Tree";
        cout << "\n3. Add Node";
        cout << "\n4. Count";
        cout << "\n0. End Program";
        cout << "\nChoose number: ";
        cin >> choice;
        switch (choice) {
        case 1: if (!root) root = CreateNode(); else cout << "Root exist!";
            system("Pause>>nul"); break;
        case 10: if (root) cout << "ROOT = " << root->data; else cout << "Root  doesn't exist!";
            system("Pause>>nul"); break;
        case 2: if (root) { cout << "\nBMK: \n"; PrintTree(root); system("Pause>>nul"); }break;
        case 3: if (root) AddNode(root); else root = CreateNode(); break;
        case 0: cout << "End!!!";  system("Pause>>nul"); break;
        default: cout << "Incorect choice!"; system("Pause>>nul");
        }
    } while (choice != 0);

    system("Pause>nul");
    return 0;
}