#include <bits/stdc++.h>

using namespace std;

namespace dtree{
	class Node{
		const int INF=2e9;
		inline void passtodo(){
			this->r_child->val += this->todo;
			this->l_child->val += this->todo;
			this->r_child->todo += this->todo;
			this->l_child->todo += this->todo;
			this->todo = 0;
		}
		public:
			int l_it;
			int r_it;
			Node* l_child;
			Node* r_child;
			int val=0;
			int todo=0;
			bool bisected = false;
			bool last(){
				return l_it==r_it;
			}
			~Node(){
				if(this->bisected){
					delete this->l_child;
					delete this->r_child;
				}
			}
			void bisectNode(){
				//cerr << "\nDEBUG\t bisected node <"<<this->l_it<<","<<this->r_it<<">"; 
				if(!this->bisected){
					
					this->l_child = new Node();
					this->r_child = new Node();
					
					int middle=(this->l_it+this->r_it)/2;
					this->l_child->l_it = this->l_it;
					this->l_child->r_it = middle;
					this->r_child->l_it = middle+1;
					this->r_child->r_it = this->r_it;
					
					this->passtodo();
					
					l_child->bisected = l_child->last();
					r_child->bisected = r_child->last();
					this->bisected=true;
				}
			}
			void set(int &node, int &value){
				if(node>=this->l_it and node<=this->r_it){
					if(this->last()){
						this->val=value;
						this->todo=0;
					}else{
						this->bisectNode();
						this->passtodo();
						
						this->l_child->set(node, value);
						this->r_child->set(node, value);
						
						this->val = min(this->l_child->val, this->r_child->val);
					}
				}
			}
			int ask(int &left, int &right){
				if(this->r_it<left or this->l_it>right){
					//cerr << "\nDEBUG\t asking for interval OUT of search bounds <"<<this->l_it << "," << this->r_it << ">";
					return INF;   
				}
				if(this->r_it<=right and this->l_it>=left){
					//cerr << "\nDEBUG\t asking for interval INSIDE search bounds <"<<this->l_it << "," << this->r_it << ">";
					return this->val;
				}
				if(this->bisected){
					//cerr << "\nDEBUG\t asking for interval children @ <"<<this->l_it << "," << this->r_it << ">";
					this->passtodo();
					return min(this->l_child->ask(left,right),
						       this->r_child->ask(left,right));
				}
				//cerr << "\nDEBUG\t no children to ask for @ <"<<this->l_it << "," << this->r_it << ">";
				return this->val;
			}
			void add(int &left, int &right, int &value){
				if(this->r_it<left or this->l_it>right){
					//cerr << "\nDEBUG\t adding at interval OUT of query bounds <"<<this->l_it << "," << this->r_it << ">";
					return;  
				}
				if(this->r_it<=right and this->l_it>=left){
					//cerr << "\nDEBUG\t adding at interval INSIDE query bounds <"<<this->l_it << "," << this->r_it << ">";
					this->val+=value;
					this->todo+=value;
					return;
				}
				this->bisectNode();
				this->passtodo();
				this->l_child->add(left,right,value);
				this->r_child->add(left,right,value);
				this->val = min(this->l_child->val, this->r_child->val);
			}
			
	};
	class Tree{
		Node root;
		
		public:
			Tree(int left, int right){
				this->root.l_it=left;
				this->root.r_it=right;
				//this->root.val=0;
				//this->root.todo=0;
			}
			inline int ask(int left, int right){
				//cerr << "\nDEBUG\t searching at interval <" << left << "," << right << ">";
				return this->root.ask(left, right);
			}
			inline void set(int node, int value){
				//cerr << "\nDEBUG\t seting value " << value << " @ " << node <<".";
				this->root.set(node,value);
			}
			inline void add(int left, int right, int value){
				//cerr << "\nDEBUG\t adding "<<value<<" at interval <" << left << "," << right << ">";
				this->root.add(left,right,value);
			}
			
	};
}

int main(){
	dtree::Tree tree(0,1000000);
	/*for(int i=0;i<=1000000;i++){
		tree.set(i,i);
	}*/
	cout << "Type ? to show available commands\n";
		while(true){
		char command;
		cout << "\n  command> ";
		cin >> command;
		switch(command){
			int left,right,node,val;
			case '?':
				cout << "\nHelp:\n\n\
q                    Quits program\n\
s  node,value        SETs value at node\n\
u  left,right,value  UPDates value to all nodes in <left,right>\n\
a  left,right        ASKs for min at <left,right>\n\
?                    Shows this help\n";
				break;
			case 'q':
				cout << " Exiting";
				return 0;
			case 's':
				cout << " SET node> ";
				cin >> node;
				cout << "  SET val> ";
				cin >> val;
				tree.set(node,val);
				break;
			case 'a':
				cout << " ASK left> ";
				cin >> left;
				cout << "ASK right> ";
				cin >> right;
				cout << "ANSWER: " << tree.ask(left,right) << "\n";
				break;
			case 'u':
				cout << " UPD left> ";
				cin >> left;
				cout << "UPD right> ";
				cin >> right;
				cout << "UPD value> ";
				cin >> val;
				tree.add(left,right,val);
				break;
			case 0:
				return 0;
			default:
				cout << "Unknown command: " << command << ". Type ? to show available commands\n";
				break;
				
		}
	}
}
