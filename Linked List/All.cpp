

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

class Node
{
public:
	int data;
	Node* next;

	Node(int d){
		data=d;
		next=NULL;
	}	
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

Node* insertAtHead(Node* &head, int d)
{    
	Node *temp=new Node(d);
	temp->next=head;
	head=temp;

}
void insertAtTail(Node* &tail, int d)
{    
	Node *temp=new Node(d);
	tail->next=temp;
	tail=temp;

}
void insertAtPosition(Node* &head,Node* &tail, int pos,int d)
{    
	int cnt=1;
	Node* temp=head;
	if(pos==1){
		insertAtHead(head,d);
		return;
	}
	while(cnt<pos-1){
          temp=temp->next;
          cnt++;
	}
	if(temp->next==NULL){
		insertAtTail(tail,d);
		return;
	}
   Node* t=new Node(d);
   t->next=temp->next;
   temp->next=t;

}
void deletehead(Node* &head){
     Node * temp=head;
     head=head->next;
     delete(temp);
}
void deleteatany(Node* &head,int pos, Node* &tail){
	int cnt=1;
	   Node * temp=head;
	while(cnt<pos-1){
       cnt++;
       temp=temp->next;
	}

     Node * t=temp->next;
     if(!t->next)tail=temp;
     temp->next=temp->next->next;

     //t->next=NULL;
     delete(t);
}
void reverseiterative(Node* &head){

	Node * cur=head;
	Node * prev=NULL;
	Node * fwd=NULL;

	while(cur){

		fwd=cur->next;
		cur->next=prev;
		prev=cur;
		cur=fwd;
	}
	head=prev;

}
void rec_reverse(Node* &head, Node* cur, Node* prev){

	if(cur==NULL){
		head=prev;
		return;
	}

		Node* fwd=cur->next;
		rec_reverse(head,fwd,cur);
		cur->next=prev;

}
int getMiddle(Node *head)
    {
        // Your code here
        Node* fast=head;
          Node* slow=head;
          while(fast != NULL and fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
void solve() {
	// int d,e,f;
	// cin>>d>>e>>f;
	Node* head=new Node(1);
	//cout<<head->data;
	Node* tail=head;

	insertAtHead(head,0);
	insertAtTail(tail,2);
	insertAtTail(tail,4);
	insertAtPosition(head,tail,1,3);
	insertAtPosition(head,tail,6,10);
	insertAtHead(head,11); 
	deleteatany(head,7,tail);
	//deletehead(head);
	printList(head);cout<<endl;
	Node * cur=head;
	Node * prev=NULL;
	
	rec_reverse(head,cur,prev);
	//reverseiterative(head);
	printList(head);cout<<endl;
	cout<<getMiddle(head);
	//cout<<head->data<<" "<<tail->data;
	// int n, m;
	// cin >> n >> m;
	//bug(n, m);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
	// cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}
