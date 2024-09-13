#include <iostream>

using namespace std;

struct Node
{
	Node* prev = nullptr;
	int val = NULL;
	Node* next = nullptr;
};

class DoubleLinkedList {
public:
	Node* head = new Node;
	Node* tail = head;

	unsigned int len = 0;

	DoubleLinkedList(int val) {
		if (val) { this->head->val = val; this->len++; }
	};

	int set_val(unsigned int idx, int val) {
		if (idx < 0 || idx > this->len) { return 1; }

		Node* tmp = this->head;
		for (unsigned int i = 0; i < idx; i++) {
			tmp = tmp->next;
		}

		tmp->val = val;
		return 0;
	};

	int add_val_at_front(int val) {
		Node* newnode = new Node;
		newnode->val = val;
		newnode->next = this->head;
		this->head->prev = newnode;
		this->head = newnode;

		this->len++;
		return 0;
	};

	int add_val(int val) {
		if (this->is_empty()) {
			this->head->val = val;
			this->len++;
			return 0;
		}

		Node* newnode = new Node;
		newnode->val = val;
		newnode->prev = this->tail;
		this->tail->next = newnode;
		this->tail = newnode;

		this->len++;
		return 0;
	};

	int add_val_at_any(unsigned int idx, int val) {
		if (idx == 0) { this->add_val_at_front(val); }
		else if (idx == this->len) { this->add_val(val); }

		if (idx < 0 || idx > this->len) { return 1; }

		Node* newnode = new Node;
		newnode->val = val;

		Node* tmp = this->head;

		for (unsigned int i = 0; i < idx; i++) {
			tmp = tmp->next;
		}

		tmp->prev->next = newnode;
		newnode->next = tmp;
		tmp->prev = newnode;

		this->len++;
		return 0;
	};

	void printlist() {

		if (this->is_empty()) {
			return;
		}
		else
		{
			Node* tmp = this->head;
			cout << tmp->val << " ";

			while (tmp->next != nullptr) {
				tmp = tmp->next;
				cout << tmp->val << " ";
			}
		}
		cout << endl;
	}

	int remove_node(unsigned int idx) {
		if (this->is_empty() || idx < 0 || idx >= this->len) { return 1; }

		if (idx == 0) {
			if (this->head->next == nullptr) {
				this->head->val = NULL;
				this->len--;
				return 0;
			}
			else {
				Node* tmp = this->head;
				this->head = this->head->next;
				this->head->prev = nullptr;
				this->len--;
				return 0;
			}
		}

		if (idx == this->len - 1) {
			this->tail = this->tail->prev;
			delete this->tail->next;
			this->tail->next = nullptr;
			this->len--;
			return 0;
		}
		
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		Node* tmp = this->head;

		for (unsigned int i = 0; i < idx; i++) {
			tmp = tmp->next;
			cout << 1;
		}
		cout << 2;
		tmp->prev->next = tmp->next;
		cout << 3;
		tmp->next->prev = tmp->prev;
		cout << 4;
		delete tmp;
		cout << "done";

		this->len--;
		return 0;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	int clear_list() {
		if (this->head->next != nullptr) {
			Node* tmp = this->head->next;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
				delete tmp->prev;
			}
		}

		this->head->val = NULL;
		this->head->next = nullptr;
		this->tail = head;
		this->len = 0;
		return 0;
	};

	unsigned int get_len() {
		return this->len;
	}

	bool is_empty() {
		return this->len == 0;
	}

	~DoubleLinkedList() {
		Node* tmp = this->head;

		while (tmp->next != nullptr) {
			tmp = tmp->next;
			delete tmp->prev;
		}

		delete tmp;
	};
};

int main() {
	DoubleLinkedList a = 3;
	//a.printlist();

	a.add_val(999);
	//a.printlist();

	a.add_val_at_front(111);
	a.add_val_at_front(222);
	//a.printlist();

	a.add_val_at_any(2, 42);
	a.printlist();
	//cout << "len: " << a.get_len() << endl;

	/*a.set_val(-1, 99997);
	a.printlist();
	cout << "len: " << a.get_len() << endl << endl;*/

	/*a.clear_list();
	cout << "len: " << a.get_len() << endl;

	a.add_val(42);
	a.printlist();
	cout << "len: " << a.get_len() << endl;*/
	a.remove_node(0);
	a.printlist();

	a.remove_node(a.get_len() - 1);
	a.printlist();
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//a.remove_node(1);
	//a.printlist();
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	return 0;
}