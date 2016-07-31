#pragma once

#include <queue>

#include <Event.h>

struct EventLessThan
{
   bool operator()(const Event &lhs, const Event &rhs)
   {
       return lhs.sweepOrder() < rhs.sweepOrder();
   }
};

typedef std::priority_queue<Event, std::vector<Event>, EventLessThan> Queue;
