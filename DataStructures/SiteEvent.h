#pragma once

#include <Event.h>
#include <Site.h>

/*!
 *
 */
class SiteEvent : public Event
{
public:

 SiteEvent(const Site &site) : site_(site) {};
   virtual ~SiteEvent() {}

   virtual double sweepOrder() const { return site_.yOrd(); }

private:

   Site site_;
};
