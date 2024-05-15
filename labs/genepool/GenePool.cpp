#include "GenePool.h"
#include "Enums.h"
#include <sstream>
#include <iostream>
// GenePool Member Functions

GenePool::GenePool(std::istream& line){
    std::string temp;
    while(std::getline(line, temp)){
        if(temp[0] == '#' || temp.empty()){
            continue;
        }

        size_t index = 0;
        std::string name, mf, momname, dadname;

        size_t tab = temp.find('\t');
        name = temp.substr(index, tab - index);
        index = tab + 1;

        tab = temp.find('\t' , index);
        mf = temp.substr(index, tab - index);
        index = tab + 1;

        tab = temp.find('\t' , index);
        dadname = temp.substr(index, tab - index);
        index = tab + 1;

        momname = temp.substr(index);

        Gender gender;
        if(mf == "male"){
            gender = Gender::MALE;
        } else if (mf == "female"){
            gender = Gender::FEMALE;
        } 

        Person* person = new Person(name, gender);

        family[name] = person;

        if (momname != "???"){
            person->setmother(family[momname]);
            family[momname]->setchild(person);
        }
        if (dadname != "???"){
            person->setmother(family[dadname]);
            family[dadname]->setchild(person);
        }
    }
}

GenePool::~GenePool(){
    for (std::map<std::string, Person*>::iterator i = family.begin(); i != family.end(); i++) {
        delete i->second;
    }
}

std::set<Person*> GenePool::everyone()const{
    std::set<Person*> result;
    for (std::map<std::string, Person*>::const_iterator i = family.begin(); i != family.end(); i++) {
        result.insert(i->second);
    }
    return result;
}

Person* GenePool::find(const std::string& name) const {
    std::map<std::string, Person*>::const_iterator i = family.find(name);
    if (i != family.end()) {
        return i->second;
    }
    return nullptr;
}







