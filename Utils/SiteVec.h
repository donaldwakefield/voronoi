#pragma once

#include <Site.h>

#include <vector>

typedef std::vector<Site> SiteVec;
typedef SiteVec::iterator SiteVecIter;

void fillSiteVec(SiteVec &sites);
void fillCircularSiteVec(SiteVec &sites);
