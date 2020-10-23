/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** City
*/

#include "City.hpp"

City::City()
{
    this->_map.load("Map/tileset.png", sf::Vector2u(16, 16), TileMap::get_map_from_file("Map/overworld.txt"), 191, 171);
    this->_colision.load("Map/tileset.png", sf::Vector2u(16, 16), TileMap::get_map_from_file("Map/mapcol.txt"), 191, 171);
    this->_player = new Player("lol", this->_colision.getVertexArray());
    this->_forgeron = new Forgeron();
    this->_bucheron = new Bucheron();
    this->_mineur = new Mineur();

    this->read_and_init_all_buildings();

    this->read_and_init_all_tree();

    this->read_and_init_all_ressources();

    this->_woodBar = new ProgressBar("Assets/wood_bar.png", sf::Vector2f(0, 0));
    this->_ironBar = new ProgressBar("Assets/iron_bar.png", sf::Vector2f(0, 35));
    this->_rockBar = new ProgressBar("Assets/rock_bar.png", sf::Vector2f(0, 70));
}

City::~City()
{
    delete _player;
    for (Building *tmp : _buldings)
        delete tmp;
    for (Ressoureces *tmp: _rocks)
        delete tmp;
    for (Tree *tmp: _trees)
        delete tmp;
}

static int find_building_type(std::string s)
{
    std::string name = s.substr(0,s.find(' ', 0));

    if (name.compare("LittleBuilding") == 0)
        return (1);
    if (name.compare("MiddleBuilding") == 0)
        return (2);
    if (name.compare("BigBuilding") == 0)
        return (3);
    return (-1);
}

void City::read_and_init_all_buildings() {
    std::string file_name = "City/Buildings.txt";
    std::ifstream file_content;
    int is_open_ret = 0;
    std::string s;
    int build_type = -1;
    std::string reapared_little_texture[] = {"Assets/hb3.png", "Assets/hb4.png"};
    float x = -1;
    float y = -1;

    file_content.open(file_name.data());
    is_open_ret = file_content.is_open();
    if (is_open_ret == 0) {
        std::cout << "Can't open " << file_name << " file !!" << std::endl;
        return;
    }
    while(std::getline(file_content, s)) {
        build_type = find_building_type(s);
        x = std::stof(s.substr(s.find(' ', 0)).c_str());
        y = std::stof(s.substr(s.find(' ', s.find(' ', 0) + 1)).c_str());
        if (build_type == 1)
            this->_buldings.push_back(new LittleBuilding(sf::Vector2f(x, y),
            "Assets/hfbrk.png",
            reapared_little_texture[random() % 2]));
        if (build_type == 2)
            this->_buldings.push_back(new MiddleBuilding(sf::Vector2f(x, y)));
        if (build_type == 3)
            this->_buldings.push_back(new BigBuilding(sf::Vector2f(x, y)));
    }
    file_content.close();
}

void City::read_and_init_all_tree() {
    std::string file_name = "City/Trees.txt";
    std::ifstream file_content;
    int is_open_ret = 0;
    std::string s;
    float x = -1;
    float y = -1;

    file_content.open(file_name.data());
    is_open_ret = file_content.is_open();
    if (is_open_ret == 0) {
        std::cout << "Can't open " << file_name << " file !!" << std::endl;
        return;
    }
    while(std::getline(file_content, s)) {
        x = std::stof(s.substr(s.find(' ', 0)).c_str());
        y = std::stof(s.substr(s.find(' ', s.find(' ', 0) + 1)).c_str());
        this->_trees.push_back(new Tree(sf::Vector2f(x, y)));
    }
    file_content.close();
}

void City::read_and_init_all_ressources() {
    std::string file_name = "City/Rocks.txt";
    std::ifstream file_content;
    int is_open_ret = 0;
    std::string s;
    float x = -1;
    float y = -1;

    file_content.open(file_name.data());
    is_open_ret = file_content.is_open();
    if (is_open_ret == 0) {
        std::cout << "Can't open " << file_name << " file !!" << std::endl;
        return;
    }
    while(std::getline(file_content, s)) {
        x = std::stof(s.substr(s.find(' ', 0)).c_str());
        y = std::stof(s.substr(s.find(' ', s.find(' ', 0) + 1)).c_str());
        this->_rocks.push_back(new Ressoureces(sf::Vector2f(x, y)));
    }
    file_content.close();
}

std::vector<Building *> City::getBuldings() const
{
    return (this->_buldings);
}

std::vector<Ressoureces *> City::getRocks() const
{
    return (this->_rocks);
}

std::vector<Tree *> City::getTrees() const
{
    return (this->_trees);
}

Player *City::getPlayer() const
{
    return (this->_player);
}

void City::cityGetCliked(sf::RenderWindow *window)
{
    sf::Vector2f mosePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    this->_forgeron->isClicked(mosePos);
    this->_bucheron->isClicked(mosePos);
    this->_mineur->isClicked(mosePos);
    for (Tree *tmp : this->_trees)
        tmp->_is_cliked(mosePos, _player);
    for (Ressoureces *tmp : _rocks)
        tmp->_is_cliked(mosePos, _player);
    for (Building *tmp : _buldings)
        tmp->isClicked(mosePos);
}

void City::cityGetKeyCliked()
{
    for (Building *tmp : _buldings) {
        if (tmp->getPopped(_player) && !tmp->isRepaired()) {
            tmp->repair(_player);
            if (tmp->isRepaired() && !tmp->_isHabitate) {
                int nPos = 0;
                sf::Vector2f nnpos(tmp->getSprite().getPosition());
                for (int i = 0; i != tmp->getSize(); i++) {
                    _Pnjs.push_back(new Pnj("lol", sf::Vector2f(nnpos.x + nPos, nnpos.y + 36)));
                    nPos += 40;
                }
            }
        }
    }
    if (this->_forgeron->isPopped()) {
        this->_forgeron->order(this->_player);
    }
    if (this->_bucheron->isPopped()) {
        this->_bucheron->order(this->_player);
    }
    if (this->_mineur->isPopped()) {
        this->_mineur->order(this->_player);
    }
}

void City::manage(sf::RenderWindow *window)
{
    if (_player->isAdded){
        _woodBar->ChangeBar(_player->getWood());
        _ironBar->ChangeBar(_player->getIron());
        _rockBar->ChangeBar(_player->getRock());
        _player->isAdded = false;
    }
    this->_bucheron->get_ressources();
    this->_mineur->get_ressources();
    window->draw(_map);
    for (Building *tmp : _buldings) {
        window->draw(tmp->getSprite());
        if (tmp->getPopped(_player))
            tmp->drawMenu(window);
    }
    for (Tree *tmp : this->_trees)
        window->draw(tmp->getRessTodraw());
    for (Ressoureces *tmp : _rocks)
        window->draw(tmp->getRessTodraw());
    for (Pnj *tmp : _Pnjs)
        window->draw(tmp->getSprite());
    _player->move(this->_trees, this->_rocks);
    window->draw(_player->getSprite());
    _woodBar->setNewPose(_player->getSprite().getPosition());
    _ironBar->setNewPose(_player->getSprite().getPosition());
    _rockBar->setNewPose(_player->getSprite().getPosition());

    window->draw(_player->getSprite());
    _woodBar->draw(window);
    _ironBar->draw(window);
    _rockBar->draw(window);
    window->draw(this->_forgeron->getSprite());
    window->draw(this->_bucheron->getSprite());
    window->draw(this->_mineur->getSprite());
    if (this->_forgeron->isPopped()) {
        if (this->_forgeron->getPopped(_player))
            this->_forgeron->drawMenu(window, this->_player);
    }
    if (this->_bucheron->isPopped()) {
        if (this->_bucheron->getPopped(_player))
            this->_bucheron->drawMenu(window);
    }
    if (this->_mineur->isPopped()) {
        if (this->_mineur->getPopped(_player))
            this->_mineur->drawMenu(window);
    }
}