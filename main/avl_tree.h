#ifndef AVL_TREE_H
#define AVL_TREE_H

template <class T>
struct avl_tree
{
private:
	struct Node
	{
		T value;
		size_t size = 0;
		size_t depth = 0;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(T value, size_t size, size_t depth, Node* left, Node* right)
		{
			this->value = value;
			this->size = size;
			this->depth = depth;
			this->left = left;
			this->right = right;
		}
		
		~Node() = default;
	};

	Node* root = nullptr;

	size_t size(Node* v)
	{
		return (v == nullptr ? 0 : v->size);
	}

	size_t depth(Node* v)
	{
		return (v == nullptr ? 0 : v->depth);
	}

	template<class T>
	Node* make_node(Node* left, T value, Node* right)
	{
		if (left == nullptr)
		{
			return new Node(value, right->size + 1, right->depth + 1, nullptr, right);
		}
		else if (right == nullptr)
		{
			return new Node(value, left->size + 1, left->depth + 1, left, nullptr);
		}
		else
		{
			return new Node(value, left->size + right->size + 1, std::max(left->depth, right->depth) + 1, left, right);
		}
	}

	template <class T>
	Node* insert(T value, Node* v)
	{
		if (v == nullptr)
		{
			return new Node(value, 1, 1, nullptr, nullptr);
		}

		if (value < v->value)
		{
			v = make_node(insert(value, v->left), v->value, v->right);
		}
		else if (value > v->value)
		{
			v = make_node(v->left, v->value, insert(value, v->right));
		}
		else
		{
			return v;
		}

		if (depth(v->right) - depth(v->left) == 2 && depth(v->right->left) <= depth(v->right->right))
		{
			return left_rotate(v);
		}
		else if (depth(v->left) - depth(v->right) == 2 && depth(v->left->right) <= depth(v->left->left))
		{
			return right_rotate(v);
		}
		else if (depth(v->right) - depth(v->left) == 2 && depth(v->right->left) > depth(v->right->right))
		{
			v->right = right_rotate(v->right);
			return left_rotate(v);
		}
		else if (depth(v->left) - depth(v->right) == 2 && depth(v->left->right) > depth(v->left->left))
		{
			v->left = left_rotate(v->left);
			return right_rotate(v);
		}
		else
		{
			return v;
		}
	}
	
	template <class T>
	bool find(T value, Node* v)
	{
		if (v == nullptr)
		{
			return false;
		}

		if (value < v->value)
		{
			find(value, v->left);
		}
		else if (value > v->value)
		{
			find(value, v->right);
		}
		else
		{
			return true;
		}
	}

	void print(Node* v)
	{
		if (v != nullptr)
		{
			print(v->left);
			std::cout << v->value << ' ';
			print(v->right);
		}
	}

	Node* left_rotate(Node* v)
	{
		Node* b = v->right;
		Node* c = b->left;
		b->left = v;
		v->right = c;
		v->size = size(v->left) + size(v->right) + 1;
		v->depth = std::max(depth(v->left), depth(v->right)) + 1;
		b->size = size(b->left) + size(b->right) + 1;
		b->depth = std::max(depth(b->left), depth(b->right)) + 1;
		return b;
	}

	Node* right_rotate(Node* v)
	{
		Node* b = v->left;
		Node* c = b->right;
		b->right = v;
		v->left = c;
		v->size = size(v->left) + size(v->right) + 1;
		v->depth = std::max(depth(v->left), depth(v->right)) + 1;
		b->size = size(b->left) + size(b->right) + 1;
		b->depth = std::max(depth(b->left), depth(b->right)) + 1;

		return b;
	}

public:
	avl_tree()
	{
		root = nullptr;
	}

	~avl_tree() = default;

	size_t size()
	{
		return (root != nullptr ? root->size : 0);
	}

	size_t depth()
	{
		return (root != nullptr ? root->depth : 0);
	}

	template <class T>
	bool find(T value)
	{
		return find(value, root);
	}

	template <class T>
	void insert(T value)
	{
		root = insert(value, root);
	}

	void print()
	{
		if (root != nullptr)
		{
			print(root->left);
			std::cout << root->value << ' ';
			print(root->right);
		}
	}
};

#endif
