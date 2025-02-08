class NumberContainers {
public:
unordered_map<int,int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> d;
    NumberContainers() {}
    
    void change(int i, int n) {
       if(m.count(i) && m[i]==n)return;
        m[i]=n;
        d[n].push(i);
    }
    
    int find(int n) {
        if(!d.count(n)) return -1;
        auto &pq = d[n];
        while(!pq.empty() && m[pq.top()]!=n) pq.pop();
        return pq.empty()? -1 : pq.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */