#ifndef _ABSITER_H_
#define _ABSITER_H_
/*
  Note: For templated classes you cannot write the implementation of
  methods in .cc files.
  Details: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 */

template<typename T>
class AbstractIterator {
 public:
  //dereference operation
  virtual T &operator*() const = 0;
  //prefix ++
  virtual AbstractIterator<T> &operator++() = 0;

  // NON-virtual != operator defined in terms of == operator
  bool operator!=(const AbstractIterator<T> &other) const{
    return !(*this == other);
  }

  // pure virtual == operator. Subclasses must implement,
  // otherwise abstract
  virtual bool operator==(const AbstractIterator<T> &other) const = 0;

  //virtual destructor to prevent any memory leaks
  virtual ~AbstractIterator() = default;
};
#endif
