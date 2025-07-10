struct node {
	int data;
	node* p_next, *p_prev;
}

void insert_at_beginning(int k, node* &head) {
	if (head == NULL) {
		head = new node;
		head->data = k;
		head->p_next = head->p_prev = NULL;
	}
	else {
		node* tmp = new node;
		tmp->data = k;
		tmp->p_next = head;
		head->p_prev = tmp;
		tmp->p_prev = NULL;
		head = tmp;
	}
}