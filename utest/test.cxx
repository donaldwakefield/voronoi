#define BOOST_TEST_MODULE VoronoiTest

#include <boost/test/included/unit_test.hpp>

#include <Circle.h>
#include <CircleEvent.h>
#include <Site.h>
#include <SiteEvent.h>
#include <EventQueue.h>

#include <iostream>

BOOST_AUTO_TEST_CASE(first_test)
{
   double feedStock[] = { 6, 7, 0, 1, 4, 5, 8, 9, 2, 3 };
   std::vector<Site> siteVec;
   for (uint32_t i = 0; i < 9; i += 2) {
      siteVec.push_back(Site(feedStock[i], feedStock[i+1]));
   }

   EventQueue eq;
   std::vector<Site>::iterator iter, e_iter = siteVec.end();
   for (iter = siteVec.begin(); iter != e_iter; ++iter) {
      eq.push(EventPtr(new SiteEvent(*iter)));
   }

   Circle circle(siteVec[0], siteVec[1], siteVec[2]);
   eq.push(EventPtr(new CircleEvent(circle)));

   EventPtr currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 9);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 7);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 5);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 3);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 1);

   eq.pop();
   BOOST_CHECK(!eq.empty());
   currPtr = eq.top();
   // This will change when we fix Circle minimum() method.
   BOOST_REQUIRE(currPtr->sweepOrder() == -1000000);
}
