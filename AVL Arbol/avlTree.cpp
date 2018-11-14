#include <iostream>
#include <assert.h>
#include "avlTree.h"

void print(int &x);

using namespace std;

int main()
{
    AVLTreeType<int> avl;
	int num;
	cout << "Enter numbers ending with -999" << endl; cin >> num;
	while(num != -999) {
            avl.insert(num);
            cin >> num;
    }
	/*avl.insert(30);
	avl.insert(10);
	avl.insert(15);
	avl.insert(40);
	avl.insert(50);
	avl.insert(20);*/
	cout << endl << "Recorrido en inorder:  ";
	avl.inorderTraversal();
	cout << endl << "Ingrese un numero a eliminar " << endl;  cin >> num; avl.delet(num);
	//avl.delet(9);
	cout << endl << "Recorrido en inorder:  "; avl.inorderTraversal(); cout << endl;
}
//void print( int & x) {cout << x << " ";}


