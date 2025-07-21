class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }

    };
    Node* head=new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    int cap;
    unordered_map<int,Node *> um;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* node){
        Node * temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    void deleteNode(Node * node){
        Node * temp=node->prev;
        Node * temp2=node->next;
        temp->next=temp2;
        temp2->prev=temp;
    }
    
    int get(int key) {
        if(um.find(key)==um.end())
            return -1;
        Node *node=um[key];
        deleteNode(node);
        addNode(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(um.find(key)!=um.end()){
            Node* temp=um[key];
            temp->val=value;
            deleteNode(temp);
            addNode(temp);
        }
        else{
            if(um.size()<cap){
            Node * node= new Node(key,value);
            um[key]=node;
            addNode(node);
            }
            else{
                Node * temp=tail->prev;
                um.erase(temp->key);
                deleteNode(temp);
                Node * node= new Node(key,value);
                um[key]=node;
                addNode(node);
                
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */