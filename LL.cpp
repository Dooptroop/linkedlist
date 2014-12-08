#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <sstream>

#include <iostream>
    

using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int data;
        Node *next;
    };

// public member
public:
    int digits;
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
        digits=0;
    }

    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->data = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
        digits++;
    }

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(){
        Node *n = head;
        int ret = n->data;
                                   
        head = head->next;
        digits--;
        delete n;
        return ret;
    }


    void readValues(){
        Node *n = head;
        int count=0;
        cout << endl  << endl << endl;
        for(int i=0; i<=this->digits; i++){
            if(n != NULL){
                cout <<  n->data;
                count++;
                n = n->next;
            }
        }

        
    }
   void reverseList(){

    if(head == NULL) return; // check for empty list

    Node *p = NULL, *c = NULL, *n = NULL;
    c = head;
    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
   }
   
    
  
// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
};

static void addList(LinkedList one, LinkedList two, LinkedList RESULT){
        LinkedList tmp, tmp2;
        int val1,val2,rem=0;
        cout << endl << "start ADDLIST() digits: " << one.digits << endl;
        int j = one.digits;
        int k = two.digits;
        for(int i=0;i<j;i++){
            cout << i << " LOOP" << endl;
            val1 = one.popValue();
            //val2 = two.popValue();
        

            //
            // Case if no more digits in 2nd list.
            //
            if(i > k-1){
                val2 = 0;
            } else{
                val2 = two.popValue();
            }

            
            if( (val1+val2+rem) >= 10){
                
                rem = (val1+val2)%10;
                
                tmp.addValue(rem);

                cout << "Val1: " << val1 << " - Val2: " << val2 << " Rem: " << rem << " carry 1" << endl;

                rem = 1;

            } else{
                tmp.addValue(val1+val2+rem);
                rem = 0;
                cout << "Val1: " << val1 << " - Val2: " << val2 << " Rem: " << rem << endl;
            }

    }

   
   
 


     
}



int main() {
    LinkedList list;
    LinkedList list2;
    LinkedList RESULT;
    
    int num_chars, num2_chars;

    
  
    // read the numbers from the text
    ifstream myfile ("number.txt");
    char temp;// temp char for numbers
    cout << endl << myfile << endl;
    
    while (myfile.get(temp)) {
        list.addValue(atoi(&temp));
        num_chars++;
        // atoi to get the number relate to the char
    }
    
    // read the numbers from the text
    ifstream my2file ("number2.txt");
    char temp2;// temp char for numbers

    while (my2file.get(temp2)) {

        list2.addValue(atoi(&temp2));
        num2_chars++;
        // atoi to get the number relate to the char
    }

    //list.addByValue(list, List2);

//    cout << list.toString(num_chars) <<endl;
    cout << endl << "file 1 digita = " << list.digits << endl;
    cout << "file 2 digits = " << list2.digits << endl;

    list.readValues();


    //list2.readValues();

    addList(list, list2, RESULT);
    
    //print the output list to output.txt

    ofstream outFile; // Declare outstream file

    outFile.open("output.txt");
    if(outFile.fail()) // Check for creation and return error;
    {
        cout << endl << "Error opening \"output.txt\" for output.\n";

        return 1;
    }

   
    

   

    cout << endl << "This is the end" << endl;
    return 0;
}