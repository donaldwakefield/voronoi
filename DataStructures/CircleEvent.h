#pragma once

#include <Event.h>
#include <Circle.h>

/*!
 *
 */
class CircleEvent : public Event
{
public:

   CircleEvent(const Circle &circle) : circle_(circle) {};
   virtual ~CircleEvent() {};

   virtual double sweepOrder() { return circle_.minimum(); }

private:

   Circle circle_;
};
