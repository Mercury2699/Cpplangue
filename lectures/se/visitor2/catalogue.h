#ifndef __CATALOGUE_H__
#define __CATALOGUE_H__
#include <map>
#include <string>

#include "BookVisitor.h"
class Book;
class Comic;
class Text;

class CatalogueVisitor: public BookVisitor {
  std::map<std::string, int> theCatalogue;

 public:
  std::map<std::string, int> getResult() const;

  virtual void visit(Book &b) override;
  virtual void visit(Comic &cb) override;
  virtual void visit(Text &csb) override;
};

#endif
