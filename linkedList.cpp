#include <iostream>
#include<cstdlib>

//value is the value that the node contains                                                                                    
//the nextNode pointer points should point to the next node                                                                    
struct node{
  int value;
  struct node* nextNode;
};

class linkedList{
public:

  linked_list(){
    head = NULL;
    tail = NULL;
    temp = NULL;
  }

  //creates a new node at the begining of the list                                                                             
  void creatFirstNode(int newValue){
    if(head == NULL){
      head->value = newValue;
      head->nextNode = NULL;
    }
    else{
      temp = new node;
      temp->value = newValue;
      temp->nextNode = head;
      head = temp;
      temp = NULL; //no need to delete anything, nothing nodes are deleted                                                     
      //so everything must stay in the heap                                                                                    
    }

  }

  //creates a new node at the end of the linked list                                                                           
  void createNode(int newValue){
    temp->data = newValue;
    temp->nextNode = NULL;
    if(head == NULL){ //list is empty                                                                                          
      head = temp;
      tail = temp; //with no elements, head and tail are the same node                                                         
      temp = NULL;
    }
    else{ //list is not empty                                                                                                  
      tail->nextNode = temp;
      tail = tail->nextNode;
    }
  }

  //deletes the first node                                                                                                     
  void delete_First_Node(){
    if(head == NULL){
      std::cout << "The list is empty already..." <<endl;
    }
    else{
      temp = head;
      head = head->nextNode;
      delete temp; //clears the previous head value from the heap                                                              
    }
  }

  void delete_Last_Node(){
    if(head == NULL){
      std::cout << "The list is empty already..." <<endl;
      
    }
    if(head->next == NULL){
      delete head; //clear from heap
      head = NULL;
      std::cout << "Your list is now empty" <<endl;
   
    }
    //if the list is bigger than or equal to 2, we must transverse the list
    else{
      temp = head;
      while(temp->next->next != null){
	temp = temp->next; //while there is another item, this runs
      }
      delete temp->next;
      temp->next = null;
    }
    return NULL;
  }
  
  int main(){
    linkedList a;
    a.createFirstNode(1);
    a.createNode(2);
    a.createNode(3);
    a.createNode(4);
    
  }

private:
  node* head;
  node* tail;
  node* temp;
}; //end of linkedList class.                                                                                                  
