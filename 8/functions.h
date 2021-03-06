#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

template <class In>
bool equal(In b, In e, In b2) {
  while(b != e) {
    if(b2 == e || *b != *b2) return false;
    ++b;
    ++b2;
  }
  //it doesn't matter if there are elements after b2+(e-b)
  return true;
}

template <class In, class X>
In find(In b, In e, X t) {
  while(b != e) {
    if(*b == t) break;
    b++;
  }
  return b;
}

template <class In, class Out>
In copy(In b, In e, Out d) {
  while(b != e) {
    *d = *b;
    ++d;
    ++b;
  }
  return d;
}

template <class For, class Out, class Pred>
For remove_copy_if(For b, For e, Out d, Pred p) {
  For b2 = b;
  while(b2 != e && b != e) {
    if(!p(*b2)) {
      //move match to front
      *b = *b2;
      b++;
      b2++;
    } else {
      //output match
      d = *b2;
      d++;
      
      b2++;
    }
    //Invariants
    //all elements before b are not matches: [0, b)
  }
  return b;
}


template <class For, class Out, class T>
For remove_copy(For b, For e, Out d, T t) {
  For b2 = b;
  while(b2 != e && b != e) {
    if(!(*b2 == t)) {
      //move match to front
      *b = *b2;
      b++;
      b2++;
    } else {
      //output match
      d = *b2;
      d++;
      
      b2++;
    }
    //Invariants
    //all elements before b are not matches: [0, b)
  }
  return b;
}

template <class In, class Out, class F>
Out transform(In b, In e, Out d, F f) {
  while(b != e) {
    d = f(*b);
    ++b;
    ++d;
  }
  return d;
}

template <class In, class T>
T accumulate(In b, In e, T t) {
  T x = t;
  while(b != e) {
    x += *b++;
  }
  return x;
}

template <class In>
In search(In b, In e, In b2, In e2) {
  while(b != e) {
    if(*b == *b2) {
      In sb = b;
      In sb2 = b2;
      while(*sb == *sb2) {
        sb++;
        sb2++;
        if(sb2 == e2) return b;
      }
    }
    b++;
  }
  return e;
}

template <class In, class Pred>
In find_if(In b, In e, Pred p) {
  while(b != e) {
    if(p(*b)) break;
    b++;
  }
  return b;
}

//Coalesces at the beginning of the sequence
template <class For, class T>
For remove(For b, For e, T t) {
  For b2 = b;
  while(b2 != e && b != e) {
    if(!(*b2 == t)) {
      //move match to front
      *b = *b2;
      b++;
      b2++;
    } else {
      b2++;
    }
    //Invariants
    //all elements before b are not matches: [0, b)
  }
  return b;
}

template <class For, class Pred>
For partition(For b, For e, Pred p) {

  For b2 = b;
  while(b2 != e && b != e) {
    if(!p(*b2)) {
      //move match to front
      std::swap(*b, *b2);
      b++;
      b2++;
    } else {
      b2++;
    }
    //Invariants
    //all elements before b are not matches: [0, b)
    //all elements between b and b2 are matches: [b, b2)
  }
  return b;
}

#endif
