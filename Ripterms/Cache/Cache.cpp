#include "Cache.h"
#include <iostream>

Ripterms::Cache::Cache()
{
}

Ripterms::Cache::~Cache()
{
	prev_thePlayer.clear();
}

bool Ripterms::Cache::fillCache()
{
	theMinecraft = Minecraft::getTheMinecraft();
	if (!theMinecraft) return false;
	thePlayer = theMinecraft.getThePlayer();
	if (!thePlayer) return false;
	if (!prev_thePlayer.isEqualTo(thePlayer)) {
		std::clog << "object updated" << std::endl;
		prev_thePlayer = thePlayer;
		theWorld = theMinecraft.getTheWorld();
		playerEntities = theWorld.getPlayerEntities();
	}
	return true;
}
