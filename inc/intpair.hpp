#pragma once
#include<ostream>

class intpair {
private:
    int first, second;
public:
    intpair();
    intpair(const int i1, const int i2);
    int First() const { return first; }
    int Second() const { return second; }

    intpair operator! (); // apply '!' to both fields
    intpair& operator= (const intpair& p);
  
    bool operator!= (const intpair& p) const;
    bool operator== (const intpair& p) const;
    
    struct intpair_hash; // hash-function for unordered_map
    friend std::ostream& operator<< (std::ostream & out, const intpair &p);
};

intpair::intpair()
  :  first(0), second(0)
{
}

intpair::intpair(const int i1, const int i2)
    :  first(i1), second(i2)
{
}

intpair& intpair::operator= (const intpair& i)
{
  if (this != &i)      // don't assign to self!
  {
    first = i.first;
    second = i.second;
  }
  return *this;        
}

std::ostream& operator<< (std::ostream & out, const intpair &p)
{
  out << "(" << p.First() << ", " << p.Second() << ")";
  return(out);
}

intpair intpair::operator! ()
{
	int newFirst = !this->First();
	int newSecond = !this->Second();
	return intpair(newFirst,newSecond);
}

bool intpair::operator!=(const intpair& p) const
{
  return (first != p.first) || (second != p.second);
}

bool intpair::operator==(const intpair& p) const
{
  return (first == p.first) && (second == p.second);
}

struct intpair::intpair_hash {
    size_t operator()(const intpair& p) const {
        return 117 * (p.First() + 1) + p.Second();
    }
};