# oopAssinment3

































typedef T* iterator;

    iterator begin(){
        return data;
    }

    iterator end(){
        return data + size;
    }
    
    
    bool operator==(GMvector &v) {
        if (size != v.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] != v.data[i]) {
                return false;
            }
        }
        return true;
    }
    
    
    
   bool operator<(GMvector &v) {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (data[i] < v.data[i]) {
                flag = !flag;
            } else {
                flag = flag;
            }
        }
        return flag;
    }
    
    friend ostream &operator<<(ostream &out, GMvector<T> v) {
        for (int i = 0; i < v.size; i++)
            out << v.data[i] << ' ';
        return out;
    };
    
   bool empty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
