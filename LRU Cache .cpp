
class LRUCache{
public:
    LRUCache(int capacity) :
        total_size_(capacity),
        cur_size_(0)
    {
        
    }
    
    int get(int key) {
        auto map_res = map_.find(key);
        if(map_res == map_.end())
            return -1;
        
        list<pair<int, int> >::iterator p = map_res->second;
        int v = p->second;
        int k = p->first;
        list_.erase(p);
        list_.push_front(make_pair(k, v));
        map_res->second = list_.begin();
        
        return v;
    }
    
    void set(int key, int value) {
        auto map_res = map_.find(key);
        if(map_res == map_.end()) {
            list_.push_front(make_pair(key, value));
            map_.insert(make_pair(key, list.begin()));
            if(cur_size_ < total_size_) {
                ++cur_size_;
            }
            else {
                int tk = list_.back().first;
                map_.erase(tk);
                list_.pop_back();
            }
        }
        else {
            list<pair<int, int> >::iterator it = map_res->second;
            int k = it->first;
            list_erase(it);
            list_push_front(make_pair(k, value));
            map_res->second = list_.begin();
        }
    }
    
private:
    int total_size_;
    int cur_size_;
    list<pair<int, int> > list_;
    unordered_map<int, list<pair<int, int> >::iterator> map_;
};