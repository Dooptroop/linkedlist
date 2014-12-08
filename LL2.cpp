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

    bool isEmpty(){
        Node *n = head;
        if(n->next==NULL){return true;}
        else{return false;}
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
    int readNode(int x){
        Node *n = head;
        int i;
        if (i==0){
            int ret = n->data;
            delete n;
            return ret;
        } else {
            for (i = 0; i <= x; i++)
            {

               if(i==x){
                int ret = n->data;
                delete n;
                return ret;
               } else {
                n = n->next;
               }
            }
        }
        int ret = n->data;
        delete n;
        return ret;
       
      
    }
    void readValues(){
        Node* n = head;
        int count = 0;
        cout << endl;
        for (int i = 0; i <= this->digits; i++){
            if(n != NULL){
                cout << "node[" << count << "]" << " Data: "<< n->data << endl;
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

static LinkedList addList(LinkedList one, LinkedList two, LinkedList RESULT){
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
                
                RESULT.addValue(rem);

                cout << "Val1: " << val1 << " - Val2: " << val2 << " Rem: " << rem << " carry 1" << endl;

                rem = 1;

            } else{
                RESULT.addValue(val1+val2+rem);
                rem = 0;
                cout << "Val1: " << val1 << " - Val2: " << val2 << " Rem: " << rem << endl;
            }
       
    }

 return RESULT;
}
static LinkedList multiply(LinkedList one, LinkedList two, LinkedList RESULT){
     LinkedList tmp, tmp2, res;
     int val1,val2,hold,rem=0;
     int a = one.digits;
     int b = two.digits;
     int i, j, tI; // counters

        
        for(i=0; i<b; i++){
            val1 = two.readNode(i);

            for(j=0; j<a; j++){
                hold = one.readNode(j);

                if(val1*hold+rem > 9){
                    sum=(val1*hold+rem);
                    if(tI==0){tmp.addValue(sum%10);}
                    else{tmp2.addValue(sum%10);}
                    rem=(sum/10);

                } else {
                    sum=(val1*hold+rem);
                    if(tI==0){tmp.addValue(sum);}
                    else{tmp2.addValue(sum);}
                }
            }
            if(tI=1){
                if(res.isEmpty()){
                    res = addList(tmp,tmp2,RESULT);
                } else {
                    RESULT = addList(tmp,tm2,RESULT);
                    RESULT = addList(res, RESULT, RESULT);
                    res->next=NULL;
                }
                
                tI=0;
            }
            tI++;

            
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

   


    cout << endl << "file 1 digita = " << list.digits << endl;
    cout << "file 2 digits = " << list2.digits << endl;

    

    list.readValues();
    list2.readValues();

    RESULT = addList(list, list2, RESULT);
    
    RESULT.readValues();
    int s = RESULT.readNode(1);

    cout << " read node :" << s << " ; ." << endl;
    //print the output list to output.txt
   

    cout << endl << "This is the end" << endl;
    return 0;
}






