/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** game_loop
*/

#include "../includeSFML.hpp"
#include "../Universe/universe.hpp"
#include "../City/City.hpp"

void game_loop(void) {
    universe *all = new universe();
    City *city = new City();
    sf::Music music;

    if (!music.openFromFile("Assets/music.ogg"))
            return;
    music.play();
    music.setLoop(true);
    while (all->_window->isOpen()) {
        while (all->_window->pollEvent(all->_game->_event))
        {
            if(all->_game->_event.type == sf::Event::Closed)
                all->_window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
                all->unzoom_camera();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
                all->rezoom_camera();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                city->cityGetCliked(all->_window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                city->cityGetKeyCliked();
        }
        all->_window->clear();
        all->getView().setCenter(city->getPlayer()->getSprite().getPosition());
        all->_window->setView(all->getView());
        city->manage(all->_window);
        all->_window->display();
    }
    music.stop();
}