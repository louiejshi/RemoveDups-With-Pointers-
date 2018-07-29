// Remove duplicates without buffer (Using pointers)
//
//  main.cpp
//  RemoveDups2
//
//  Created by Louie Shi on 7/27/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

void removeDups(ListNode* ln)
{
    ListNode* p;
    ListNode* q;
    
    for(p = ln; p; p=p->getNext())
    {
        for(q = p->getNext(); q; q=q->getNext())
        {
            if(p->getData() == q->getData())
            {
                if(q->getNext() != NULL)
                {
                    q->getPrev()->next = q->getNext();
                    q->getNext()->prev = q->getPrev();
                }
                else
                {
                    q->getPrev()->next = NULL;
                }
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    LinkedList* l1 = new LinkedList();
    
    ListNode* ln1 = new ListNode(1);
    ListNode* ln1A = new ListNode(1);
    ListNode* ln1B = new ListNode(1);
    ListNode* ln2 = new ListNode(2);
    ListNode* ln3 = new ListNode(3);
    ListNode* ln4 = new ListNode(4);
    ListNode* ln5 = new ListNode(5);
    ListNode* ln6 = new ListNode(6);
    
    l1->insertEnd(ln5);
    l1->insertEnd(ln1A);
    l1->insertEnd(ln2);
    l1->insertEnd(ln3);
    l1->insertEnd(ln1);
    l1->insertEnd(ln4);
    l1->insertEnd(ln6);
    l1->insertEnd(ln1B);
    
    l1->print();
    cout << endl;
    
    removeDups(l1->head);
    
    l1->print();
    cout << endl;
    
    return 0;
}
