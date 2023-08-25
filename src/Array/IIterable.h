template <typename>
class ConstIterator;

template <typename T>
class IIterable
{
public:
    virtual ConstIterator<T> begin() const = 0;
    virtual ConstIterator<T> end() const = 0;
};