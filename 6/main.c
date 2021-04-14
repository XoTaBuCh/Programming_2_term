/*В текстовом файле содержатся n целых чисел в двоичной системе
счисления (m бит каждое). Построить бинарное дерево, в котором
числам соответствуют листья дерева, а путь по дереву определяется
двоичным представлением числа (‘1’ – переход к правому потомку,
‘0’ – переход к левому потомку).*/

#include <stdlib.h>
#include <stdio.h>

void checkPtr(void *ptr) {
    if (ptr == NULL) {
        printf("Failed to allocate memory. The program has stopped working.\n");
        exit(-1);
    }
}

long int filesize(FILE* fp) {
    long int save_pos, size_of_file;
    save_pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    size_of_file = ftell(fp);
    fseek(fp, save_pos, SEEK_SET);
    return(size_of_file);
}

struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};

struct tree* root; // начальная вершина дерева

void print_tree(struct tree* r, int l, int n) {
    int i;
    if (l > n - 1) return;
    print_tree(r->right, l + 1, n);
    for (i = 0; i < l; ++i) printf("                 ");
    printf("%d\n", r->info);
    print_tree(r->left, l + 1, n);
}

void treeremove(struct tree* root) {
    if (root != NULL) {
        treeremove(root->left);
        treeremove(root->right);
        free(root);
    }
}

struct tree* NodeBuilder(int n) {
    struct tree* r = (struct tree*) malloc(sizeof(struct tree));
	checkPtr(r);
    if (n > 0) {
        int a = -1;
        r->info = a;
        r->right = NodeBuilder(n - 1);
        r->left = NodeBuilder(n - 1);
    } else {
        r->right = NULL;
        r->left = NULL;
    }
    return r;
}

int main() {
    FILE* fp;
    char file[100];
    char* a;
	int countNum = 1;
	
    fp = fopen("input.txt", "r");
    if (!fp) {
		printf("Input file is invalid");
        exit(-1);
	}
	
    a = fgets(file, sizeof(file), fp);
    for (int i = 0; i < filesize(fp); i++) {
        if (a[i] == ' ') countNum++;
	}
    countNum++;
    root = NodeBuilder(countNum);
    for (int i = 0, j = 0; i < countNum - 1; i++, j++) {
        struct tree* temp = root;
        for (;; j++) {
            if (a[j] == '0') temp = temp->left;                        
            else if (a[j] == '1') temp = temp->right;           
            if (temp->right->right == NULL) {
                temp->info = 1;
                for (int k = j, l = 0; k != 0 && a[k] != ' '; k--, l++) {
                    if (a[k] == '1') temp->info += (2 << (l - 1));
				}
                break;
            }
        }
    }
	
    fclose(fp);
    print_tree(root, 0, countNum);
    treeremove(root);
    return 0;
}

