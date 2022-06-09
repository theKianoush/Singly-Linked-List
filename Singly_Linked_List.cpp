#include<iostream>
#include<string>
using namespace std;







// this is to create each element, or node
struct Node {
     int Data;          // the value contained in the node
     Node* Next;         // pointer, pointing to the next node

};


class LinkedList {       // data structure contained in a class
private:
     Node* head;

public:

     LinkedList() { // default constuctor 
          head = NULL;
     }



     void print() {
          Node* temp = head; // create temporary node, set it equal to head, head node is NULL by default, so if there are no other nodes, the head node will be null, and if it is NULL jump to else statment 
          if (temp != NULL) {
               cout << "This linked list contains: " << endl;
               while (temp != NULL) {
                    cout << temp->Data << "  ";          // print the nodes data
                    temp = temp->Next;                   // move to the next node
               }
               cout << endl;

          }
          else {
               cout << "This Linked List is empty." << endl;
          }

     }    // what difference between display/print and read


     void insertAtTheFront(int newData) {
          // 1. create a new node, which point to empty new Node()
          Node* newnode = new Node();
          newnode->Data = newData;      // the data for this new node will be equal to the input
          // 2. link the new node with the head node, new node goes in front, the next node will be the head
          newnode->Next = head;
          // 3. now switch positions, the new node, becomes the head node... so the new node is the head node now 
          head = newnode; // head node is equal to this new node we just created
     }


     void insertAtTheEnd(int newData) {
          // 1. create a new node
          Node* newnode = new Node(); // allocate new node 
          newnode->Data = newData;   // assign input as data for new node
          newnode->Next = NULL;    // last node points to NULL

          // 2. if linked list is empty, this new node will be head node 
          if (head == NULL) {
               head = newnode;
               return;
          }
          // 3. find the last node 
          else {
               Node* last = head;
               while (last->Next != NULL) {
                    last = last->Next; // move to next node
               }
               // 4. insert new node after last node (at the end)... change the next of the last node to new node
               last->Next = newnode;
          }





     }

   
     void insertAtIndex(int newData, int position) {

          //1. prepare new node 
          Node* newnode = new Node();
          newnode->Data = newData;
          newnode->Next = NULL;

          //2. check if position is > 0 
          if (position < 1) { // position cant be less than 1
               cout << "position should be greater than or equal to 1" << endl<< endl;
          }
          else if (position == 1) {
               // if the postion is 1, this is the first spot, so its pretty much excat same as insertAtTheFront 
               newnode->Next = head;
               head = newnode;
          }
          else {
               Node* temp = head;  // create temporay node set it equal to head 
               for (int i = 1; i < position - 1; i++) {     // we use our input for, the for loop count 
                    if (temp != NULL) { // if the temporary node is not NULL
                         temp = temp->Next;  // move to the next node
                    }
               }

          // if temp node is still not NULL after traversal, make newNode next as temp next and temp next as newNode.
               if (temp != NULL) {
                    newnode->Next = temp->Next;
                    temp->Next = newnode;
          }
               else { // once the temp node hits NULL 
                    cout << "You cannot enter " << newData << " into position " << position << endl;
                    cout << "Because the previous node is null, please enter a valid position."<<endl<< endl;    // so it has nothing to link to
               }
         


          }

     }

     
     void deleteAtTheFront() {
          if (head != NULL) {
               // how this works: 
               // temp points to the first node
               // head points to the second node
               // then we delete temp which deletes first node

               Node* temp = head;  //this is a temporay node it is a copy of Node* head

               head = head->Next; // what i dont understand is that if we delete head node, wouldnt that delte this as well?

               delete temp;    // delete temp node
          }
     }

     void deleteAtTheEnd() {
          if (head != NULL) {


               if (head->Next == NULL) { // if there is one elemenet, aka the head element, that means its next will point to NULL
                    head = NULL; // just make the whole head null, so it dont exist
               }


               else {

                    //  traverse to second to last element of list
                    Node* temp = head;
                    while (temp->Next->Next != NULL)// we want seocnd to last node of the list
                         temp = temp->Next;         // this iterates each time so we get there                


                    // at this point temp node is holding second to last data, and pointing to last node
                    // we want to change temp->next to null instead of pointing to last node
                    Node* lastNode = temp->Next;  // create copy of lastnode 
                    temp->Next = NULL;            // make second to last node the last node
                    delete lastNode;               // delete the last node, or the copy of it

                    // could just do
                    // temp->Next = NULL;   like the above function we could just do head = head->next;
                    // but we do the extra steps to acutally delete the node isntead of just ignoring it
               }
          }
     }

     void deleteAtIndex(int position) {
          if (position < 1) { // position cant be less than 1
               cout << "position should be greater than or equal to 1" << endl << endl;
          }
          else if (position == 1 && head != NULL) { //if first position and head is not null, we want to make the next node head and delete the first position
               Node* NodetoDelete = head;
               head = head->Next;
               delete NodetoDelete;
          }
          else {
               Node* temp = head;
               for (int i = 1; i < position - 1; i++) {     // iterate to 1 node previous to position
                    if (temp != NULL) {
                         temp = temp->Next; // itereate to next only while node is not NULL
                    }
               }

               // now we should be in correct position aka the node behind the one we want to delete
               if (temp != NULL && temp->Next != NULL) {   //if the node behind is not null and the one we want to delete is not null as well
                    Node* nodeToDelete = temp->Next;
                    temp->Next = temp->Next->Next;     // point to the next node, disrgard the one we are on
                    delete nodeToDelete;

               }
               else {
                    cout << "Cannot delete position " <<position<< " becuase the node is already NULL" << endl<<endl;
               }

          }

     }


     void SearchElement(int searchValue) {

          // create a temp node pointing to head
          Node* temp = head;

          int found = 0;
          

          if (temp != NULL) {
               while (temp != NULL) {

                    if (temp->Data == searchValue) {
                         found++;
                         break;
                    }
                    temp = temp->Next;
               }
               if (found == 1) {
                    cout << searchValue << " is found in the List.\n";
               }
               else {
                    cout << searchValue << " is not found in the list.\n";
               }
          }
          else {
 
               //   the list is empty
               
          }
     }


     void sort() {  // bubble sort, i did not write this in any capacity and i dont know what is going on

          if (head != NULL) {

               struct Node* current = NULL;
               int status = 0;
               do {
                    current = head;
                    status = 0;
                    while (current != NULL && current->Next != NULL) {

                         if (current->Data > current->Next->Data) {
                              //Swap node values
                              status = 1;
                              current->Data = current->Data + current->Next->Data;

                              current->Next->Data = current->Data - current->Next->Data;

                              current->Data = current->Data - current->Next->Data;
                         }
                         current = current->Next;
                    }

               } while (status == 1);

          }
          else {
               
          }
     }

     void reverse() {
          //1. If head is not null create three nodes
//   prevNode - pointing to head,
//   tempNode - pointing to head,
//   curNode - pointing to next of head
          if (head != NULL) {
               Node* prevNode = head;
               Node* tempNode = head;
               Node* curNode = head->Next;

               //2. assign next of prevNode as null to make the
               //   first node as last node of the reversed list
               prevNode->Next = NULL;

               while (curNode != NULL) {
                    //3. While the curNode is not null adjust links 
                    //   (unlink curNode and link it to the reversed list 
                    //   from front and modify curNode and prevNode) 
                    tempNode = curNode->Next;
                    curNode->Next = prevNode;
                    prevNode = curNode;
                    curNode = tempNode;
               }

               //4. Make prevNode (last node) as head
               head = prevNode;
          }
     }



};




int main()
{



     LinkedList one;          // first linked list (object/data structure) created
     one.insertAtTheEnd(5);
     one.insertAtTheFront(3); 
     one.insertAtTheFront(8);
     one.insertAtTheFront(9);
     one.insertAtTheEnd(2);

     one.sort();
    
     one.print();





     return 0;
}



//------------------------------------------------------------------------------------------------------------

// int* myArray = new int[40]; //allcoates an array of size 40 bytes and my array points to this

//Node* head = new Node();           //creating Node object called, head, because this is the head node       // so this tells the moemry we want space for a node, so later we can link the head node to the new Node()
//Node* secondElement = new Node();   // creating the second node after the head node
//Node* thirdElement = new Node();  // third element 


//// initalizing values for nodes
//head->Data = 11;    // i think since it is pointers we use -> instead of .
//secondElement->Data = 22;
//thirdElement->Data = 33;

////linking nodes
//head->Next = secondElement;
//secondElement->Next = thirdElement;
//thirdElement->Next = NULL;

//------------------------------------------------------------------------------------------------------------








