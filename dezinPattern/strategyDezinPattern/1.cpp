// defines the family of Algorithm, put them into separate classes so that they can be changed at runtime;
#include<iostream> 
using namespace std;
class WalkAbleRobot{
public:
    virtual void walk()=0;
    virtual ~WalkAbleRobot() {}
};
class NormalWalk : public WalkAbleRobot{
public:
    void walk() override {
        // business logic;
    }
};
class NoWalk : public WalkAbleRobot{
public:
    void walk() override {
        // business logic
    }
};
class TalkAbleRobot{
public:
    virtual void Talk()=0;
    virtual ~TalkAbleRobot() {}
};
class NormalTalk : public TalkAbleRobot{
public:
    void Talk() override {
        // business logic
    }
};
class NoTalk: public TalkAbleRobot{
public:
    void Talk() override {

    }
};
class FlyAbleRobot{
public:
    virtual void fly()=0;
    virtual ~FlyAbleRobot() {}
};
class NormalFly : public FlyAbleRobot{
public:
    void fly() override{ 
        // business logic
    }
};
class NoFly : public FlyAbleRobot{
public:
    void fly() override { 
        // business logic
    }
};
class Robot{
protected:
    WalkAbleRobot* walkBehavior;
    TalkAbleRobot* talkBehavior;
    FlyAbleRobot* flyBehavior;
    Projection* projection;
public:
    Robot(WalkAbleRobot* w,TalkAbleRobot* t,FlyAbleRobot* f,Projection* p){
        this->walkBehavior=w;
        this->talkBehavior=t;
        this->flyBehavior=f;
        this->projection=p;
    }
    void walk(){ 
        walkBehavior->walk(); 
    }
    void talk(){ 
        talkBehavior->Talk(); 
    }
    void fly(){ 
        flyBehavior->fly(); 
    }
    // virtual void projection() = 0; // Abstract method for subclasses
    void project(){
        projection->project();
    }
};
// --- Concrete Robot Types ---
// class CompanionRobot : public Robot{
// public:
//     CompanionRobot(WalkAbleRobot* w,TalkAbleRobot* t,FlyAbleRobot* f)
//         : Robot(w, t, f) {}
//     void projection() override{
//         cout<<"Displaying friendly companion features..."<<endl;
//     }
// };
// class WorkerRobot : public Robot{
// public:
//     WorkerRobot(WalkAbleRobot* w, TalkAbleRobot* t, FlyAbleRobot* f)
//         : Robot(w,t,f) {}
//     void projection() override{
//         cout<<"Displaying worker efficiency stats..."<< endl;
//     }
// };
// int main(){
//     Robot *robot1=new CompanionRobot(new NormalWalk(),new NormalTalk(),new NoFly());
//     robot1->walk();
//     robot1->talk();
//     robot1->fly();
//     robot1->projection();
//     cout << "--------------------" << endl;
//     Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
//     robot2->walk();
//     robot2->talk();
//     robot2->fly();
//     robot2->projection();
//     return 0;
// }

// let make projection also another separate class so that a robot class has a (has -> a) relationship;
class Projection{
public:
    virtual void project()=0;
};
class CompanionRobot : public Projection{
public:
    void project() override{
        // business logic;
    }
};
class WorkerRobot : public Projection{
public:
    void project() override{
        // business logic;
    }
};
int main(){
    Robot* r1=new Robot(new NormalWalk(),new NormalTalk(),new NoFly(),new CompanionRobot());
    r1->walk();
    r1->talk();
    r1->fly();
    r1->project();
}