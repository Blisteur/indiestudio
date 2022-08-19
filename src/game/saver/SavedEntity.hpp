/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SavedEntity
*/

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "../../gameEngine/GameEngine.hpp"

class SavedEntity {
    public:
        SavedEntity() = default;
        SavedEntity(std::shared_ptr<Indie::IEntity> &entity);
        ~SavedEntity() = default;

        std::size_t _entityID;
        long unsigned _entityGameID;
        int _health;
        std::size_t _speed;
        std::size_t _damage;
        std::size_t _data;
        float _x;
        float _y;
        float _z;
    protected:
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive &ar, const unsigned int version)
        {
            (void)version;
            ar & _entityID;
            ar & _entityGameID;
            ar & _health;
            ar & _speed;
            ar & _damage;
            ar & _data;
            ar & _x;
            ar & _y;
            ar & _z;
        }
};
