class MedianFinder {
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<=left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(abs((int)left.size()-(int)right.size())>1){
            if(left.size()>right.size()){
                int x=left.top();
                left.pop();
                right.push(x);
            }
            else{
                int x=right.top();
                right.pop();
                left.push(x);
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        else{
            if(left.size()>right.size()) return left.top();
            else return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */