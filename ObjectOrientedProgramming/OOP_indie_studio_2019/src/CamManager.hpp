/*
** EPITECH PROJECT, 2020
** cross_platform
** File description:
** CamManager
*/

#ifndef CAMMANAGER_HPP_
#define CAMMANAGER_HPP_

#include "IrrScean.hpp"
#include "IrrGui.hpp"
#include <unordered_map>
#include "CreatorCam.hpp"
#include "IEventHandeler.hpp"
#include <memory>


class CamManager : public IEventHandeler {
    public:
        CamManager(std::shared_ptr<IrrGui> gui, std::shared_ptr<IrrScean> scean);
        ~CamManager();
        virtual bool onEvent(const irr::SEvent& event) override;
        void addCam();
        void selectCam(int id);

    protected:
        std::shared_ptr<CreatorCam> _creatCam;
        irr::gui::IGUIButton *_DispWin;
        std::shared_ptr<IrrGui> _gui;
        std::unordered_map<int, std::string> _cams;
    private:
};

#endif /* !CAMMANAGER_HPP_ */
