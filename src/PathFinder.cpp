#include "../include/PathFinder.hpp"
#include "../include/Handler.hpp"

PathFinder::PathFinder(Handler& handler)
: handler(handler),
coordinateConverter(handler.getCoordinateConverter())
{
}