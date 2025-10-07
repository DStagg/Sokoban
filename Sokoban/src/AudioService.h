#pragma once

#include <SDL3_mixer/SDL_mixer.h>
#include "core/Service.h"
#include <map>
#include <vector>
#include <iostream>

class SDLAudio : public AudioService
{
public:

	SDLAudio(MIX_Mixer* mix = nullptr);
	~SDLAudio();

	void PlaySFX(std::string id);
	void PlayStream(std::string id);
	void StopSFX(std::string id);
	void StopStream(std::string id);
	void PauseStream(std::string id);
	bool StreamPlaying(std::string id);

	bool StoreSFX(std::string id, std::string filename);
	bool StoreStream(std::string id, std::string filename);

protected:

	std::vector<MIX_Track*> _Tracks;
	std::map<std::string, MIX_Audio*> _SFXs;
	std::map<std::string, MIX_Audio*> _Music;
	MIX_Mixer* _Mixer;
};