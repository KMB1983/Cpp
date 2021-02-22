#include <iostream>
#include <string>

class BufferManager{
private:
    int _size;
    char *_buffer;
public:
    BufferManager(int size): _size(size) {
        _buffer = new char[_size];
    }

    ~BufferManager() {
        delete []_buffer;
    }

    //copy constructor
    BufferManager(const BufferManager& other) {
        _size = other._size;
        _buffer = new char[_size];

        for (size_t i=0; i<_size; i++) {
            _buffer[i] = other._buffer[i];
        }
    }

    // assignment operator
    /*
    BufferManager& operator=(const BufferManager& other) {
        if (&other != this) {
            delete[] _buffer;
            _size = other._size;
            char *_buffer = new char[_size];
            for (size_t i=0; i<_size; i++) {
                _buffer[i] = other._buffer[i];
            }
            return *this;
        }
    }
    */
    BufferManager& operator=(const BufferManager& other) {
        BufferManager temp(other);
        using std::swap;
        swap(*this, temp);
        return *this;
    }

    BufferManager(BufferManager&& other) noexcept {
        using std::swap;
        swap(*this, other);
        other._buffer = nullptr;
    }

    BufferManager& operator=(BufferManager&& other) noexcept {
        using std::swap;
        swap(*this, other);
        return *this;
    }

    void Print() {
        std::cout << _buffer << std::endl;
    }

    friend void Swap(BufferManager& l, BufferManager& r) noexcept;

};

void Swap(BufferManager& l, BufferManager& r) noexcept {
    using std::swap;
    swap(l._size, r._size); // for built in types
    swap(l._buffer, r._buffer);
}



int main() {

    return 0;
}
