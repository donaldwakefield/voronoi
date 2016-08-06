#pragma once

#include <Site.h>

#include <vector>

class SiteSet
{
public:
  typedef std::vector<Site> Set;
  typedef Set::iterator     SetIter;

  SiteSet();
  ~SiteSet();

  void writeSites();

private:

  Set set_;
};
