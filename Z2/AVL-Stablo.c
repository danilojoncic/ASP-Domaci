#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;

node_t *trazi(node_t *root, int val){
    if (root == NULL) return NULL;
    if (val < root->val)
        return trazi(root->left, val);
    else if (val > root->val)
        return trazi(root->right, val);
    else
        return root;
}

int visina(node_t *root){
    return root ? root->height : 0;
}
int max(int a, int b) {
    return a > b ? a : b;
}

void podesiVisinu(node_t *root){
    root->height = 1 + max(visina(root->left), visina(root->right));
}

node_t *rotirajDesno(node_t *root){
    node_t *new_root = root->left;
    if (root->parent){
        if (root->parent->left == root) root->parent->left = new_root;
        else root->parent->right = new_root;
    }
    new_root->parent = root->parent;
    root->parent = new_root;
    root->left = new_root->right;
    if (root->left) root->left->parent = root;
    new_root->right = root;

    podesiVisinu(root);
    podesiVisinu(new_root);
    return new_root;
}

node_t *rotirajLijevo(node_t *root){
    node_t *new_root = root->right;
    if (root->parent){
        if (root->parent->right == root) root->parent->right = new_root;
        else root->parent->left = new_root;
    }
    new_root->parent = root->parent;
    root->parent = new_root;
    root->right = new_root->left;
    if (root->right) root->right->parent = root;
    new_root->left = root;

    podesiVisinu(root);
    podesiVisinu(new_root);
    return new_root;
}

node_t *kreirajCvor(int val, node_t *parent){
    node_t *n = malloc(sizeof(node_t));
    n->val = val;
    n->parent = parent;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node_t *balansiraj(node_t *root){
    if (visina(root->left) - visina(root->right) > 1){
        if (visina(root->left->left) > visina(root->left->right)){
            root = rotirajDesno(root);
        }
        else{
            rotirajLijevo(root->left);
            root = rotirajDesno(root);
        }
    }
    else if (visina(root->right) - visina(root->left) > 1){
        if (visina(root->right->right) > visina(root->right->left)){
            root = rotirajLijevo(root);
        }
        else{
            rotirajDesno(root->right);
            root = rotirajLijevo(root);
        }
    }
    return root;
}
node_t *dodaj(node_t *root, int val){
    node_t *curr = root;
    while (curr->val != val){
        if (val < curr->val){
            if (curr->left) curr = curr->left;
            else{
                curr->left = kreirajCvor(val, curr);
                curr = curr->left;
            }
        }
        else if (val > curr->val){
            if (curr->right) curr = curr->right;
            else{
                curr->right = kreirajCvor(val, curr);
                curr = curr->right;
            }
        }
        else return root;
    }
    do{
        curr  = curr->parent;
        podesiVisinu(curr);
        curr = balansiraj(curr);
    } while (curr->parent);
    return curr;
}
void printAVLStablo(node_t *root, int level){
    if (root == NULL)
        return;
    printAVLStablo(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("          ");
    }
    printf("[%d]-\n", root->val);
    printAVLStablo(root->left, level + 1);
}

int main(){
    //opcija za brisanje nije uradjena
    //kod je isproban na primjeru sa vjezbi u decembru
    printf("Unesi prvi element:\n");
    int num;
    scanf("%d",&num);
    node_t *root = kreirajCvor(num, NULL);
    printf("Usao sam u u petlju dodavanja,kada si zadovoljan unosom, pritisni nulu!\n");
    printf("Sve rotacije se rade automatski, jedina opcija jeste dodavanje, stablo se stampa 	horiznotalno!\n");
    while(1){
        int vrijednost;
        printf("Unesi vrijednost za iduci cvor: ");
        scanf("%d",&vrijednost);
        if(vrijednost == 0){
            break;
        }else{
            root = dodaj(root, vrijednost);
            printf("--------------------------\n");
            printAVLStablo(root, root->height);
            printf("--------------------------\n");
        }
    }
    return 0;
}

