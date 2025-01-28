class MedianFinder {
public:

    multiset<int> s;
    multiset<int>::iterator mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.size() == 0){
            s.insert(num);
            mid = s.begin();
        }
        else{
            s.insert(num);
            if(s.size() %2 ==0){
                if(num < *mid) mid--;
            }
            else {
                if(num>=*mid) mid++;
            }
        }
    }
    
    double findMedian() {
        if(s.size() %2 ==0){
            auto midP = mid;
            midP++;
            return (double)(*mid + *midP) / 2;
        }
        else return *mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */