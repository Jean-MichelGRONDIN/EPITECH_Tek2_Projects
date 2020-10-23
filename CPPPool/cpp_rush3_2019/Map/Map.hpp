/*
** EPITECH PROJECT, 2020
** map
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../includeSFML.hpp"
#include <map>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, std::map<int, int>  tiles, unsigned int width, unsigned int height);
    static std::map<int, int> get_map_from_file(const std::string &file);
    sf::VertexArray getVertexArray() const;
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
/*
class Map {
	public:
		Map();
		~Map();
        void drawMap(sf::RenderWindow *window);
        std::vector<int> get_map_from_file(const std::string &file);
        sf::RenderStates init_map_states(const std::string &file);
        sf::VertexArray load_map_in_vertexarray(std::vector<int> , int , int);

	protected:
        std::vector<int>  _map_pieces;
        std::vector<int>  _col_pieces;
        sf::RenderStates  _map_state;
        sf::VertexArray   _map;
        sf::VertexArray   _col;
	private:
};
*/
#endif /* !MAP_HPP_ */
