运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

//题解：讲道理，这种设计的题目，确实比有些脑经急转弯要好很多，考察的基础知识及数据结构更加好，这题开始写的不对，然后自己写出来一版，用的是unordered_map
//与deque实现的，虽然慢了一点，但还歹还是ace了；
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
    }

    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        int res = m[key];
        for(auto i = queue_.begin();i!=queue_.end();++i) {
            if ((*i).first == key) {
                queue_.erase(i);
                break;
            }
        }
        queue_.push_back(make_pair(key, res));
        return res;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if(it == m.end())
            queue_.push_back(make_pair(key, value));
        else{
            for(auto i = queue_.begin();i!=queue_.end();++i) {
                if ((*i).first == key) {
                    queue_.erase(i);
                    break;
                }
            }
            queue_.push_back(make_pair(key, value));
        }
        if(queue_.size() > capacity_){
            int tmp = queue_.front().first;
            queue_.pop_front();
            m.erase(tmp);
        }
        m[key] = value;
    }

private:
    unordered_map<int, int> m;
    deque<pair<int, int>> queue_;
    int capacity_;
};


//2.看的别人的题解，用list与unordered_map实现，并不好理解，这里作为记录一下；
        
        
