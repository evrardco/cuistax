#include <bitset>
#include <utility>
#include<vector>
#include<unordered_map>
#include<stack>
template <class T> 
class Recycler {
    public:
        Recycler(int size) : 
            size(size), next_free(0),
            ptr_idx_map(), free_list()
        {
            elements = new T[size];
            for (int i = 0; i < size; i++) {
                elements[i] = new T();
                recycle_callback(elements[i]);
                ptr_idx_map.insert(std::pair<T *, int>(elements[i], i));
            }

            for (int i = size - 1; i >= 0; i--) {
                free_list.push(i);
            }

        }

        ~Recycler() {
            for (int i = 0; i < size; i++) {
                delete elements[i];
            }
            delete[] elements;
        }

        void recycle(T * to_recycle) {
            int idx = ptr_idx_map.at(to_recycle);
            recycle_callback(to_recycle);
            free_list.push(idx);
        }   

        virtual void recycle_callback(T *);

        T * take() {
            if (free_list.empty()) {
                return NULL;
            }
            int idx = free_list.top();
            free_list.pop();
            take_callback(elements[idx]);
            return elements[idx];
        }
        virtual void take_callback(T *);
    protected:
        T * elements;
        int size;
        int next_free;
        std::unordered_map<T *, int> ptr_idx_map;
        std::stack<int> free_list;
    private:
};