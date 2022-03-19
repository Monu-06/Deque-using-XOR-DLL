#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

struct Node
{
    int data;
    struct Node *add;
};
Node *head = NULL, *tail = NULL;
int sz = 0;

Node *createNode(int d)
{
    Node *new_node = (Node *)malloc(sizeof(Node *));
    new_node->data = d;
    new_node->add = NULL;
    sz++;
    return new_node;
}

Node *XOR(Node *a, Node *b)
{
    return reinterpret_cast<Node *>(
        reinterpret_cast<uintptr_t>(a) ^
        reinterpret_cast<uintptr_t>(b));
}

void push_front(int k)
{

    Node *new_node = createNode(k);
    new_node->add = head;

    if (head == NULL)
        tail = new_node;

    else if (head != NULL)
    {
        head->add = XOR(new_node, head->add);
    }
    head = new_node;
}

void push_back(int k)
{

    Node *new_node = createNode(k);
    new_node->add = tail;

    if (tail == NULL)
        head = new_node;
    else if (tail != NULL)
    {
        tail->add = XOR(new_node, tail->add);
    }

    tail = new_node;
}

void pop_back()
{
    if(sz==0)
        cout<<"List is Empty!";
    else
    {
    Node *curr = tail;
    if (tail == NULL)
        return;

    tail = tail->add;
    if (tail == NULL)
    {
        free(curr);
        head = NULL;
        sz--;
        return;
    }

    tail->add = XOR(tail->add, curr);
    free(curr);
    sz--;
    return;
  }
}

void pop_front()
{
    if(sz==0)
       cout<<"List is Empty!";
    else
    {
    Node *curr = head;
    if (head == NULL)
        return;

    head = head->add;
    if (head == NULL)
    {
        free(curr);
        tail = NULL;
        sz--;
        return;
    }
    head->add = XOR(curr, head->add);
    free(curr);
    sz--;
    return;
   }
}

void printDeque()
{
    if(sz==0)
        cout<<"List is empty!";
    else
    {
    Node *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        Node *t = curr;
        curr = XOR(curr->add, prev);
        prev = t;
    }
    }
}

int size()
{
    return sz;
}

bool isEmpty()
{
    if(sz==0)
     return true;
    return false;
}

void front()
{
    if (head != NULL)
        cout<<"Front Element: "<<head->data<<"\n";
        else
    cout<<"List is Empty!\n" ;
}

void back()
{
    if (tail != NULL)
        cout<<"Back Element: "<<tail->data<<"\n";
        else
    cout<<"List is Empty!\n";
}

void front_Next()
{
    if (head != NULL && head->add != NULL)
        cout<<"Front Next: "<<head->add->data<<"\n";

      else if(head==NULL)
       cout<<"list is Empty!"<<"\n";
    else
        cout<<"list has 1 element"<<"\n";

}

void second_Last()
{
    if (tail != NULL && tail->add != NULL)
        cout<<"Second Last: "<<tail->add->data<<"\n";
       else if(head==NULL )
        cout<<"list is empty!"<<"\n";

      else
      cout<<"list has 1 element"<<"\n";


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int ch,k;
// "1.push front \n 2.push back \n 3.pop front\n 4.pop back\n 5.size \n6.print deque\n7.front\n8.back\n 9.front next\n10.Second last ";
  while(1)
 {
     //ch determines choice
  while(cin>>ch)
  {
    switch(ch)
    {
    	case 1:
        //"Enter data";
    	   cin>>k;
    	  push_front(k);
    	 break;
    	case 2:
    	 //"Enter data";
    	   cin>>k;
    	  push_back(k);
    	  break;
    	case 3:
    	  pop_front();
    	  break;
    	case 4:
    	  pop_back();
    	  break;
    	case 5:
    	    size();
    	    cout <<"Size: "<< size() << "\n";
    	   break;
    	case 6:

    	    if(isEmpty())
                cout<<"List is Empty!\n";
            else
                cout<<"List is not Empty!\n";
    	   break;
    	case 7:
    	   front();
    	   break;
    	case 8:
    	  back();
    	  break;
    	case 9:
    	  front_Next();
    	  break;
    	case 10:
    	  second_Last();
    	  break;
    	default:
    	   exit(0);
       }
    }
  }

}
