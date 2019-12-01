#ifndef CLONA_DEVICE_ORGANIZER_H
#define CLONA_DEVICE_ORGANIZER_H

#include <map>
#include <string>
#include <SDL.h>

namespace clona {
	/**
	 * 组织器
	 * 
	 * 资源管理。
	 */
	class organizer final {
		SDL_Window* window;
		SDL_Surface* screen;
		SDL_Renderer* renderer;
		std::map<std::string, SDL_Surface*> images;
		std::map<std::string, SDL_Texture*> textures;
	public:
		organizer() :window(nullptr), screen(nullptr), renderer(nullptr), images(), textures() {}
		organizer(organizer &&) = delete;
		organizer(const organizer&&) = delete;

		void attach();
		void detach();
		void update();

		SDL_Surface* get_image(const std::string& name);
		SDL_Texture* get_texture(const std::string& name);
	};
}

#endif
