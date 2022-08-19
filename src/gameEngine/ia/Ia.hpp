/*
** EPITECH PROJECT, 2022
** ia
** File description:
** ia
*/

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <memory>
#include "../entity/interface/IEntity.hpp"

namespace Indie {
    namespace gameEngine {
        class Ia {
            public:

                                /* Constructor and Destructor */
                Ia(std::pair<float, float>, std::vector<std::vector<char>>, std::list<std::tuple<float, float, float>>);
                ~Ia();
                                /*----------------------------*/


                                    /* All useful methods */
                int isSolid(int x, int y) const;
                int isDangerousZone(int x, int y) const;
                void fillVarsAndMap();
                void putBomb();
                                    /*--------------------*/

                                        /* All setters */
                void setNewGoal();
                void setNewGoalOffense();
                void setNewGoalDefense();
                void setPlayerPos();
                void updatePos();
                                        /*-------------*/

                                        /* All getters */
                //std::indie::Map GetClassMap
                std::pair<float, float> getPlayerPos() const;
                std::list<std::tuple<float, float, float>> getBombPos() const;
                std::pair<float, float> getGoalPos() const;
                bool getWillBombBePlaced();
                                        /*-------------*/

            private:
                bool willBombBePlaced;
                std::vector<std::vector<char>> _charMap; // 0 == vide // 1 mur destructible // 2 Mur indestructible // 3 Bombe // 4 Portée bombe // 5 Autres joueurs;
                std::list<std::tuple<float, float, float>> _bombs_pos;
                std::pair<float, float> _player_pos;
                std::pair<float, float> _goal_pos;
                std::pair<float, float> _new_pos;
                int where_they_go;
            protected:
        };
    }
}
