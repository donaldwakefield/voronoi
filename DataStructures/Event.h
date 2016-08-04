#pragma once

#include <boost/shared_ptr.hpp>

/*!
 * \class Event forms the base protocol class for all event types.
 * \brief The sweepOrder method allows derived classes to say where
 *        they should fall in the queue
 */
class Event
{
public:

   Event() {};
   virtual ~Event() {}

   virtual double sweepOrder() const = 0;
   virtual double xLocation() const = 0;
};

typedef boost::shared_ptr<Event> EventPtr;
