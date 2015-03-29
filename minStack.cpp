class MinStack {
public:
    void push(int x) {
        data.push_back(x);
        if(minStack.empty() || x<minStack.back().first)
            minStack.push_back(make_pair(x, 1));
        else if (x == minStack.back().first) {
            ++minStack.back().second;
        }
    }

    void pop() {
        if(data.empty())
            return;
        int x = data.back();
        data.pop_back();
        
        if(minStack.back().first != x)
            return;
            
        if(--minStack.back().second < 1 ) {
            minStack.pop_back();
        }
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return minStack.back().first;
    }
    
private:
    vector<int> data;
    vector<pair<int, int> > minStack;
};
