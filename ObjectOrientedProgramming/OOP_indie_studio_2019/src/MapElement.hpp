/*
** EPITECH PROJECT, 2020
** oop_indie_studio_2019
** File description:
** MapElement
*/

#ifndef MAPELEMENT_HPP_
#define MAPELEMENT_HPP_

#include "IMapElem.hpp"
#include "Map.hpp"



#define CUBE_SIZE 12.0F

class MapElement : public IMapElem {
    public:
        MapElement(MapManager *map, char sym, std::uint64_t = 1000, std::uint64_t = 1000);
        ~MapElement();
        virtual std::list<std::shared_ptr<IMapElem>> getRightElem() override;
        virtual std::list<std::shared_ptr<IMapElem>> getTopElem() override;
        virtual std::list<std::shared_ptr<IMapElem>> getleftElem() override;
        virtual std::list<std::shared_ptr<IMapElem>> getBotomElem() override;
        virtual std::list<std::shared_ptr<IMapElem>> getCurElem() override;
        virtual std::uint64_t getCurrentRow() override;
        virtual std::uint64_t getCurrentCol() override;
        virtual void getHited() override;
        virtual bool isSolide() override;
        virtual irr::core::vector3df getPos() override;
        virtual char getSym() override;
        MapManager *getMap();
        // virtual bool isOnMap() override;
    protected:
        irr::core::vector3df _pos;
        MapManager *_map;
        std::uint64_t _current_row;
        std::uint64_t _current_column;
        char _sym;
        bool _onMap;
        bool _solide;
    private:
};

#endif /* !MAPELEMENT_HPP_ */
