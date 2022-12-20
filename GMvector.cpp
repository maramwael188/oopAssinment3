//Name: George Ashraf Farhan Wahba ID: 20210103
//Name: Maram Wael ID: 20211087
//Group Task : Making a vector


#include<iostream>
#include<algorithm>


using namespace std;
template <typename T>
class GMvector
{
private:
    T* data;
    int size;
    int c; //capacity

public:
    GMvector(int c1)
    {
        c = c1;
        size = 0;
        data = new T[c];
    }
    
    GMvector(T* p, int n)
    {
        this->size = n;
        this->c = n * 2;
        this->data = new T[c];
        for (int i = 0;i < n;i++)
        {
            data[i] = p[i];
        }
    }
    int getSize()
    {
        return size;
    }
    T& operator[](int index)
    {
        if (index > size - 1)
        {
            cout << "Invalid index;(" << endl;
            exit(1);   
        }
        else
        {
            return data[index];
        }
    }
    GMvector& operator=(const GMvector& v)
    {
        if (this->size != v.size)
        {
            delete[] data;
            this->size = v.size;
            this->c = v.c;
            this->data = new T[c];
        }
        for (int i = 0;i < size;i++)
        {
            data[i] = v.data[i];
        }
        return *this;
    }
    GMvector(const GMvector& v)
    {
        this->size = v.size;
        this->c = v.c;
        data = new T[c];
        for (int i = 0;i < size;i++)
        {
            data[i] = v.data[i];
        }
    }
    void push_back(T e)
    {
        if (size == c)
        {
            c = c * 2;
            T* temp = new T[c];
            for (int i = 0;i < size;i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            temp = nullptr;
        }
        data[size] = e;
        size++;
    }
    void pop_back()
    {
        size--;
    }
    void resize(int n)
    {
        T* temp = new T[n];
        for (int i = 0;i < n;i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = n;
    }
    void resize(int n, T e)
    {
        T* temp = new T[n];
        for (int i = 0;i < n;i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = n;
        for (int i = 0;i < n;i++)
        {
            data[i] = e;
        }
    }
    void clear()
    {
        delete[] data;
        size = 0;
    }
    void earse(T* p)
    {
        int index;
        for (int i = 0; i < size;i++)
        {
            if (data[i] == *p)
            {
                index = i;
                break;
            }
        }
        T* temp = new T[size - 1];
        for (int i = 0; i < index;i++)
        {
            temp[i] = data[i];
        }
        for (int i = index + 1; i < size; i++)
        {
            temp[i - 1] = data[i];

        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = size - 1;

                
    }
    void erase(T* p1, T* p2)
    {
        int index1, index2;
        for (int i = 0; i < size;i++)
        {
            if (data[i] == *p1)
            {
                index1 = i;
                break;
            }
        }
        for (int i = 0; i < size;i++)
        {
            if (data[i] == *p2)
            {
                index2 = i;
                break;
            }
        }
        T* temp = new T[size - (index2 - index1)];
        for (int i = 0; i < index1;i++)
        {
            temp[i] = data[i];
        }
        for (int i = index2 + 1; i < size;i++)
        {
            temp[i - (index2 - index1)] = data[i];
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = size - (index2 - index1);
    }
    void insert(T* p, T e)
    {
        int index;
        for (int i = 0; i < size;i++)
        {
            if (data[i] == *p)
            {
                index = i;
                break;
            }
        }
        T* temp = new T[size + 1];
        for (int i = 0; i < index;i++)
        {
            temp[i] = data[i];
        }
        temp[index] = e;
        for (int i = index + 1; i < size + 1;i++)
        {
            temp[i] = data[i - 1];
        }
        delete[] data;
        data = temp;
        temp = nullptr;
        size = size + 1;
    }
    int capacity()
    {
        return c;
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

    bool operator<(GMvector& v)
    {
        bool flag = false;
        for (int i = 0; i < size; i++) {
            if (data[i] < v.data[i]) {
                flag = !flag;
            }
            else {
                flag = flag;
            }
        }
        return flag;
    }

    bool empty()
    {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    friend ostream &operator<<(ostream &out, GMvector<T> v) {
        for (int i = 0; i < v.size; i++)
            out << v.data[i] << ' ';
        return out;
    }
    typedef T* iterator;
    iterator begin(){
        return data;
    }

    iterator end(){
        return data + size;
    }
};


int main()
{
    GMvector<int> v1(5);
    GMvector<int> v2(5);
    for (int i = 0; i < 5; i++) 
    {
        v1.push_back(i);
        v2.push_back(i);
    }
    cout <<"v1 : "<< v1 << endl;
    cout <<"v2: "<< v2 << endl;
    cout << "v1 == v2 : " << (v1 == v2) << endl;
    cout << "v1 < v2 : " << (v1 < v2) << endl;
    cout << "v1.empty() : " << v1.empty() << endl;
    cout << "v1.capacity() : " << v1.capacity() << endl;
    v1.push_back(5);
    cout << "v1.push_back(5) : " << v1 << endl;
    cout << "v1.capacity() : " << v1.capacity() << endl;
    v1.pop_back();
    cout << "v1.pop_back() : " << v1 << endl;
    v1.resize(10);
    cout << "v1.resize(10) : " << v1 << endl;
    v1.resize(10, 5);
    cout << "v1.resize(10,5) : " << v1 << endl;
    v1.clear();
    cout << "v1.clear() : " << v1 << endl;
    cout << "v2: "<< v2 <<endl;
    v2.earse(&v2[0]);
    cout << "v2.earse(&v2[0]) : " << v2 << endl;
    v2.push_back(3);
    cout << "v2 : " << v2 << endl;
    
}
