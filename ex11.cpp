#include <iostream>
#include <limits>

using namespace std;

struct node 
{
    int data;
    node* next;

    node(int newdata) 
    {
        data = newdata;
        next = nullptr;
    }
};

node* reverseList(node* head) 
{
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while(curr!=nullptr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void zojofard(node* head, node*& fard, node*& zoj) 
{
    node* fardtail = nullptr;
    node* zojtail = nullptr;
    int index = 1;
    while(head!=nullptr) 
    {
        if(index%2!=0) 
        {
            if(fard==nullptr) 
            {
                fard = head;
                fardtail = fard;
            } 
            else 
            {
                fardtail->next = head;
                fardtail = fardtail->next;
            }
        } 
        else 
        {
            if(zoj==nullptr) 
            {
                zoj = head;
                zojtail = zoj;
            } 
            else 
            {
                zojtail->next = head;
                zojtail = zojtail->next;
            }
        }
        head = head->next;
        index++;
    }
    if(fardtail!=nullptr)
        fardtail->next = nullptr;
    if(zojtail!=nullptr)
        zojtail->next = nullptr;
}

node* tarkibList(node* fard, node* zoj) 
{
    if(fard==nullptr)
        return zoj;
    node* tail = fard;
    while(tail->next!=nullptr)
        tail = tail->next;
    tail->next = zoj;
    return fard;
}

void printList(node* head) 
{
    while(head!=nullptr) 
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() 
{
    int value;
    node* head = nullptr;
    node* count = nullptr;
    while(true) 
    {
        if(cin.peek()=='\n')
            break;
        cin >> value;
        if(!cin)
            break;
        if(head==nullptr) 
        {
            head = new node(value);
            count = head;
        } 
        else 
        {
            count->next = new node(value);
            count = count->next;
        }
    }
    node* fard = nullptr;
    node* zoj = nullptr;
    zojofard(head, fard, zoj);
    fard = reverseList(fard);
    head = tarkibList(fard, zoj);
    printList(head);
}