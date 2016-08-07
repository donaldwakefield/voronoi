#pragma once

#include <Site.h>
#include <SiteVec.h>
#include <EventQueue.h>

class Voronoi
{
public:

  Voronoi(const SiteVec &sites);
  ~Voronoi() {};

  void outputSVG();

private:
  SiteVec    sites_;
  EventQueue eq_;
};
