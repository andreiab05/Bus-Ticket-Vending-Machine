#ifndef REPOSITORYFILE_H
#define REPOSITORYFILE_H
#include "Repository.h"


class RepositoryFile : public Repository {
public:
      RepositoryFile() = default;
      void loadFromFile(const string&);
      void printAll() const;
};



#endif //REPOSITORYFILE_H
