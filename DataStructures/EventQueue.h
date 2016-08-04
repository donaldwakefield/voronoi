#pragma once

#include <queue>

#include <Event.h>

struct EventLessThan
{
   bool operator()(const EventPtr &lhs, const EventPtr &rhs)
   {
      return (
               (lhs->sweepOrder() < rhs->sweepOrder()) ||
               (
                  (lhs->sweepOrder() == rhs->sweepOrder()) &&
                  (lhs->xLocation() < rhs->xLocation())
               )
             );
   }
};

typedef std::priority_queue<EventPtr, std::vector<EventPtr>, EventLessThan> EventQueue;
