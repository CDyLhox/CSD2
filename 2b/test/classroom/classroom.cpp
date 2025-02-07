#include <iostream>

class Classroom
{
public:
    Classroom();
    bool haveSpeakers();

private:
    int chairs = 30;
    bool speakers = false;
    int desks = chairs / 2;
};

Classroom::Classroom()
{
    std::cout << "we are in a Classroom the default one" << std::endl;
    std::cout << "we have " << chairs << " chairs" << std::endl;
    std::cout << "we have " << desks << " amount of desks" << std::endl;
}

bool Classroom::haveSpeakers()
{
    if (speakers == true)
    {
        std::cout << "goddamn nice sound.." << std::endl;
    }
    else
    {
        std::cout << "the sound is nowhere to be found" << std::endl;
    }
    return speakers;
}

class Human
{
public:
    bool removeHeart();
    void stealHeart(Human heartlessBastard);

protected:
    bool haveHeartBeat = true;
    int weight;
    int amountOfHearts = 0;
};

bool Human::removeHeart()
{
    if (!haveHeartBeat)
    {
        weight = -0.35;
        std::cout << "badoenk badoenk" << std::endl;
        return true;
    }
    else
    {
        haveHeartBeat = false;
        std::cout << "amount of weight " << weight << std::endl;
        return false;
    }
}

void Human::stealHeart(Human heartlessBastard)
{
    if (removeHeart() == true)
    {
    heartlessBastard:
        removeHeart();
    }
    else{
        std::cout << "there is no heart toe" << std::endl;
    }
}

class Teacher : public Human
{
public:
    Teacher();

private:
    bool caffeine = false;
};

Teacher::Teacher()
{
    weight = 101;
    std::cout << "jaMan" << std::endl;
    std::cout << "yo man ik heb zieke gains ik weeg nu " << weight << std::endl;
}

class Student : public Human
{
public:
    Student();
};

Student::Student()
{
    weight = 65;
    std::cout << "pieter ik snap er niks van" << std::endl;
    std::cout << "ik ben naar de jumbo geweest + frikandelbroodje. ik weeg nu " << weight << std::endl;
}
int main()
{
    Classroom aClassroom;
    bool removeHeart();
    return 0;
}
