    #include<iostream>
    using namespace std;

    class Node {
        public: 
            int data;
            Node *next;
            Node(int x)
            {
                this->data = x;
                this->next = NULL;
            }

    };
    void display (Node *node) 
    {
        while (node != NULL)
        {
            /* code */
            cout << node->data <<endl;
            node = node->next;
        }
        
    }

    int length( Node  *node){
        int lengthCounter = 0;

        while (node != NULL)
        {

            ++lengthCounter;
            node = node->next;
        }

        return lengthCounter;
        
    }
    
    int main () 
    {
        Node n1(5);
        Node n2 = Node(10);
        n1->next = &n2;
        Node *n3 = new Node(20);
        n2->next = n3;
        Node *head = &n1;
        display(head);

        cout << endl<<length(head)<<endl;

        return 0;
    }