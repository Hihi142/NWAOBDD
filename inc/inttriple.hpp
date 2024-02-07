#pragma once 
#include<ostream>

class inttriple {
private:
    int first, second, third;
public:
    inttriple();
    inttriple(const int i1, const int i2, const int i3);
    int First() const { return first; }
    int Second() const { return second; }
    int Third() const { return third; }

    inttriple& operator= (const inttriple& p);
    bool operator!= (const inttriple& p) const;
    bool operator== (const inttriple& p) const;


    struct inttriple_hash;
    friend std::ostream& operator<< (std::ostream & out, const inttriple &p);
};

inttriple::inttriple()
  :  first(0), second(0), third(0)
{
}

inttriple::inttriple(const int i1, const int i2, const int i3)
  :  first(i1), second(i2), third(i3)
{
}

std::ostream& operator<< (std::ostream & out, const inttriple &p)
{
  out << "(" << p.First() << ", " << p.Second() << ", " << p.Third() << ")";
  return(out);
}

inttriple& inttriple::operator= (const inttriple& i)
{
  if (this != &i)      // don't assign to self!
  {
    first = i.first;
    second = i.second;
    third = i.third;
  }
  return *this;        
}

// Overloaded !=
bool inttriple::operator!=(const inttriple& p) const
{
  return (first != p.first) || (second != p.second) || (third != p.third);
}

// Overloaded ==
bool inttriple::operator==(const inttriple& p) const
{
  return (first == p.first) && (second == p.second) && (third == p.third);
}

struct inttriple::inttriple_hash {
    size_t operator()(const inttriple& p) const {
        return 117 * (p.First() + 1) + p.Second() + p.Third() ^ 2024;
    }
};