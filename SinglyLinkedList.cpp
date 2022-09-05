#include<iostream> // my version, written by xiao yi lin
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node * next;

        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int key, int data){
            key = key;
            data = data;
            next =  NULL;
        }

};

class Single_Link_List{
    public:
        Node * head;

        Single_Link_List(){
            head = NULL;
        }

        void append(Node * n){
            if(head == NULL){
                head = n;
            }else{
                Node * temp;
                temp = head;
                while(temp != NULL){
                    if(temp->next != NULL){
                        
                        temp = temp->next;
                    }else{
                        temp->next = n;
                        break;
                    }
                }
            }
        }

        void insert_at_start(Node * n){
            if(head == NULL){
                head = n;
            }else{
                n->next = head;
                head = n;
            }
        }

        void insert_after(int key, Node * n){
            if(head == NULL){
                cout<<"Error, empty linked list, no node to insert after. "<<endl;
            }else{
                Node * temp = head;
                Node * temp2;
                while(temp!=NULL){
                    if(temp->key == key){
                        temp2 = temp->next;
                        temp->next = n;
                        n->next = temp2;
                        break;
                    }else{
                        temp = temp->next;
                    }
                }
                if(temp == NULL)
                    cout<<"Error, the node to insert after cannot be found"<<endl; // node with the unique key
                else 
                    cout<<"Node inserted. "<<endl;

            }
        }

        void deleleNodeByKey(int key){
            if(head == NULL){
                cout<<"Error, cannot delete because the linked list is empty "<<endl;
            }else if(head->key == key){
                head = head -> next;
            }else{
                Node * temp = head;
                Node * temp2 = head->next;
                Node * copy = NULL;
                while(temp2 != NULL){
                    if(temp2->key == key){
                        copy = temp2;
                        temp->next = temp2->next;
                        temp2->next = NULL;
                        temp2 = NULL;
                    }else{
                        temp = temp->next;
                        temp2 = temp2->next;
                    }
                }
                if(temp2 == NULL && copy != NULL){
                    cout<<"( " <<copy->key<<" , "<<copy->data<< " )"<< " deleted"<<endl;  // copy<<"
                }else if(temp2 == NULL && copy == NULL){
                    cout<<"ERROR, Unable to find the node with the unique key you specified, cannot delete"<<endl;
                }else if(temp2 == NULL){
                    cout<<"ERROR, Unable to find the node with the unique key you specified, cannot delete"<<endl;
                }else{
                    cout<<"why else would this be printed?"<<endl;
                }
            }

        }
        



        // void printList() {
        //     if (head == NULL) {
        //     cout << "No Nodes in Singly Linked List";
        //     } else {
        //     cout << endl << "Singly Linked List Values : ";
        //     Node * temp = head;

        //     while (temp != NULL) {
        //         cout << "(" << temp->key << "," << temp->data << ") --> ";
        //         temp = temp->next;
        //     }
        //     }

        // }

        void update(int key, int data){
            if(head == NULL){
                cout<<"ERROR, empty link list, nothing to update"<<endl;
                return;
            }

            if(head->key == key){
                head->data = data;
            }else if(head->key != key && head->next == NULL){
                cout<<"ERROR, cannot update because node to update cannot be found"<<endl;
            }else{
                Node * temp = head;
                while(temp != NULL){
                    if(temp->key != key){
                        temp = temp->next;
                    }else if(temp->key = key){
                        cout<<" oringal node  "<<"( "<<temp->key<<" , "<<temp->data<<" )"<<endl;
                        temp->data = data;
                        break;
                    }

                }
                if(temp == NULL)
                    cout<<"Error, cannot update, key not found "<<endl;
                else
                    cout<<"updated"<<endl;
            }
        }

        void print(){
            Node * temp = head;
            if(temp == NULL){
                cout<<"Error, cannot print, it is empty"<<endl;
                return;
            }
            while(temp != NULL){
                cout<<"("<<temp->key<<" , "<<temp->data<<" ) -->";
                temp = temp->next;
            }
        }
};

int main(){
//     Node * n1 = new Node();
//     //cout<<n1->key<<endl;
//     n1->key = 5;
//     n1->data = 119;

//     Node * n2 = new Node();
//     n2->key = 9;
//     n2->data = 119;
//     //cout<<n2->key<<",  "<<n2->data<<endl;

//     Node * n3 = new Node();
//     n3->key = 8;
//     n3->data = 119;
    
//     Node * n4 = new Node();
//     n4->key = 7;
//     n4->data = 119;
//    //cout<<n2->key<<",  "<<n2->data<<n3->key<<",  "<<n3->data<<n4->key<<",  "<<n4->data<<endl;

//     Single_Link_List l1;
//     l1.append(n2);
//     l1.append(n1);

//     l1.insert_at_start(n3);
//     l1.insert_after(9, n4);

//     l1.deleleNodeByKey(9);
//     l1.update(5, 555);

    
//     l1.print();

int option = -1;
int key;//features of node
int k; // for identification
int data; 
//Node * b1 = new Node();   // error cannot declare outside do while
Single_Link_List ll1;

do
{
    cout<<" \n\n choose an option by the number below: \n You must enter a number , no special character. "<<endl;
    cout<<"enter 0 to exit"<<endl;
    cout<<" 1. append"<<endl;
    cout<<" 2. insert at start"<<endl;
    cout<<" 3. insert node after "<<endl;
    cout<<" 4. delete node by key"<<endl;
    cout<<" 5. update"<<endl;
    cout<<" 6. print"<<endl;
    cout<<" 7. clear screen"<<endl;
    cin>>option;
    Node * b1 = new Node();

    switch(option){
        case 1:
            cout<<" 1. append"<<endl;
            cout<<"enter key : ";
            cin>>key;
            cout<<"enter data : ";
            cin>>data;
            b1->key = key;
            b1->data = data;
            ll1.append(b1);
            break;

        case 2:
            cout<<" 2. insert at start"<<endl;
            cout<<"enter key : ";
            cin>>key;  // cannot enter a non integer character , it must be a number
            cout<<"enter data : ";
            cin>>data;
            b1->key = key;
            b1->data = data;
            ll1.insert_at_start(b1);
            break;

        case 3:
            cout<<" 3. insert node after "<<endl;
            cout<<"Enter key for a new node : ";
            cin>>key;
            cout<<"Enter data for a new node : ";
            cin>>data;
            cout<<" Enter a key which identifies the node the insert after: ";
            cin>>k;
            b1->key = key;
            b1->data = data;
            ll1.insert_after(k, b1);
            break;

        case 4:
            cout<<" 4. delete node by key"<<endl;
            cout<<"enter a key which identify the node to delete: ";
            cin>>k;
            ll1.deleleNodeByKey(k);
            break;

        case 5:
            cout<<" 5. update"<<endl;
            cout<<"enter a key which identify the node you want to update: ";
            cin>>k;
            cout<<"enter the data to update: ";
            cin>>data;
            ll1.update(k, data);
            break;

        case 6:
            cout<<" 6. print"<<endl;
            ll1.print();
            break;

        case 7:
            cout<<" 7. clear screen"<<endl;
            //system('cls');
            system("CLS");
            break;
        
        default:
            cout<<"enter a proper option number "<<endl;
    }

} while(option != 0);  // 0 and any non integer character would terminate the loop, cuz option int type or main() method int

    return 0;
}





/* 
        // void append(Node * n){
        //     if(head == NULL){
        //         head = n;
        //     }else{
        //         Node * temp;
        //         temp = head;
        //         while(temp != NULL){
        //             if(temp->next == NULL){
        //                 temp->next = n;
        //             }else{
        //                 temp = temp->next;
        //             }
        //         }
        //     }
        //}
//////////////////////////////// */