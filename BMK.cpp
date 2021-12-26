#include <iostream>
#include <cstdlib>
#define SPACE 20

using namespace std;

int x = 1;

struct Node
{
    int data;
    Node *left, *right;
};

Node* CreateNode()
{
    Node* newNode;
    newNode = new Node;
    cout << "\n\t\t\t\t\tIevadiet skaitli, kuru pievienot: ";
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

void AddNode(Node *root) {
    Node* newNode, * temp;
    newNode = CreateNode();
    temp = root;
    while ((temp->data > newNode->data && temp->left != NULL) || (temp->data <= newNode->data && temp->right != NULL)) {
        while (temp->data > newNode->data && temp->left != NULL) {
            temp = temp->left;
        }

        while (temp->data <= newNode->data && temp->right != NULL) {
            temp = temp->right;
        }
    }
    if (temp->data > newNode->data && temp->left == NULL)
        temp->left = newNode;

    if (temp->data <= newNode->data && temp->right == NULL)
        temp->right = newNode;
}

void PreOrder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void InOrder(Node *p)
{
    if (p != NULL)
    {
        InOrder(p->left);
        cout << p->data << " ";
        InOrder(p->right);
    }
}

void PostOrder(Node *p)
{
    if (p != NULL)
    {
        PostOrder(p->left);
        PostOrder(p->right);
        cout << p->data << " ";
    }
}

Node *search(Node *p, int key)
{
    Node* temp;
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

Node *swaptree(Node *p)
{
    Node* temp1 = NULL, * temp2 = NULL;
    if (p != NULL)
    {
        temp1 = swaptree(p->left);
        temp2 = swaptree(p->right);
        p->right = temp1;
        p->left = temp2;
    }
    return p;
}

int CountNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL)
    {
        x = x + 1;
        x = CountNodes(root->left);
    }
    if (root->right != NULL)
    {
        x = x + 1;
        x = CountNodes(root->right);
    }
    return x;
}

void print2D(Node *root, int space)
{
    if (root == NULL)
        return;
    space += SPACE;
    print2D(root->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print2D(root->left, space);
}

int main()
{
    Node *root = NULL;
    Node *temp;
    int choice, n;

    do {
        system("cls");
        cout << "\t\t\t\t\t --------------------------------\n";
        cout << "\t\t\t\t\t|  Binary Search Tree algortihm  |\n";
        cout << "\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t|        1. Create Root          |";
        cout << "\n\t\t\t\t\t|        2. Print Root           |";
        cout << "\n\t\t\t\t\t|        3. Add Node             |";
        cout << "\n\t\t\t\t\t|        4. Search               |";
        cout << "\n\t\t\t\t\t|        5. Print Tree           |";
        cout << "\n\t\t\t\t\t|        6. Count Nodes          |";
        cout << "\n\t\t\t\t\t|        7. Preorder             |";
        cout << "\n\t\t\t\t\t|        8. Inorder              |";
        cout << "\n\t\t\t\t\t|        9. Postorder            |";
        cout << "\n\t\t\t\t\t|        10. Swap tree           |";
        cout << "\n\t\t\t\t\t|        0. End Program          |";
        cout << "\n\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t --------------------------------";
        cout << "\n\n\t\t\t\t\t\tChoose number:  ";
        cin >> choice;
        switch (choice) {
        case 1: if (!root) 
            root = CreateNode();
            else cout << "\n\t\t\t\t\t\tRoot already exist!";
            system("Pause>>nul");
            break;
        case 2: if (root)
            cout << "\n\t\t\t\t\t\tRoot = " << root->data;
            else cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 3: if (root)
            AddNode(root);
              else root = CreateNode();
            break;
        case 4: if (root)
        {
            cout << "\n\t\t\t\t\t\tWhich node are u looking for: ";
            cin >> n;
            temp = search(root, n);
            if (temp)
                cout << "\n\t\t\t\t\t\tNode exist!";
            else 
                cout << "\n\t\t\t\t\t\tNode doesn't exist!";
            system("Pause>>nul");
            break;
        }
            else 
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 5: 
            if (root)
        {
            cout << "\nBinary search tree: \n";
            print2D(root, SPACE);
            system("Pause>>nul");
        }
            else cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
                system("Pause>>nul");
            break;
        case 6: 
            if (root)
            {
                n = CountNodes(root);
                cout << "This binary search tree has " << n << " nodes.";
            }
            else
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
                system("Pause>>nul");
                break;
        case 7:
            if (root)
            {
                PreOrder(root);
            }
            else
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 8:
            if (root)
            {
                InOrder(root);
            }
            else
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 9:
            if (root)
            {
                PostOrder(root);
            }
            else
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 10:
            if (root)
            {
                swaptree(root);
            }
            else
                cout << "\n\t\t\t\t\t\tRoot doesn't exist!";
            system("Pause>>nul");
            break;
        case 0:
            cout << "\n\t\t\t\t\t\tEnd!";
            system("Pause>>nul");
            break;
        default:
            cout << "\n\t\t\t\t\t\tIncorect choice!";
            system("Pause>>nul");
        }
    } while (choice != 0);

    system("Pause>nul");
    return 0;
}