#include "AudioService.h"

SDLAudio::SDLAudio(MIX_Mixer* mix)
{
	if (!mix) mix = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
	_Mixer = mix;
};

SDLAudio::~SDLAudio()
{
	for (std::vector<MIX_Track*>::iterator i = _Tracks.begin(); i != _Tracks.end(); i++)
		MIX_DestroyTrack(*i);
	for (std::map<std::string, MIX_Audio*>::iterator i = _SFXs.begin(); i != _SFXs.end(); i++)
		MIX_DestroyAudio(i->second);
	for (std::map<std::string, MIX_Audio*>::iterator i = _Music.begin(); i != _Music.end(); i++)
		MIX_DestroyAudio(i->second);
}

void SDLAudio::PlaySFX(std::string id)
{
	std::map<std::string, MIX_Audio*>::iterator result = _SFXs.find(id);
	if (result != _SFXs.end())
		MIX_PlayAudio(_Mixer, _SFXs[id]);
};

void SDLAudio::PlayStream(std::string id)
{
	std::map<std::string, MIX_Audio*>::iterator result = _Music.find(id);
	if (result == _Music.end())
		return;

	for (std::vector<MIX_Track*>::iterator i = _Tracks.begin(); i != _Tracks.end(); i++)
		if (MIX_GetTrackAudio(*i) == _Music[id])
		{
			if (MIX_TrackPaused(*i))
				MIX_ResumeTrack(*i);
			else
			{
				SDL_PropertiesID options = SDL_CreateProperties();
				SDL_SetNumberProperty(options, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
				MIX_PlayTrack(*i, options);
				SDL_DestroyProperties(options);
			}
			return;
		}

	MIX_Track* mix = MIX_CreateTrack(_Mixer);
	MIX_SetTrackAudio(mix, _Music[id]);
	SDL_PropertiesID options = SDL_CreateProperties();
	SDL_SetNumberProperty(options, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
	MIX_PlayTrack(mix, options);
	SDL_DestroyProperties(options);

	_Tracks.push_back(mix);
};

void SDLAudio::StopSFX(std::string id)
{
	//	Not needed with SDL_Mixer.
	std::cout << "Did you mean to call this? SFXs are fire-and-forget under SDL_Mixer." << std::endl;
};

void SDLAudio::StopStream(std::string id)
{
	for (std::vector<MIX_Track*>::iterator i = _Tracks.begin(); i != _Tracks.end(); i++)
		if (MIX_GetTrackAudio(*i) == _Music[id])
			MIX_StopTrack(*i, 0);
};

void SDLAudio::PauseStream(std::string id)
{
	for (std::vector<MIX_Track*>::iterator i = _Tracks.begin(); i != _Tracks.end(); i++)
		if (MIX_GetTrackAudio(*i) == _Music[id])
			MIX_PauseTrack(*i);
};

bool SDLAudio::StreamPlaying(std::string id)
{
	for (std::vector<MIX_Track*>::iterator i = _Tracks.begin(); i != _Tracks.end(); i++)
		if (MIX_GetTrackAudio(*i) == _Music[id])
			return MIX_TrackPlaying(*i);
	return false;
};

bool SDLAudio::StoreSFX(std::string id, std::string filename)
{
	MIX_Audio* sfx = nullptr;
	sfx = MIX_LoadAudio(_Mixer, filename.c_str(), true);

	if (!sfx) return false;

	std::map<std::string, MIX_Audio*>::iterator result = _SFXs.find(id);
	if (result != _SFXs.end())
		MIX_DestroyAudio(result->second);
	_SFXs[id] = sfx;

	return true;
};

bool SDLAudio::StoreStream(std::string id, std::string filename)
{
	MIX_Audio* music = nullptr;
	music = MIX_LoadAudio(_Mixer, filename.c_str(), true);

	if (!music) return false;

	std::map<std::string, MIX_Audio*>::iterator result = _Music.find(id);
	if (result != _Music.end())
		MIX_DestroyAudio(result->second);
	_Music[id] = music;

	return true;
};