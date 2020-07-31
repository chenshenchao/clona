#include <SDL_image.h>
#include "organizer.h"

/**
 * 初始化资源。
 * 
 */
void clona::organizer::attach() {
	window = SDL_CreateWindow(
		"clona",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		//SDL_WINDOW_FULLSCREEN |
		SDL_WINDOW_OPENGL
	);
	screen = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

/**
 * 释放图片资源。
 * 
 */
void clona::organizer::detach() {
	for (auto& texture : textures) {
		SDL_DestroyTexture(texture.second);
	}
	for (auto& image : images) {
		SDL_FreeSurface(image.second);
	}
	if (nullptr != renderer) SDL_DestroyRenderer(renderer);
	if (nullptr != screen) SDL_FreeSurface(screen);
	if (nullptr != window) SDL_DestroyWindow(window);
}

/**
 * 更新
 */
void clona::organizer::update()
{
	// SDL_BlitSurface(surface, nullptr, screen, nullptr);
	SDL_UpdateWindowSurface(window);
}


/**
 * 加载图片。
 * 
 */
SDL_Surface* clona::organizer::get_image(const std::string& name) {
	auto result = images.find(name);
	if (images.end() != result) {
		return result->second;
	}
	auto image = IMG_Load(name.c_str());
	images.emplace(name, image);
	return image;
}

/**
 *
 */
SDL_Texture* clona::organizer::get_texture(const std::string& name) {
	auto result = textures.find(name);
	if (textures.end() != result) {
		return result->second;
	}
	auto image = this->get_image(name);
	auto texture = SDL_CreateTextureFromSurface(renderer, image);
	textures.emplace(name, texture);
	return texture;
}