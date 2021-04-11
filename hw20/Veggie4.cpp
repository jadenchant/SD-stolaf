#include<iostream>

class Veggie {
  char *name;
  int calories;
public:
  Veggie() : calories(0), name(0) { }

  Veggie(int c) : calories(c), name(0) { }

  Veggie(const char *n, int c) : calories(c) {
    int len = 0;
    while (n[len++]) { }
    name = new char[len];
    for (int i = 0; i < len; ++i) {
      name[i] = n[i];
    } 
  }

  Veggie(Veggie &v) : calories(v.calories) {
    int len = 0;
    while(v.name[len++]) { }
    name = new char[len];
    for(int i = 0; i < len; ++i) {
      name[i] = v.name[i];
    }
  }

  void print() { 
    if (name) {
      std::cerr << name << " calories " << calories << std::endl;
    } else {
      std::cerr << calories << std::endl;
    }
  }

  ~Veggie() { 
    if (name) {
      std::cerr << "deallocating " << name << std::endl;
    }
    delete [] name;  // does not do anything if name is zero
  }
};

int main() { 
  Veggie a("kale", 42);
  Veggie b("brocc", 33);
  Veggie c(10);
  Veggie w(a);
  Veggie* d[4]; 
  d[0] = &a; 
  d[1] = &b; 
  d[2] = &c; 
  d[3] = &w;
  Veggie **e = d; 
  e[2]->print();  // first line of output;  where are the others?
}