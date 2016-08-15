#pragma once

#include <Site.h>

#include <vector>

typedef std::vector<Site> SiteVec;
typedef SiteVec::iterator SiteVecIter;
typedef SiteVec::const_iterator SiteVecCIter;

void fillSiteVec(SiteVec &sites);
void fillCircularSiteVec(SiteVec &sites);
