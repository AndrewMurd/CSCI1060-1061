#include "Buffer.h"

#define DEBUG

Buffer::Buffer(const char *contents)
{
    sz = strlen(contents);
    m = new char[sz];
    strcpy(m, contents);
}

Buffer::Buffer(int _sz)
{
    sz = _sz;
    m = new char[sz];
}

Buffer::~Buffer()
{
    delete[] m;
}

const char *Buffer::mem() const
{
    return m;
}

const int &Buffer::size() const
{
    return sz;
}

void Buffer::resize(int _sz)
{
    char *tmp = new char[_sz];
    int n = (sz < _sz) ? sz : _sz;
    memcpy(tmp, m, n);
    delete[] m;
    m = tmp;
    sz = _sz;
}

int Buffer::write(ostream &os) const
{
    return write(os, sz);
}

int Buffer::write(ostream &os, int n) const
{
    int c = (n < sz) ? n : sz;
    os.write((char *)&c, sizeof(int));
    os.write(m, c);
    return c;
}

int Buffer::read(istream &is)
{
    int n;
    is.read((char *)&n, sizeof(int));
    resize(n);
    is.read(m, n);

    return is.gcount();
}

ostream &operator<<(ostream &os, const Buffer &buf)
{
    cout << "Buffer = " << buf.size() << "[";
    for (int i = 0; i < buf.size(); ++i)
    {
        cout << buf.mem()[i];
    }
    cout << "]";
    return os;
}