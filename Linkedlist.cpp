#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		void replace_by_pos(Node* head, int data, int pos){
			Node* temp = new Node;
			int len = size_of_LL(head);
			if(pos>=len|pos<0){
				cout<<"Total Elements in the list is "<<len<<". Enter Valid position\n";
				return;
			}
			temp = head->next;
			for(int i=0;i<pos;i++)
				temp = temp->next;
			temp->data = data;			
		}
		void delete_by_pos(Node* head, int pos){
			int len = size_of_LL(head);
			if(pos>=len|pos<0){
				cout<<"Total Elements in the list is "<<len<<". Enter Valid position\n";
				return;
			}
			Node* temp = new Node;
			temp = head->next;
			//if(head->next==NULL){
//				cout<<"List has only Head"<<endl;
//				return;
//			}
			if(temp->next==NULL){				
				head->next = NULL;
				delete temp;
				return;
			}
			Node* prev_temp = new Node;
			prev_temp = head;
			for(int i=0;i<pos;i++){
				//cout<<"Conmm";
				if(i==pos-1)
					prev_temp = temp;
				temp = temp->next;				
			}
			prev_temp->next = temp->next;
			//cout<<"Before:  "<<temp->data<<" "<<temp->next<<endl;
			delete temp;
			//cout<<"After:  "<<temp->data<<" "<<temp->next<<endl;
		}
		void insert_begining(Node* head,int data){
			Node* new_node = new Node;
			new_node->data = data;
			new_node->next = head->next;
			head->next = new_node;
		}
		void insert_between(Node* head,int data,int pos){
			int len = size_of_LL(head);
			if(pos>len){
				cout<<"Total Elements in the list (N) is "<<len<<" Enter position less than N-1\n";
				return;
			}
			Node* new_node = new Node;
			new_node->data = data;
			new_node->next = NULL;
				
			if(head->next == NULL){
				head->next = new_node;
				return;
			}
			Node* temp = new Node;
			temp = head;
			for(int i=0;i<pos;i++){
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
		}
		void insert_tail(Node* head,int data){
			Node* new_node = new Node;
			new_node->data = data;
			new_node->next = NULL;
			
			Node* temp = new Node;
			temp->next = head->next;
			while(temp->next){
				temp = temp->next;
			}
			temp->next = new_node;
		}
		int size_of_LL(Node* head){
			 Node* temp = new Node;
			 temp->next = head->next;
			 int count =0;
			 while(temp->next){
			 	//cout<<temp->data<<endl<<endl;
			 	temp = temp->next;
			 	count++;
			 }
			 //cout<<count<<endl<<endl;
			 return count;
		}
		void print_node(Node* head){
			int len = size_of_LL(head);
			//cout<<len<<endl;
			Node* temp = new Node;
			temp->next = head->next;
			temp->data = head->data;
			if(len==0)
				cout<<"Node has only Head\n";
			temp = temp->next;
			for(int i=1;i<=len;i++){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

void test_fn(){
	Node* head = new Node;
	head->next = NULL;
	//head->data = 10;
	head->insert_begining(head,20);
	head->insert_tail(head,500);
	head->insert_begining(head,33);
	head->insert_between(head,87,0);
	cout<<"Before:"<<endl;
	head->print_node(head);
	cout<<"After:"<<endl;
	head->delete_by_pos(head,0);
	head->replace_by_pos(head,20,0);
	//head->delete_by_pos(head,2);
	head->print_node(head);
	//cout<<head->data;
}
int main(){
	test_fn();
	//cout<<sizeof(a);
	return 0;
}

