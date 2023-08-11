template <typename>
class Iterator;

template <typename T>
class IIterable
{
public:
    virtual Iterator<T> begin() = 0;
    virtual Iterator<T> end() = 0;
};