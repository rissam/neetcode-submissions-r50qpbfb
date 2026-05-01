class MedianFinder {
    struct Compare {
        bool operator() (const int &val1, const int &val2) const {
            return val1 > val2;
        }
    };

    priority_queue<int, vector<int>, Compare> min_pq;
    priority_queue<int> max_pq;
private:
    int count;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(max_pq.size() == 0) {
            max_pq.push(num);
            return;
        }
        if(num < max_pq.top()) {
            max_pq.push(num);
            cout << num << "in max heap"<<endl;
        } else {
            min_pq.push(num);
            cout << num << "in min heap"<<endl;
        }

        int maxpq_sz = max_pq.size();
        int minpq_sz = min_pq.size();
        if(abs(maxpq_sz-minpq_sz) < 2) {
            return;
        }
        if(maxpq_sz > minpq_sz) {
            int val = max_pq.top();
            max_pq.pop();
            min_pq.push(val);
            return;
        } else {
            int val = min_pq.top();
            min_pq.pop();
            max_pq.push(val);
        }
    }
    
    double findMedian() {
        int maxpq_sz = max_pq.size();
        int minpq_sz = min_pq.size();
        if(maxpq_sz == minpq_sz) {
            return (double)(max_pq.top()+min_pq.top())/2.0;
        }
        if(maxpq_sz > minpq_sz) {
            return max_pq.top();
        }
        else {
            return min_pq.top();
        }
    }
};
