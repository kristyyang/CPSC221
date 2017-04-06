// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  curr = head;      
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next);   //why here the size of pointer need to +1, why not + 4 bytes?
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int> to_vector(Node* head) {
  std::vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    result.push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  if(head == NULL){
    return ;
  }
  if(head->next == NULL){
    delete head;
    head = NULL;
  }else{
    Node* pre = head;
    Node* curr = head->next;
    while( curr->next != NULL){
      pre = curr;
      curr = curr->next;
    }
    delete curr;
    pre->next =NULL;
  }
  // ******** WRITE YOUR CODE HERE ********

}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {
  if(!head) return ;
  if(!head->next){    // Only one element in the list
    if(head->key ==oldKey){
      delete(head);
      head=NULL; 
    }
    return ;
  }

  Node* curr = head;
  if(curr->key == oldKey){
    head = curr->next;
    delete(curr);
    return ;
  }

  while(!curr->next &&curr->key != oldKey){
    curr = curr-> next;
  }
  if(!curr->next) return ;
  Node* temp= new Node;
  temp = curr->next;
  curr->next = temp->next;
  delete(temp);

}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  if(!head) return ;

  Node* curr = head;
  
  while(!curr->next && curr->key != oldKey)  
    curr = curr->next;
  if(curr->key == oldKey){
    Node* temp = new Node;
    temp->key = newKey;
    temp->next = curr->next;
    curr->next = temp;
    
  // ******** WRITE YOUR CODE HERE ********
  }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  Node* head = NULL;
  Node* curr = head;

  while(list1 && list2){
    Node* n1 = new Node;
    Node* n2 = new Node;
    n1 -> key = list1->key;
    n2 -> key = list2->key;
    n1 -> next= n2;
    n2 -> next= NULL;

    if(!head){
      head = n1;
    }else{
      curr -> next = n1;
    }
    curr = n2;
    list1 = list1 -> next;
    list2 = list2 -> next;
  }

   while(list2){
    Node* n3 = new Node;
    n3 -> key = list2 ->key;
    n3 -> next = NULL;

    if(!head){
      head = n3;
      curr = head;   // i was using curr = n3;
    } else{
      curr -> next = n3;
      curr = curr->next;   // try curr = n3;
    }
    list2 = list2 -> next;
   }

   while(list1){
    Node* n4 = new Node;
    n4 -> key = list1 -> key;
    n4 -> next = NULL;

    if(!head){
      head = n4;
      curr = head;
    }else{
      curr -> next = n4;
      curr = curr ->next;
    }
    list1 = list1 -> next;
   }
   return head; 

  // ******** WRITE YOUR CODE HERE ********
   // ******** DELETE THIS LINE ********
}

Node* interleave(Node* list1, Node* list2){
/*
  if(!list1) return list2;
  if(!list2) return list1;
*/
  if (list1 && list2){
     Node* n1 = new Node;
     Node* n2 = new Node;
     n1->key = list1 -> key;
     n2->key = list2 -> key;
     n1->next = n2;
     n2-> next =interleave(list1->next,list2->next);
     return n1;
   }

   if(list1){
    Node* n3 = new Node;
    n3->key = list1 ->key;
    n3->next =interleave(list1->next, NULL);
    return n2;
   }

   if(list2){
    Node* n4 = new Node;
    n4->key = list2 ->key;
    n4->next =interleave(NULL, list2->next);
    return n4;
   }

}

















