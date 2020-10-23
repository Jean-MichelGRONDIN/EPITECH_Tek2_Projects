#include "EndGame.hpp"

EndGame::EndGame(ICameraSceneNode* cam, Indie::STATE& indieState, ISceneManager* smgr, IVideoDriver* driver, IrrlichtDevice* device, std::shared_ptr<GameSettings> settings,
    Indie::STATE curentState, vector3df pos, vector3df rot) : GamePart(cam, indieState, settings, curentState, pos, rot), _music(MUSIC_END, false)
{
    _music.initMusic();
    irr::scene::IMeshSceneNode* box = smgr->addCubeSceneNode(CUBE_SIZE, 0, -1, irr::core::vector3df(3000.0F, 3000.0F, 3000.0F));
    box->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    box->setMaterialTexture(0, driver->getTexture(BOX_TEXTURE));
    box = smgr->addCubeSceneNode(CUBE_SIZE, 0, -1, irr::core::vector3df(3005.0F, 3000.0F, 3000.0F + CUBE_SIZE));
    box->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    box->setMaterialTexture(0, driver->getTexture(BOX_TEXTURE));
    box = smgr->addCubeSceneNode(CUBE_SIZE, 0, -1, irr::core::vector3df(3010.0F, 3000.0F , 3000.0F -   CUBE_SIZE));
    box->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    box->setMaterialTexture(0, driver->getTexture(BOX_TEXTURE));
    box = smgr->addCubeSceneNode(CUBE_SIZE, 0, -1, irr::core::vector3df(3015.0F, 3000.0F, 3000.0F - 2 * CUBE_SIZE));
    box->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    box->setMaterialTexture(0, driver->getTexture(BOX_TEXTURE));
}

EndGame::~EndGame()
{
}

void EndGame::update()
{
    static int i = 0;
    GamePart::update();
    if (!isActive())
        return;
    if (i == 0) {
        _music.playMusic();
        i++;
    }
}

bool EndGame::onEvent(const irr::SEvent& event)
{
    if (!isActive())
        return (false);
    return false;
}
