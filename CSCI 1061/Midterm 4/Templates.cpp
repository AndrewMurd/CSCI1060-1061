template<class T>
class Pair
{
public:
    Pair( );
    Pair(T firstValue, T secondValue);
    void setFirst(T newValue);
    void setSecond(T newValue);
    T getFirst( ) const;
    T getSecond( ) const;
private:
    T first;
    T second;
};

template<class T>
Pair<T>::Pair(T firstValue, T secondValue)
{
    first = firstValue;
    second = secondValue;
}

template<class T>
void Pair<T>::setFirst(T newValue)
{
    first = newValue;
}

template<class T>
T Pair<T>::getFirst( ) const
{
    return first;
}

int main(){
   // getFirst<float>(1, 2.4, 3);
}

template<class T> void showStuff(T stuff1, T stuff2, T stuff3);

template<class T> void showStuff(T stuff1, T stuff2, T stuff3)
{   
    cout << stuff1 << endl
         << stuff2 << endl
         << stuff3 << endl;
}