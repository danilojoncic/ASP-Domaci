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
    printf("[ROTIRANI CVOR] : [%d]\n",new_root->val);
    printf("[DESNA ROTACIJA]\n");
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
    printf("[ROTIRANI CVOR] : [%d]\n",new_root->val);
    printf("[LIJEVA ROTACIJA]\n");
    return new_root;
}
node_t *kreirajCvor(int val, node_t *parent){
    node_t *n = (malloc(sizeof(node_t)));
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
        printf("         ");
    }
    if(root->right && root ->left) {
        printf("[%d]--{\n", root->val);
    }else if(root ->right && root->left == NULL){
        printf("[%d]--/ \n", root->val);
    }else if(root->left && root->right == NULL){
        printf("[%d]--\\\n", root->val);
    }else if(root->parent){
        printf("--[%d]\n", root->val);
    }
    printAVLStablo(root->left, level + 1);
}

node_t *brisanje(node_t *root, int val){
    if (root == NULL) return NULL;
    if (val < root->val)
        root->left = brisanje(root->left, val);
    else if (val > root->val)
        root->right = brisanje(root->right, val);
    else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if (root->left == NULL){
            node_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            node_t *temp = root->left;
            free(root);
            return temp;
        }
        else{
            node_t *temp = root->right;
            while (temp->left) temp = temp->left;
            root->val = temp->val;
            root->right = brisanje(root->right, temp->val);
        }
    }
    podesiVisinu(root);
    return balansiraj(root);
}

void meni(){
    printf("[1] Dodaj element u AVL stablo\n");
    printf("[2] Obrisi element iz AVL stabla\n");
    printf("[3] Izadji iz programa\n");
}
void formatPrint(node_t *root, int level){
    printf("__________________________\n");
    printAVLStablo(root, level);
    printf("__________________________\n");
}

int main() {
    printf("AVL stablo, sve rotacije se izvrsavaju automatski uslijed dodavanja ili brisanja\n");
    printf("pri unosenju broja 0, bilo koja mogucnost se prekida i korisnik se vraca nazad u meni\n");
    printf("\nUnesi prvi element:\n");
    int num;
    scanf("%d", &num);
    node_t *root = kreirajCvor(num, NULL);
    while (1) {
        meni();
        int opcija;
        scanf("%d", &opcija);
        switch (opcija) {
            case 1:
                printf("[Dodavanje]\n");
                while (1) {
                    int vrijednost;
                    printf("Unesi vrijednost za iduci cvor: \n");
                    scanf("%d", &vrijednost);
                    if (vrijednost == 0) {
                        printf("[Kraj dodavanja]\n");
                        break;
                    } else {
                        root = dodaj(root, vrijednost);
                        formatPrint(root,root->height);
                    }
                }
                break;
            case 2:
                printf("[Brisanje]\n");
                while (1) {
                    int obrisi;
                    printf("Vrijednost za brisanje : ");
                    scanf("%d", &obrisi);
                    if (obrisi == 0) {
                        printf("[Kraj brisanja]\n");
                        break;
                    } else {
                        root = brisanje(root, obrisi);
                        formatPrint(root,root->height);
                    }
                }
                break;
            case 3:
                printf("[Kraj programa]\n");
                return 0;
            default:
                printf("Unesi broj koji odgovara zadatim mogucnostima\n");
        }
    }
    return 0;
}