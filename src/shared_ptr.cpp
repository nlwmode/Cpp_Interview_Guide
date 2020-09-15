#include <string>
#include <iostream>

using namespace std;

namespace NLWMODE_ALGORIOTHM
{
    template<class T>
    class shared_ptr{
    private:
        T* _ptr;                        // 指向的对象
        mutable int* _pCount;           // 用于计数

    public:
        shared_ptr(T* ptr = nullptr) 
            : _ptr(ptr)
        {
            if(_ptr)
                _pCount = new int(1);
        }
        shared_ptr(const shared_ptr<T>& sdp)    //  拷贝构造函数
            ： _ptr(sdp._ptr) , _pCount( new int(1) )
        {
            ++(*_pCount);
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sdp)
        {
            if(this == sdp)
                return this;
            ++(*_pCount);
            // 不相等时，引用技术需要 -- ，如果--之后为0，则可释放
            if(this->_ptr && 0 == --( *this->_pCount ))
            {
                delete _pCount;
                delete _ptr;
            }
            this->_ptr = sdp._ptr;
            this->_pCount = sdp._pCount;
            return *this;
        }

        ~shared_ptr()
        {
            if(_ptr && --(*pCount) == 0)
            {
                delete _pCount;
                delete _ptr;
            }
        }
    };
}


int main()
{
       return 0;
}
