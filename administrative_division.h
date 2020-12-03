//
// Created by Zenbook on 16.11.2020.
//
#include <string>
#include <utility>
#include <iostream>
#ifndef PP_V_IS_LABA_2_ADMINISTRATIVE_DIVISION_H
#define PP_V_IS_LABA_2_ADMINISTRATIVE_DIVISION_H

using namespace std;
class locality{
protected:
    string name;
    int population{};
    float square{};
public:
    virtual string get_name()= 0;
    virtual int get_population()= 0;
    virtual float get_square()= 0;
    virtual void set_name(string Name)= 0;
    virtual void set_population(int Population)= 0;
    virtual void set_square(float Square)= 0;
};
class region:virtual public locality{
public:
    region()= default;
    region(string name,int population,float square){
        this->name=std::move(name);
        this->population=population;
        this->square=square;
    }
    string get_name() override{
        return name;
    }
    int get_population() override{
        return population;
    }
    float get_square() override{
        return square;
    }
    void set_name(string Name) override{
        this->name=Name;
    }
    void set_square(float Square) override{
        this->square=Square;
    }
    void set_population(int Population) override{
        this->population=Population;
    }

};

class city:virtual public locality{
public:
    city()= default;
    city(string name,int population,float square){
        this->name=std::move(name);
        this->population=population;
        this->square=square;
    }
    string get_name() override{
        return name;
    }
    int get_population() override{
        return population;
    }
    float get_square() override{
        return square;
    }
    void set_name(string Name) override{
        this->name=Name;
    }
    void set_square(float Square) override{
        this->square=Square;
    }
    void set_population(int Population) override{
        this->population=Population;
    }
    float density(){
        return this->population/this->square;
    }

};


class region_center: public region,public city{
public:
    region_center()= default;
    region_center(string name, int population, float square){
        this->name=std::move(name);
        this->population=population;
        this->square=square;
    }
    string get_name() override{
        return name;
    }
    int get_population() override{
        return population;
    }
    float get_square() override{
        return square;
    }
    void set_name(string Name) override{
        this->name=Name;
    }
    void set_square(float Square) override{
        this->square=Square;
    }
    void set_population(int Population) override{
        population=Population;
    }

};
class district_center:virtual protected region_center{
public:
    district_center()= default;
    district_center(string name, int population, float square){
        this->name=std::move(name);
        this->population=population;
        this->square=square;
    }
    void voting_to_change_name(int people_for,int people_against,string new_name){
        if (people_for>people_against){
            set_name(new_name);
        }
    }
};
class capital:virtual private district_center{
public:
    capital(string name, int population, float square){
        this->name=std::move(name);
        this->population=population;
        this->square=square;
    }
    int imigration(int people_that_imigrate){
        set_population(population+people_that_imigrate);
        return population;
    }
    int emigration(int people_that_emigrate){
        this->set_population(population-people_that_emigrate);
        return population;
    }
    string start_voting_for_chaging_name(int people_for,int people_against,int start_people,string new_name){
        if (start_people>10000){
            voting_to_change_name(people_for,people_against,new_name);
        }
        return name;
    }
};


#endif //PP_V_IS_LABA_2_ADMINISTRATIVE_DIVISION_H
