#include <cstdio>

template <class T>	class BSTree;

template <class T>
class Node {
	friend class BSTree<T>;
public:
	Node() {}
	Node(int k, T d) {
		key = k;
		data = d;
	}
private:
	int key;
	T data;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
};

template<class T>
class BSTree {
public:
	BSTree() {};
	BSTree(int k, T d) {
		root = new Node<T>(k, d);
		count = 1;
	}
	int NumberOfNode() {
		return count;
	}
	bool IsEmpty() {
		return !count;
	}
	T Get(int k) {
		return Get(root, k)->data;
	}
	Node<T>* Get(Node<T>* p, int k) {
		if (!p) return NULL;

		//순환적 탐색
		if (p->key == k) return p;
		if (k < p->key) return Get(p->left, k);
		if (k > p->key) return Get(p->right, k);

		//루프 탐색
		/*while (p) {
			if (p->key == k) return p->data;
			if (k < p->key) p = p->left;
			else if (k > p->key) p = p->right;
		}*/
	}

	void Insert(int k, T d) {
		Node<T>* curr = root; 
		Node<T>* prev = curr;
		while (curr) {
			prev = curr;
			if (k < curr->key) curr = curr->left;
			else if (k > curr->key) curr = curr->right;
			else {
				curr->data = d;
				return;
			}
		}
		if (root) {
			curr = new Node<T>(k, d);
			if (prev->key > k) prev->left = curr;
			else if (prev->key < k)prev->right = curr;
			curr->parent = prev;
		}
		else {
			root = curr;
		}
		count++;
	}

	void Delete(int k) {
		Node<T>* p = Get(root, k);
		if (p) {
			if (!p->left && !p->right) {
				p = NULL;
			}
			else if (p->left && p->right) {
				p->key = p->right->key;
				p->data = p->right->data;
				Delete(p->right);
			}
			else {
				if (p->left) p = p->left;
				else if (p->right)	p = p->right;
			}
		}
		else {
			p->parent = NULL;
		}
	}

	//전위순회
	void PreOrder()const {
		;
		Node<T>* s = new Node<T>[count];
		int top = 0;
		Node<T>* curr = root;
		while (1) {
			while (curr) {
				s[top++] = *curr;
				printf("%c ", curr->data);
				curr = curr->left;
			}
			curr = s[--top].right;
			if (top < 0) return;
		}
	}

private :
	Node<T>* root;
	int capacity;
	int count;
};