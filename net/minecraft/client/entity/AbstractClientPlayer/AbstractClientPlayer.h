#pragma once
#include "../../../entity/player/EntityPlayer/EntityPlayer.h"

class AbstractClientPlayer : public EntityPlayer {
public:
	using EntityPlayer::EntityPlayer;
	static bool init();
protected:
	inline static Ripterms::JavaClass AbstractClientPlayerClass{};
};