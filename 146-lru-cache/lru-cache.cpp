class LRUCache {
public:
    struct Node
    {
        int key,value;
        Node *prev, *next;
        Node(int k,int v) : key(k),value(v),prev(nullptr),next(nullptr){}
    };

    int cap;
    unordered_map<int ,Node*>mp;
    Node *head = new Node(-1,-1), *tail = new Node(-1,-1);

    LRUCache(int capacity) : cap(capacity) {
    head->next= tail;
    tail->prev = head;    
    }

    void addNode(Node* newNode)
    {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* delNode)
    {
       Node* prevNode= delNode->prev;
       Node* afterNode= delNode->next;
       prevNode->next= afterNode;
       afterNode->prev= prevNode; 
    }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* temp = mp[key];
            int resValue = temp->value;
            deleteNode(temp);
            addNode(temp);
            return resValue;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* existNode = mp[key];
            mp.erase(key);
            deleteNode(existNode);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */