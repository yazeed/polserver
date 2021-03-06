/*
History
=======


Notes
=======

*/

#ifndef ZONE_H
#define ZONE_H

#include "../plib/realm.h"
#include "poltype.h"
#include "wrldsize.h"

#include <string>
#include <vector>

namespace Pol {
  namespace Core {
	const unsigned WORLD_MIN_X = 0;
	const unsigned WORLD_MAX_X = 6142;

	const unsigned WORLD_MIN_Y = 0;
	const unsigned WORLD_MAX_Y = 4094;

	inline bool VALID_WORLD_LOC( unsigned short x, unsigned short y, Plib::Realm* realm )
	{
	  return realm->valid( x, y, 0 );
	}
	inline bool VALID_WORLD_LOC( unsigned short x, unsigned short y, short z, Plib::Realm* realm )
	{
	  return realm->valid( x, y, z );
	}


	const unsigned ZONE_SIZE = 4;
	const unsigned ZONE_SHIFT = 2;

	const unsigned ZONE_X = WORLD_X / ZONE_SIZE;
	const unsigned ZONE_Y = WORLD_Y / ZONE_SIZE;

	void XyToZone( xcoord x, ycoord y, unsigned* zonex, unsigned* zoney );

	typedef unsigned short RegionId;
  }
}
#endif
