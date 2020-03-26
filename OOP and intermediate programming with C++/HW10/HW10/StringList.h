//
//  StringList.h
//  HW10
//
//  Created by Arvind Kumar on 3/10/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#ifndef StringList_h
#define StringList_h
#include <iostream>
#include <string>
using namespace std;

class StringList
{
private:
    struct ListNode
    {
        string firstName;
        string lastName;
        struct ListNode *next;
    };
    
    ListNode *head;
public:
    //Constructor
    StringList()
    {
        head = nullptr;
    }
    
    //Destructor
    ~StringList()
    {
        ListNode* cur = head;
        ListNode* prev;
        while(cur != nullptr)
        {
            prev = cur;
            cur = cur->next;
            prev->next = nullptr;
            delete prev;
        }
    }
    
    void insertNode(string, string);
    void displayList();
};
#endif /* StringList_h */

/*
 PRE- fname- first name string
    - lname- last name string
 POST- none
 PURPOSE- inserts the values to a node then that node to a new list
 */
void StringList::insertNode(string fname, string lname)
{
    //create a newnode
    ListNode *newNode = new ListNode;
    //populate it's values with fname, lname, and set next to nullptr
    newNode->firstName = fname;
    newNode->lastName = lname;
    newNode->next = nullptr;
    //create a current node pointer to head
    ListNode *cur = head;
    //create a previous node pointer to head
    ListNode *prev = head;
    
    //check if there are any elements in the list first
    if(head == nullptr)
    {
        //if not set the new node to the head, or the first node
        head = newNode;
    }
    else
    {
        //otherwise, while the cur node exists,
        while(cur != nullptr)
        {
            //compare last names
            if(newNode->lastName < cur->lastName)
            {
                //if newnode last name is less than current node's place newnode before current
                newNode->next = cur;
                break;
            }
            //change previous node to current, and current to the next
            prev = cur;
            cur = cur->next;
        }
        //if cur is head, set head to the newnode
        if(cur == head)
        {
            head = newNode;
        }
        //otherwise, newnode comes after previous node.
        else
        {
            prev->next = newNode;
        }
        
    }
}

/*
 PRE- NONE
 POST- Prints out all the names in the list
 PURPOSE- display the entire linked list
 */
void StringList::displayList()
{
    //create a new pointer to the current node and set it as head
    ListNode *cur = head;
    //while cur exists
    while(cur != nullptr)
    {
        //print first and last name
        cout << cur->firstName << " " << cur->lastName << endl;
        //set cur to the next element in the list
        cur = cur->next;
    }
}
