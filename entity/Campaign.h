/// @file
/// @brief Header file containing class declaration for Campaign.class
/// @details  1. Game Rules: The Map enforces that a cell of type wall cannot be occupied \n\n
/// 2. Model class from the MVC pattern. The Campaign keeps a vector of maps. \n\n
/// 3. Libraries: The campaign uses the boost archive and vector serialization libraries in order for its state to be saved/loaded.

#pragma once
#include "Map.h"
#include <vector>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>


class Campaign {
    public:
    
        Campaign();
        Campaign(vector<std::string>* m);
        Campaign(Campaign* c);
    
        bool validate();
        vector<std::string>* getMaps();
        void setMaps(vector<std::string>* m);
        std::string getName();
        void setName(std::string n);
    
        void display();
    
    
    private:
    
        std::vector<std::string>* maps;
        string name;
    

        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & maps;
            ar & name;
        }


};

inline vector<std::string>* Campaign::getMaps(){
    return maps;
}


inline void Campaign::setMaps(vector<std::string>* m){
    maps = m;
}

inline string Campaign::getName(){
    return name;
}

inline void Campaign::setName(std::string n){
    name = n;
}
