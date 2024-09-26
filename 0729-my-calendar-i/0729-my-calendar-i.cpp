class MyCalendar {
    map<int,int> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=intervals.lower_bound(start);
        if(next!=intervals.end() && next->first<end) return false;
        if(next!= intervals.begin() && prev(next)->second>start) return false;
        intervals[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */