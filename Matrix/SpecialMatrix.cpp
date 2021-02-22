#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class AbstractMatrix{
public:
    AbstractMatrix() = default;
    virtual void Set(int i, int j, T val) = 0;
    virtual T Get(int i, int j) = 0;
    virtual void Display() = 0;
    virtual ~AbstractMatrix() = default;
};
template<typename T>
class LowerTriangle: public AbstractMatrix<T>{
private:
    T* A;
    int size_;

public:
    LowerTriangle(int n): size_(n * (n+1) / 2) {
        cout << "Making lower triangle matrix with number elem: " << size_ << std::endl;
        A = new T[size_];
    }
    LowerTriangle(const std::vector<T>& v) {
        this->size_ = v.size();
        cout << "Making lower triangle matrix with number elem: " << size_ << std::endl;
        A = new T[size_];
        for (int i=0; i!=v.size(); i++) {
            A[i] = v[i];
        }
    }

    void Set(int i, int j, T val) override{
        if (i >= j) {
            A[i*(i-1) / 2 + j-1] = val;
        }
    }


    T Get(int i, int j) override {
    if (i>=j) {
        return A[i*(i-1)/2 + j-1];
    }
    }
    void Display() override{
       for (int i = 0; i!= size_; i++) {
        for (int j=0; j!= size_; j++) {
            if (i >= j) {
                std::cout << Get(i, j) <<" ";
            } else {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
    }
};


template<typename T>
class Diagonal {
private:
    T* A;
    int size_;
public:
    Diagonal(int n): size_(n), A(new T[n]){};
    explicit Diagonal(std::vector<T> v){
        size_ = v.size();
        A = new T[size_];
        for (int i=0; i!=size_; i++) {
            A[i] = v[i];
        }
    }
    void Set(int i, int j, T val);
    T Get(int i, int j);
    void Display();

    ~Diagonal() { delete []A;}

};
template<typename T>
void Diagonal<T>::Set(int i, int j, T val) {
    if (i == j) {
        A[i-1]=  val;
    }
}

template<typename T>
T Diagonal<T>::Get(int i, int j) {
    if (i == j && i<size_) {
        return A[i-1];
    } else return 0;
}
template<typename T>
void Diagonal<T>::Display() {
    for (int i = 0; i!= size_; i++) {
        for (int j=0; j!= size_; j++) {
            if (i == j) {
                std::cout << A[i] <<" ";
            } else {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    std::vector<int> z{6,5,4,3,2,1};
    LowerTriangle<int> t(z);
    t.Display();

    std::vector<int> v{4,3,2};
    Diagonal<int> d(v);
    //d.Set(1,1,5);
    //d.Set(2,2,8);
    d.Display();

    return 0;
}
